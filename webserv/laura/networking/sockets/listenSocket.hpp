/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenSocket.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:31 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 16:46:24 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.hpp"

class listenSocket : public bindSocket
{
    private :
        int backlog;
        int listening;
    public :
        listenSocket(int domain, int service, int protocol, int port, unsigned long interface, int bcklg);
        ~listenSocket();
        void start_listen();
};