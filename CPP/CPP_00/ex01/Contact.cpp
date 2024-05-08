/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:08:39 by laura             #+#    #+#             */
/*   Updated: 2024/05/08 19:31:52 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}
Contact::~Contact() {}

std::string Contact::_getInput(std::string str) const
{
    std::string input = "";
    bool valid = false;
    do
    {
        std::cout << str << std::flush;
        std::getline(std::cin, input);
        if (std::cin.good() && !input.empty())
            valid = true;
        else
        {
            std::cin.clear();
            std::cout << "Invalid input, try again" << std::endl;
        }
    } while (!valid);
    return (input);
}

void Contact::init(void)
{
    std::cin.ignore();
    this->_firstName = this->_getInput("Enter your first name: ");
    this->_lastName = this->_getInput("Enter your last name: ");
    this->_nickname = this->_getInput("Enter your nickname: ");
    this->_phoneNumber = this->_getInput("Enter your phone number: ");
    this->_darkestSecret = this->_getInput("Enter your darkest secret: ");
    std::cout << std::endl;
}

std::string Contact::_printLen(std::string str) const
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

void Contact::setIndex(int i)
{
    this->_index = i;
}

void Contact::view(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_firstName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_lastName) << std::flush;
    std::cout << "|" << std::setw(10) << this->_printLen(this->_nickname) << std::flush;
    std::cout << "|" << std::endl;
}

void Contact::display(int index) const
{
    if (this->_firstName.empty() || this->_lastName.empty() || this->_nickname.empty())
        return ;
    std::cout << std::endl;
    std::cout << ">> CONTACT -" << index << "- <<" << std::endl;
    std::cout << "First name:\t" << this->_firstName << std::endl;
    std::cout << "Last name:\t" << this->_lastName << std::endl;
    std::cout << "Nickame:\t" << this->_nickname << std::endl;
    std::cout << std::endl;
}