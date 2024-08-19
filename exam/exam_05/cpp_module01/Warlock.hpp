/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Warlock.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:19:05 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:31:17 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <map>
# include "ASpell.hpp"
# include "ATarget.hpp"

class Warlock
{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell*> spellBook;
    public:
        Warlock(std::string const& name, std::string const& title);
        ~Warlock();
        std::string const& getName() const;
        std::string const& getTitle() const;
        void setTitle(std::string const& title);
        void introduce() const;

        void learnSpell(ASpell* spell);
        void forgetSpell(std::string name);
        void launchSpell(std::string name, ATarget const& target);
};

#endif