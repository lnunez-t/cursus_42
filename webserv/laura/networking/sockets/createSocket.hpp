/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:04:28 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 16:47:15 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "webserv.hpp"

class createSocket
{
    private:
        int sock;
        struct sockaddr_in address;
    public:
        createSocket(int domain, int service, int protocol, int port, unsigned long interface);
        ~createSocket();
        virtual void netConnect(int sock, struct sockaddr_in address) = 0;
        void testConnection(int);
        struct sockaddr_in getAddress();
        int getSock();
};