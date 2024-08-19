/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:48:50 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:56:11 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

# include <iostream>
# include "ASpell.hpp"
# include <map>

class SpellBook
{
    private:
        SpellBook(const SpellBook& cpy);
        SpellBook& operator=(const SpellBook& oth);
        std::map<std::string, ASpell*> spellBook;
    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
        
};

#endif