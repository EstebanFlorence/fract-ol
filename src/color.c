/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:51:20 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/19 11:59:25 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* 
Rainbow
Ocean
Fire
Pastel
Boh
Galaxy
 */

void	color_set(t_fractol *fractol)
{
	fractol->color_set[0] = malloc(sizeof(int) * 7);
	if (!fractol->color_set[0])
		ft_error(4);
	fractol->color_set[0][0] = 0x9400D3;
	fractol->color_set[0][1] = 0x4B0082;
	fractol->color_set[0][2] = 0x0000FF;
	fractol->color_set[0][3] = 0x00FF00;
	fractol->color_set[0][4] = 0xFFFF00;
	fractol->color_set[0][5] = 0xFF7F00;
	fractol->color_set[0][6] = 0xFF0000;
	fractol->color_set[1] = malloc(sizeof(int) * 7);
	if (!fractol->color_set[1])
		ft_error(4);
	fractol->color_set[1][0] = 0x1B4F72;
	fractol->color_set[1][1] = 0x2E86C1;
	fractol->color_set[1][2] = 0x3498DB;
	fractol->color_set[1][3] = 0x85C1E9;
	fractol->color_set[1][4] = 0xD6EAF8;
	fractol->color_set[1][5] = 0xF1C40F;
	fractol->color_set[1][6] = 0xFFA07A;
	color_set2(fractol);
}

void	color_set2(t_fractol *fractol)
{
	fractol->color_set[2] = malloc(sizeof(int) * 6);
	if (!fractol->color_set[2])
		ft_error(4);
	fractol->color_set[2][0] = 0xFFFFFF;
	fractol->color_set[2][1] = 0xFFC300;
	fractol->color_set[2][2] = 0xFF5733;
	fractol->color_set[2][3] = 0xC70039;
	fractol->color_set[2][4] = 0x900C3F;
	fractol->color_set[2][5] = 0x581845;
	fractol->color_set[3] = malloc(sizeof(int) * 7);
	if (!fractol->color_set[3])
		ft_error(4);
	fractol->color_set[3][0] = 0xF7DC6F;
	fractol->color_set[3][1] = 0xF8C471;
	fractol->color_set[3][2] = 0xF5B041;
	fractol->color_set[3][3] = 0xEB984E;
	fractol->color_set[3][4] = 0xE74C3C;
	fractol->color_set[3][5] = 0xC0392B;
	fractol->color_set[3][6] = 0x6C3483;
	color_set3(fractol);
}

void	color_set3(t_fractol *fractol)
{
	fractol->color_set[4] = malloc(sizeof(int) * 5);
	if (!fractol->color_set[4])
		ft_error(4);
	fractol->color_set[4][0] = 0xFF4081;
	fractol->color_set[4][1] = 0x009688;
	fractol->color_set[4][2] = 0x9C27B0;
	fractol->color_set[4][3] = 0x3F51B5;
	fractol->color_set[4][4] = 0xFFEB3B;
	fractol->color_set[5] = malloc(sizeof(int) * 6);
	if (!fractol->color_set[5])
		ft_error(4);
	fractol->color_set[5][0] = 0x000080;
	fractol->color_set[5][1] = 0x191970;
	fractol->color_set[5][2] = 0x483D8B;
	fractol->color_set[5][3] = 0x800080;
	fractol->color_set[5][4] = 0x8A2BE2;
	fractol->color_set[5][5] = 0xBA55D3;
}

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
	while (i < COLOR_SETS)
		free(fractol->color_set[i++]);
}
