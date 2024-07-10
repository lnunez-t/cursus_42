/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:00:23 by laura             #+#    #+#             */
/*   Updated: 2024/07/09 17:33:40 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
protected:
    std::string type;
public:
    Animal(void);
    Animal(std::string type);
    Animal(const Animal& cpy);
    Animal& operator=(const Animal &rhs);
    virtual ~Animal(void);

    virtual void makeSound(void) const;
    std::string getType(void) const;
};


#endif