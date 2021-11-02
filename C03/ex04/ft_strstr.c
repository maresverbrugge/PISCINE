/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mverbrug <mverbrug@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/28 15:45:08 by mverbrug      #+#    #+#                 */
/*   Updated: 2020/09/29 10:57:40 by mverbrug      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int temp_i;
	int len_str;
	int len_to_find;

	i = 0;
	len_str = ft_strlen(str);
	len_to_find = ft_strlen(to_find);
	if (len_to_find == 0)
		return (str);
	else
	{
		while (i <= (len_str - len_to_find))
		{
			temp_i = i;
			if (to_find[0] == str[i])
			{
				if (ft_strncmp(&str[i], to_find, len_to_find) == 0)
					return (&str[temp_i]);
			}
			i++;
		}
		return (NULL);
	}
}
