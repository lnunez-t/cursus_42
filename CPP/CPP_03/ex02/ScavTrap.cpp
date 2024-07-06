/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 08:32:22 by laura             #+#    #+#             */
/*   Updated: 2024/07/06 11:36:59 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->enPoints = 50;
    this->attackDam = 20;

    std::cout << "ScavTrap " << this->name << " has been created" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const& target)
{
    if (this->enPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << " is out of energy" << std::endl;
        return ;
    }
    std::cout << "ScavTrap" << this->name << " attacks " << target << ", causing " << this->attackDam << " points of damage" << std::endl;
    this->enPoints--;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}
