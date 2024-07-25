/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:05:04 by laura             #+#    #+#             */
/*   Updated: 2024/07/24 16:04:23 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <fstream>

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
    char c;
    int n;
    float f;
    double d;

    bool impossible;

    std::string str;
    e_type type;
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter& cpy);
    ~ScalarConverter();

    ScalarConverter& operator=(const ScalarConverter& cpy);

    void convert(void);

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

    bool isImpossible(void);
    
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