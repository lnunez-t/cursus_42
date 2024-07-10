/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:04:06 by laura             #+#    #+#             */
/*   Updated: 2024/07/09 15:51:25 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << this->type << " constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << this->type << " destructor called" << std::endl;
}

void Dog::makeSound(void) const
{
    std::cout << "Wouaf !!!" << std::endl;
}