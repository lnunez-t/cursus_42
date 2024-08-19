/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:26:19 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 16:34:02 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() 
{   
}

TargetGenerator::TargetGenerator(const TargetGenerator& cpy)
{
    *this = cpy;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& oth)
{
    if (this != &oth)
        this->_target = oth._target;
    return (*this);
}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (target)
        _target[target->getType()] = target;
}

void TargetGenerator::forgetTargetType(std::string const& target)
{
    if (_target.find(target) != _target.end())
        _target.erase(_target.find(target));
}

ATarget* TargetGenerator::createTarget(std::string const &target)
{
    ATarget* tmp = NULL;
    if (_target.find(target) != _target.end())
        tmp = _target[target];
    return (tmp);
}