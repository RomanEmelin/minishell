/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <mwinter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 17:59:06 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/26 13:39:09 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int key_len(char *line)
{
	int i;

	i = 0;
	while (line[i] && !ft_strchr("\'\" <>|;", line[i]))
		i++;
	return (i);
}
static char *get_key(char *line, t_all *all)
{
	char	*key;
	int		k;

	all->i++;
	if (!(key = (char *)malloc(sizeof(char) * (key_len(&line[all->i]) + 1))))
		return (NULL);
	k = 0;
	while (line[all->i] && !ft_strchr("\'\" <>|;$", line[all->i]))
		key[k++] = line[all->i++];
	key[k] = '\0';
	return (key);
}

char *get_env(char *line, t_all *all)
{
	char	*key;
	char	*env;

	if (!(key = get_key(line, all)))
		return (NULL);
	env = get_env_by_key(all, key);
	free(key);
	return(env);

}