/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:57:10 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 07:06:28 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    std::string name;

    std::cout << "Create a zombie in the stack" << std::endl;
    std::cout << "Name your zombie: " << std::flush;
    std::cin >> name;

    //Zombie zombie1(name);

    randomChump(name);
    
    std::cout << "Create a zombie in the heap" << std::endl;
    std::cout << "Name your zombie: " << std::flush;
    std::cin >> name;
    
    Zombie *zombie2 = newZombie(name);
    zombie2->announce();
    delete zombie2;
    
    return (0);
}