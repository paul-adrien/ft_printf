/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/03/10 15:20:59 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*static int	st_print_c(char **print, char **tab, size_t i, int printlength)
{
	size_t	j;
	size_t	c_width;

	j = 0;
	c_width = ft_findwidth(tab[i]);
	if (print[i][0] == '\0')
	{
		ft_putchar('\0');
		while (++j < c_width)
			ft_putchar(print[i][j]);
	}
	else
	{
		while (j < ft_strlen(print[i]))
		{
			ft_putchar(print[i][j]);
			j++;
		}
		if (j < c_width)
		{
			ft_putchar('\0');
			j++;
		}
	}
	return ((printlength = printlength + j));
}

static int	st_print_c(char **print, char **tab, size_t i)
{
	size_t	j;
	size_t	c_width;

	j = 0;
	c_width = ft_findwidth(tab[i]);
	if (print[i][0] == '\0')
	{
		//ft_putchar('\0');
		j++;
		while (j < c_width)
			j++;
			//ft_putchar(print[i][j]);
	}
	else
	{
		while (j < ft_strlen(print[i]))
		{
			//ft_putchar(print[i][j]);
			j++;
		}
		if (j < c_width)
		{
			//ft_putchar('\0');
			j++;
		}
	}
	return (ft_fill_buff(print[i], j, 0));
}

static int	st_print(char **print, char **tab)
{
	size_t	i;
	int		type;
	int		printlength;

	i = 0;
	printlength = 0;
	while (print[i])
	{
		if ((type = ft_findtype(tab[i])) == 3 || type == 7)
			st_print_c(print, tab, i);
		else
		{
			//ft_putstr(print[i]);
			ft_fill_buff(print[i], ft_strlen(print[i]), 0);
		}
		i++;
	}
	return (printlength);
}*/

static void	st_tabdel(char **tab)
{
	size_t i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

int			ft_printf(const char *restrict format, ...)
{
	va_list	ap;
	char	**tab;
	int		print_length;
	int		i;

	i = 0;
	va_start(ap, format);
	tab = ft_formattotab(format);
	if ((print_length = ft_dispatcher(tab, ap)) == -1)
	{
		va_end(ap);
		return (-1);
	}
	if (tab)
		st_tabdel(tab);
	va_end(ap);
	ft_fill_buff("", 2);
	return(print_length);
}
