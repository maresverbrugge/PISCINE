/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rush03.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: abeznik <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/12 10:56:49 by abeznik       #+#    #+#                 */
/*   Updated: 2020/09/13 20:32:34 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c);

void		iter_firstlastrow(int col, int x);

void		iter_middlerow(int col, int x);

void		print_error(void);

void		rush(int x, int y)
{
	int col;
	int row;

	if (x <= 0 || y <= 0)
	{
		print_error();
	}
	else
	{
		row = 1;
		while (row <= y)
		{
			col = 1;
			if (row == 1 || row == y)
			{
				iter_firstlastrow(col, x);
			}
			else
			{
				iter_middlerow(col, x);
			}
			ft_putchar('\n');
			row++;
		}
	}
}

void		iter_firstlastrow(int col, int x)
{
	while (col <= x)
	{
		if (col == 1)
		{
			ft_putchar('A');
		}
		else if (col == x)
		{
			ft_putchar('C');
		}
		else
		{
			ft_putchar('B');
		}
		col++;
	}
}

void		iter_middlerow(int col, int x)
{
	while (col <= x)
	{
		if (col == 1 || col == x)
		{
			ft_putchar('B');
		}
		else
		{
			ft_putchar(' ');
		}
		col++;
	}
}

void		print_error(void)
{
	write(1, "Please enter strictly positive numbers as input\n", 48);
}
