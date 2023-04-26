/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:41:31 by esteban           #+#    #+#             */
/*   Updated: 2023/04/26 22:35:19 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include "minilibx-linux/mlx.h"

# define WIN_WIDTH 	500
# define WIN_HEIGHT 500

typedef struct s_fractol
{
	char	*fractal;
    void	*mlx;
	void	*win;
    double	x;
    double	y;
    double	x_min;
    double	x_max;
    double	y_min;
    double	y_max;
	double	zoom;
	
	t_image	*img;
}	t_fractol;

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		bitsxpixel;
	int		size_line;
	int		endian;

}	t_image;

void	ft_fractol(int ac, char **av, t_fractol *fractol);
void	ft_check(int ac, char **av, t_fractol *fractol);
void	ft_mlx(t_fractol *fractol);
void	ft_innit(t_fractol *fractol);
void	ft_error(int n);


#endif