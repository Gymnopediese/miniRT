/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilibx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albaud <albaud@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 17:30:13 by albaud            #+#    #+#             */
/*   Updated: 2022/11/23 14:48:45 by albaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIBX_H
# define MINILIBX_H

# include "../sources.h"

void		ft_mlx_init(t_window *w, int x, int y, char *name);

void		ft_draw_line(t_canvas *cvs, t_vector a, t_vector b, int color);
void		ft_draw_square(t_canvas *cvs, t_vector pos, int size, int color);
void		ft_draw_fsquare(t_canvas *cvs, t_vector pos, int size, int color);
void		ft_put_pixel(t_canvas *cvs, int x, int y, int color);
char		*ft_get_pixel(t_canvas *cvs, int x, int y);
void		ft_clone_pixel(t_canvas *cvs, int x, int y, char *pixel);
t_canvas	ft_rotate_h(void *mlx, t_canvas cvs, int angle);
t_canvas	ft_rotate_right(void *mlx, t_canvas cvs, int angle);
t_canvas	ft_init_filled_canvas(void *mlx, int x, int y, int color);
void		ft_draw_canvas(t_canvas *dest, t_canvas *src, int x, int y);
void		ft_copy_shrinked_col(t_canvas dest, t_canvas src, t_vector inds,
				t_vector std);
void		ft_init_player(t_player *plr, t_vector size, t_vector pos,
				t_vector data);
long int	ft_get_pixel_color(void *mlx, t_canvas *cvs, int x, int y);
long int	ft_has_pixel(t_canvas *cvs, int x, int y);
t_canvas	ft_init_canvas(void *mlx, int x, int y);
t_canvas	ft_init_image(void *mlx, char *filename);
int			ft_touches(t_canvas *tchr, t_canvas *target, int x, int y);
int			ft_rgb(int r, int g, int b);
t_vector	ft_put_line_to(t_window *w, t_canvas map, t_vector a, double angle);
t_canvas	ft_resize_cvs(void *mlx, t_canvas cvs, double mult);
void		ft_resize_ligne(t_canvas dest, t_canvas src, t_vector inds,
				t_vector std);
t_vector	ft_get_ray(t_matrix map, t_vector a, double angle, int res);
void		ft_put_wall(t_matrix map, t_vector pos, int num, int size);
int			ft_touches_wall(t_matrix map, t_vector pos, int size);
void		ft_putimg(t_window w, void *img, t_vector pos);
void		ft_clean_canvas(t_canvas cvs);
void		ft_fill_canvas(t_canvas cvs, int color);
void		ft_draw_gline(t_canvas *cvs, t_line l,
				int	*colors, t_vector color);
#endif