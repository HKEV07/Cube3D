/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3D_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hazz <fel-hazz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 00:30:09 by fel-hazz          #+#    #+#             */
/*   Updated: 2023/10/07 19:07:07 by fel-hazz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_BONUS_H
# define CUBE3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <MLX42.h>
# include <fcntl.h>
# include <libc.h>
# define FIELD_OF_VIEW 0.923598775598298873077107230546583813
# define C_S 500
# define M_C_S 50
# define MLX_HEIGHT 1000
# define MLX_WIDTH 1000
# define ROTATION_SPEED 0.07
# define MOVEMENT_SPEED	50
# define PIPI 6.28318530717958647692528676655900576

typedef struct s_point
{
	int				x;
	int				y;
	unsigned int	c;
}	t_point;

typedef struct s_tx
{
	int				x;
	int				y;
	char			type;
	mlx_texture_t	*tx;
	int				visible;
	double			angle;
	double			distance;
	double			r_d;
	double			size;
}	t_tx;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_st
{
	double				x;
	double				dx;
	double				dy;
	double				y;
	double				angle;
	double				rx;
	double				ry;
	mlx_image_t			*img;
	mlx_t				*mlx;
	mlx_texture_t		*tx_no;
	t_list				*tx;
	mlx_texture_t		*a[8];
	mlx_texture_t		*b[8];
	mlx_texture_t		*c[8];
	mlx_texture_t		*tx_so;
	mlx_texture_t		*tx_ea;
	mlx_texture_t		*tx_we;
	mlx_texture_t		*tx_sp;
	mlx_texture_t		*tx_dr;
	mlx_texture_t		*tx_dr1;
	mlx_texture_t		*tx_dr2;
	unsigned int		**map_img;
	int					fl_clr;
	int					cl_clr;
	int					height;
	int					width;
	int					m_height;
	int					m_width;
	int					door;
	char				**map;
	int					ds[MLX_WIDTH];
}	t_st;

void			protect_sprites(t_st *v);
void			draw_map(t_st *v);
void			dr1(t_st *v, int i, int j);
void			dr2(t_st *v, int i, int j);
void			dr3(t_st *v, int i, int j);
void			draw_cercle(t_point a, int r, t_st v);
void			horizental_door_collision(t_st *v, double hz[12], int dir[4]);
void			vertical_door_collision(t_st *v, double hz[12], int dir[4]);
void			draw_door(t_st *v, double hz[4], int dir[4]);
void			calculate(t_st *v, double angle, double screenwall[4], int i);
void			ft_set3(t_st *v, int x[7], double hz[12], int dir[4]);
void			draw_cube(t_point p, t_st *v, int size);
int				door_decision_maker(t_st *v, double hz[6], int dir[4]);
int				chd(char c);
void			ft_init2(t_st *v);
void			draw_rectangle(t_point p, t_st *v, int size);
int				ft_check(t_st *v, double x, double y);
int				ft_check3(t_st *v, double x, double y, char c);
int				ft_check1(t_st *v, double x, double y);
void			advanced_collision1(t_st *v, double p[3]);
double			hs(double x, double y, t_st *v);
void			load_animated_sprites(t_st *v);
void			draw_sprite(t_st *v, t_tx *tx);
void			draw_sprite2(t_st *v, t_tx *tx, double f[4], 
					unsigned int color);
void			visible_sprite(t_st *v, t_list *walker, t_tx *tx, double f[4]);
double			normalize(double angle);
void			draw_rectangle(t_point p, t_st *v, int size);
void			draw_map2(t_st *v);
void			draw_map(t_st *v);
void			bresenham(t_st v, t_point a, t_point b, mlx_image_t *img);
int				ft_check_name(char *argv);
void			clear_window(t_st *v);
void			advanced_collision(t_st *v, double p[3]);
void			mlx_move_player2(t_st *v, double p[2]);
void			mlx_move_player1(t_st *v, double p[2]);
void			mlx_move_player(void *param);
void			horizental_collision(t_st *v, double hz[8], int dir[4]);
void			vertical_collision(t_st *v, double hz[8], int dir[4]);
void			decision_maker(t_st *v, double hz[6], int dir[4]);
void			floor_ceiling(t_st *v, int i,
					double angle, double screenwall[4]);
void			draw_wall(t_st *v, int i, double s[4], int dir[4]);
int				ch_b(int c);
void			cast_ray1(t_st *v, int i, double angle);
void			cast_ray(t_st *v);
void			draw_map2(t_st *v);
void			mlx_move_player(void *param);
int				ft_player_position(t_st *v, int i, int j);
void			ft_max_row(t_st *v);
void			ft_exit(int condition, t_st *v);
void			ft_init(t_st *v);
void			ft_load_color1(t_st *v, int var[2], char buff[1]);
void			ft_load_color2(t_st *v, int var[2], char buff[1]);
void			ft_load_texture(t_st *v, int var[2], char buff[1]);
void			ft_load_texture1(t_st *v, int var[2], char buff[1]);
void			ft_load_texture2(t_st *v, int var[2], char buff[1]);
void			ft_load_texture3(t_st *v, int var[2], char buff[1]);
void			ft_load_texture4(t_st *v, int var[2], char buff[1]);
void			ft_load_map9(t_st *v, int var[2]);
void			ft_load_map8(t_st *v, int *var);
void			ft_load_map7(t_st *v);
void			ft_load_map6(t_st *v, char *s, int *var);
void			ft_load_map5(t_st *v, char *s, int j);
void			ft_load_map4(t_st *v, char buff[1], char *map, int i[6]);
void			ft_load_map3(t_st *v, char buff[1], char *map, int i[6]);
void			ft_load_map2(t_st *v, int var[2], char buff[1]);
void			ft_load_map1(t_st *v, char *name);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *src, char *dst, size_t dstsize);
int				ft_isalpha(int n);
int				ft_isdigit(int n);
int				ft_isalnum(int n);
int				ft_isascii(int n);
int				ft_isprint(int n);
int				ft_toupper(int n);
int				ft_tolower(int n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *haystack,
					const char *needle, size_t len);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
int				ft_atoi(const char *str, t_list **lst);
char			*ft_strdup(const char *s1);
void			*ft_calloc(size_t count, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			**ft_split(char const *s, char c);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
char			**ft_freeall(char **p);
mlx_texture_t	*ft_set2(t_st *v, int x[7], int dir[4], double s[4]);
#endif