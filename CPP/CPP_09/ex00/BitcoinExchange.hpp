/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:28:39 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/07/31 14:39:31 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, std::string> data;
    
    std::string prevDate(const std::string& date);
    std::string nextDate(const std::string& date);
    std::string trim(const std::string& str);

    void validValue(const std::string& str);
    bool validFile(const std::string& filename);
    bool validDate(const std::string& date);
    bool isLeapYear(const std::string& year);
    
public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& cpy);
    BitcoinExchange& operator=(const BitcoinExchange& cpy);

    void run(const std::string &filename);
};

std::ostream& operator<<(std::ostream& o, const BitcoinExchange& b)
{
    std::cout << 
}

#endif