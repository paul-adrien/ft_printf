/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/03/01 12:02:36 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	st_print(char **print, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	c_width;
	int		printlength;

	i = 0;
	printlength = 0;
	while (print[i])
	{
		if (ft_findtype(tab[i]) == 3) // A ajuster avec la width
		{
			j = 0;
			if (print[i][0] == '\0' && (c_width = ft_findwidth(tab[i])) <= 1)
			{
				ft_putchar('\0');
				j++;
				while (j < c_width)
				{
					ft_putchar(print[i][j]);
					j++;
				}
				printlength = printlength + 1;
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
				printlength = printlength + j;
			}
		}
		else
		{
			ft_putstr(print[i]);
			printlength = printlength + ft_strlen(print[i]);
		}
		i++;
	}
	return (printlength);
}

int			ft_printf(const char * restrict format, ...)
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
	va_end(ap);
	return (printlength);
}
/*
int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	char	*print;
	int		printlength;

	va_start(ap, format);
	tab = ft_formattotab(format);
	//if (!(ft_check_arg_nb(tab, ap)))
	//{
	//	va_end(ap);
	//	return (-1);
	//}
	if (!(print = ft_dispatcher(tab, ap)))
	{
		va_end(ap);
		return (-1);
	}
	ft_putstr(print);
	printlength = ft_strlen(print);
	va_end(ap);
	return (printlength);
}*/
