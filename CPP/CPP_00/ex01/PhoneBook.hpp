/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 08:54:10 by laura             #+#    #+#             */
/*   Updated: 2024/05/05 09:17:24 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"

class PhoneBook 
{
private:
    Contact _contacts[8];
    int     _readInput(void) const;
public:
    PhoneBook(void);
    ~PhoneBook(void);
    void addContacts(void);
    void printContacts(void) const;
    void search(void) const;
    void welcome(void) const;
};

#endif