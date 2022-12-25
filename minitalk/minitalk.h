/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydegerli <ydegerli@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:20:42 by ydegerli          #+#    #+#             */
/*   Updated: 2022/12/25 17:38:35 by ydegerli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stddef.h>
# include <stdarg.h>

int		hexa_dec_up(unsigned int c);

int		hexa_dec_lwr(unsigned int c);

int		str_print(char *str);

int		ft_putchar(int c);

int		uns_print(unsigned int num);

int		ptr_len(unsigned long num);

int		hexa_dec_lwr_ptr(unsigned long c);

int		ptr_print(unsigned long ptr);

size_t	ft_putnbr(int n);

int		ft_putstr(char *s);

int		int_print(int s);

int		ctl(va_list lst, char c);

int		ft_printf(const char *start, ...);

int		ft_atoi(char *str);

#endif
