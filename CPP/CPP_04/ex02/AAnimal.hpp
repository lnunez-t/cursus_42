/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:08:23 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 16:56:57 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
protected:
    std::string type;
public:
    AAnimal(void);
    AAnimal(std::string type);
    AAnimal(const AAnimal& cpy);
    AAnimal& operator=(const AAnimal &rhs);
    virtual ~AAnimal(void);

    virtual void makeSound(void) const;
    std::string getType(void) const;
};

#endif