/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 07:56:20 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 08:29:39 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

class HumanA
{
private:
    std::string name;
    Weapon &weapon;
    HumanA();
public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack(void) const;
};