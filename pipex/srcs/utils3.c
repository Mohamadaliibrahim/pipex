/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:17 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 15:51:37 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	lets_fork2(char **env, int pipe_list[2], t_list *list, char **av)
{
	int	fd;

	fd = open(list->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		p_error_list(list);
	if (dup2(pipe_list[0], STDIN_FILENO) == -1)
		p_error_list(list);
	if (dup2(fd, STDOUT_FILENO) == -1)
		p_error_list(list);
	close(pipe_list[0]);
	close(pipe_list[1]);
	close(fd);
	parse_cmd2(list, env, av);
}

void	find_the_files(char **av)
{
	t_list	*list;

	list = init_list_av(av);
	if (!list->infile || list->infile[0] == '\0')
		p_error_list(list);
	if (!list->outfile || list->outfile[0] == '\0')
		p_error_list(list);
	free(list);
}
