/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 07:56:51 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 08:39:06 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) 
{
    this->weapon = NULL;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon &weapon) 
{
    this->weapon = &weapon;
}

void    HumanB::attack(void) const 
{
    if (this->weapon != NULL && this->weapon->getType() != "") 
        std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
}