/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/02/14 16:47:43 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>

char *randstring(int length, char *string)
{
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

int             main(int ac, char **av)
{
	char    *str1;
	char    *str2;
	char    *str3;
	char    *str4;
	char    *str5;
	char    str6[1] = "d";
	char    *str7;

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
		ft_printf(str7, atol(str5));
		ft_putstr("|\n");
		ft_putstr("R2 |");
		printf(str7, atol(str5));
	}
	else if (ac == 3)
	{
		ft_putstr("MANUAL MODE :\n");
		ft_printf(av[1], str6);
		ft_putstr("|\nR2 |");
		printf(av[1], str6);
	}
	else
		ft_putstr("wrong number of inputs");
	(void)ac;
	(void)av;
	return (0);
}
