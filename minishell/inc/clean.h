/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <mdaryn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:09:49 by mdaryn            #+#    #+#             */
/*   Updated: 2022/09/28 17:09:50 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_H
# define CLEAN_H
# include "minishell.h"

void	clean_shell_data(t_shell *shell);
void	clean_array(char	**arr);
void	clean_envs_list(t_blist	*list);
void	clean_shell_data(t_shell	*shell);
#endif