/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrisell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 10:28:14 by fgrisell          #+#    #+#             */
/*   Updated: 2021/01/28 10:28:16 by fgrisell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void error_mes_unset(char *command)
{
	ft_putstr_fd(PROMT_ERROR, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(command, 2);
	ft_putstr_fd("'", 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd("not a valid identifier", 2);
}

int check_valid_argv(char *key)
{
	int i;

	i = 0;
	while (key[i])
	{
		if (!ft_isalnum(key[i]) || ft_strrchr("!@#$%^&*-+", key[i]) != NULL)
			return (0);
		i++;
	}
	return (1);
}

/*!
** \author fgrisell
** removes an element from the environment variable by key
*/
int ft_unset(t_all *all)
{
	int i;
	int j;

	i = 1;
	while (all->command_argv[i])
	{
//		printf("cmd = %s\n", all->command_argv[i]);
		j = 0;
		if (!check_valid_argv(all->command_argv[i]))
		{
			error_mes_unset(all->command_argv[i]);
		}
		while (all->env_array->str[j])
		{
			if (ft_strncmp(all->env_array->str[j], all->command_argv[i], ft_strlen(all->command_argv[i])) == 0)
			{
				all->env_array->delete_one_by_key(all->env_array, all->command_argv[i]);
			}
			j++;
		}
		i++;
	}
	return (0);
}