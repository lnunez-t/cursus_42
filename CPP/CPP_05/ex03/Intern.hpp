/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 11:13:26 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 11:37:06 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& src);
    ~Intern();

    Intern& operator=(const Intern& cpy);

    AForm* makeForm(std::string name, std::string target);
};


#endif