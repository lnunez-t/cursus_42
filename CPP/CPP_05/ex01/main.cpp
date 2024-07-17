/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:39 by laura             #+#    #+#             */
/*   Updated: 2024/07/13 12:48:21 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat Lucy("Lucy", 5);
        Form form1("Lucy's form", 4);
        Lucy.signForm(form1);
        
        Bureaucrat Lucas("Lucas", 1);
        Form form2("Lucas's form", 10);
        Lucas.signForm(form2);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        
        
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}