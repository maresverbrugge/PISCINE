/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test1.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mgershfi <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/26 15:57:19 by mgershfi      #+#    #+#                 */
/*   Updated: 2020/09/27 15:04:49 by mgershfi      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_zeromaker(char *str)
{
	int i;
	i = 0;

	ft_putchar(str[i]);
	i++;

	while (str[i] != '\0')
	{
		i++;
		write(1, "0", 1);
	}
	return(0);
}

int main()
{
	int result; 
	result = ft_zeromaker("9456") / 10;
	printf("%d", result);
}
