/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:44:35 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/25 17:07:52 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	is_approved(int signal)
{
	(void) signal;
	ft_printf("KARAKTER ONAYLANDI!\n");
}

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	nbr;

	i = 0;
	neg = -1;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + str[i] - '0';
		i++;
	}
	return (nbr * neg);
}

void	send_string(int pid, char *str)
{
	int				i;
	unsigned char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		signal(SIGUSR1, is_approved);
		signal(SIGUSR2, is_approved);
		send_string(pid, av[2]);
		send_string(pid, "\n");
	}
	else
	{
		ft_printf("0==============0\n");
		ft_printf("  Hatalı Giriş! \n");
		ft_printf("0==============0");
	}
}
