/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviana <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 17:52:25 by eviana            #+#    #+#             */
/*   Updated: 2019/02/28 18:07:15 by eviana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	int i;

	i = ft_printf("%p", &free);
	
	//ft_printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");	
	//ft_putstr("\n--------------------------------\n");
	ft_putnbr(i);	
	//ft_putstr("\n--------------------------------\n");
	//printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c");	
	//ft_putstr("\n--------------------------------\n");
	//ft_putnbr(printf("%s%p%d%d%p%s%p%p%s", "a", &free, 1, 2, &malloc, "b", &free, &malloc, "c"));	
	return (0);
}
