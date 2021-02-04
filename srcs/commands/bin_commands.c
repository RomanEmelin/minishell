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

/*!
** checks the /bin/ prefix
** \author fgrisell
*/

static int	is_prefix_bin(char *line)
{
	if (ft_strncmp("/bin/", line, 5) == 0)
		return (1);
	return (0);
}

char		*check_bin_func(char *cmd)
{
	char *command;
	int i;
	int flag;
	static char *bin_array[] = {"cp", "df", "hostname", "link", "mv", "rm",
	"stty", "test", "bash", "csh", "echo", "kill", "ln", "pax", "rmdir", "sync",
	"unlink", "cat", "date", "ed", "ksh", "ls", "ps", "sh", "syslog.py", "zsh",
	"wait4path", "chmod", "dd", "expr", "launchctl", "mkdir", "tcsh", "sleep",
	"pwd", NULL};

	flag = 0;
	i = -1;
	command = ft_strdup(cmd);
	while (bin_array[++i])
	{
		if (ft_strcmp(cmd, bin_array[i]) == 0)
			flag = 1;
	}
	if (flag)
	{
		if (is_prefix_bin(cmd))
			return command;
		else
			command = ft_strjoin("/bin/", cmd);
	}
	return (command);
}

/*
** \author fgrisell
**
*/
/*
** 	printf("bin command!\n");
**
**	printf("command argv = \n");
**	for (int i = 0; all->command_argv[i]; ++i)
**	{
**		printf("cmd_agrv[%d] = %s\n", i, all->command_argv[i]);
**	}
*/


//void bin_func(t_all *all)
//{
//	int status;
//	char *command;
//	pid_t pid;
//
//	signals_init(2);
//	all->env_array->str[all->env_array->current_size] = NULL;
//	command = check_bin_func(all->command_argv[0]);
//	if ((pid = fork()) < 0)
//		ft_putendl_fd(strerror(errno), 2);
//	if (pid == 0)
//	{
//		status = execve(command, all->command_argv, all->env_array->str);
//		if (status == -1)
//			exit(3);
//		free(command);
//		exit(status);
//	}
//	else
//	{
//		waitpid(pid, &status, 0);
//		if (WIFEXITED(status) != 0)
//		{
//			if (WEXITSTATUS(status) == 3)
//			{
//				ft_putstr_fd(PROMT_ERROR, 2);
//				ft_putstr_fd("command not found", 2);
//				ft_putstr_fd(": ", 2);
//				ft_putendl_fd(all->command_argv[0], 2);
//			}
//		}
//	}
//}
