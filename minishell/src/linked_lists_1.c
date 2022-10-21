/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_lists_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdaryn <mdaryn@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 17:08:48 by mdaryn            #+#    #+#             */
/*   Updated: 2022/09/28 17:08:49 by mdaryn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "linked_lists.h"

void	ll_change_value(t_blist *node, void *new_val)
{
	if (node->val)
		free(node->val);
	node->val = new_val;
}

void	*ll_drop(t_l_list *list)
{
	blst_clear(&list->head, free, free);
	free(list);
	return (NULL);
}
