/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:08:13 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 16:52:23 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
    std::cout << this->type << " constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) : type(type)
{
    std::cout << "AAnimal " << this->type << " constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& cpy)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = cpy;
}

AAnimal& AAnimal::operator=(const AAnimal &rhs)
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound(void) const
{
    std::cout << "AAnimal makeSound called" << std::endl;
}

std::string AAnimal::getType(void) const
{
    return (this->type);
}