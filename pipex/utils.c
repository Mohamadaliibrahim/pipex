/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohamibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:01 by mohamibr          #+#    #+#             */
/*   Updated: 2024/09/05 15:03:02 by mohamibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **str)
{
	int		i;
	char	*path;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str[i], "PATH=", 5) == 0)
		{
			path = ft_strdup(str[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

t_list	*init_list_av(char **av)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
	{
		ft_printf("Error\n");
		exit(1);
	}
	list->infile = av[1];
	list->outfile = av[4];
	list->cmd1 = av[2];
	list->cmd2 = av[3];
	return (list);
}

char	*after_split(char **path, char *cmd)
{
	int		i;
	char	**cmd_split;
	char	*full_cmd_path;
	char	*temp;

	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split)
		p_error_list(NULL);
	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		if (!temp)
			p_error_list(NULL);
		full_cmd_path = ft_strjoin(temp, cmd_split[0]);
		free(temp);
		if (access(full_cmd_path, X_OK) == 0)
		{
			lets_free(cmd_split);
			return (full_cmd_path);
		}
		free(full_cmd_path);
	}
	lets_free(cmd_split);
	return (NULL);
}

void	p_error_list(t_list *list)
{
	free(list);
	ft_printf("Error\n");
	exit(1);
}

void	lets_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
