/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:05:18 by laura             #+#    #+#             */
/*   Updated: 2024/08/22 14:54:51 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char ScalarConverter::c;
long ScalarConverter::n;
float ScalarConverter::f;
double ScalarConverter::d;
std::string ScalarConverter::str;
e_type ScalarConverter::type;
bool ScalarConverter::impossible;

ScalarConverter::ScalarConverter(void)
{
    this->c = '\0';
    this->n = 0;
    this->f = 0.0f;
    this->d = 0.0;
}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
    *this = cpy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy)
{
    if (this != &cpy)
    {
        this->n = cpy.getI();
        this->f = cpy.getF();
        this->c = cpy.getC();
    }
    return (*this);
}

char ScalarConverter::getC(void) const
{
    return (this->c);
}

void ScalarConverter::setC(char c)
{
    this->c = c;
}

bool ScalarConverter::isLiterals(void) const
{
    if (impossible || (str.compare("nan") == 0) || (str.compare("nanf") == 0)
    || (str.compare("+inf") == 0) || (str.compare("+inff") == 0)
    || (str.compare("-inf") == 0) || (str.compare("-inff") == 0))
        return (true);
    return (false);
}

void ScalarConverter::printChar(void) const
{
    long i = std::atoll(str.c_str());
    if (this->isLiterals())
        std::cout << "impossible";
    else if ((i < 32 && i >= 0) || (i == 127) || i < 0 || i > 127)
        std::cout << "Non displayable";
    else
        std::cout << "'" << getC() << "'";
    std::cout << std::endl;
}

int ScalarConverter::getI(void) const
{
    return (this->n);
}

void ScalarConverter::setI(int n)
{
    this->n = n;
}

void ScalarConverter::printInt(void) const
{
    long i = std::atoll(str.c_str());
    if (this->isLiterals() || (i > std::numeric_limits<int>::max() && i < std::numeric_limits<int>::min() && str.length() <= 10))
        std::cout << "impossible";
    else
        std::cout << getI();
    std::cout << std::endl;
}

float ScalarConverter::getF(void) const
{
    return (this->f);
}

void ScalarConverter::setF(float f)
{
    this->f = f;
}

double ScalarConverter::getD(void) const
{
    return (this->d);
}

void ScalarConverter::setD(double d)
{
    this->d = d;
}

std::string ScalarConverter::getStr(void) const
{
    return (this->str);
}

void ScalarConverter::setStr(std::string str)
{
    this->str = str;
    this->setType();
    if (getType() == NONE)
        throw ScalarConverter::ConverterException();
}

e_type ScalarConverter::getType(void) const
{
    return (this->type);
}

bool ScalarConverter::isChar(void) const
{
    return (str.length() == 1 && std::isalpha(str[0]) && std::isprint(str[0]));
}

bool ScalarConverter::isInt(void) const
{
    int j = 0;

    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i = j; i < (int) str.length(); i++)
    {
        if (!std::isdigit(str[i]) || i > 10)
            return (false);
    }
    long tmp = std::atol(str.c_str());
	if (tmp <= std::numeric_limits<int>::max() && tmp >= std::numeric_limits<int>::min())
		return (true);
	else
		return (false);
}

bool ScalarConverter::isDouble(void) const
{
    if (str.find('.') == std::string::npos || str.find('.') == 0
    || str.find('.') == str.length() - 1)
        return (false);
    int j = 0;
    int found = 0;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i = j; i < (int)str.length(); i++)
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || found > 1)
            return (false);
    }
    return (true);
}

bool ScalarConverter::isFloat(void) const
{
    if (str.find('.') == std::string::npos || str[str.size() - 1] != 'f'
    || str.find('.') == 0 || str.find('.') == str.length() - 2)
        return (false);
    int found = 0;
    int j = 0;
    if (str[j] == '-' || str[j] == '+')
        j++;
    for (int i = j; i < (int)str.length() - 1; i++)
    {
        if (str[i] == '.')
            found++;
        if ((!std::isdigit(str[i]) && str[i] != '.') || found > 1)
            return (false);
    }
    return (true);
}

void ScalarConverter::printFloat(void) const
{
    if (str.compare("nan") == 0 || str.compare("nanf") == 0)
        std::cout << "nanf";
    else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
        std::cout << "+inff";
    else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
        std::cout << "-inff";
    else if (impossible)
        std::cout << "impossible";
    else
    {
        if (f - static_cast<int>(f) == 0)
            std::cout << f << ".0f";
        else
            std::cout << getF() << "f";
    }
    std::cout << std::endl;
}

void ScalarConverter::printDouble(void) const
{
    if (str.compare("nan") == 0 || str.compare("nanf") == 0)
        std::cout << "nan";
    else if (str.compare("+inff") == 0 || str.compare("+inf") == 0)
        std::cout << "+inf";
    else if (str.compare("-inff") == 0 || str.compare("-inf") == 0)
        std::cout << "-inf";
    else if (impossible)
        std::cout << "impossible";
    else
    {
        if (d - static_cast<int>(d) == 0)
            std::cout << d << ".0";
        else
            std::cout << getD();
    }
    std::cout << std::endl;
}

void ScalarConverter::setType(void)
{
    if (isChar())
        type = CHAR;
    else if (isInt())
        type = INT;
    else if (isFloat())
        type = FLOAT;
    else if (isDouble())
        type = DOUBLE;
    else if (isLiterals())
        type = LITERALS;
    else
        type = NONE;
}

void ScalarConverter::convert(void)
{
    try
    {
        if (type == INT)
            n = std::atol(str.c_str());
        else if (type == FLOAT)
            f = static_cast<float>(std::atof(str.c_str()));
        else if (type == DOUBLE)
            d = std::atof(str.c_str());
    }
    catch(std::exception& e)
    {
        impossible = true;
    }
    impossible = false;
    if (impossible)
        return;
    switch (type)
    {
        case CHAR:
            c = str[0];
            n = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        case INT:
            n = std::atol(str.c_str());
            f = static_cast<float>(n);
            d = static_cast<double>(n);
            c = static_cast<char>(n);
            break;
        case FLOAT:
            f = static_cast<float>(std::atof(str.c_str()));
            n = static_cast<int>(f);
            d = static_cast<double>(f);
            c = static_cast<char>(f);
            break;
        case DOUBLE:
            d = std::atof(str.c_str());
            n = static_cast<int>(d);
            f = static_cast<float>(d);
            c = static_cast<char>(d);
            break;
        default:
            break;
    }
}

std::ostream& operator<<(std::ostream& out, const ScalarConverter& cpy)
{
    out << "char: "; cpy.printChar();
    out << "int: "; cpy.printInt();
    out << "float: "; cpy.printFloat();
    out << "double: "; cpy.printDouble();
    return out;
}



