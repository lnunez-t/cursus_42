/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:21:29 by laura             #+#    #+#             */
/*   Updated: 2024/09/18 16:01:27 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <cmath>

class RPN
{
private:
    std::stack<float> _stack;

    typedef float (RPN::*func)(float, float);
    struct do_op {
      std::string op;
      func f;  
    };
    
    do_op ops[5];
    
    float add(float a, float b);
    float sub(float a, float b);
    float mult(float a, float b);
    float div(float a, float b);
    float pow(float a, float b);

    int _index(std::string str, std::string *arr, int size);
    float ft_stof(const std::string& str);
    std::string ft_all(const std::string& str, int (*isDigit)(int));
    
public:
    RPN();
    RPN(const RPN& cpy);
    RPN& operator=(const RPN& oth);
    ~RPN();

    void run(std::string str);
};



#endif