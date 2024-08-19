/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Polymorph.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:45:24 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:45:41 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include <iostream>
# include "ASpell.hpp"

class Polymorph : public ASpell
{
    public:
        Polymorph();
        ~Polymorph();
        ASpell* clone() const;
};

#endif