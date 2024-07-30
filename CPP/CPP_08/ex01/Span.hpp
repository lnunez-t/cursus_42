/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:11:32 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 15:18:51 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>

class Span
{
private:
    unsigned int N;
public:
    Span(unsigned int N);
    ~Span();

    void addNumber(int nb);
    void shortestSpan();
    void longestSpan();
};


#endif