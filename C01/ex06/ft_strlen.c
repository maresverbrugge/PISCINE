/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/21 15:45:41 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/21 16:07:59 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int nbr;

	nbr = 0;
	while (str[nbr] != '\0')
	{
		nbr++;
	}
	return (nbr);
}
