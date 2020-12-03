/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 04:25:32 by eelaazmi          #+#    #+#             */
/*   Updated: 2020/11/24 19:38:37 by eelaazmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <stdio.h>
# include "gnl/get_next_line.h"
# include "./libft/libft.h"
# include <math.h>
# include <stdlib.h>

# define KEY_UP				13
# define KEY_DOWN			1
# define KEY_LEFT			2
# define KEY_RIGHT			0
# define KEY_CAMERA_UP		126
# define KEY_CAMERA_DOWN	125
# define KEY_CAMERA_LEFT	124
# define KEY_CAMERA_RIGHT	123
# define KEY_ESC			53
# define PRESS				2
# define REL				3
# define RECROSS			17
# define FALSE				0
# define TRUE				1
# define PI					3.14159265
# define TWO_PI				6.28318530
# define FOV_ANGLE			(66 * (M_PI / 180))
# define TEXTURE_WIDTH		64
# define TEXTURE_HEIGHT		64
# define MAX_WIDTH			2548
# define MAX_HIGHT			1352
# define MIN_WIDTH			600
# define MIN_HIGHT			600
# define MINIMAP_SCALE		0.2
# define TILE_SIZE			64

struct						s_player
{
	double					x;
	double					y;
	double					width;
	double					height;
	double					rotationangle;
	double					walkspeed;
	double					turnspeed;
	int						turndirection;
	int						walkdirection;
	int						moveright;
	int						moveleft;
}							s_player;

struct						s_ray
{
	float					rayangle;
	float					wallhitx;
	float					wallhity;
	float					distance;
	int						washitvertical;
	int						israyfacingup;
	int						israyfacingdown;
	int						israyfacingleft;
	int						israyfacingright;
	int						wallhitcontent;
}							s_rays[MAX_WIDTH];

struct						s_tmp
{
	int						window_width;
	int						window_height;
	int						israyfacingdown;
	int						israyfacinup;
	int						israyfacinright;
	int						israyfacinleft;
	int						foundhorzwallhit;
	int						horzwallcontent;
	int						foundvertwallhit;
	int						vertwallcontent;
	float					xintercept;
	float					yintercept;
	float					xstep;
	float					ystep;
	float					horzwallhitx;
	float					horzwallhity;
	float					nexthorztouchx;
	float					nexthorztouchy;
	float					xtocheck;
	float					ytocheck;
	float					vertwallhitx;
	float					vertwallhity;
	float					nextverttouchx;
	float					nextverttouchy;
	float					horzhitdistance;
	float					verthitdistance;
}							s_tmp;

typedef struct				s_bmp
{
	unsigned int			width;
	unsigned int			height;
	unsigned short			bitcount;
	unsigned int			width_in_bytes;
	unsigned int			img_sz;
	unsigned int			bisize;
	unsigned int			bf0ffbits;
	unsigned int			filesize;
	unsigned short			biplanes;
	unsigned char			*header;
}							t_bmp;

struct						s_rendering
{
	float					perpdistance;
	float					distanceprojplane;
	float					projectedwallheight;
	int						wallstripheight;
	int						walltoppixel;
	int						wallbottompixel;
	int						c;
	int						y;
	int						textureoffsetx;
	int						distancefromtop;
	int						textureoffsety;
	int						texelcolor;
}							render;

typedef struct				s_vector
{
	float					x;
	float					y;
}							t_vector;

typedef struct				s_sprite
{
	float					x;
	float					y;
	float					dist;
}							t_sprite;

typedef struct				s_bousole
{
	int						x;
	int						y;
}							t_bousole;

typedef struct				s_image
{
	t_vector				size;
	void					*img;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	int						width;
	int						height;
	int						*data;
	int						ignored_color;
	char					*path;
	float					stepy;
	float					stepx;
	float					x;
	float					y;
	float					endx;
	float					endy;
	float					z;
	float					f;
	float					endz;
	float					endf;
}							t_image;

typedef struct				s_window
{
	void					*mlx_ptr;
	void					*win_ptr;
	void					*texture_ptr;
	int						*texture_data[5];
	int						size_line;
	int						endian;
	int						bpp;
	int						**map;
	int						*img_data;
	int						no;
	int						so;
	int						we;
	int						ea;
	int						x_width;
	int						y_hight;
	int						width;
	int						hight;
	char					*no_texture;
	char					*so_texture;
	char					*we_texture;
	char					*ea_texture;
	char					*s_texture;
}							t_window;

typedef char*				t_string;

typedef	struct				s_texture
{
	int						*data;
	int						width;
	int						height;
}							t_texture;

t_image						g_img;
t_image						g_textures[20];
t_bousole					g_bousole;
t_sprite					g_sprites[50];
char						g_t[100000][100000];
char						*g_no_chemin;
char						*g_so_chemin;
char						*g_we_chemin;
char						*g_ea_chemin;
char						*g_s_chemin;
int							g_sol_couleur;
int							g_plafond_couleur;
int							g_number_of_sprites;
int							g_tile_size;
int							g_num_rays;
int							g_resolution_y;
int							g_resolution_x;
int							g_map[100000][100000];
void						*g_mlx_ptr;
void						*g_win_ptr;
int							g_high;
int							g_wight;
char						g_deriction;
float						*g_ray;
int							*g_p;
int							*g_ttextures[5];
int							g_j;
int							g_maps_x;
int							g_maps_y;
static int							g_player_number;

void						save(t_image win);
void						ft_error(char *str);
t_image						load_image(int i, t_string path);
void						load_texture(t_string line, int index);
void						config_init(void);
int							rgb_to_int(int r, int g, int b);
int							read_map(char **argv);
void						put_pixel(t_vector a, int color);
void						put_pixel_texture(t_vector a, int color, int j);
t_vector					new_vector(float x, float y);
void						draw_square(int row, int col, int grid_size,\
							int color);
void						draw_mini_map(void);
void						draw_circle(int a, int b, int d, int couleur);
void						draw_cub(int i, int y, int couleur);
float						normalizeangle(float angle);
int							haswallat(int x, int y);
int							hassprite(int x, int y);
void						draw_line(int a, int b, float angle, int d);
int							ray_cast(float rayangle, int stripid);
void						castallrays();
void						draw_the_player();
void						key_pressed(int key);
int							keyrelease(int key);
void						action_player();
int							ft_exit();
void						renderrays();
void						clearcolorbuffer(int color);
int							texture_num(int i);
void						generate3dprojection();
int							loop_game(int key);
void						load_textures_setup();
int							setup_the_game();
float						ft_distancebetweenpoints(float x1, float y1,\
							float x2, float y2);
void						ft_handle_bmp();
void						ft_set_header(void);
void						ft_set_infoheader(void);
void						ft_right_shift(void);
void						ft_to_bmp(void);
int							ft_hasspace(int m_index);
int							ft_check_for_error(char *s, int m_index);
int							ft_check_valid(char *s, int m_index);
int							ft_check_final(char *s, int m_index);
int							ft_check_maze(void);
void						check_map();
void						check_save(char *str);
void						draw_textures();
int							deal_key(int key);
void						init_direction_player();
void						init_player();
int							is_valid(char c);
int							check_for_invalid_char(char *s);
int							get_wall_strip_height(int y, int i);
void						hor_cast(float rayangle);
void						ver_cast(float rayangle);
void						cast_init(void);
void						hor_cast_init(float rayangle);
void						ver_cast_init(float rayangle);
void						render_render(int i, int y, int txt);
void						init_generat(int i);
void						plafond_g(int y, int i);
void						txt_choose(int i);
char						*ft_trim_check(char *s);
void						draw_ssprite(int i, int j, int block_size);
void						draw_splayer(int i, int j);
void						assigne(char c, int i, int j);
void						read_resolution(int fd, char *line);
void						free_double_p(char **d);
void						skip_the_line(int fd, int index, char *line);
void						read_no_path(int fd, char *line);
void						read_so_path(int fd, char *line);
void						read_we_path(int fd, char *line);
void						read_ea_path(int fd, char *line);
void						read_s_path(int fd, char *line);
void						read_f_couleur(int fd, char *line);
void						read_c_couleur(int fd, char *line);
char						**not_numerique(char **d, int j);
void						get_r(char **d);
void						invalid_resolution(int i, int j, char **d);
void						cheak_line(char *line);
void						not_found(int i);
void						read_c_couleur_seconde(char **d);
void						invalid_c(char **d, int j);
void						read_all(int fd);
int							handle(char c, int ip, int wight_t,\
							int g_player_number);
int							read_boucle(int ret, int uy, int fd);
int							handle_player(char c, int g_player_number);
void						check_argument_errors(int argc, char **argv);
void						check_check_argument_errors(int i, char **argv);
void						is_there_no_wallt(char *trim, int ii);
void						ft_free_map(int n, char *error_msg);
void						is_there_no_wall_two(char *trim, int ii);
void						is_there_no_wall_three(char *trim, int i, int ii);
long long					get_img_pix(void *img, int x, int y);
void						bmp_file(void);
void						bmp_next(t_bmp *bmp);
void						bmp_last(t_bmp *bmp, unsigned char *buf);

#endif
