/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 23:41:31 by esteban           #+#    #+#             */
/*   Updated: 2023/05/19 16:18:54 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "key.h"
# include <math.h>
# include <complex.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define MAX_ITER		200
# define WIN_WIDTH		1000
# define WIN_HEIGHT		1000
# define ZOOM_FACTOR	1.3
# define COLOR_SETS		6

typedef struct s_set
{
	int	*color;
	int	size;
}	t_set;

typedef struct s_image
{
	void	*ptr;
	char	*data;
	int		bitsxpixel;
	int		size_line;
	int		endian;

}	t_image;

typedef struct s_fractol
{
	int		fractal;
	void	*mlx;
	void	*win;
	double	x;
	double	y;
	double	x_min;
	double	x_max;
	double	y_min;
	double	y_max;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	zoom;
	double	img_shift;
	int		iter;
	int		max_iter;
	int		color_iter;
	t_set	color_set[COLOR_SETS];
	t_image	*img;
}	t_fractol;

void	ft_fractol(t_fractol *fractol);
void	ft_check(int ac, char **av, t_fractol *fractol);
void	ft_checkjulia(int ac, char **av, t_fractol *fractol);
void	ft_mlxinnit(t_fractol *fractol);
void	ft_innit(t_fractol *fractol);
void	ft_render(t_fractol *fractol);
void	ft_coordinates(t_fractol *fractol);
void	ft_pixelput(t_image *img, int x, int y, int color);
void	ft_error(int n);
int		ft_exit(t_fractol *fractol);
void	ft_destroy(t_fractol *fractol);
void	ft_freecolors(t_fractol *fractol);

//	Fractals
void	ft_mandelbrot(t_fractol *fractol);
void	ft_julia(t_fractol *fractol);
void	ft_yarrr(t_fractol *fracol);
void	ft_newton(t_fractol *fractol);

//	Colors
void	color_set(t_fractol *fractol);
void	color_set2(t_fractol *fractol);
void	color_set3(t_fractol *fractol);
int		ft_pixelcolor(t_fractol *fractol);

//	Hooks
void	ft_mlxhooks(t_fractol *fractol);
int		zoom_hook(int button, int x, int y, t_fractol *fractol);
int		key_hook(int key, t_fractol *fractol);
void	ft_coloriter(int key, t_fractol *fractol);

#endif