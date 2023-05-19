/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 20:51:20 by adi-nata          #+#    #+#             */
/*   Updated: 2023/05/19 16:18:24 by adi-nata         ###   ########.fr       */
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
	fractol->color_set[0].color = malloc(sizeof(int) * 7);
	if (!fractol->color_set[0].color)
		ft_error(4);
	fractol->color_set[0].color[0] = 0x9400D3;
	fractol->color_set[0].color[1] = 0x4B0082;
	fractol->color_set[0].color[2] = 0x0000FF;
	fractol->color_set[0].color[3] = 0x00FF00;
	fractol->color_set[0].color[4] = 0xFFFF00;
	fractol->color_set[0].color[5] = 0xFF7F00;
	fractol->color_set[0].color[6] = 0xFF0000;
	fractol->color_set[0].size = 7;
	fractol->color_set[1].color = malloc(sizeof(int) * 7);
	if (!fractol->color_set[1].color)
		ft_error(4);
	fractol->color_set[1].color[0] = 0x1B4F72;
	fractol->color_set[1].color[1] = 0x2E86C1;
	fractol->color_set[1].color[2] = 0x3498DB;
	fractol->color_set[1].color[3] = 0x85C1E9;
	fractol->color_set[1].color[4] = 0xD6EAF8;
	fractol->color_set[1].color[5] = 0xF1C40F;
	fractol->color_set[1].color[6] = 0xFFA07A;
	fractol->color_set[1].size = 7;
	color_set2(fractol);
}

void	color_set2(t_fractol *fractol)
{
	fractol->color_set[2].color = malloc(sizeof(int) * 6);
	if (!fractol->color_set[2].color)
		ft_error(4);
	fractol->color_set[2].color[0] = 0xFFFFFF;
	fractol->color_set[2].color[1] = 0xFFC300;
	fractol->color_set[2].color[2] = 0xFF5733;
	fractol->color_set[2].color[3] = 0xC70039;
	fractol->color_set[2].color[4] = 0x900C3F;
	fractol->color_set[2].color[5] = 0x581845;
	fractol->color_set[2].size = 6;
	fractol->color_set[3].color = malloc(sizeof(int) * 7);
	if (!fractol->color_set[3].color)
		ft_error(4);
	fractol->color_set[3].color[0] = 0xF7DC6F;
	fractol->color_set[3].color[1] = 0xF8C471;
	fractol->color_set[3].color[2] = 0xF5B041;
	fractol->color_set[3].color[3] = 0xEB984E;
	fractol->color_set[3].color[4] = 0xE74C3C;
	fractol->color_set[3].color[5] = 0xC0392B;
	fractol->color_set[3].color[6] = 0x6C3483;
	fractol->color_set[3].size = 7;
	color_set3(fractol);
}

void	color_set3(t_fractol *fractol)
{
	fractol->color_set[4].color = malloc(sizeof(int) * 5);
	if (!fractol->color_set[4].color)
		ft_error(4);
	fractol->color_set[4].color[0] = 0xFF4081;
	fractol->color_set[4].color[1] = 0x009688;
	fractol->color_set[4].color[2] = 0x9C27B0;
	fractol->color_set[4].color[3] = 0x3F51B5;
	fractol->color_set[4].color[4] = 0xFFEB3B;
	fractol->color_set[4].size = 5;
	fractol->color_set[5].color = malloc(sizeof(int) * 6);
	if (!fractol->color_set[5].color)
		ft_error(4);
	fractol->color_set[5].color[0] = 0x000080;
	fractol->color_set[5].color[1] = 0x191970;
	fractol->color_set[5].color[2] = 0x483D8B;
	fractol->color_set[5].color[3] = 0x800080;
	fractol->color_set[5].color[4] = 0x8A2BE2;
	fractol->color_set[5].color[5] = 0xBA55D3;
	fractol->color_set[5].size = 6;
}

int	ft_pixelcolor(t_fractol *fractol)
{
	int	i;
	int	j;
	int	size;
	int	color;

	i = fractol->color_iter;
	size = fractol->color_set[i].size;
	j = fractol->iter % size;
	color = fractol->color_set[i].color[j];
	return (color);
}

void	ft_freecolors(t_fractol *fractol)
{
	int	i;

	i = 0;
	while (i < COLOR_SETS)
		free(fractol->color_set[i++].color);
}
