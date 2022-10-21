/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <mdaryn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:08:19 by mdaryn            #+#    #+#             */
/*   Updated: 2022/09/28 17:08:20 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "clean.h"

int	ft_change_value(t_blist *llist, char *key, char *value)
{
	t_blist	*tmp;
	int		len;

	tmp = llist;
	len = ft_strlen(key);
	while (tmp)
	{
		if (ft_strncmp(key, tmp->key, (len + 1)) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (0);
	else if (ft_strncmp(key, tmp->key, (len + 1)) == 0)
	{
		free(tmp->val);
		tmp->val = value;
		free(key);
	}
	return (1);
}

void	ft_newelem_export(t_shell *shell, char *str)
{
	int		i;
	char	*key;
	char	*value;
	t_blist	*new;

	i = 0;
	while (str[i] && str[i] != '=')
		++i;
	key = ft_strndup(str, i);
	if (str[i] == '=')
		++i;
	value = ft_strdup(str + i);
	if (key == NULL || value == NULL)
		perror_exit("", 12);
	if (ft_change_value(shell->export, key, value))
		return ;
	new = blst_new(key, value);
	if (new == NULL)
		perror_exit("", 12);
	blst_add_back(&shell->export, new);
}

void	ft_newelem_env(t_shell *shell, char *str)
{
	int		i;
	char	*key;
	char	*value;
	t_blist	*new;

	i = 0;
	while (str[i] && str[i] != '=')
		++i;
	key = ft_strndup(str, i);
	if (str[i] == '=')
		++i;
	value = ft_strdup(str + i);
	if (key == NULL || value == NULL)
		perror_exit("", 12);
	if (ft_change_value(shell->envs, key, value))
		return ;
	new = blst_new(key, value);
	if (new == NULL)
		perror_exit("", 12);
	blst_add_back(&shell->envs, new);
}

void	ft_adding_to_struct(t_shell *shell, char **cmd_args)
{
	int	i;
	int	put;

	i = 1;
	while (cmd_args[i])
	{
		put = ft_check_arguments_export(shell, cmd_args[i]);
		if (put > 0)
		{
			ft_newelem_export(shell, cmd_args[i]);
			if (put == 2)
				ft_newelem_env(shell, cmd_args[i]);
		}
		i++;
	}
}

void	export_cmd(t_shell *shell, char **cmd_args)
{
	if (shell->export == NULL)
		copy_env_to_export(shell, shell->envs);
	if (cmd_args[0] != NULL && cmd_args[1] == NULL)
		ft_print_sort(shell);
	else if (cmd_args[0] != NULL && cmd_args[1] != NULL)
		ft_adding_to_struct(shell, cmd_args);
	if (!ft_strncmp(cmd_args[1], "PATH", ft_strlen("PATH")))
	{
		clean_array(shell->env_arr);
		shell->env_arr = get_envp(shell->envs);
	}
}
