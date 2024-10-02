/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connectSocket.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:10:27 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:33:39 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.hpp"
#include "createSocket.hpp"

class connectSocket : public createSocket
{
    private :
        int binding;
        void connectToNetwork(int sock, struct sockaddr_in address);
    public:
        connectSocket(int domain, int service, int protocol, int port, unsigned long interface);
        ~connectSocket();

        int getBinding();
};