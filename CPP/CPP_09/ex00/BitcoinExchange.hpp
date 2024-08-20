/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:28:39 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/20 13:23:32 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <sstream>
# include <algorithm>

typedef std::string str;

class BitcoinExchange
{
    private:
        std::map<std::string, std::string> data;
        
        std::string prevDate(const std::string& date);
        std::string nextDate(const std::string& date);
        std::string trim(const std::string& str);

        void validValue(const std::string& str);
        bool validFile(const std::string& filename);
        bool emptyFile(const std::string& filename);
        bool validDate(const std::string& date);
        bool isLeapYear(int year);
        bool ft_alldigit(const std::string& str, int (*isdigit)(int));

        int ft_stoi(const std::string& str);
        double ft_stod(const std::string& str);
        std::string ft_tostr(int value);
        
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& cpy);
        BitcoinExchange& operator=(const BitcoinExchange& cpy);

        void run(const std::string &filename);
};

#endif