/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/24 10:09:23 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/24 13:40:49 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < n && j < n)
	{
		if (src[j] != '\0')
		{
			dest[i] = src[j];
			j++;
		}
		else
		{
			dest[i] = '\0';
		}
		i++;
	}
	return (dest);
}
