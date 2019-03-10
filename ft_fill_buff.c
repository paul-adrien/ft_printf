/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_buff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:28:09 by plaurent          #+#    #+#             */
/*   Updated: 2019/03/10 15:22:57 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_printf.h"

static char	*ft_write_refresh(char *buff, size_t length)
{
	write(1, buff, length);
	ft_bzero(buff, length);
	return (buff);
}

static char	*st_(char *buff, char *str, size_t *length_total)
{
	size_t		length;
	size_t		size;
	size_t		size_tmp;

	size_tmp = 0;
	length = ft_strlen(buff);
	size = ft_strlen (str);
	if (length + size == 4096)
	{
		buff = ft_write_refresh(buff, length);
		return (buff);
	}
	*length_total = *length_total + size;
	while (size + length > 4096)
	{
		buff = ft_strncat(buff, str + size_tmp, 4096 - length);
		size = size - (4096 - length);
		size_tmp = size_tmp + (4096 - length);
		buff = ft_write_refresh(buff, 4096);
		length = 0;
	}
	buff = ft_strncat(buff, str, size);
	return (buff);
}

int			ft_fill_buff(char *str, int end)
{
	static char		*buff;
	static size_t	length_total;
	size_t			length;
	size_t			size;

	if (end == 2)
		length_total = 0;
	if (!buff)
		if (!(buff = ft_strnew(4096)))
			return (0);
	length = ft_strlen(buff);
	size = 0;
	if (str)
		size = ft_strlen(str);
	if (size == 0 && end == 0)
		return (0);
	if (end == 1)
	{
		if (length != 0)
			buff = ft_write_refresh(buff, length);
		return (length_total = length_total + size);
	}
	if (length + size < 4096)
	{
		buff = ft_strncat(buff, str, size);
		return (length_total = length_total + size);
	}
	else if (length + size >= 4096)
		buff = st_(buff, str, &length_total);
	return (length_total);
}

/*int			main(int argc, char **argv)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (++i < 1000)
	{
		if (i == 999)
			j = 1;
		ft_putnbr(ft_fill_buff(argv[1], 15, j));
		ft_putchar('|');
	}
	return (0);
}*/
