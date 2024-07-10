/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:03:36 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 15:23:25 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
    Brain *brain;
public:
    Cat();
    ~Cat();
    
    Cat(const Cat& cpy);
    Cat& operator=(const Cat& src);
    
    void makeSound(void) const;
};

#endif