/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:22:14 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 15:06:25 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>

template <typename T>
void easyfind(T& a, int b)
{
    if (std::find(a.begin(), a.end(), b) != a.end())
        std::cout << "Number found" << std::endl;
    else
        std::cout << "Number not found" << std::endl;
}


#endif