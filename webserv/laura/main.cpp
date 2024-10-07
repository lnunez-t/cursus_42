/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:54:19 by laura             #+#    #+#             */
/*   Updated: 2024/10/07 18:01:31 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/webserv.hpp"

int g_sigint = 0;

void ft_sigint_handler(int c)
{
    (void) c;
    g_sigint = 1;
    std::cout << "STOPPING THE SERVER...\n";
}

int main(int ac, char **av)
{
    (void)ac;
    signal(SIGINT, ft_sigint_handler);

    std::string fileConfigPath(av[1] ? av[1] : "confDefault.conf");
    try{
        Config conf(fileConfigPath);
        conf.run();
    }
    catch (std::exception &e)
    {std::cerr << e.what() << std::endl;}
    return (0);
}