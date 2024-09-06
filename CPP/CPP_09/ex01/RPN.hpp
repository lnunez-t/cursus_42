/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:21:29 by laura             #+#    #+#             */
/*   Updated: 2024/09/06 08:44:52 by laura            ###   ########.fr       */
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
    std::stack<int> _stack;

    typedef int (RPN::*func)(int, int);
    struct do_op {
      std::string op;
      func f;  
    };
    
    do_op ops[5];
    
    int add(int a, int b);
    int sub(int a, int b);
    int mult(int a, int b);
    int div(int a, int b);
    int pow(int a, int b);

    int _index(std::string str, std::string *arr, int size);
    int ft_stoi(const std::string& str);
    std::string ft_all(const std::string& str, int (*isDigit)(int));
    
public:
    RPN();
    RPN(const RPN& cpy);
    RPN& operator=(const RPN& oth);
    ~RPN();

    void run(std::string str);
};



#endif