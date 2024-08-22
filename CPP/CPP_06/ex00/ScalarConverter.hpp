/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:05:04 by laura             #+#    #+#             */
/*   Updated: 2024/08/22 14:06:27 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <fstream>
# include <string>
# include <cstdlib>

enum e_type
{
    NONE,
    INT,
    FLOAT,
    CHAR,
    DOUBLE,
    LITERALS
};

class ScalarConverter
{
private:
    static char c;
    static long n;
    static float f;
    static double d;

    static bool impossible;

    static std::string str;
    static e_type type;
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cpy);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& cpy);

    static void convert(void);

    char getC(void) const;
    void setC(char c);

    int getI(void) const;
    void setI(int n);

    float getF(void) const;
    void setF(float f);

    double getD(void) const;
    void setD(double d);

    std::string getStr(void) const;
    void setStr(std::string str);

    e_type getType(void) const;
    void setType(void);

    bool isChar(void) const;
    bool isInt(void) const;
    bool isFloat(void) const;
    bool isDouble(void) const;
    
    void printChar(void) const;
    void printInt(void) const;
    void printFloat(void) const;
    void printDouble(void) const;

    bool isLiterals(void) const;

    class ConverterException : public std::exception
    {
        virtual const char* what() const throw()
        {
            return ("Unknown type");
        }
    };
};

std::ostream& operator<<(std::ostream& o, const ScalarConverter& converted);



#endif