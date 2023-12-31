/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leobarbo <leobarbo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:14:39 by leobarbo          #+#    #+#             */
/*   Updated: 2023/12/04 15:04:56 by leobarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./bonus/includes_bonus/ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int		num1;
	int		num2;
	int		num3;
	int		ret;

	num1 = 42;
	num2 = 99;
	num3 = 0;

	ret = ft_printf("%+++++++++++++++++++++++++++++d", 42);
	printf("\n\n%d\n\n", ret);
	ret = printf("%++++++++++++++++++++++++++++++++d", 42);
	printf("\n\n%d\n\n", ret);

	ret = ft_printf("%+d", -42);
	printf("\n\n%d\n\n", ret);
	ret = printf("%+d", -42);
	printf("\n\n%d\n\n", ret);

	return (0);
}
