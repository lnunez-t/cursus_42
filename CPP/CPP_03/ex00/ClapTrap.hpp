/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 15:21:20 by laura             #+#    #+#             */
/*   Updated: 2024/07/06 08:14:12 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
private:
    std::string name;
    unsigned int hitPoints;
    unsigned int enPoints;
    unsigned int attackDam;
public:
    ClapTrap(std::string name);
    ~ClapTrap();
    ClapTrap(const ClapTrap &);
    ClapTrap &operator=(const ClapTrap& rhs);
    
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif