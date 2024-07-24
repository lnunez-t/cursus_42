/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:39 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 12:00:04 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    {
        Intern  someRandomIntern;
        AForm*   rrf;
        rrf = someRandomIntern.makeForm("Robotomy Request", "Bender");
        delete rrf;
    }
    
    try{
        Bureaucrat Lucy("Lucy", 2);
        ShrubberyCreationForm form1("Shrubbery");
        RobotomyRequestForm form2("Robotomy");
        PresidentialPardonForm form3("President");

        std::cout << std::endl;
        std::cout << "Form 1 : Shrubbery" << std::endl;
        Lucy.signForm(form1);
        Lucy.executeForm(form1);
        
        std::cout << "Form 2 : Robotomy" << std::endl;
        Lucy.signForm(form2);
        Lucy.executeForm(form2);
        Lucy.executeForm(form2);
        Lucy.executeForm(form2);
        Lucy.executeForm(form2);
        Lucy.executeForm(form2);

        std::cout << "Form 3 : Presidential" << std::endl;
        Lucy.signForm(form3);
        Lucy.executeForm(form3);
        
    } 
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}