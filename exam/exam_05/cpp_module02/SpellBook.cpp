/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpellBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:53:34 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 16:09:00 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook() 
{
    for (std::map<std::string, ASpell*>::iterator it = spellBook.begin(); it != spellBook.end(); ++it)
        delete (it->second);
    spellBook.clear();    
}

SpellBook::SpellBook(const SpellBook& cpy)
{
    *this = cpy;
}

SpellBook& SpellBook::operator=(const SpellBook& oth)
{
    if (this != &oth)
        this->spellBook = oth.spellBook;
    return (*this);
}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spell)
        spellBook[spell->getName()] = spell->clone();
}

void SpellBook::forgetSpell(std::string const& name)
{
    std::map<std::string, ASpell*>::iterator it = spellBook.find(name);
    if (it != spellBook.end())
    {
        delete (it->second);
        spellBook.erase(it);
    }
}

ASpell* SpellBook::createSpell(std::string const& spell)
{
    ASpell* tmp = NULL;
    if (spellBook.find(spell) != spellBook.end())
       tmp = spellBook[spell];
    return (tmp);
}
