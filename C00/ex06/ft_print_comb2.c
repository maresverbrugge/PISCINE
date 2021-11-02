/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_comb2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 11:47:38 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/16 18:14:40 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writedigits(int i, int j, int k, int l);

void	lastloop(int i, int j, int k, int l);

void	ft_print_comb2(void)
{
	int i;
	int j;
	int k;
	int l;

	i = '0';
	while (i <= '9')
	{
		j = '0';
		while (j <= '9')
		{
			k = '0';
			while (k <= '9')
			{
				l = '0';
				lastloop(i, j, k, l);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	lastloop(int i, int j, int k, int l)
{
	while (l <= '9')
	{
		if ((i * 10 + j) < (k * 10 + l))
		{
			writedigits(i, j, k, l);
		}
		l++;
	}
}

void	writedigits(int i, int j, int k, int l)
{
	if (i == '0' && j == '0' && k == '0' && l == '0')
	{
		return ;
	}
	else
	{
		write(1, &i, 1);
		write(1, &j, 1);
		write(1, " ", 1);
		write(1, &k, 1);
		write(1, &l, 1);
		if (!(i == '9' && j == '8' && k == '9' && l == '9'))
			write(1, ", ", 2);
	}
}
