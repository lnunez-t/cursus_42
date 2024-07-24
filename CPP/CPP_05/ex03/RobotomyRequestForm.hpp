/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:18:04 by laura             #+#    #+#             */
/*   Updated: 2024/07/23 16:02:51 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_H
# define ROBOTOMYREQUESTFORM_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    const std::string target;
    
    RobotomyRequestForm();
public:
    RobotomyRequestForm(const std::string& target);
    RobotomyRequestForm(const RobotomyRequestForm& src);
    ~RobotomyRequestForm();
    
    RobotomyRequestForm &operator=(RobotomyRequestForm& cpy);
    
    void execute(const Bureaucrat& executor) const;
};


#endif