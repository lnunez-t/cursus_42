/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:12:14 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 10:26:13 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void swap(T& a, T& b)
{
    T c = a;
    a = b;
    b = c;
}

template <typename T>
T max(T& a, T& b)
{
    return (a > b ? a : b);
}

template <typename T>
T min(T& a, T& b)
{
    return (a < b ? a : b);
}

#endif