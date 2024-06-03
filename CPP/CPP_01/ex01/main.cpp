/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 07:13:44 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 07:16:55 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define N 4

int main( void ) 
{
    size_t i = 0;
    Zombie *zombie = zombieHorde(N, "zombie");

    while (i < N) 
    {
        zombie[i].announce();
        i++;
    }
    delete [] zombie;
    return 0;
}