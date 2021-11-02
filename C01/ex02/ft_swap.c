/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_swap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/17 21:58:46 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/21 11:48:00 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int t;

	t = *b;
	*b = *a;
	*a = t;
}
