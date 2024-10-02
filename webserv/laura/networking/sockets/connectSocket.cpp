/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectSocket.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:01 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:33:31 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "connectSocket.hpp"
#include "createSocket.hpp"

connectSocket::connectSocket(int domain, int service, int protocol, int port, unsigned long interface) : createSocket(domain, service, protocol, port, interface)
{
    connectToNetwork(getSock(), getAddress());
    testConnection(binding);
}

void connectSocket::connectToNetwork(int sock, struct sockaddr_in address)
{
    binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}

int connectSocket::getBinding()
{
    return (binding);
}