/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configServ.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:14:49 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/09/26 17:03:20 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

configServ::configServ() {
    this->keys[0] = "listen";
    this->keys[1] = "server_name";
    this->keys[2] = "error_page";
    this->keys[3] = "client_max_body_size";
    this->keys[4] = "root";
    this->keys[5] = "autoindex";
    this->keys[6] = "index";
    this->keys[7] = "fastcgi_param";
}

configServ::~configServ() {}

configServ::configServ(const configServ& cpy)
{
    *this = cpy;
}
configServ& configServ::operator=(const configServ& oth)
{
    if (this != &oth)
    {
        this->config = oth.config;
        this->port = oth.port;
        this->root_dir = oth.root_dir;
        this->ip = oth.ip;
        this->keys = oth.keys;
    }
    return (*this);
}

std::map<std::string, void*> configServ::readConfigFile(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file)
    {
        std::cerr << "Erreur lors de l'ouverture du fichier de configuration" << std::endl;
        return (this->config);
    }

    while(std::getline(file, line))
    {
        std::istringstream is_line(line);
        
        
        std::string key;
        
        if (std::getline(is_line, key))
        {
            std::string value;
            if (std::getline(is_line, value))
                config[key] = value;
        }
    }

    file.close();
    
    return (config);
}