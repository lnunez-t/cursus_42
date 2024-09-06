/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:33:26 by laura             #+#    #+#             */
/*   Updated: 2024/09/06 08:27:06 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: bad number of arguments" << std::endl;
        return (1);
    }
    
    RPN str;

    str.run(av[1]);

    return (0);
}