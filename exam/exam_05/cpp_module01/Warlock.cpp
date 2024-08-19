/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:22:08 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:39:35 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Warlock.hpp"

Warlock::Warlock(std::string const& name, std::string const& title) : name(name), title(title)
{
    std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() 
{
    std::cout << name << ": My job here is done!" << std::endl;
}

std::string const& Warlock::getName() const{
    return (this->name);
}

std::string const& Warlock::getTitle() const{
    return (this->title);
}

void Warlock::setTitle(std::string const& title)
{
    this->title = title;
}

void Warlock::introduce() const{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        if (spellBook.find(spell->getName()) == spellBook.end())
            spellBook[spell->getName()] = spell->clone();
}

void Warlock::forgetSpell(std::string name)
{
    if (spellBook.find(name) != spellBook.end())
        spellBook.erase(spellBook.find(name));
}

void Warlock::launchSpell(std::string name, ATarget const& target)
{
    if (spellBook.find(name) != spellBook.end())
        spellBook[name]->launch(target);
}