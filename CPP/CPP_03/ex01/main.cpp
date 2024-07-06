/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:05 by laura             #+#    #+#             */
/*   Updated: 2024/07/06 11:39:14 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap bob("Bob");
    ScavTrap robot("Robot");

    bob.attack("target");
    bob.takeDamage(10);
    bob.beRepaired(10);
    bob.guardGate();
    
    return (0);
}