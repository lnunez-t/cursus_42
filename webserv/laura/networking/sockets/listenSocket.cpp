/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listenSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:01:14 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 16:32:49 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "listenSocket.hpp"

listenSocket::listenSocket(int domain, int service, int protocol, int port, unsigned long interface, int bcklg) : bindSocket(domain, service, protocol, port, interface)
{
    backlog = bcklg;
    start_listen();
    testConnection(listening);
}

void listenSocket::start_listen()
{
    listening = listen(getSock(), backlog);
}