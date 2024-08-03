/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lilizarr <lilizarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 09:40:21 by lilizarr          #+#    #+#             */
/*   Updated: 2024/04/12 13:06:25 by lilizarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
/*
malloc, free, write, close, fork, waitpid, signal, kill, exit, 
chdir, execve, dup, dup2, pipe, strcmp, strncmp
ERRORS
pipes or error in execve-> "error: fatal\n"
cd-> 
	wrong arguments-> "error: cd: bad arguments\n"
	cd failed-> 
		[STDERR]"error: cd: cannot change directory to path_to_change\n" + path
	never after or before "|"
ecevbe failed-> "error: cannot execute cmd\n"

*/
// #ifdef TEST_SH
// # define TEST		1
// #else
// # define TEST		0
// #endif

void	ft_err(char *msg, char *av)
{
	while (*msg)
		write(2, msg++, 1);
	if (av)
	{
		while (*av)
			write(2, av++, 1);
	}
	write(2, "\n", 1);
}

int	cd(char *av[])
{
	if (!av[1] || av[2])
	{
		ft_err("error: cd: bad arguments", NULL);
		return (1);
	}
	else if (chdir(av[1]) != 0)
	{
		ft_err("error: cd: cannot change directory to ", av[1]);
		return (1);
	}
	return (0);
}

int	handle_fd(int f_pipe, int *fd, int in_out)
{
	int	ret;

	ret = dup2(fd[in_out], in_out) == -1;
	ret |= (close(fd[0]) == -1 || close(fd[1]) == -1);
	ret &= f_pipe;
	if (ret)
		return (ft_err("error: fatal", NULL), 1);
	return (0);
}

int	ft_execv(char *av[], char *env[], int i)
{
	int	fd[2];
	int	pid;
	int	f_pipe;
	int	stat;

	f_pipe = av[i] && !strcmp(av[i], "|");
	if (f_pipe && pipe(fd) == -1)
		return (ft_err("error: fatal", NULL), 1);
	pid = fork();
	if (pid == 0)
	{
		av[i] = 0;
		if (handle_fd(f_pipe, fd, 1))
			return (1);
		execve(*av, av, env);
		return (ft_err("error: cannot execute ", *av), 1);
	}
	waitpid(pid, &stat, 0);
	if (handle_fd(f_pipe, fd, 0))
		return (1);
	return (WIFEXITED(stat) && WEXITSTATUS(stat));
}

int	main(int ac, char *av[], char *env[])
{
	int	i;
	int	stat;
	int	j;

	stat = 0;
	i = 0;
	j = 0;
	if (ac > 1)
	{
		while (av[i] && av[i + 1])
		{
			av = &av[i + 1];
			i = 0;
			fprintf(stderr, "[----- %d ----]\n", j);
			while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			{
				fprintf(stderr, "{%d} ", strcmp(av[i], ";") && strcmp(av[i], "|"));
				fprintf(stderr, " %s ", av[i]);
				fprintf(stderr, "[%d]\n", i);
				i++;
			}
			if (strcmp(av[0], "cd") == 0)
				stat = cd(av);
			else if (i)
				stat = ft_execv(av, env, i);
			j++;
		}
	}
	return (stat);
}
