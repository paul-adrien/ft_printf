/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/11 14:43:21 by eviana           ###   ########.fr       */
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
#include "ft_printf.h"

int		ft_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' 
			|| c == 'o' || c == 'u' || c == 'x' || c == 'X' || c == 'f')
		return (1);
	return (0);
}

unsigned int	ft_strcountparts(const char *s) // ATTENTION AU DOUBLE %% / A TRAITER COMME %c ???
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

char	**ft_formattotab(const char * restrict s) // ATTENTION A TRAITER LE % comme un %c avec un % en param
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

char	*ft_findflags(char *tab, size_t *i)
{
	char	*str;

	*i = *i + 1;
	while (tab[*i] && (tab[*i] == '-' || tab[*i] == '+' || tab[*i] == ' ' || tab[*i] == '0' || tab[*i] == '#'))
		*i = *i + 1;
	if (!(str = ft_strsub(tab, 1, *i - 1)))
			return (NULL);
	return (str);
}

int		ft_findwidth(char *tab, size_t *i)
{
	//char	*str;
	//int	j;
	int		n;

	//j = *i;
	n = 0;
	while (tab[*i] && (tab[*i] >= '0' && tab[*i] <= '9'))
	{
		n = 10 * n + (tab[*i] - '0'); 
		*i = *i + 1;
	}
	//if (!(str = ft_strsub(tab, j, *i - j)))
	//	return (NULL);
	return (n);
}

int		ft_findprecision(char *tab, size_t *i)
{
	//char	*str;
	//size_t	j;
	int		n;

	//j = *i;
	n = 0;
	if (tab[*i] && (tab[*i] == '.'))
	{
		*i = *i + 1;
		while (tab[*i] && tab[*i] >= '0' && tab[*i] <= '9')
		{
			n = 10 * n + (tab[*i] - '0'); 
			*i = *i + 1;
		}
	}
	//if (!(str = ft_strsub(tab, j, *i - j)))
	//	return (NULL);
	return (n);
}

int		ft_conv_num(char *tab, size_t *i) // Pour identifier la conversion
{
	int n;
	
	n = 0;
	if (!tab)
		return (-1);
	if (tab[0] == '%') // && (tab[1] && tab[1] != '%')) si on ne prend pas en compte le %% en %c
	{
		if (*i == 0)
		{
			while (tab[*i])
				*i = *i + 1;
			*i = *i - 1;
		}
		(tab[*i] == 'd' ? n = 1 : 0);
		(tab[*i] == 'i' ? n = 2 : 0);
		(tab[*i] == 'o' || tab[*i] == 'u' || tab[*i] == 'x' || tab[*i] == 'X' ? n = 3 : 0);
		(tab[*i] == 'c' || tab[*i] == '%' ? n = 4 : 0); // a verifier pour le %%
		(tab[*i] == 's' ? n = 5 : 0);
		(tab[*i] == 'p' ? n = 6 : 0);
		(tab[*i] == 'f' ? n = 7 : 0);
		return (n);
	}
	return (0);
}
/*
char 	*ft_findcomplexity(t_asset asset) // A MODIFIER POUR LA STRUCTURE
{
	size_t	i;
	size_t	j;
	char 	*str;

	i = 1;
	j = 0;
	while (i <= 4)
	{
		if (asset[i][0])
			j++;
		i++;
	}
	if (!(str = ft_strnew(1)))
		return (NULL);
	str[0] = j + '0';
	return (str);
}*/

/*
int		ft_convd(char **asset, va_list *ap) // EN CONSTRUCTION // ap en pointeur ???
{
	int		i;
	int		d;
	char	*str;

	i = 0;
	d = va_arg(ap, int);

	return (0);
}*/

t_asset		ft_digest(char *tab) // Pour determiner les elements presents dans une conversion (exclure les no_conv)
{
	t_asset	asset; // flags, width, precision, (length : pas pris en compte), type + assets[0] = numbers of non nul assets
	size_t	i;

	i = 0;
	if (!(asset.flags = ft_findflags(tab, &i)))
	{
		asset.complexity = 0;
		return (asset);
	}	// QUE SE PASSE-T-IL SI I = 0 / si on a pas de flag ?! // je crois que ca passe avec un strnew de taille 1.
	asset.width = ft_findwidth(tab, &i);
	asset.precision = ft_findprecision(tab, &i);
	//asset.length = ft_findlength(tab, &i);
	asset.type = ft_conv_num(tab, &i); // IF PAS BON CHAR A LA FIN => wrong format
	//asset.complexity = ft_findcomplexity(asset);
	return (asset);
}

void	ft_printasset(t_asset asset)
{
	ft_putstr(asset.flags);
	ft_putchar('\n');
	ft_putnbr(asset.width);
	ft_putchar('\n');
	ft_putnbr(asset.precision);
	ft_putchar('\n');
	ft_putnbr(asset.type);
	ft_putchar('\n');
}

int		ft_dispatcher(char **tab) //, va_list ap) // Pour dispatcher par les conversions possibles
{
//	int		(*list_ft[8])(t_asset)(va_list);
	t_asset	asset;
	int 	n;
	int		i;
	size_t	j;

//	list_ft[0] = &ft_no_conv;
//	list_ft[1] = &ft_convd;
//	list_ft[2] = &ft_convi;
//	list_ft[3] = &ft_convouxX;
//	list_ft[4] = &ft_convc;
//	list_ft[5] = &convs;
//	list_ft[6] = &convp;
//	list_ft[7] = &convf;
	i = 0;
	while (tab[i])
	{
		j = 0;
		n = ft_conv_num(tab[i], &j); // SI CONV = 0 faire une condition speciale
		printf("j'ai mon n : %d \n", n); // TEST TEST TEST
		if (n != 0)
		{
			asset = ft_digest(tab[i]);
			if (asset.complexity == 0)
				return (-1);
			//if (!(list_fd[n](asset, &ap))) // ATTENTION A INCREMENTER AP AU BON MOMENT / Increment dans la FT
			//	return (-1);
			ft_printasset(asset);
			free(asset.flags);
		}
		else
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
		}
		// if (!(ft_atoi(asset[4]) == 0))
		// FREE ASSET SUR 2 DIMENSIONS
		i++; // A VERIFIER
	}
	return (1);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	//int		n;

	//n = 0;
	va_start(ap, format);
	tab = ft_formattotab(format);
	if (ft_dispatcher(tab) < 0) // remettre ap ou &ap en 2eme argument
	{
		ft_putstr("error\n");
		return (-1);
	}
	return (0);
}

int		main(int ac, char **av)
{
//	char **tab;
//	int i;

//	i = 0;
	ft_printf(av[1]); //, av[2], av[3], av[4]);
//	tab = ft_formattotab(av[1]);
//	while (tab[i])
//	{
//		ft_putstr(tab[i]);
//		ft_putchar('\n');
//		i++;
//	}
	(void)ac;
//	(void)av;
	return (0);
}

/*
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
