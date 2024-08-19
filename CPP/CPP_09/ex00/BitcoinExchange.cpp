/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:28:02 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 18:31:38 by lnunez-t         ###   ########.fr       */
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
            size_t delim = line.find(',');
            std::string date = trim(line.substr(0, delim));
            std::string value = trim(line.substr(delim + 1, line.length()));
            
            data[date] = value;
        }
        
        file.close();
    }
    else
        std::cerr << "File could not be opened" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {}

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

int ft_stoi(const std::string& str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    return (value);
}

double ft_stod(const std::string& str)
{
    std::stringstream ss(str);
    double value;

    ss >> value;
    return (value);
}

std::string ft_tostr(int value)
{
    std::stringstream ss;

    ss << value;

    return (ss.str());    
}

std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return (str);
    
    size_t last = str.find_last_not_of(' ');
    return (str.substr(first, (last - first + 1)));
}

void validValue(const std::string& str)
{
    double value;

    try
    {
        if (std::find(str.begin(), str.end(), '.') != str.end())
        {
            size_t decPoint = str.find('.');
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

bool validFile(const std::string& filename)
{
    std::fstream file(filename);

    bool exists = file.good();
    file.close();
    
     return (exists);
}

bool emptyFile(const std::string& filename)
{
    std::ifstream file(filename);

    bool isEmpty = file.peek() == std::ifstream::traits_type::eof();

    file.close();
    return (isEmpty);    
}

std::string prevDate(const std::string& date)
{
    
}

std::string nextDate(const std::string& date)
{
    
}

bool validDate(const std::string& date);

bool isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 10 != 0) || year % 400 == 0);
}

bool ft_alldigit(const std::string& str, int (*isdigit)(int))
{
    for (size_t i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

void run(const std::string &filename)
{
    
}