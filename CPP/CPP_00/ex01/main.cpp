/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 09:01:45 by laura             #+#    #+#             */
/*   Updated: 2024/05/08 19:43:50 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <limits>
#include <iostream>

int main(void) 
{
    PhoneBook book;
    std::string input = "";
    book.welcome();
    while (input.compare("EXIT"))
    {
        if (input.compare("ADD") == 0)
            book.addContacts();
        else if (input.compare("SEARCH") == 0)
        {
            book.printContacts();
            book.search();
        }
        std::cout << "> " << std::flush;
        std::cin >> input;
    }
    return 0;
}