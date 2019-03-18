/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/18 18:54:02 by eviana           ###   ########.fr       */
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
	char	c = 0;
	int		nb;
	double	i = 1.23;

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
		ft_putnbr(ft_printf(av[1], c));
		ft_putstr("|\nR2 |");
		ft_putnbr(printf(av[1], c));
	}
	else if (ac == 4)
	{
		nb = 0;
		ft_printf("null prec : %.0x\n", nb);
		ft_printf("null prec : %.x\n", nb);
		ft_printf("null prec : %12.0x\n", nb);
		ft_printf("null prec : %-5.x\n", nb);
		ft_printf("null prec : %#.0x\n", nb);
		ft_printf("null prec : %#.x\n", nb);
		ft_printf("null prec : %#12.0x\n", nb);
		ft_printf("null prec : %#-5.x\n", nb);
		ft_printf("null prec : %.0X\n", nb);
		ft_printf("null prec : %.X\n", nb);
		ft_printf("null prec : %12.0X\n", nb);
		ft_printf("null prec : %-5.X\n", nb);
		ft_printf("null prec : %#.0X\n", nb);
		ft_printf("null prec : %#.X\n", nb);
		ft_printf("null prec : %#12.0X\n", nb);
		ft_printf("null prec : %#-5.X\n", nb);
		ft_printf("null prec : %.0o\n", nb);
		ft_printf("null prec : %.o\n", nb);
		ft_printf("null prec : %12.0o\n", nb);
		ft_printf("null prec : %-5.o\n", nb);
		ft_printf("null prec : %#.0o\n", nb);
		ft_printf("null prec : %#.o\n", nb);
		ft_printf("null prec : %#12.0o\n", nb);
		ft_printf("null prec : %#-5.o\n", nb);

		nb = 21;
		ft_printf("null prec : %.0x\n", nb);
		ft_printf("null prec : %.x\n", nb);
		ft_printf("null prec : %12.0x\n", nb);
		ft_printf("null prec : %-5.x\n", nb);
		ft_printf("null prec : %.0X\n", nb);
		ft_printf("null prec : %.X\n", nb);
		ft_printf("null prec : %12.0X\n", nb);
		ft_printf("null prec : %-5.X\n", nb);
		ft_printf("null prec : %.0o\n", nb);
		ft_printf("null prec : %.o\n", nb);
		ft_printf("null prec : %12.0o\n", nb);
		ft_printf("null prec : %-5.o\n", nb);

		nb = -543;
		ft_printf("null prec : %.0x\n", nb);
		ft_printf("null prec : %.x\n", nb);
		ft_printf("null prec : %12.0x\n", nb);
		ft_printf("null prec : %-5.x\n", nb);
		ft_printf("null prec : %.0X\n", nb);
		ft_printf("null prec : %.X\n", nb);
		ft_printf("null prec : %12.0X\n", nb);
		ft_printf("null prec : %-5.X\n", nb);
		ft_printf("null prec : %.0o\n", nb);
		ft_printf("null prec : %.o\n", nb);
		ft_printf("null prec : %12.0o\n", nb);
		ft_printf("null prec : %-5.o\n", nb);
	
		nb = 0;
		ft_printf("null prec : %+.0d\n", nb);
		nb = 8;
		ft_printf("null prec : %+.0d\n", nb);
		nb = -1234212;
		ft_printf("null prec : %+.0d\n", nb);

		nb = 0;
		ft_printf("null prec : %.0d\n", nb);
		nb = 8;
		ft_printf("null prec : %.0d\n", nb);
		nb = -1234212;
		ft_printf("null prec : %.0d\n", nb);

		nb = 0;
		ft_printf("null prec : %+.0d\n", nb);
		ft_printf("null prec : %+.d\n", nb);
		ft_printf("null prec : %.0d\n", nb);
		ft_printf("null prec : %012.0d\n", nb);
		ft_printf("null prec : %-.0d\n", nb);
		ft_printf("null prec : %-12.0d\n", nb);

		nb = 0;
		ft_printf("big prec : %+.420d ", nb);
		nb = 8;
		ft_printf("big prec : %+.42d ", nb);
		nb = -1234212;
		ft_printf("big prec : %.12d ", nb);
		nb = -1;
		ft_printf("big prec : %+.23d ", nb);
		nb = 12354;
		ft_printf("big prec : %+.250d ", nb);

		i = 1234.12345;
		ft_printf("%12.15f\n", i);
		i = -1654.586855;
		ft_printf("%12.18f\n", i);
		i = 123121.51421;
		ft_printf("%12.11f\n", i);

		nb = 12312;
		ft_printf("%13.34o", nb);
		ft_printf("%13.34x", nb);
		ft_printf("%13.34X", nb);

		nb = -1;
		ft_printf("%13.52o", nb);
		ft_printf("%13.52x", nb);
		ft_printf("%13.52X", nb);

		nb = 0;
		ft_printf("null prec : %.0u\n", nb);
		nb = 8;
		ft_printf("null prec : %.0u\n", nb);
		nb = -1234212;
		ft_printf("null prec : %.0u\n", nb);
		nb = -1;
		ft_printf("null prec : %.0u\n", nb);
		nb = 12354;
		ft_printf("null prec : %.0u\n", nb);

		i = 0;
		ft_printf("null prec : %+.0f\n", i);
		i = 12.5;
		ft_printf("null prec : %+.0f\n", i);
		i = -25632.2541;
		ft_printf("null prec : %+.0f\n", i);
		i = -1.0123;
		ft_printf("null prec : %+.0f\n", i);
		i = 12354.569874;
		ft_printf("null prec : %+.0f\n", i);

		ft_printf("%.0s\n", "");
		ft_printf("%.0s\n", NULL);
		ft_printf("%.0s\n", "Okalm");
		ft_printf("%.0s\n", "asd34a");

		c = '!';
				ft_printf( "%c ", c);
						ft_printf( "%1c ", c);
								ft_printf( "%7c ", c);
										ft_printf( "%-1c ", c);
												ft_printf( "%-5c ", c);

		c = 'A';
		ft_printf("%c", c);
		ft_printf("%12c", c);
		ft_printf("%-1c", c);
		ft_printf("%1c", c);
		ft_printf("%5c", c);
		ft_printf("%-5c", c);

		ft_printf(" %c\n", 0);
		ft_printf("%c\n", 0);

		ft_printf("%%\n");
		ft_printf("%%%%%d\n", -120);
	}
	else
	{
		i = -1654.586855;
		ft_printf("%12.18f\n", i);
		printf("%12.18f\n", i);
	}
	(void)ac;
	(void)av;
	return (0);
}
