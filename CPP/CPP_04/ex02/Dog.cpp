/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:04:06 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 16:55:26 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << this->type << " constructor called" << std::endl;
    try
    {
        this->brain = new Brain();
    }
    catch(const std::bad_alloc& e)
    {
        std::cout << "Memory allocation failed : " << e.what() << std::endl;
    }
}

Dog::~Dog()
{
    delete (this->brain);
    std::cout << this->type << " destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Wouaf !!!" << std::endl;
}

Dog::Dog(const Dog& cpy)
{
    *this = cpy;
}

Dog& Dog::operator=(const Dog& src)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}