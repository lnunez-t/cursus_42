/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:19:40 by laura             #+#    #+#             */
/*   Updated: 2024/07/23 16:03:43 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("Robotomy Request Form", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& cpy)
{
    (void)cpy;
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (executor.getGrade() > this->getGradeExec())
        throw AForm::GradeTooLowException();
    else
    {
        static int i;
        if (i % 2 == 0)
            std::cout << "BZZZZZT! " << target << " has been robotomized" << std::endl;
        else
            std::cout << "Robotomy failed" << std::endl;
        i++;
    }
}