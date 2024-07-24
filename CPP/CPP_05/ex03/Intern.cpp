/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:13:09 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 11:36:54 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern& src)
{
    *this = src;
}

Intern::~Intern()
{
}

Intern& Intern::operator=(const Intern& cpy)
{
    (void)cpy;
    return (*this);
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    std::string formNames[] = {
        "Robotomy Request",
        "Presidential Pardon",
        "Shrubbery Creation"
    };
    
    AForm* forms[] = {
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target),
        new ShrubberyCreationForm(target)
    };

    for (int i = 0; i < 3; i++)
    {
        if (name == formNames[i])
        {
            std::cout << "Intern creates " << name << std::endl;
            return (forms[i]);
        }
    }
    std::cout << "Intern cannot create " << name << " form" << std::endl;
    return (nullptr);
}