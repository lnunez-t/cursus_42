/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:24:32 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 12:47:14 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
    std::string type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    ~WrongAnimal();

    WrongAnimal(const WrongAnimal& cpy);
    WrongAnimal& operator=(const WrongAnimal &rhs);

    void makeSound(void) const;
    std::string getType(void) const;
};


#endif