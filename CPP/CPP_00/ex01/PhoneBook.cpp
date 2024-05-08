/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:53:09 by laura             #+#    #+#             */
/*   Updated: 2024/05/08 19:57:43 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}
PhoneBook::~PhoneBook() {}

void PhoneBook::welcome(void) const
{
    std::cout << std::endl;
    std::cout << "Welcome to my Phonebook" << std::endl;
    std::cout << std::endl;
    std::cout << "Type ADD to add a contact" << std::endl;
    std::cout << "Type SEARCH to search for a contact" << std::endl;
    std::cout << "Type EXIT to quit the Phonebook" << std::endl;
    std::cout << std::endl;
}

void PhoneBook::addContacts(void)
{
    static int i;
    this->_contacts[i % 8].init();
    this->_contacts[i % 8].setIndex(i % 8);
    i++;
}

void PhoneBook::printContacts(void) const
{
    std::cout << "PHONEBOOK CONTACTS" << std::endl;
    for (size_t i = 0; i < 8; i++)
        this->_contacts[i].view(i);
    std::cout << std::endl;
}

int PhoneBook::_readInput() const
{
    int input = -1;
    bool valid = false;
    do
    {
        std::cout << "Enter the contact index" << std::flush;
        std::cin >> input;
        if (std::cin.good() && (input >= 0 && input <= 8))
            valid = true;
        else{
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Invalid index, please re-enter" << std::endl;
        }
    } while (!valid);
    return (input);
}

void PhoneBook::search(void) const 
{
    int i = this->_readInput();
    this->_contacts[i].display(i);
}