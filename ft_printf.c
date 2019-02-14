/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/14 13:56:30 by eviana           ###   ########.fr       */
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

char    *sp_strnjoin(char const *s1, char const *s2, size_t n, int mode)
{
	char    *str;

	if (!s1 || !s2 || !(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	str = ft_strcpy(str, s1);
	(mode == 0 ? free((void*)s1) : free((void*)s2));
	return (ft_strncat(str, s2, n));
}

char	*ft_set_precision(char *initial, t_asset asset, int signmode)
{
	size_t	l;
	size_t	length;
	char	*additional;

	ft_putstr("P1 |"); // TEST
	ft_putnbr(asset.precision); // TEST
	ft_putstr("|\n"); // TEST
	if (asset.precision > 0)
	{
		l = ft_strlen(initial) - (signmode == -1 ? 1 : 0); // pour les cas ou asset.precision <= strlen a cause du signe (-)
		length = ((size_t)asset.precision > l ? asset.precision - l : 0);
		//if (signmode == -1 && ) par exemple pour (%+ 7.3d / -11)
		//	length++;
		if (!(additional = ft_strnew(length)))
			return (NULL);
		additional = ft_memset(additional, '0', length);
		if (signmode == -1 && length > 0)
		{
			additional[0] = '-';
			initial[0] = '0';
		}
		return (additional);
	}
	return (ft_strnew(0));
}

char	*ft_set_width(char *initial, t_asset asset, int signmode)
{
	size_t	length;
	char	*additional;

	length = (asset.width > ft_strlen(initial) ? asset.width - ft_strlen(initial) : 0);

	if (length == 0 && ft_strchr(asset.flags, ' ') && !ft_strchr(asset.flags, '-') && !ft_strchr(asset.flags, '+') && signmode == 1)
		length++; // Pour rajouter l'espace de debut quand length est nul, le num sans signe, et pas cale a gauche
	if (!(additional = ft_strnew(length)))
		return (NULL);
	if (length && ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-') && asset.precision == -1)
	{
		additional = ft_memset(additional, '0', length);
		if (ft_strchr(asset.flags, '+') || signmode == -1)
		{
			additional[0] = (signmode == -1 ? '-' : '+');
			initial[0] = (signmode && length > 0 ? '0' : initial[0]);
		}
		else if (ft_strchr(asset.flags, ' '))
			additional[0] = ' ';
	}
	else
		additional = ft_memset(additional, ' ', length);
	return (additional);
}

char	*ft_addbuild(char *initial, char *additional, t_asset asset)
{
	char *build;
	
	if (ft_strchr(asset.flags, '-'))
	{
		if (!(build = ft_strjoin(initial, additional)))
		{
			free(additional);
			free(initial);
			return (NULL);
		}
	}
	else 
		if (!(build = ft_strjoin(additional, initial)))
		{
			free(additional);
			free(initial);
			return (NULL);
		}
	return (build);
}

char	*ft_preparewidth(char *processed, t_asset asset, int signmode)
{
	if (signmode == 1)
	{
		if (ft_strchr(asset.flags, '+'))
		{
			if (!(processed = sp_strnjoin("+", processed, ft_strlen(processed), 1)))
				return (NULL);
		}
		else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '-')) // a peut etre sortir du if signmode pour autres types
			if (!(processed = sp_strnjoin(" ", processed, ft_strlen(processed), 1)))
				return (NULL);
	}
	return (processed);
}

char	*ft_build(char *initial, t_asset asset, int signmode)
{
	char	*additional;
	char	*final;
	
	if (signmode)
   		signmode = (initial[0] == '-' ? -1 : 1);
	if (!(additional = ft_set_precision(initial, asset, signmode)))
		return (NULL);
	ft_putstr("A1 |"); // TEST
	ft_putstr(additional); // TEST
	ft_putstr("|\n"); // TEST

	if (!(asset.precision == 0 && ft_atoi(initial) == 0))
	{
		if (!(final = ft_strjoin(additional, initial)))
			return (NULL);
		ft_putstr("F1 |"); // TEST
		ft_putstr(final); // TEST
		ft_putstr("|\n"); // TEST
	}
	else
		if (!(final = ft_strnew(0)))
			return (NULL);
	if (!(final = ft_preparewidth(final, asset, signmode)))
		return (NULL);
	ft_putstr("F2 |"); // TEST
	ft_putstr(final); // TEST
	ft_putstr("|\n"); // TEST
	//ft_putstr("Final apres la precision : "); // TEST TEST TEST
	//ft_putendl(final); // TEST TEST TEST
	free(additional);
	if (!(additional = ft_set_width(final, asset, signmode)))
		return (NULL);
	ft_putstr("A2 |"); // TEST
	ft_putstr(additional); // TEST
	ft_putstr("|\n"); // TEST

	if (!(final = ft_addbuild(final, additional, asset)))
		return (NULL);
	free(additional);
	free(initial);
	return (final);
}

/*	if (signmode == 1)
 *	{
 *		if (ft_strchr(asset.flags, '-'))
		{
			if (ft_strchr(asset.flags, '+'))
				initial = sp_strnjoin("+", initial, ft_strlen(initial), 1);
			else if (ft_strchr(asset.flags, ' '))
				initial = sp_strnjoin(" ", initial, ft_strlen(initial), 1);
		}
		else if (ft_strchr(asset.flags, '+'))
			initial = sp_strnjoin("+", initial, ft_strlen(initial), 1);
	}

	// j'ai un nb positif, je demande le +, je n'ai pas de flag -, 
	// j'ai un 0 : je mettrai le + dans additional qu'importe la width
	// && (!(ft_strchr(asset.flags, '0') && asset.width > ft_strlen(initial))))
*/

char	*ft_conv_d(t_asset asset, va_list ap) // ap pas en pointeur
{
	char		*str;
//	long		l;
//	long long	ll;
//	short		h;
//	signed char hh;

	ft_putstr("L1 |"); // TEST
	ft_putnbr(asset.length); // TEST
	ft_putstr("|\n"); // TEST
	if (asset.length == 1)
	{
		if (!(str = ft_ltoa(va_arg(ap, long)))) // FAIRE NOTRE PROPRE LTOA
			return (NULL);
	}
	else if (asset.length == 2)
	{
		if (!(str = ft_lltoa(va_arg(ap, long long))))
			return (NULL);
	}
	else if (asset.length == 3)
	{
		if (!(str = ft_itoa((short)va_arg(ap, int)))) // PAS LA MM SORTIE QUE PRINTF QUI SORT UN INT NORMAL
			return (NULL);
	}
	else if (asset.length == 4)
	{
		if (!(str = ft_itoa((char)va_arg(ap, int)))) // A VERIFIER // PRINTF DONNE INVALID DIRECTIVE
		   return (NULL);
	}
	else
	{
 		if (!(str = ft_itoa(va_arg(ap, int))))
			return (NULL);
	}
	if (!(str = ft_build(str, asset, 1)))
		return (NULL);
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
	asset.length = ft_findlength(tab, &i);
	asset.type = ft_findtype(tab, i); // IF PAS BON CHAR A LA FIN => wrong format
	return (asset);
}

void	ft_printasset(t_asset asset)
{
	ft_putstr("flags : ");
	ft_putstr(asset.flags);
	ft_putchar('\n');
	ft_putstr("width : ");
	ft_putnbr(asset.width);
	ft_putchar('\n');
	ft_putstr("precision : ");
	ft_putnbr(asset.precision);
	ft_putchar('\n');
	ft_putstr("length : ");
	ft_putnbr(asset.length);
	ft_putchar('\n');
	ft_putstr("type : ");
	ft_putnbr(asset.type);
	ft_putchar('\n');
}

char	*ft_dispatcher(char **tab, va_list ap) // Pour dispatcher par les conversions possibles
{
	char	*(*list_ft[8])(t_asset, va_list);
	char	*print[2];
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
	if (!(print[0] = ft_strnew(0)))
		return (NULL);
	while (tab[i])
	{
		if ((n = ft_findtype(tab[i], 0)) == -1)
			return (NULL);
		if (n > 0)
		{
			asset = ft_digest(tab[i]);
			if (asset.type == -1)
				return (NULL);
			if (!(print[1] = list_ft[n](asset, ap)))
				return (NULL);
			if (!(print[0] = sp_strnjoin(print[0], print[1], ft_strlen(print[0]) + ft_strlen(print[1]), 0)))
				return (NULL);
			//ft_printasset(asset);
			free(asset.flags);
		}
		else
			if (!(print[0] = sp_strnjoin(print[0], tab[i], ft_strlen(print[0]) + ft_strlen(tab[i]), 0)))
				return (NULL);
		// if ((asset.type == 0))
		// FREE ASSET SUR 2 DIMENSIONS
		i++; // A VERIFIER
	}
	return (print[0]);
}

int		ft_printf(const char * restrict format, ...)
{
	va_list	ap;
	char	**tab;
	char	*print;

	va_start(ap, format);
	tab = ft_formattotab(format);
	if (!(print = ft_dispatcher(tab, ap)))
	{
		ft_putstr("error de dispatcher\n");
		return (0); // CHECKER LES VALEURS DE RETOUR DE PRINTF
	}
	ft_putstr("R1 |"); // TEST
	ft_putstr(print);
	va_end(ap);
	return (0); // CHECKER LES VALEURS DE RETOUR DE PRINTF
}
