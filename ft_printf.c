/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 10:07:11 by eviana            #+#    #+#             */
/*   Updated: 2019/02/13 21:15:45 by eviana           ###   ########.fr       */
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
		if ((j = ft_charcount(s, i , 2)))
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

size_t		ft_findwidth(char *tab, size_t *i)
{
	size_t	n;

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
	else
		return (-1); // Pour condition de non prise en charge dans la construction de la conversion
	return (n);
}

int		ft_findlength(char *tab, size_t *i)
{
	if (tab[*i] && tab[*i] == 'l')
		return ((tab[*i + 1] && tab[*i + 1] == 'l' ? 2 : 1));
	else if (tab[*i] && tab[*i] == 'h')
		return ((tab[*i + 1] && tab[*i + 1] == 'h' ? 4 : 3));
	return (0);
}

int		ft_findtype(char *tab, size_t i) // Pour identifier la conversion
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
*/
	// j'ai un nb positif, je demande le +, je n'ai pas de flag -, 
	// j'ai un 0 : je mettrai le + dans additional qu'importe la width
	// && (!(ft_strchr(asset.flags, '0') && asset.width > ft_strlen(initial))))

/*
char	*ft_applyflags(char *str, t_asset asset, int signmode)
{
	size_t	length;
	char	*str2;

	length = (asset.width > ft_strlen(str) ? asset.width - ft_strlen(str) : 0);
	if (length > 0 && signmode && !(ft_strchr(asset.flags, ' ') || ft_strchr(asset.flags, '-')) && !(ft_strchr(asset.flags, '0')) && !ft_strchr(asset.flags, '+'))
		length--;
	else if (length == 0 && signmode == 1 && (!!(ft_strchr(asset.flags, '+')) != 
				!!(ft_strchr(asset.flags, ' '))) && !ft_strchr(asset.flags, '-'))
		length++;
	if (!(str2 = ft_strnew(length)))
		return (NULL);
	if (ft_strchr(asset.flags, '0') && !ft_strchr(asset.flags, '-') && length)
	{
		str2 = ft_memset(str2, '0', length);
		if (ft_strchr(asset.flags, '+') || signmode == -1)
		{
			str2[0] = (signmode == -1 ? '-' : '+');
			str[0] = (signmode == -1 && length > 0 ? '0' : str[0]);
		}
		else if (ft_strchr(asset.flags, ' '))
			str2[0] = ' ';
	}
	else
		str2 = ft_memset(str2, ' ', length);
	return (str2);
}

char	*ft_buildresult(char *str, t_asset asset, int signmode)
{
	char	*str2;
	char	*str3;
	
	if (signmode)
   		signmode = (str[0] == '-' ? -1 : 1);
	if (ft_strchr(asset.flags, '+') && signmode == 1 && 
			(!(ft_strchr(asset.flags, '0') && asset.width > ft_strlen(str)) || ft_strchr(asset.flags, '-')))
		str = sp_strnjoin("+", str, ft_strlen(str), 1);
	else if (ft_strchr(asset.flags, ' ') && ft_strchr(asset.flags, '-') && signmode == 1)
		str = sp_strnjoin(" ", str, ft_strlen(str), 1);
	if (!(str2 = ft_applyflags(str, asset, signmode)))
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
		if (!(str3 = ft_strjoin(str2, str)))
		{
			free(str2);
			free(str);
			return (NULL);
		}
	free(str2);
	free(str);
	return (str3);
}*/

char	*ft_conv_d(t_asset asset, va_list ap) // ap pas en pointeur
{
	char		*str;
//	long		l;
//	long long	ll;
//	short		h;
//	signed char hh;


	if (asset.length == 1)
	{
		if (!(str = ft_itoa(va_arg(ap, long))))
			return (NULL);
	}
	else if (asset.length == 2)
	{
		if (!(str = ft_itoa(va_arg(ap, long long))))
			return (NULL);
	}
//	else if (asset.length == 3)
//	{
//		if(!(str = ft_itoa(va_arg(ap, short))))
//			return (NULL);
//	}
//	else if (asset.length == 4)
//		str = 
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
	char	*print;

	va_start(ap, format);
	//ft_testprint(ap);
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

#include <string.h> // A SUPPR
#include <time.h> // A SUPPR

char *randstring(int length, char *string) {
	static int mySeed = 25011984;
	size_t stringLen = strlen(string);        
	char *randomString = NULL;

	srand(time(NULL) * length + ++mySeed);

	if (length < 1) {
		length = 1;
	}

	randomString = malloc(sizeof(char) * (length +1));

	if (randomString) {
		short key = 0;

		for (int n = 0; n < length; n++) {
			key = rand() % stringLen;
			randomString[n] = string[key];
		}

		randomString[length] = '\0';

		return randomString;
	}
	else {
		printf("No memory");
		exit(1);
	}
}

int		main(int ac, char **av)
{
//	char **tab;
	//int i;
	char *str1;
	char *str2;
	char *str3;
	char *str4;
	char str5[1] = "d";
	char *str6;

	if (ac == 1)
	{
		str1 = randstring(4, "- +0");
		str1[0] = '%';
		str2 = randstring(2, "0123456789");
		str3 = randstring(3, "0123456789");
		str3[0] = '.';
		str4 = randstring((rand() % 5), "0123456789");
		if (!(rand() % 3))
			str4[0] = '-';
		str6 = ft_strjoin(str1, ft_strjoin(str2, ft_strjoin(str3, str5)));
		str6[10] = '\0';

		ft_putstr("RESULTS FOR : ");
		ft_putstr(str6);
		ft_putstr(" && ");
		ft_putstr(str4);
		ft_putstr("\n");
		ft_printf(str6, ft_atoi(str4));
		ft_putstr("|\n");
		ft_putstr("R2 |");
		printf(str6, ft_atoi(str4));
	}
	else if (ac == 3)
	{
		ft_putstr("MANUAL MODE :\n");
		ft_printf(av[1], 3000000000);
		ft_putstr("|\nR2 |");
		printf(av[1], 3000000000);
	}
	else
		ft_putstr("wrong number of inputs");
	(void)ac;
	(void)av;
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
