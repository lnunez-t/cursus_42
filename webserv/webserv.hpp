/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:59:49 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/09/26 16:58:52 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

#define PORT 8080
#define MAX_EVENTS 10
#define BUFFER_SIZE 1024


class configServ
{
    private:
        int port;
        std::string ip;
        std::string root_dir;
        std::map<std::string, void*> config;
        std::vector<std::string> keys;
    public:
        configServ();
        ~configServ();

        configServ(const configServ& cpy);
        configServ& operator=(const configServ& oth);
        std::map<std::string, void*> readConfigFile(const std::string &filename);
};