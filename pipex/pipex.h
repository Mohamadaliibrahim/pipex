/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:02:45 by mohamibr          #+#    #+#             */
/*   Updated: 2024/09/05 15:02:48 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "ft_printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_list
{
	char	*infile;
	char	*outfile;
	char	*cmd1;
	char	*cmd2;
}			t_list;

char		*find_path(char **str);
t_list		*init_list_av(char **av);
char		*after_split(char **path, char *cmd);
void		p_error_list(t_list *list);
void		lets_free(char **str);
char		*find_place_of_path(char **av, char **env);
char		*find_place_of_path2(char **av, char **env);
void		parse_cmd1(t_list *list, char **env, char **av);
void		parse_cmd2(t_list *list, char **env, char **av);
void		lets_fork1(char **env, int pipe_list[2], t_list *list, char **av);
void		lets_fork2(char **env, int pipe_list[2], t_list *list, char **av);
void		find_the_files(char **av);
int			pipex(char **av, char **env);

#endif
