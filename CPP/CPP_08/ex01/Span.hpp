/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:11:32 by laura             #+#    #+#             */
/*   Updated: 2024/07/30 13:54:11 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>
# include <exception>

class Span
{
private:
    std::list<int> _list;
    unsigned int N;

    Span(void);
public:
    Span(unsigned int N);
    Span(const Span& cpy);
    ~Span();

    Span& operator=(const Span& cpy);

    void addNumber(int nb);
    unsigned int shortestSpan();
    unsigned int longestSpan();
};


#endif