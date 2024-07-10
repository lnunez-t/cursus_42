/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:03:50 by laura             #+#    #+#             */
/*   Updated: 2024/07/09 15:51:19 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << this->type << " destructor called" << std::endl;
}

void Cat::makeSound(void) const
{
    std::cout << "Miaou !!!" << std::endl;
}