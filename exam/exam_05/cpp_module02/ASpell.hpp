/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ASpell.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:38:49 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:26:36 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASPELL_HPP
# define ASPELL_HPP

# include <iostream>
# include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;
    public:
        ASpell();
        ASpell(std::string const& name, std::string const& effects);
        virtual ~ASpell();
        ASpell(const ASpell& cpy);
        ASpell& operator=(const ASpell& oth);
        std::string const& getName() const;
        std::string const& getEffects() const;
        
        virtual ASpell* clone() const = 0;
        void launch(ATarget const& target) const;
};

#endif