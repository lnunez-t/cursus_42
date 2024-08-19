/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fwoosh.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:14:11 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:18:42 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include <iostream>
# include "ASpell.hpp"

class Fwoosh : public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();
        ASpell* clone() const;
};

#endif