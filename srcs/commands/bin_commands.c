/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 10:54:52 by fgrisell          #+#    #+#             */
/*   Updated: 2021/01/27 10:54:53 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** checks the /bin/ prefix
** \author fgrisell
*/

static int	is_prefix_bin(char *line)
{
	if (ft_strncmp("/bin/", line, 5) == 0)
		return (1);
	return (0);
}

char *check_cmd(char **path, char *cmd)
{
	int i;
	char *temp;
	char *temp_cmd;
	int fd;

	i = 0;
	if (is_prefix_bin(cmd))
		return ft_strdup(cmd);
	temp_cmd = ft_strjoin("/", cmd);
	while (path[i])
	{
		if ((temp = ft_strjoin(path[i], temp_cmd)))
		{
			if ((fd = open(temp, O_RDONLY)) > 0)
			{
				close(fd);
				free(temp_cmd);
				return (temp);
			}
			free(temp);
		}
		i++;
	}
	free(temp_cmd);
	return NULL;
}

char *get_path(t_all *all, char *cmd)
{
	char **path;

	int i;
	i = 0;

	while (i < all->env_array->current_size)
	{
		if (ft_strcmp("PATH", all->env_array->key[i]) == 0)
			break;
		i++;
	}
	if (i == all->env_array->current_size)
		return (0);
	if (!(path = ft_split(all->env_array->value[i], ':')))
		return (0);
	char *command = check_cmd(path, cmd);
//	printf("com = %s\n", command);
	ft_free_split(path);
	return command;
//	return 0;
}


char		*check_bin_func(t_all *all, char *cmd)
{
	char		*command;
	int			i;
	int			flag;
	char		*temp;

	command = get_path(all, cmd);
	printf("command = %s\n", command);
//	exit(1000);
//	flag = 0;
//	i = -1;
//	command = ft_strdup(cmd);
//	while (bin_array[++i])
//	{
//		if (ft_strcmp(cmd, bin_array[i]) == 0)
//			flag = 1;
//	}
//	if (flag)
//	{
//		if (is_prefix_bin(cmd))
//			return (command);
//		else
//		{
//			free(command);
//			command = ft_strjoin("/bin/", cmd);
//		}
//	}
	return (command);
}