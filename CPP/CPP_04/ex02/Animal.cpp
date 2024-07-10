/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:00:58 by laura             #+#    #+#             */
/*   Updated: 2024/07/09 17:31:03 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
    std::cout << this->type << " constructor called" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal " << this->type << " constructor called" << std::endl;
}

Animal::Animal(const Animal& cpy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = cpy;
}

Animal& Animal::operator=(const Animal &rhs)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &rhs)
        this->type = rhs.type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal makeSound called" << std::endl;
}

std::string Animal::getType(void) const
{
    return (this->type);
}