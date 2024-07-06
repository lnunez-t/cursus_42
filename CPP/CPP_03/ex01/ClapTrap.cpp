/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:32 by laura             #+#    #+#             */
/*   Updated: 2024/07/06 08:25:19 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), enPoints(10), attackDam(0)
{
    std::cout << "ClapTrap " << name << " has been created !" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
    *this = rhs;
    std::cout << "Copy constructor called" << std::endl;
    return ;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
    this->name = rhs.name;
    this->hitPoints = rhs.hitPoints;
    this->enPoints = rhs.enPoints;
    this->attackDam = rhs.attackDam;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (enPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is out of energy" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDam << " points of damage !" << std::endl;
    enPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= amount)
    {
        std::cout << "ClapTrap " << name << " is dead" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " takes " << amount << " damage" << std::endl;
    hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (enPoints <= amount)
    {
        std::cout << "ClapTrap " << name << " is out of energy" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << name << " repairs itself for " << amount << " hitPoints" << std::endl;
    enPoints--;
    hitPoints += amount;
}