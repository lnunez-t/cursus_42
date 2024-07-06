/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 11:42:53 by laura             #+#    #+#             */
/*   Updated: 2024/07/06 11:59:07 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->hitPoints = 100;
    this->enPoints = 100;
    this->attackDam = 30;

    std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void FragTrap::highFive(void)
{
    if (this->enPoints <= 0)
    {
        std::cout << "FragTrap " << this->name << " is out of energy" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->name << " gives hig five to everybody" << std::endl;
    this->enPoints--;
}