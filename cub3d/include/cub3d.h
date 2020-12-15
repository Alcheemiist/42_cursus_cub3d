/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 19:25:36 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/12/13 19:25:39 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../src/libft/libft.h"
# include "../src/get_next_line/get_next_line.h"

# define TILE_SIZE 60
# define RAD (M_PI / 180)
# define STEP 10
# define FOV 60.0

typedef struct		s_position
{
	float			x;
	float			y;
}					t_pos;

typedef struct		s_windata
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				*data;
}					t_windata;

typedef	struct		s_resulotion
{
	int				width;
	int				height;
}					t_res;

typedef struct		s_bmp
{
	unsigned int	width;
	unsigned int	height;
	unsigned short	bitcount;
	unsigned int	width_in_bytes;
	unsigned int	img_sz;
	unsigned int	bisize;
	unsigned int	bf0ffbits;
	unsigned int	filesize;
	unsigned short	biplanes;
	unsigned char	*header;
}					t_bmp;

typedef struct		s_textr
{
	char			*path;
	void			*img;
	int				*addr;
	t_res			xpm;
}					t_textr;

typedef	struct		s_object
{
	t_pos			p;
	float			dest;
	t_textr			*sp_img;
	struct s_object	*next;
}					t_obj;

struct				s_player
{
	char			dir;
	float			ang;
	t_pos			pos;
	int				check;
}					t_player;

struct				s_full
{
	t_textr			no;
	t_textr			so;
	t_textr			we;
	t_textr			ea;
	int				color;
	int				offset;
}					t_full;

struct				s_sprite
{
	char			*file_spr;
	float			*wall_dst;
	t_obj			*lstobj;
}					t_sprite;

struct				s_map
{
	int				check;
	char			**map;
	int				colorf;
	int				colorc;
	t_res			len;
}					t_map;

struct				s_keys
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				esc;
	int				fcleft;
	int				fcright;
}					t_key;

struct				s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_res			resul;
	t_windata		img;
	t_bmp			bmp;
	int32_t			img_width;
	int32_t			img_height;
	uint16_t		img_bitcount;
	int				width_pt;
	uint32_t		imagesize;
	uint32_t		bisize;
	uint32_t		bfoffbits;
	uint32_t		filesize;
	uint16_t		biplanes;
	unsigned char	header[55];
	unsigned char	*buf;
}					t_mlx;

struct				s_ray
{
	float			ang;
	float			xstep;
	float			ystep;
	short			faceleft;
	short			faceup;
	float			x;
	float			y;
	short			horay;
}					t_ray;

void				*g_freetmp;

int					main(int argc, char *argv[]);
int					setup(char *file);
char				**param(char **prm);
int					ft_set_colors(char fp, char **params);
int					texture(char **params);
int					ft_set_resolution(char **params);
int					quit();
int					ft_puterror(char *error);
void				ft_putstr(char *str);
int					checkforin(int c, char *str);
size_t				ft_lenfrom(int c, char *s);
int					ft_lentwop(char **s);
int					validfile(char *file, char *ext);
int					check_rgb(int r, int g, int b);
int					ft_help(char *s);
int					ft_isnumber(char *s);
int					ft_set_map(char *cubfile, int fd, char *line);
int					mapset(char *cubfile, int lenx, int leny);
int					addlinemap(int index, char *line, int lenx, int leny);
int					checkmap(int lenx, int leny);
void				ft_set_player(char dir, float x, float y);
int					retfree(char *tmp1, char *tmp2, int ret);
int					retfreetwo(char **tmp1, int ret);
void				ft_rander();
int					keypressed(int key);
int					keyreleased(int key);
int					update();
int					deal_key(int key, void *param);
float				normalizeang(float ang);
int					checkforwall(t_pos p, int h);
float				get_dest(float angle);
void				pixput(int x, int y, int color);
void				drawmap(void);
void				ft_get_texture(void);
int					shadow(int color, float dest);
void				setdests(void);
void				sortlst(t_obj **objlst);
void				ft_lstaddobj(t_obj **objlst, t_obj *newobj);
t_obj				*ft_lstnewobj(float x, float y, float dest, char *tex);
void				sp_render(int x, int y, int sp_size, t_obj *obj);
short				set_sprtex(t_obj *obj);
void				ft_sprite(t_obj *obj);
void				print_sprite(void);
void				set_sprite(int x, int y);
void				ft_handl_key();
int					check_for_step();
void				bmp_last(t_bmp *bmp, unsigned char *buf);
void				bmp_next(t_bmp *bmp);
void				bmp_file();
long long			get_img_pix(void *img, int x, int y);
void				help_keypress(void);
char				*ft_path(char *str, char c1, char c2, short o);
char				*clear_color(char *str);
void				setwalldst(int dest, int px);

#endif
