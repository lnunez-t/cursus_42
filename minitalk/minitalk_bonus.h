/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:30:28 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/19 18:08:54 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "libft/libft.h"
# include "messages.h"

typedef struct s_mini
{
	char	*s;
	int		waiting;
}		t_minitalk;

/* *** client.c & bonus *** */

void	convert_and_send(int server_pid, char c);
int		str_isdigit(char *s);

void	signal_handler(int signal);
void	def_sigaction(void);

/* *** server.c & bonus *** */

void	new_handler(int signal, siginfo_t *siginfo, void *vd);

#endif
