/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:59:01 by laura             #+#    #+#             */
/*   Updated: 2024/07/11 11:29:23 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool _signed;
    const int gradeSign;
    const int gradeExec;

    Form();
    
public:
    Form(const std::string& name, int gradeSign);
    Form(const std::string& name, int gradeSign, int gradeExec);
    Form(const Form& cpy);
    Form& operator=(const Form& rhs);
    ~Form();

    std::string getName() const;
    bool getSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;
    
    void beSigned(const Bureaucrat& bureaucrat);

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

std::ostream& operator<<(std::ostream& o, const Form& rhs);


#endif