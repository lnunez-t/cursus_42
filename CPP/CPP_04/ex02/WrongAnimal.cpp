/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:25:04 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 12:48:12 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "WrongAnimal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = cpy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &rhs)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string WrongAnimal::getType(void) const
{
    return (this->type);
}