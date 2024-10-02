/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindSocket.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:41:51 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:33:22 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bindSocket.hpp"
#include "createSocket.hpp"

bindSocket::bindSocket(int domain, int service, int protocol, int port, unsigned long interface) : createSocket(domain, service, protocol, port, interface)
{
    connectToNetwork(getSock(), getAddress());
    testConnection(binding);
}

void bindSocket::connectToNetwork(int sock, struct sockaddr_in address)
{
    binding = bind(sock, (struct sockaddr *)&address, sizeof(address));
}

int bindSocket::getBinding()
{
    return (binding);
}