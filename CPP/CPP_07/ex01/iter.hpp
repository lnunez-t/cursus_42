/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:27:32 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 10:57:00 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T* array, size_t size, void (*f)(T &))
{
    for (size_t i = 0; i < size; i++)
        f(array[i]);
}

template <typename T>
void print(T &i)
{
    std::cout << i << std::endl;
}

#endif