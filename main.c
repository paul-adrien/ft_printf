/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/18 17:04:06 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>
#include <limits.h>


int             main(int argc, char **argv)
{
	ft_putnbr(ft_printf("{purple}test0{yellow}test1%s{red}test2{blue}test3{eoc}" , argv[1]));
	ft_putnbr(printf("test0test1%stest2test3" , argv[1]));
	(void)argc;
	return (0);
}
