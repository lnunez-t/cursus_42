/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:32:45 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/01/17 11:48:56 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define C_ERROR "\nError !"
# define C_ARGS "Add the server PID and a string or smiley."
# define C_EX_ARGS "Example : ./client 4242(PID) Hello(Message)\n"

# define C_NOTIFICATION "Waiting for notification...\n"

# define S_PID "My PID : [%d], parameter for the client.\n\n"
# define S_MESS "I print messages sent by the client.\n"
# define S_CHEV ">> "

# define NOTIFICATION_R1 "RECE"
# define NOTIFICATION_R2 "IVED\n"

# define SA_USR1_FAIL "SIGUSR1 failed\n"
# define SA_USR2_FAIL "SIGUSR2 failed\n"

# define SERV_FAIL_USR1 "SIGUSR1"
# define SERV_FAIL_USR2 "Server failed to send SIGUSR2"

#endif
