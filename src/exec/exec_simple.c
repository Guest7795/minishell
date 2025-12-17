/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarras <jocarras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:34:09 by jocarras          #+#    #+#             */
/*   Updated: 2025/12/17 17:23:05 by jocarras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_simple(t_cmd *cmd, t_shell *sh)
{
	int	pid;
	int	status;

	if (cmd->argv && cmd->argv[0]
		&& ft_strncmp(cmd->argv[0], "echo", 5) == 0)
	{
		sh->last_status = builtin_echo(cmd->argv);
		return ;
	}	
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
		if (WIFEXITED(status))
			sh->last_status = WEXITSTATUS(status);
	}
}

