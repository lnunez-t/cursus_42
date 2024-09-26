/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:21:56 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/09/24 14:57:16 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "webserv.hpp"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT "8080"

int main(void)
{
    int sock = 0;
    struct addrinfo hints, *res;
    char buffer[1024] = {0};
    const char *request = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";

    //Init de la struct hints
    memset(&hints, 0, sizeof(hints)); //Allocation de la memoire necessaire et remplissage par des 0
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    
    if (getaddrinfo("127.0.0.1", PORT, &hints, &res) != 0)
    {
        std::cerr << "Erreur lors de la resolution de l'adresse" << std::endl;
        return (-1);
    }
    
    //Creation du socket
    if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0)
    {
        std::cerr << "Erreur lors de la creation du socket client" << std::endl;
        return (-1);
    }

   if (connect(sock, res->ai_addr, res->ai_addrlen) < 0)
   {
        std::cerr << "Erreur lors de la connexion au serveur" << std::endl;
        freeaddrinfo(res);
        close(sock);
        return (-1);
   }

    //Envoi de la requete HTTP au serveur
    send(sock, request, strlen(request), 0);
    std::cout << "Requete envoyee au serveur" << std::endl;

    //Lecture de la reponse du serveur
    int valread = read(sock, buffer, 1024);

    if (valread == 0)
        std::cout << "Connexion fermee par le serveur" << std::endl;
    else if (valread < 0)
        std::cout << "Erreur lors de la lecture de la reponse du serveur" << std::endl;
    else
        std::cout << "Reponse recue du serveur :\n" << buffer << std::endl;

    freeaddrinfo(res);
    
    //Fermeture du socket client
    close(sock);
    
    return (0);
}