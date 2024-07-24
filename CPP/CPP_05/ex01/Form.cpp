/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:08 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 11:08:11 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeSign) : name(name), gradeSign(gradeSign), gradeExec(0)
{
    if (gradeSign < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& cpy) : name(cpy.getName()), gradeSign(cpy.getGradeSign()), gradeExec(cpy.getGradeExec())
{
}

Form::~Form()
{
}

Form& Form::operator=(const Form& cpy)
{
    if (this != &cpy)
    {
        _signed = cpy.getSigned();
    }
    return (*this);
}

std::string Form::getName() const
{
    return (name);
}

bool Form::getSigned() const 
{
    return (_signed);
}

int Form::getGradeSign() const
{
    return (gradeSign);    
}

int Form::getGradeExec() const
{
    return (gradeExec);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeSign)
        throw Form::GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& o, const Form& cpy)
{
    o << " Form informations " << std ::endl;
    o << "Form name: " << cpy.getName() << std::endl;
    o << "Grade to sign: " << cpy.getGradeSign() << std::endl;
    o << "Grade to execute: " << cpy.getGradeExec() << std::endl;
    return (o);
}