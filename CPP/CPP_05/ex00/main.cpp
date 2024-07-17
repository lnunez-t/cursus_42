/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:39 by laura             #+#    #+#             */
/*   Updated: 2024/07/11 10:57:22 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try{
        Bureaucrat Lucy("Lucy", 5);
        Bureaucrat Lucas("Lucas", 1);

        std::cout << Lucy << std::endl;
        std::cout << "Bureaucrat got promoted" << std::endl;
        Lucy.incGrade();
        std::cout << Lucy << std::endl;
        
        std::cout << Lucas << std::endl;
        std::cout << "Bureaucrat got promoted" << std::endl;
        Lucas.incGrade();
        std::cout << Lucas << std::endl;
        
        //bureaucrat.decGrade();
    } 
    catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << e.what() << std::endl;
    }
    return (0);
}