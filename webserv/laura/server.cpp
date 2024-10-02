/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:17:06 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/10/02 17:10:35 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

int set_non_blocking(int fd)
{
    int flags = fcntl(fd, F_GETFL, 0); //recupere les flags associes au fd
    if (flags == -1)
    {
        std::cerr << "Erreur fcntl F_GETFL" << std::endl;
        return (-1);
    }
    
    flags |= O_NONBLOCK; //configure le fd en mode non-bloquant ena joutant le flag aux flags existants
    
    if (fcntl(fd, F_SETFL, flags) == -1) //applique les nouveaux flags au fd
    {
        std::cout << "Erreur fcntl F_SETFL" << std::endl;
        return (-1);
    }

    return (0);
}

int main(void)
{

    //Creation d'un socket
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    //Message de reponse HTTP
    const char *response = "HTTP/1.1 200 OK\n"
        "Content-Type: text/html\n"
        "Content-Length: 57\n\n"
        "<html><body><h1>Hello, this is a simple C++ web server!</h1></body></html>";
    
    //Creation du socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cerr << "Erreur lors de la creation du socket" << std::endl;
        return (-1);
    }

    //Activation mode non-bloquant pour le socket du serveur
    if (set_non_blocking(server_fd) < 0)
    {
        std::cerr << "Erreur lors de l'activation du mode non-bloquant pour le serveur" << std::endl;
        close(server_fd);
        return(-1);
    }

    //Configuration adresse et port
    address.sin_family = AF_INET; //Famille adresses IPv4
    address.sin_addr.s_addr = INADDR_ANY; //Adresse IP
    address.sin_port = htons(PORT); //Conversion du PORT en ordre d'octets reseau

    //Attache le socket au port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        std::cerr << "Erreur lors de l'attachement au port" << std::endl;
        close(server_fd);
        return (-1);
    }

    if (listen(server_fd, 3) < 0)
    {
        std::cerr << "Erreur lors de l'ecoute" << std::endl;
        close(server_fd);
        return (-1);
    }

    std::cout << "Serveur web en ecoute sur le port " << PORT << std::endl;

    //Creation epoll : surveille plusieurs fd pour voir si les E/S sont possibles sur l'un d'entre eux
    int epoll_fd = epoll_create(1);
    if (epoll_fd == -1)
    {
        std::cerr << "Erreur lors de la creation de epoll" << std::endl;
        close(server_fd);
        return (-1);
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = server_fd;

    //Ajout du socket du serveur a epoll
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1)
    {
        std::cerr << "Erreur lors de l'ajout du socket du serveur a epoll" << std::endl;
        close(epoll_fd);
        close(server_fd);
        return (-1);
    }

    while(true)
    {
        struct epoll_event events[MAX_EVENTS];
        int nfds = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);

        for (int i = 0; i < nfds; i++)
        {
            if (events[i].data.fd == server_fd)
            {
                //Accepte une connexion entrante
                if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0)
                {
                    std::cerr << "Erreur lors de l'acceptation de la connexion" << std::endl;
                    continue ; //Continue a accepter d'autres connexions
                }

                //Activation du mode non-bloquant pour chaque socket client
                if (set_non_blocking(new_socket) < 0)
                {
                    std::cerr << "Erreur lors de l'activation du mode non-bloquant pour le client" << std::endl;
                    close(new_socket);
                    continue;
                }

                event.events = EPOLLIN;
                event.data.fd = new_socket;

                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_socket, &event) == -1)
                {
                    std::cerr << "Erreur lors de l'ajout du socket client a epoll" << std::endl;
                    close(new_socket);
                    continue ;
                }

                std::cout << "Nouvelle connexion acceptee" << std::endl;
            }
            else
            {
                //Le socket client a des donnees a lire
                char buffer[1024] = {0};
                int valread = read(events[i].data.fd, buffer, sizeof(buffer));

                if (valread <= 0)
                {
                    close(events[i].data.fd);
                    std::cout << "Connexion fermee" << std::endl;
                }
                else
                {
                    //Envoi de la reponse HTTP au client
                    send(events[i].data.fd, response, strlen(response), 0);
                    std::cout << "Reponse envoyee au client" << std::endl;
                    close(events[i].data.fd);
                }
            }
        }
    }

    //Fermeture du socket du serveur
    close(server_fd);
    close(epoll_fd);

    return (0);
}