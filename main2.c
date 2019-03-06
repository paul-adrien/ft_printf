/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/06 16:06:41 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>
#include <limits.h>

char *randstring(int length, char *string)
{
	static int mySeed = 25011984;
	size_t stringLen = ft_strlen(string);
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

int             main(int ac, char **av)
{
	char    *str1;
	char    *str2;
	char    *str3;
	char    *str4;
	char    *str5;
	char    str6[1] = "d";
	char    *str7;
	double	i = 1.42;
	double	j = 1444565444646.6465424242242;
	int		nb;

	nb = 45;
	if (ac == 1)
	{
		str1 = randstring(4, "- +0");
		str1[0] = '%';
		str2 = randstring(2, "0123456789");
		str3 = randstring(2, "0123456789");
		str3[0] = '.';
		str4 = randstring(1, "hl");
		str5 = randstring((rand() % 7), "0123456789");
		if (!(rand() % 3))
			str5[0] = '-';

		str7 = ft_strjoin(str1, ft_strjoin(str2, ft_strjoin(str3, ft_strjoin(str4, str6))));
		str7[10] = '\0';

		ft_putstr("RESULTS FOR : ");
		ft_putstr(str7);
		ft_putstr(" && ");
		ft_putstr(str5);
		ft_putstr("\n");
		ft_putstr("R1 |");
		ft_printf(str7, atol(str5));
		ft_putstr("|\n");
		ft_putstr("R2 |");
		printf(str7, atol(str5));
	}
	else if (ac == 2)
	{
		ft_putstr("MANUAL MODE :\n");
		ft_putstr("R1 |");
		ft_printf("%lo, %lo", 0, ULONG_MAX);
		ft_putstr("|\nR2 |");	
		printf("%lo, %lo", (unsigned long)0, ULONG_MAX);
	}
	else if (ac == 3)
	{
		ft_putstr("MANUAL MODE :\n");
		ft_putstr("R1 |");
		ft_printf(av[1], i, j);
		ft_putstr("|\nR2 |");
		printf(av[1], i, j);
	}
	else if (ac == 4)
	{
		ft_printf("test o:%o\n", nb);
		ft_printf("hash:%#o\n", nb);
		ft_printf("precision / grande:%.5o\n", nb);
		ft_printf("Prec + hash / grande:%#.5o\n", nb);
		ft_printf("Prec + hash / petite:%#.1o\n", nb);
		ft_printf("Prec + 0:%0.5o\n", nb);
		ft_printf("Prec + minus:%-.5o\n", nb);
		ft_printf("Size:%5o\n", nb);
		ft_printf("size + prec:%7.3o\n", nb);
		ft_printf("size + minus:%-5o\n", nb);
		ft_printf("size + zero:%05o\n", nb);
		ft_printf("size + zero + hash:%#05o\n", nb);
		ft_printf("size + zero + prec:%05.3o\n", nb);
		ft_printf("size + minus + prec:%-5.3o\n", nb);
		ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
		ft_printf("size + hash + zero + prec:%0#5.3o\n", nb);
		ft_printf("size + hash + minus + prec:%-#7.3o\n", nb);

		printf("test o:%o\n", nb);
		printf("hash:%#o\n", nb);
		printf("precision / grande:%.5o\n", nb);
		printf("Prec + hash / grande:%#.5o\n", nb);
		printf("Prec + hash / petite:%#.1o\n", nb);
		printf("Prec + 0:%0.5o\n", nb);
		printf("Prec + minus:%-.5o\n", nb);
		printf("Size:%5o\n", nb);
		printf("size + prec:%7.3o\n", nb);
		printf("size + minus:%-5o\n", nb);
		printf("size + zero:%05o\n", nb);
		printf("size + zero + hash:%#05o\n", nb);
		printf("size + zero + prec:%05.3o\n", nb);
		printf("size + minus + prec:%-5.3o\n", nb);
		printf("size + hash + zero + prec:%#05.3o\n", nb);
		printf("size + hash + zero + prec:%0#5.3o\n", nb);
		printf("size + hash + minus + prec:%-#7.3o\n", nb);
	}
	else
	{
		ft_printf("size + hash + zero + prec:%#05.3o\n", nb);
		ft_printf("size + zero + hash:%#05o\n", nb);
		printf("size + hash + zero + prec:%#05.3o\n", nb);
		printf("size + zero + hash:%#05o\n", nb);
	}
	(void)ac;
	(void)av;
	return (0);
}
