/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:10 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 15:51:37 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_place_of_path(char **av, char **env)
{
	char	*path_without_split;
	char	*str;
	char	**path;
	char	*place;

	if (access(av[2], F_OK) == 0)
		return (ft_strdup(av[2]));
	find_the_files(av);
	str = find_path(env);
	if (!str)
	{
		ft_printf("Error: PATH not found\n");
		exit(1);
	}
	path_without_split = ft_strdup(&str[5]);
	free(str);
	path = ft_split(path_without_split, ':');
	free(path_without_split);
	place = after_split(path, av[2]);
	lets_free(path);
	return (place);
}

char	*find_place_of_path2(char **av, char **env)
{
	char	*path_without_split;
	char	*str;
	char	**path;
	char	*place;

	if (access(av[3], F_OK) == 0)
		return (ft_strdup(av[3]));
	find_the_files(av);
	str = find_path(env);
	if (!str)
	{
		ft_printf("Error: PATH not found\n");
		exit(1);
	}
	path_without_split = ft_strdup(&str[5]);
	free(str);
	path = ft_split(path_without_split, ':');
	free(path_without_split);
	place = after_split(path, av[3]);
	lets_free(path);
	return (place);
}

void	parse_cmd1(t_list *list, char **env, char **av)
{
	char	*place;
	char	**cmd;

	place = find_place_of_path(av, env);
	cmd = ft_split(list->cmd1, ' ');
	if (!cmd)
	{
		ft_printf("Error\n");
		exit(1);
	}
	free(list);
	if (execve(place, cmd, env) == -1)
	{
		lets_free(cmd);
		p_error_list(NULL);
	}
	lets_free(cmd);
}

void	parse_cmd2(t_list *list, char **env, char **av)
{
	char	*place;
	char	**cmd;

	place = find_place_of_path2(av, env);
	cmd = ft_split(list->cmd2, ' ');
	if (!cmd)
	{
		free(place);
		ft_printf("Error\n");
		exit(1);
	}
	free(list);
	if (execve(place, cmd, env) == -1)
	{
		free(place);
		ft_printf("Error\n");
		exit(1);
	}
}

void	lets_fork1(char **env, int pipe_list[2], t_list *list, char **av)
{
	int	fd;

	fd = open(list->infile, O_RDONLY);
	if (fd == -1)
		p_error_list(list);
	if (dup2(fd, STDIN_FILENO) == -1)
		p_error_list(list);
	if (dup2(pipe_list[1], STDOUT_FILENO) == -1)
		p_error_list(list);
	close(pipe_list[0]);
	close(pipe_list[1]);
	close(fd);
	parse_cmd1(list, env, av);
}
