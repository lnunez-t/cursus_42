/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:20:47 by laura             #+#    #+#             */
/*   Updated: 2024/07/23 16:01:47 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& cpy)
{
    (void)cpy;
    return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    else
    {
        std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
}