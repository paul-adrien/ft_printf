/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/07 18:46:22 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** A apprendre :
** - stdarg
**
**
**
**
**
**
*/

#include <stdarg.h>
#include <stdio.h> // A RETIRER
#include "libft.h"

int		ft_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

unsigned int	ft_strcountparts(const char *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while ((s[i] && s[i] != '%') || ((s[i] && s[i] == '%') && (s[i + 1] && s[i + 1] == '%')))
			((s[i] && s[i] == '%') && (s[i + 1] && s[i + 1] == '%') == 1 ? i = i + 2 : i++);
		if (i != 0)
			k++;
		if (s[i] && s[i] == '%')
			while (s[i + j] && !ft_isconv(s[i + j]))
				j++;
		if (s[i + j] && ft_isconv(s[i + j]))
			j++;
		if (j != 0)
			k++;
		i = i + j;
	}
	return (k);
}

int		ft_charcount(const char * restrict s, int i, int mode)
{
	int j;

	j = 0;
	if (mode == 1)
	{
		while ((s[i + j] && s[i + j] != '%') || ((s[i + j] && s[i + j] == '%') && (s[i + j + 1] && s[i + j + 1] == '%')))
			((s[i + j] && s[i + j] == '%') && (s[i + j + 1] && s[i + j + 1] == '%') == 1 ? j = j + 2 : j++);
		return (j);
	}
	else 
	{
		if (s[i] && s[i] == '%')
 			while (s[i + j] && !ft_isconv(s[i + j]))
				j++;
		if (s[i + j] && ft_isconv(s[i + j]))
			j++;
		return (j);
	}
}

char	**ft_formattotab(const char * restrict s)
{
	int		i;
	int		j;
	int		k;
	char 	**tab;

	i = 0;
	k = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * (ft_strcountparts(s) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((j = ft_charcount(s, i, 1)))
		{
			tab[k] = ft_strsub(s, i, (size_t)j);
			k++;
		}
		i = i + j;
		if ((j = ft_charcount(s, i ,2)))
		{
			tab[k] = ft_strsub(s, i, (size_t)j);
			k++;
		}
		i = i + j;
	}
	tab[k] = 0;
	return (tab);
}

int		ft_checkconv(char *tab, int i)
{
	int		n;

	(tab[i] == 'd' ? n = 1 : n = 0);
	(tab[i] == 'i' ? n = 2 : n = 0);
	(tab[i] == 'o' || tab[i] == 'u' ||
	 tab[i] == 'x' || tab[i] == 'X' ? n = 3 : n = 0);
	(tab[i] == 'c' ? n = 4 : n = 0);
	(tab[i] == 's' ? n = 5 : n = 0);
	(tab[i] == 'p' ? n = 6 : n = 0);
	(tab[i] == 'f' ? n = 7 : n = 0);
	return (n);
}

int		ft_conv_num(char *tab, va_list ap)
{
	int i;
	int n;
	
	i = 0;
	n = 0;
	if (!tab || !ap)
		return (-1);
	if (tab[0] == '%' && (tab[1] && tab[1] != '%'))
	{
		while (tab[i])
			i++;
		i--;
		n = ft_checkconv(tab[i], i);
		return (n);
	}
	return (0);
}



int		main(int ac, char **av)
{
	char **tab;
	int i;

	i = 0;
	int		(*list_ft[8])(char *)(va_list);

	list_ft[1] = &ft_convd;
	list_ft[2] = &ft_convi;
	list_ft[3] = &ft_convouxX;
	list_ft[4] = &ft_convc;
	list_ft[5] = &convs;
	list_ft[6] = &convp;
	list_ft[7] = &convf;
	ft_printf(av[1], ...);
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	(void)ac;
	(void)av;
	return (0);
}

int		ft_dispacher(char **tab, va_list ap, int n)
{
	int		(*list_ft[8])(char *)(va_list);

	list_ft[0] = &ft_no_conv;
	list_ft[1] = &ft_convd;
	list_ft[2] = &ft_convi;
	list_ft[3] = &ft_convouxX;
	list_ft[4] = &ft_convc;
	list_ft[5] = &convs;
	list_ft[6] = &convp;
	list_ft[7] = &convf;
	while (*tab)
	{
		if (ft_conv_num(*tab) >= 0)
			if (!(list_fd[n](*tab, ap))) // A RACCORDER
				return (-1);
		else
			return (-1);
		*tab++;
	}
	return (1);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	int		n;

	n = 0;
	va_start(ap, format);
	tab = ft_formattotab(format);
	if (ft_dispatcher(**tab, ap) < 0)
	{
		ft_putstr("error\n");
		return (0);
	}
}


void foo(char *fmt, ...)
{
	va_list ap; //ap2;
	int d;
	char c, *s;

	va_start(ap, fmt);
	//va_copy(ap2, ap);
	while (*fmt)
		switch(*fmt++) {
			case 's':
				s = va_arg(ap, char *);
				printf("string : %s\n", s);
				break;
			case 'd':
				d = va_arg(ap, int);
				ft_putnbr(d);
				ft_putchar('\n');
				printf("int : %d\n", d);
				break;
			case 'c':
				// Note: char is promoted to int.
				c = va_arg(ap, int);
				printf("char : %c\n", c);
				break;
		}
	va_end(ap);
	//...
	// use ap2 to iterate over the arguments again
	//...
	//va_end(ap2);
}

int		main(void)
{		
	foo("sdcdd", "ohlolol", 2, 'A', 9, "a");
	return (0);
}*/
