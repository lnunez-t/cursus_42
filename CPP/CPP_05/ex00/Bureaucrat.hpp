/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:14:50 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 11:07:31 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
private:
    const std::string name;
    int grade;

    Bureaucrat();
    
public:
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& cpy);
    Bureaucrat& operator=(const Bureaucrat& cpy);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incGrade();
    void decGrade();

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too high");
            }
    };
    
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade too low");
            }
    };
    
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& cpy);


#endif