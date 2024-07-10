/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:03:50 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 15:27:39 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
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

Cat::~Cat()
{
    std::cout << this->type << " destructor called" << std::endl;
    delete (this->brain);
}

Cat::Cat(const Cat& cpy)
{
    *this = cpy;
}

Cat& Cat::operator=(const Cat& src)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou !!!" << std::endl;
}