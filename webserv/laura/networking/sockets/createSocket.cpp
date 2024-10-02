/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createSocket.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:01:12 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:33:08 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

createSocket::createSocket(int domain, int service, int protocol, int port, unsigned long interface)
{
    //Definition de la structure
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    //Creer le socket
    sock = socket(domain, service, protocol);
    testConnection(sock);
}

void createSocket::testConnection(int to_test)
{
    if (to_test < 0)
    {
        std::cerr << "Failed to connect" << std::endl;
        exit(EXIT_FAILURE);
    }
}

struct sockaddr_in createSocket::getAddress()
{
    return (address);
}
int createSocket::getSock()
{
    return (sock);
}