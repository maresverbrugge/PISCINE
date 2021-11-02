/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_rev_int_tab.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 16:12:16 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/22 12:01:11 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp[size];
	int copy_size;
	int i;

	copy_size = size;
	i = 0;
	while (i < copy_size)
	{
		temp[i] = tab[size - 1];
		i++;
		size--;
	}
	i = 0;
	while (i < copy_size)
	{
		tab[i] = temp[i];
		i++;
	}
}
