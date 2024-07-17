/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:51 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 16:53:42 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() 
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    
    delete j;
    delete i;

    Dog basic;
    {
        Dog tmp = basic;
    }

    const AAnimal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
    }
    return (0); 
}