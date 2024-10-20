/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <mohamibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:02:34 by mohamibr          #+#    #+#             */
/*   Updated: 2024/10/20 15:51:37 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	pipex(char **av, char **env)
{
	t_list	*list;
	pid_t	pid1;
	pid_t	pid2;
	int		pipe_list[2];
	int		status;

	list = init_list_av(av);
	if (pipe(pipe_list) == -1)
		p_error_list(list);
	pid1 = fork();
	if (pid1 == -1)
		p_error_list(list);
	if (pid1 == 0)
		lets_fork1(env, pipe_list, list, av);
	pid2 = fork();
	if (pid2 == -1)
		p_error_list(list);
	if (pid2 == 0)
		lets_fork2(env, pipe_list, list, av);
	close(pipe_list[0]);
	close(pipe_list[1]);
	free(list);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (status);
}

void	check_for_cmd(char **av)
{
	t_list	*list;

	if ((av[2][0] == '\0' || av[3][0] == '\0')
		|| (av[2][0] == ' ' || av[3][0] == ' '))
	{
		p_error_list(NULL);
	}
	find_the_files(av);
	list = init_list_av(av);
	if (!list->cmd1 || !list->cmd2 || av[2][0] == '\0' || av[3][0] == '\0'
		|| av[2][0] == ' ' || av[3][0] == ' ')
		p_error_list(list);
	free(list);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd1;
	char	*cmd2;

	if (ac == 5)
	{
		check_for_cmd(av);
		cmd1 = find_place_of_path(av, env);
		cmd2 = find_place_of_path2(av, env);
		if (!cmd1 || !cmd2)
		{
			free(cmd1);
			free(cmd2);
			p_error_list(NULL);
		}
		free(cmd1);
		free(cmd2);
		if (pipex(av, env))
		{
			exit(1);
		}
	}
	else
		ft_printf("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	return (0);
}
