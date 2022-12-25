/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:44:20 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/25 17:14:23 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signal, siginfo_t *info, void *s)
{
	int			x;
	static int	c;
	static int	i = 7;

	(void)s;
	x = 0;
	if (signal == SIGUSR1)
		x = 1;
	else if (signal == SIGUSR2)
		x = 0;
	c += x << i;
	if (i == 0)
	{
		ft_printf("%c", c);
		i = 7;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		i--;
}

int	main(void)
{
	int					pid;
	struct sigaction	sigact;

	pid = getpid();
	ft_printf("Your PID ==> %d\n", pid);
	sigact.sa_sigaction = ft_handler;
	sigact.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
}
