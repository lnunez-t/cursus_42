/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:14:31 by laura             #+#    #+#             */
/*   Updated: 2024/07/23 16:07:19 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
    const std::string target;

    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm(const ShrubberyCreationForm& src);
    ~ShrubberyCreationForm();
    
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& cpy);

    void execute(const Bureaucrat& executor) const;
};


#endif