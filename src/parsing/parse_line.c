/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarras <jocarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:55:41 by jocarras          #+#    #+#             */
/*   Updated: 2025/12/16 15:26:00 by jocarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_cmd	*parse_line(char *line, t_shell *sh)
{
	t_cmd	*cmd;
	char	**argv;

	printf("parse_line appelee\n");
	(void)line;
	(void)sh;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	argv = malloc(sizeof(char *) * 3);
	argv[0] = ft_strdup("/bin/ls");
	argv[1] = ft_strdup("-l");
	argv[2] = NULL;
	cmd->argv = argv;
	cmd->redirs = NULL;
	cmd->is_builtin = 0;
	cmd->next = NULL;

	return (cmd);
}

