/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:10:20 by laura             #+#    #+#             */
/*   Updated: 2024/07/13 13:14:00 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool _signed;
    const int gradeSign;
    const int gradeExec;

    AForm();
    
public:
    AForm(const std::string& name, int gradeSign);
    AForm(const std::string& name, int gradeSign, int gradeExec);
    AForm(const AForm& cpy);
    AForm& operator=(const AForm& rhs);
    virtual ~AForm();

    std::string getName() const;
    bool getSigned() const;
    int getGradeSign() const;
    int getGradeExec() const;
    
    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(const Bureaucrat& executor) const = 0;

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

    class NotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Form not signed");
            }
    };
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);


#endif