/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 17:59:49 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/07 11:50:33 by laura            ###   ########.fr       */
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
//#include <sys/epoll.h> sous Linux
#include <sys/event.h> //sous macos
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>

//#include "netlibs.hpp"

#define PORT 8080
#define MAX_EVENTS 10
#define BUFFER_SIZE 1024

