/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:54:17 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:13:38 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ATarget.hpp"

ATarget::ATarget() {}
 
ATarget::ATarget(std::string const& type) : type(type) {}

ATarget::~ATarget() {}

ATarget::ATarget(const ATarget& cpy)
{
    *this = cpy;   
}

ATarget& ATarget::operator=(const ATarget& oth)
{
    if (this != &oth)
    {
        this->type = oth.type;
    }
    return (*this);
}

std::string const& ATarget::getType() const
{
    return (this->type);
}

void ATarget::getHitBySpell(ASpell const& spell) const
{
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}