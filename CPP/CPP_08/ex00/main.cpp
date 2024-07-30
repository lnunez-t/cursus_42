/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:21:58 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 15:06:06 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> vect(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int> list(arr, arr + sizeof(arr) / sizeof(int));

    easyfind(vect, std::atoi(av[1]));
    easyfind(list, std::atoi(av[1]));

    return (0);
}