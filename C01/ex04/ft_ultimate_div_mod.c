/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultimate_div_mod.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 12:46:47 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/21 13:46:12 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int temp0;
	int temp1;

	temp0 = *a / *b;
	temp1 = (*a) % (*b);
	*a = temp0;
	*b = temp1;
}
