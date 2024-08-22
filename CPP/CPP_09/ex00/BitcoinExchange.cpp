/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 12:28:02 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/22 15:08:45 by lnunez-t         ###   ########.fr       */
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

int BitcoinExchange::ft_stoi(const std::string& str)
{
    std::stringstream ss(str);
    int value;

    ss >> value;

    return (value);
}

double BitcoinExchange::ft_stod(const std::string& str)
{
    std::stringstream ss(str);
    double value;

    ss >> value;
    return (value);
}

std::string BitcoinExchange::ft_tostr(int value)
{
    std::stringstream ss;

    ss << value;

    return (ss.str());    
}

std::string BitcoinExchange::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return (str);
    
    size_t last = str.find_last_not_of(' ');
    return (str.substr(first, (last - first + 1)));
}

void BitcoinExchange::validValue(const std::string& str)
{
    double value;

    try
    {
        if (std::find(str.begin(), str.end(), '.') != str.end())
        {
            size_t decPoint = str.find('.');
            std::string::const_iterator it = std::find(str.begin() + decPoint + 1, str.end(), '.');
            if (it != str.end())
                throw std::invalid_argument("Too many decimal points");
        }
        bool hasSign = str[0] == '+' || str[0] == '-';
        for (size_t i = hasSign ? 1 : 0; i < str.length(); i++)
        {
            if (::isdigit(str[i]) || str[i] == '.')
                continue;
            throw std::invalid_argument(str + "is not a number");
        }
        value = ft_stod(str);
    }
    catch(const std::exception& e)
    {
        throw std::invalid_argument(str + "is not a number");
    }
    if (value < 0)
        throw std::invalid_argument("not a positive number");
    if (value > 1000.0)
        throw std::invalid_argument("number too high");
}

bool BitcoinExchange::validFile(const std::string& filename)
{
    std::fstream file(filename.c_str());

    bool exists = file.good();
    file.close();
    
     return (exists);
}

bool BitcoinExchange::emptyFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    bool isEmpty = file.peek() == std::ifstream::traits_type::eof();

    file.close();
    return (isEmpty);    
}

bool BitcoinExchange::validDate(const std::string& date)
{
    if (date.length() != 10)
        return (false);
    if (date[4] != '-' || date[7] != '-')
        return (false);
        
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    if (!ft_alldigit(year, &::isdigit) 
        || !ft_alldigit(month, &::isdigit)
        || !ft_alldigit(day, &::isdigit))
        return (false);
    
    int yearInt, monthInt, dayInt;
    std::stringstream ssYear(year);
    std::stringstream ssMonth(month);
    std::stringstream ssDay(day);
    
    ssYear >> yearInt;
    ssMonth >> monthInt;
    ssDay >> dayInt;

    if (yearInt < 2009 || yearInt > 2022 || monthInt < 1 || monthInt > 12
        || dayInt < 1 || dayInt > 31)
        return (false);
    
    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) 
        && dayInt > 30)
        return (false);
    
    if (monthInt == 2)
    {
        bool leapYear = isLeapYear(yearInt);
        if (dayInt > (leapYear ? 29 : 28))
            return (false);
    }
    return (true);
}

std::string BitcoinExchange::prevDate(const std::string& date)
{
    int year = ft_stoi(date.substr(0, 4));
    int month = ft_stoi(date.substr(5, 2));
    int day = ft_stoi(date.substr(8, 2));

    int daysMonth[] = {0, 30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear(year))
        daysMonth[2] = 29;

    day--;
    
    if (day == 0)
    {
        month--;
        if (month == 0)
        {
            month = 12;
            year--;
        }
        day = daysMonth[month];
    }
    
    
    std::string prevYear = ft_tostr(year);
    std::string prevMonth = (month < 10) ? "0" + ft_tostr(month) : ft_tostr(month);
    std::string prevDay = (day < 10) ? "0" + ft_tostr(day) : ft_tostr(day);
    
    return (prevYear + "-" + prevMonth + "-" + prevDay);
}

std::string BitcoinExchange::nextDate(const std::string& date)
{
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);

    int yearInt = ft_stoi(year);
    int monthInt = ft_stoi(month);
    int dayInt = ft_stoi(day);

    int daysMonth[] = {0, 30, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    if (isLeapYear(yearInt))
        daysMonth[2] = 29;

    dayInt++;
    
    if (dayInt > daysMonth[monthInt])
    {
        dayInt = 1;
        monthInt++;
    }

    if (monthInt > 12)
    {
        monthInt = 1;
        yearInt++;
    }
    
    std::string nextYear = ft_tostr(yearInt);
    std::string nextMonth = (monthInt < 10) ? "0" + ft_tostr(monthInt) : ft_tostr(monthInt);
    std::string nextDay = (dayInt < 10) ? "0" + ft_tostr(dayInt) : ft_tostr(dayInt);
    
    return (nextYear + "-" + nextMonth + "-" + nextDay);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 10 != 0) || year % 400 == 0);
}

bool BitcoinExchange::ft_alldigit(const std::string& str, int (*isdigit)(int))
{
    for (size_t i = 0; i < str.length(); i++)
        if (!isdigit(str[i]))
            return (false);
    return (true);
}

void BitcoinExchange::run(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    std::string line;

    if (!file.is_open())
    {
        std::cout << "Error : file does not exist" << std::endl;
        exit (1);
    }

    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cout << "Error : file is empty" << std::endl;
        exit (1);
    }

    std::getline(file, line);
    if (line != "date | value")
    {
        std::cout << "Error : invalid file format" << std::endl;
        exit (1);
    }
    
    while (std::getline(file, line))
    {
        size_t delim = line.find('|');
        if (delim == std::string::npos)
        {
            std::cout << "Error : bad input : " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, delim));
        std::string value = trim(line.substr(delim + 1));

        try
        {
            if (!validDate(date))
                throw std::invalid_argument("invalid date: " + (date.empty() ? "\"\"" : "'" + date + "'"));
            if (value.empty())
                throw std::invalid_argument("invalid value: " + (value.empty() ? "\"\"" : "'" + value + "'"));
            validValue(value);

            std::map<std::string, std::string>::iterator it;
            std::string previousDate = date;
            it = data.find(date);

            while (it == data.end())
            {
                const std::string& currentDate = previousDate;
                previousDate = prevDate(currentDate);
                it = data.find(previousDate);
            }

            std::cout << date << " => " << value << " = " << ft_stod(it->second) * ft_stod(value) << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        
    }

    file.close();
}