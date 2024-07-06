/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:05 by laura             #+#    #+#             */
/*   Updated: 2024/07/06 12:00:42 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
    FragTrap bob("Bob");
    FragTrap robot("Robot");

    bob.attack("target");
    bob.takeDamage(10);
    bob.beRepaired(10);
    bob.highFive();
    
    return (0);
}