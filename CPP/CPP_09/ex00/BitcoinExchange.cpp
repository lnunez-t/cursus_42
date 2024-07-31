/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:28:02 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/07/31 14:35:14 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    std::ifstream file("data.csv");

    if (file)
    {
        std::string line;
        std::getline(file, line);
        while (std::getline(file, line))
        {
            size_t delim;
            delim = line.find(',');
            std::string date = trim(line.substr(0, delim));
            std::string value = trim(line.substr(delim + 1, line.length()));
            
            data[date] = value;
        }
        
        file.close();
    }
    else
        std::cerr << "File could not be opened" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
    *this = cpy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& cpy)
{
    if (this != &cpy)
        data = cpy.data;
    return (*this);
}

void run(const std::string &filename)
{
    
}