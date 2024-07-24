/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:14:16 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 11:08:37 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeSign, int gradeExec) : name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& cpy) : name(cpy.getName()), gradeSign(cpy.getGradeSign()), gradeExec(cpy.getGradeExec())
{
}

AForm::~AForm()
{
}

AForm& AForm::operator=(const AForm& cpy)
{
    if (this != &cpy)
    {
        _signed = cpy.getSigned();
    }
    return (*this);
}

std::string AForm::getName() const
{
    return (name);
}

bool AForm::getSigned() const 
{
    return (_signed);
}

int AForm::getGradeSign() const
{
    return (gradeSign);    
}

int AForm::getGradeExec() const
{
    return (gradeExec);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& o, const AForm& cpy)
{
    o << " Form informations " << std ::endl;
    o << "Form name: " << cpy.getName() << std::endl;
    o << "Grade to sign: " << cpy.getGradeSign() << std::endl;
    o << "Grade to execute: " << cpy.getGradeExec() << std::endl;
    return (o);
}