/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarras <jocarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:55:25 by jocarras          #+#    #+#             */
/*   Updated: 2025/12/16 13:55:31 by jocarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_cmds(t_cmd *cmds)
{
	t_cmd	*next;

	while (cmds)
	{
		next = cmds->next;
		// free argv plus tard quand tu l'ajoutes
		free(cmds);
		cmds = next;
	}
}
