/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindSocket.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:04:49 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:04:30 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 

#include "webserv.hpp"

class bindSocket : public createSocket
{
    private :
        int binding;
        void connectToNetwork(int sock, struct sockaddr_in address);
    public:
        bindSocket(int domain, int service, int protocol, int port, unsigned long interface);
        ~bindSocket();

        int getBinding();
};