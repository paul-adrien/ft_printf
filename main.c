/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/08 12:08:44 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>
#include <limits.h>


int             main()
{

	int		nb;
	char	c;
	nb = 0;
	c = 'W';
	ft_printf("%5p\n", &nb);
	ft_printf("%-15p\n", &nb);
	ft_printf("%-5p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%-18p\n", &nb);
	ft_printf("%42p\n", &nb);
	ft_printf("%5p\n", &c);
	ft_printf("%-15p\n", &c);
	ft_printf("%-5p\n", &c);
	ft_printf("%42p\n", &c);
	ft_printf("%-18p\n", &c);
	ft_printf("%42p\n", &c);


	return (0);
}
