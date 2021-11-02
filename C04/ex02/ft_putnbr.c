/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/29 16:18:18 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/29 18:16:18 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		digit_counter(int n);
int		power_of_10(int n);
void	write_negative(int nb);
void	write_positive(int nb);

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		write_negative(nb);
	}
	else
	{
		write_positive(nb);
	}
}

int		digit_counter(int n)
{
	int count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int		power_of_10(int n)
{
	int power;

	power = 1;
	if (n == 0)
	{
		power = 1;
	}
	while (n > 0)
	{
		power = power * 10;
		n--;
	}
	return (power);
}

void	write_negative(int nb)
{
	char	temp;
	int		count;
	int		power;
	int		eachdigit;

	count = digit_counter(nb);
	while (count > 0)
	{
		power = power_of_10(count - 1);
		eachdigit = -1 * nb / power;
		temp = eachdigit + '0';
		write(1, &temp, 1);
		nb = nb + (eachdigit * power);
		count--;
	}
}

void	write_positive(int nb)
{
	char	temp;
	int		count;
	int		power;
	int		eachdigit;

	count = digit_counter(nb);
	while (count > 0)
	{
		power = power_of_10(count - 1);
		eachdigit = nb / power;
		temp = eachdigit + '0';
		write(1, &temp, 1);
		nb = nb - (eachdigit * power);
		count--;
	}
}
