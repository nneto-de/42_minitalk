/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:01:23 by nneto-de          #+#    #+#             */
/*   Updated: 2023/07/31 18:03:05 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <limits.h>

void	ft_putchar(int c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int num)
{
	if (num <= 9)
	{
		ft_putchar (num + '0');
	}
	if (num > 9)
	{
		ft_putnbr (num / 10);
		ft_putchar ((num % 10) + '0');
	}
}

void	convertex(char *s)
{
	int		i;
	int		base;
	char	bit;
	int		control;
	int		result;

	i = 7;
	while (s[i])
	{
		base = 1;
		control = i;
		result = 0;
		while (base <= 128)
		{
			bit = s[control];
			if (bit == '1')
				result = result + base;
			base = base * 2;
			control--;
		}
		write(1, &result, 1);
		i = i + 8;
	}
}

void	sig_handler(int sig)
{
	static int	i;
	static char	s[8];

	if (sig == SIGUSR1)
	{
		s[i] = '1';
	}
	else if (sig == SIGUSR2)
	{
		s[i] = '0';
	}
	i++;
	if (i == 8)
	{
		i = 0;
		convertex(s);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putnbr (pid);
	write (1, "\n", 1);
	signal (SIGUSR1, sig_handler);
	signal (SIGUSR2, sig_handler);
	while (1)
		sleep(1);
	return (0);
}
