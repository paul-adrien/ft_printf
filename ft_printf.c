/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/12 11:04:36 by eviana           ###   ########.fr       */
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

char	*ft_findflags(char *tab, size_t *i) // PLUS ERROR SI PLEIN DE FLAGS +-+ -#-...
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
	int		n;

	n = 0;
	while (tab[*i] && (tab[*i] >= '0' && tab[*i] <= '9'))
	{
		n = 10 * n + (tab[*i] - '0'); 
		*i = *i + 1;
	}
	return (n);
}

int		ft_findprecision(char *tab, size_t *i)
{
	int		n;

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
	return (n);
}

int		ft_conv_num(char *tab, size_t i) // Pour identifier la conversion
{
	int n;
	
	n = 0;
	if (!tab)
		return (-1);
	if (tab[0] == '%' && (tab[1] && tab[1] != '%'))
	{
		if (i == 0)
		{
			while (tab[i])
				i++;
			i--;
		}
		(tab[i] == 'd' ? n = 1 : 0);
		(tab[i] == 'i' ? n = 2 : 0);
		(tab[i] == 'o' || tab[i] == 'u' || tab[i] == 'x' ||
		 tab[i] == 'X' ? n = 3 : 0);
		(tab[i] == 'c' || tab[i] == '%' ? n = 4 : 0); // a verifier pour le %%
		(tab[i] == 's' ? n = 5 : 0);
		(tab[i] == 'p' ? n = 6 : 0);
		(tab[i] == 'f' ? n = 7 : 0);
		return (n);
	}
	return (n);
}
/*
char 	*ft_findcomplexity(t_asset asset) // A MODIFIER POUR LA STRUCTURE // OLD ON SUPPRIME
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

char	*ft_applyflags(int strlen, t_asset asset, int signmode)
{
	size_t	length;
	char	*str2;

	length = (asset.width > strlen ? asset.width - strlen : 0);
	if (signmode && length > 0 && ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '-'))
		length--;
	if (!(str2 = ft_strnew(length)))
		return (NULL);
	if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-'))
	{
		str2 = ft_memset(str2, '0', length);
		if (ft_strchr(asset.flags, '+' && signmode))
			str2[0] = (signmode == 1 ? '+' : '-');
	}
	else 
		str2 = ft_memset(str2, ' ', length);
	return (str2);
	//if (ft_strchr(asset.flags, ' ')) // ?
	//if (ft_strchr(asset.flags, '#')) // ???
	//if (ft_strchr(asset.flags, '+'))
	//if (ft_strchr(asset.flags, '-'))
}

char	*ft_setwidth(char *str, t_asset asset, int signmode)
{
	char	*str2;
	char	*str3;
	
	if (signmode)
   		signmode = (str[0] == '-' ? -1 : 1);
	if (!(str2 = ft_applyflags(ft_strlen(str), asset, signmode)))
		return (NULL);
	if (ft_strchr(asset.flags, '-'))
	{
		if (!(str3 = ft_strjoin(str, str2)))
		{
			free(str2);
			free(str);
			return (NULL);
		}
	}
	else
	{
		if (!(str3 = ft_strjoin(str2, str)))
		{
			free(str2);
			free(str);
			return (NULL);
		}
	}
	free(str2);
	free(str);
	return (str3);
}

char	*ft_conv_d(t_asset asset, va_list ap) // ap pas en pointeur
{
	char	*str;

	if (!(str = ft_itoa(va_arg(ap, int))))
		return (NULL);
	if (!(str = ft_setwidth(str, asset, 1)))
		return (NULL);
	ft_putstr(str); // TEST TEST TEST // PRINTING
	return (str);
}

t_asset		ft_digest(char *tab) // (no_conv exclus en amont)
{
	t_asset	asset;
	size_t	i;

	i = 0;
	if (!(asset.flags = ft_findflags(tab, &i)))
	{
		asset.type = -1;
		return (asset);
	}
	asset.width = ft_findwidth(tab, &i);
	asset.precision = ft_findprecision(tab, &i);
	//asset.length = ft_findlength(tab, &i);
	asset.type = ft_conv_num(tab, i); // IF PAS BON CHAR A LA FIN => wrong format
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

int		ft_dispatcher(char **tab, va_list ap) // Pour dispatcher par les conversions possibles
{
	char	*(*list_ft[8])(t_asset, va_list);
	t_asset	asset;
	size_t 	n;
	int		i;

//	list_ft[0] = &ft_no_conv;
	list_ft[1] = &ft_conv_d;
//	list_ft[2] = &ft_conv_i;
//	list_ft[3] = &ft_conv_ouxX;
//	list_ft[4] = &ft_conv_c;
//	list_ft[5] = &ft_conv_s;
//	list_ft[6] = &ft_conv_p;
//	list_ft[7] = &ft_conv_f;
	i = 0;
	while (tab[i])
	{
		if ((n = ft_conv_num(tab[i], 0)) == -1)
			return (0);
		if (n > 0)
		{
			asset = ft_digest(tab[i]);
			if (asset.type == -1)
				return (0);
			if (!(list_ft[n](asset, ap))) // ATTENTION A INCREMENTER AP AU BON MOMENT / Increment dans la FT
				return (0);
			//ft_printasset(asset);
			free(asset.flags);
		}
		else
		{
			ft_putstr(tab[i]);
			ft_putchar('\n');
		}
		// if ((asset.type == 0))
		// FREE ASSET SUR 2 DIMENSIONS
		i++; // A VERIFIER
	}
	return (1);
}

/*
void	ft_testprint(va_list ap)
{
	int d;
	
	d = va_arg(ap, int);
	ft_putnbr(d);
}*/

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	//char	*str;

	va_start(ap, format);
	//ft_testprint(ap);
	//ft_putchar('\n');
	//ft_testprint(ap);
	tab = ft_formattotab(format);
	if (!(ft_dispatcher(tab, ap))) // remettre ap ou &ap en 2eme argument
	{
		ft_putstr("error de dispatcher\n");
		return (0); // CHECKER LES VALEURS DE RETOUR DE PRINTF
	}
	va_end(ap);
	return (0); // CHECKER LES VALEURS DE RETOUR DE PRINTF
}

int		main(int ac, char **av)
{
//	char **tab;
//	int i;

//	i = 0;
	ft_printf(av[1], ft_atoi(av[2]));
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
