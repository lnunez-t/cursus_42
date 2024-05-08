/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:08:43 by laura             #+#    #+#             */
/*   Updated: 2024/05/05 10:23:30 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <iomanip>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;
    int         _index;
    std::string _printLen(std::string str) const;
    std::string _getInput(std::string str) const;
public:
    Contact();
    ~Contact();
    void init(void);
    void view(int index) const;
    void display(int index) const;
    void setIndex(int i);
};

#endif