/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 07:56:29 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 08:36:39 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) 
{}

HumanA::~HumanA()
{}

void    HumanA::attack(void) const 
{
    if (this->weapon.getType() != "") 
        std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
    else 
        std::cout << name << " doesn't have a weapon to attack." << std::endl;
}