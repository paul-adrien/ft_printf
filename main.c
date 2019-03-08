/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:39:38 by eviana            #+#    #+#             */
/*   Updated: 2019/03/07 19:07:09 by plaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <time.h>
#include <limits.h>


int             main()
{
	double		nb;


	nb = -0.000;
	ft_printf("space:% f\n", nb);
	ft_printf("plus:%+f\n", nb);
	ft_printf("hash:%#f\n", nb);
	ft_printf("precision:%.2f\n", nb);
	ft_printf("big prec:%.14f\n", nb);
	ft_printf("precision + hash:%#.0f\n", nb);
	ft_printf("space + prec:% .5f\n", nb);
	ft_printf("space + prec + hash:%# .0f\n", nb);
	ft_printf("space + prec + hash:% #.0f\n", nb);
	ft_printf("Plus + prec / grande:%+.5f\n", nb);
	ft_printf("Plus + prec / petite:%+.0f\n", nb);
	ft_printf("Plus + prec + hash:%#+.0f\n", nb);
	ft_printf("Prec + 0:%0.5f\n", nb);
	ft_printf("Prec + minus:%-.5f\n", nb);
	ft_printf("size:%5f\n", nb);
	ft_printf("size + space:% 5f\n", nb);
	ft_printf("size + plus:%+5f\n", nb);
	ft_printf("size + space:%# 5f\n", nb);
	ft_printf("size + plus:%#+5f\n", nb);
	ft_printf("size + minus:%-5f\n", nb);
	ft_printf("size + 0:%05f\n", nb);
	ft_printf("size + 0 + plus:%+05f\n", nb);
	ft_printf("size + 0 + plus:%0+5f\n", nb);
	ft_printf("size + 0 + prec:%05.3f\n", nb);
	ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb);
	ft_printf("size + minus + prec:%-5.3f\n", nb);
	ft_printf("size + minus + prec + hash:%-#5.0f\n", nb);
	ft_printf("size + plus + 0 + prec:%+05.3f\n", nb);
	ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	ft_printf("size + espace + zero + prec:%0 5.3f\n", nb);
	ft_printf("size + espace + zero + prec:% 05.3f\n", nb);
	ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	ft_printf("size + minus + plus + prec:%-+5.3f\n", nb);
	ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	printf("test basique:\n");
	printf("space:% f\n", nb);
	printf("plus:%+f\n", nb);
	printf("hash:%#f\n", nb);
	printf("precision:%.2f\n", nb);
	printf("big prec:%.14f\n", nb);
	printf("precision + hash:%#.0f\n", nb);
	printf("space + prec:% .5f\n", nb);
	printf("space + prec + hash:%# .0f\n", nb);
	printf("space + prec + hash:% #.0f\n", nb);
	printf("Plus + prec / grande:%+.5f\n", nb);
	printf("Plus + prec / petite:%+.0f\n", nb);
	printf("Plus + prec + hash:%#+.0f\n", nb);
	printf("Prec + 0:%0.5f\n", nb);
	printf("Prec + minus:%-.5f\n", nb);
	printf("size:%5f\n", nb);
	printf("size + space:% 5f\n", nb);
	printf("size + plus:%+5f\n", nb);
	printf("size + space:%# 5f\n", nb);
	printf("size + plus:%#+5f\n", nb);
	printf("size + minus:%-5f\n", nb);
	printf("size + 0:%05f\n", nb);
	printf("size + 0 + plus:%+05f\n", nb);
	printf("size + 0 + plus:%0+5f\n", nb);
	printf("size + 0 + prec:%05.3f\n", nb);
	printf("size + 0 + prec + hash:%0#5.0f\n", nb);
	printf("size + minus + prec:%-5.3f\n", nb);
	printf("size + minus + prec + hash:%-#5.0f\n", nb);
	printf("size + plus + 0 + prec:%+05.3f\n", nb);
	printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb);
	printf("size + espace + zero + prec:%0 5.3f\n", nb);
	printf("size + espace + zero + prec:% 05.3f\n", nb);
	printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb);
	printf("size + minus + plus + prec:%-+5.3f\n", nb);
	printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb);

	return (0);
}
