/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:45:30 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:26:29 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ASpell.hpp"

ASpell::ASpell() {}
 
ASpell::ASpell(std::string const& name, std::string const& effects) : name(name), effects(effects) {}

ASpell::~ASpell() {}

ASpell::ASpell(const ASpell& cpy)
{
    *this = cpy;   
}

ASpell& ASpell::operator=(const ASpell& oth)
{
    if (this != &oth)
    {
        this->name = oth.name;
        this->effects = oth.effects;
    }
    return (*this);
}

std::string const& ASpell::getName() const
{
    return (this->name);
}

std::string const& ASpell::getEffects() const
{
    return (this->effects);
}

void ASpell::launch(ATarget const& target) const
{
    target.getHitBySpell(*this);
}