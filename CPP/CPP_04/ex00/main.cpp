/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:58:51 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 12:53:03 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() 
{
    std::cout << "------- Animal -------" << std::endl;
    
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "J Type: " << j->getType() << " " << std::endl; 
    j->makeSound();
    std::cout << "I Type: " << i->getType() << " " << std::endl; 
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "------- Wrong Animal -------" << std::endl;

    const WrongAnimal* wrong = new WrongAnimal(); 
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl; 
    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
    wrong->makeSound(); 
    wrongCat->makeSound();

    delete wrong;
    delete wrongCat;
    return (0); 
}