/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:31:25 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/25 17:42:48 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int signal)
{
	int			x;
	static int	c;
	static int	i = 7;

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
	}
	else
		i--;
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Your PID ==> %d\n", pid);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
}
