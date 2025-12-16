/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarras <jocarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:34:09 by jocarras          #+#    #+#             */
/*   Updated: 2025/12/16 15:26:44 by jocarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_simple(t_cmd *cmd, t_shell *sh)
{
		printf("exec_simple appelee\n");
	int	pid;
	int status;

	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		execve(cmd->argv[0], cmd->argv, sh->envp);
		perror("execve");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
