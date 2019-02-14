/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pa <marvin@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:12:27 by pa                #+#    #+#             */
/*   Updated: 2018/11/29 10:49:16 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	i = (int)ft_strlen((char *)s) - 1;
	while ((s[j] == ' ' || s[j] == ',' || s[j] == '\n' || s[j] == '\t')
		&& s[j])
		j++;
	while ((s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		&& i > j)
		i--;
	str = ft_strsub(s, j, (i - j + 1));
	return (str);
}
