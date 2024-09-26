/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:21:15 by laura             #+#    #+#             */
/*   Updated: 2024/09/23 15:41:47 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() 
{
    this->ops[0].op = "+";
    this->ops[0].f = &RPN::add;
    this->ops[1].op = "-";
    this->ops[1].f = &RPN::sub;
    this->ops[2].op = "*";
    this->ops[2].f = &RPN::mult;
    this->ops[3].op = "/";
    this->ops[3].f = &RPN::div;
    this->ops[4].op = "^";
    this->ops[4].f = &RPN::pow;
}

RPN::RPN(const RPN& cpy)
{
    *this = cpy;
}

RPN& RPN::operator=(const RPN& oth)
{
    if (this != &oth)
    {
        this->_stack = oth._stack;
    }
    return (*this);
}

RPN::~RPN() {}

void RPN::run(std::string str)
{
    std::stringstream ss(str);
    std::string op[] = {"+", "-", "*", "/", "^"};

    try{
        while (ss >> str)
        {
            int index = _index(str, op, 5);
            if (index != -1)
            {
                if (this->_stack.size() < 2)
                    throw (std::invalid_argument("Not enough operands"));
                
                float a = this->_stack.top();
                this->_stack.pop();
                float b = this->_stack.top();
                this->_stack.pop();

                this->_stack.push((this->*ops[index].f)(b, a));
            
            }
            else
                this->_stack.push(ft_stof(ft_all(str, &std::isdigit)));
            
        }
        
        if (this->_stack.size() != 1)
            throw (std::invalid_argument("too many operands"));
        
        std::cout << this->_stack.top() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Error" << std::endl;
    }
    ss.clear();
}

float RPN::add(float a, float b)
{
    return (a + b);
}

float RPN::sub(float a, float b)
{
    return (a - b);
}

float RPN::mult(float a, float b)
{
    return (a * b);
}

float RPN::div(float a, float b)
{
    if (b == 0)
        throw (std::invalid_argument("Division by zero"));
    
    return (static_cast<float>(a) / b);
}

float RPN::pow(float a, float b)
{
    return (std::pow(a, b));
}

int RPN::_index(std::string str, std::string *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (str == arr[i])
            return i;
    }
    
    return (-1);
}

float RPN::ft_stof(const std::string& str)
{
    std::stringstream ss(str);
    float result;

    ss >> result;

    if (ss.fail())
        throw(std::invalid_argument("conversion failed"));
    
    return (result);
}

std::string RPN::ft_all(const std::string& str, int (*isDigit)(int))
{
    bool valid = true;
    size_t i = 0;

    if (str.length() == 1 && (str[0] == '+' || str[0] == '-'))
        valid = false;

    if (str.length() == 0)
        valid = false;
    
    if (str[0] == '+' || str[0] == '-')
        i = 1;

    for (; i < str.length(); i++)
    {
        if (!isDigit(str[i]))
            valid = false;
    }

    if (!valid)
        throw (std::invalid_argument("not a number"));
    return (str);
}