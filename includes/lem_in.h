/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:35:05 by afrangio          #+#    #+#             */
/*   Updated: 2018/10/25 18:59:11 by alanter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

# define E_WRONG_ANT_NUMBER -1
# define E_START_BEFORE_ANT -2
# define E_END_BEFORE_ANT -3
# define E_EMPTY_LINE_ROOM -4
# define E_DUPLICATE_ROOM -4
# define E_WRONG_ROOM_NAME -5
# define E_WRONG_LINE -6
# define E_NO_PATH -7

typedef struct		s_room
{
	struct s_room	**links;
	struct s_room	*next;
	struct s_room	*next_room;
	struct s_room	*previous_room;
	char			*name;
	int				ant;
	int				start;
	int				end;
	int				visited;
	int				white;
	int				x;
	int				y;
}					t_room;

typedef struct		s_info
{
	t_room			**path;
	t_room			*room;
	char			*file;
	char			*buff;
	char			**split;
	int				ants;
	int				start;
	int				end;
	int				error_no_exit;
	int				nb_paths;
	int				nb_inst;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	int				done;
}					t_info;

void				clean(t_info *info);
void				start_again(t_info *info);
/*
** algo.c
*/
void				find_path(t_info *info, t_room *start);
/*
** tools_algo.c
*/
t_room				*get_room(t_info *info, char *s);
t_room				*get_ending_room(t_info *info);
int					ft_count_links(t_room *room);
int					ft_size_path(t_info *info);
int					count_rooms(t_info *info);
/*
** parsing.c
*/
void				ft_search_ants(t_info *info);
void				ft_search_links(t_info *info);
void				ft_search_rooms(t_info *info);
/*
** tools_printants.c
*/
void				ft_print_start(t_info *info, t_room *tmp);
void				ft_print_end(t_room *tmp);
void				ft_print_else(t_room *tmp);
void				ft_print_lems(t_info *info, t_room *end, t_room *tmp);
void				ft_set_path(t_info *info, t_room **tmp, t_room **end);
/*
** tools_comments.c
*/
int					ft_iscomment(t_info *info);
int					ft_iscommand(t_info *info);
/*
** tools_ants.c
*/
int					ft_isant_number(t_info *info);
/*
** tools_common.c
*/
void				free_charofchar(char **table);
void				ft_saveline(t_info *info);
/*
** tools_rooms.c
*/
int					ft_isroom(t_info *info);
void				ft_setend(t_info *info);
void				ft_setstart(t_info *info);
int					ft_isvalid_room_name(char *s);
int					ft_isnumber(char *s);
/*
** tools_links.c
*/
int					ft_islink(t_info *info);
/*
** errors.c
*/
void				ft_throw_error(int error, t_info *info);
void				ft_throw_error_coc(int error, t_info *info);
/*
** node.c
*/
t_room				*create_room(char *name, int x, int y);
void				add_room(t_room **begin_node, char *name, int x, int y);
/*
** run_through.c
*/
int					start_available(t_info *info);
int					end_available(t_info *info);
int					startend_available(t_info *info);
int					check_room_duplicates(t_info *info, char *name);

#endif
