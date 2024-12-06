/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:01:14 by nneto-de          #+#    #+#             */
/*   Updated: 2023/08/01 14:44:28 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>

int	ft_atoi(char *s)
{
	int	i;
	int	num;

	num = 0;
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + s[i] - '0';
		i++;
	}
	return (num);
}

void	conv_bin(char *s, int pidserver)
{
	int		base;
	int		i;
	char	letra;

	i = 0;
	while (s[i] != '\0')
	{
		base = 128;
		letra = s[i];
		while (base > 0)
		{
			if (letra >= base)
			{
				kill (pidserver, SIGUSR1);
				letra = letra - base;
			}
			else
				kill (pidserver, SIGUSR2);
			base = base / 2;
			usleep(100);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pidserver;

	if (argc != 3)
		return (1);
	pidserver = ft_atoi(argv[1]);
	conv_bin(argv[2], pidserver);
	return (0);
}
