/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ATarget.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:50:34 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:13:33 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ATARGET_HPP
# define ATARGET_HPP

# include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string type;
    public:
        ATarget();
        ATarget(std::string const& type);
        virtual ~ATarget();
        ATarget(const ATarget& cpy);
        ATarget& operator=(const ATarget& oth);
        std::string const& getType() const;

        virtual ATarget* clone() const = 0;
        void getHitBySpell(ASpell const& spell) const;
};

#endif