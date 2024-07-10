/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:28:11 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 12:42:47 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << this->type << " destructor called" << std::endl;
}

void WrongCat::makeSound(void) const
{
    std::cout << "Miaou !!!" << std::endl;
}