/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:03:58 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 16:54:58 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
private:
    Brain *brain;
public:
    Dog();
    ~Dog();

    Dog(const Dog& cpy);
    Dog& operator=(const Dog& src);
    
    void makeSound(void) const;
};

#endif