/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:51:20 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/16 01:27:16 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_coloriter(int key, t_fractol *fractol)
{
	int	i;

	i = fractol->color_iter;
	if (key == C_KEY)
	{
		if (i < COLOR_SETS - 1)
			i++;
		else
			i = 0;
	}
	if (key == Z_KEY)
	{
		if (i > 0)
			i--;
		else
			i = COLOR_SETS - 1;
	}
	printf("i: %d\n", i);

	fractol->color_iter = i;
}

void	color_set(t_fractol *fractol)
{
    fractol->color_set[0] = malloc(sizeof(int) * 7);
    fractol->color_set[0][0] = 0x9400D3;
    fractol->color_set[0][1] = 0x4B0082;
    fractol->color_set[0][2] = 0x0000FF;
    fractol->color_set[0][3] = 0x00FF00;
    fractol->color_set[0][4] = 0xFFFF00;
    fractol->color_set[0][5] = 0xFF7F00;
    fractol->color_set[0][6] = 0xFF0000;

    fractol->color_set[1] = malloc(sizeof(int) * 7);
    fractol->color_set[1][0] = 0x1B4F72;
    fractol->color_set[1][1] = 0x2E86C1;
    fractol->color_set[1][2] = 0x3498DB;
    fractol->color_set[1][3] = 0x85C1E9;
    fractol->color_set[1][4] = 0xD6EAF8;
    fractol->color_set[1][5] = 0xF1C40F;
    fractol->color_set[1][6] = 0xFFA07A;

	//color_set2(fractol);

    fractol->color_set[2] = malloc(sizeof(int) * 6);
    fractol->color_set[2][0] = 0xFFFFFF;
    fractol->color_set[2][1] = 0xFFC300;
    fractol->color_set[2][2] = 0xFF5733;
    fractol->color_set[2][3] = 0xC70039;
    fractol->color_set[2][4] = 0x900C3F;
    fractol->color_set[2][5] = 0x581845;

    fractol->color_set[3] = malloc(sizeof(int) * 7);
    fractol->color_set[3][0] = 0xF7DC6F;
    fractol->color_set[3][1] = 0xF8C471;
    fractol->color_set[3][2] = 0xF5B041;
    fractol->color_set[3][3] = 0xEB984E;
    fractol->color_set[3][4] = 0xE74C3C;
    fractol->color_set[3][5] = 0xC0392B;
    fractol->color_set[3][6] = 0x6C3483;

}

//void	color_set(t_fractol *fractol)


int	ft_pixelcolor(t_fractol *fractol)
{
	int	i;
	int	j;
	int	color;

	i = fractol->color_iter;
	j = fractol->iter % 7;
	color = fractol->color_set[i][j];
	return (color);
}

void	ft_freecolors(t_fractol *fractol)
{
	int	i;

	i = 0;
	while(i < COLOR_SETS)
		free(fractol->color_set[i++]);
	//free(fractol->color_set);
}
