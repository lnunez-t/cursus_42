/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fireball.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:43:49 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:44:10 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include <iostream>
# include "ASpell.hpp"

class Fireball : public ASpell
{
    public:
        Fireball();
        ~Fireball();
        ASpell* clone() const;
};

#endif