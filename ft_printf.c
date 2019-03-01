/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/03/01 16:54:16 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	st_print_c(char **print, char **tab, size_t i, int printlength)
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
			printlength = st_print_c(print, tab, i, printlength);
		else
		{
			ft_putstr(print[i]);
			printlength = printlength + ft_strlen(print[i]);
		}
		i++;
	}
	return (printlength);
}

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
	char	**print;
	int		printlength;
	int		i;

	i = 0;
	va_start(ap, format);
	tab = ft_formattotab(format);
	if (!(print = ft_setprint(tab)))
	{
		va_end(ap);
		return (-1);
	}
	if (!(print = ft_dispatcher(tab, ap, print)))
	{
		va_end(ap);
		return (-1);
	}
	printlength = st_print(print, tab);
	i = 0;
	if (tab)
		st_tabdel(tab);
	//free(print[1]); // permet de retirer des leaks // free(print[0]) fait bugger
	if (print)
		st_tabdel(print);
	//if (print)  FAIT BUGGER Poiner beeing freed was not allocated
	//	st_tabdel(print);
	va_end(ap);
	return (printlength);
}
