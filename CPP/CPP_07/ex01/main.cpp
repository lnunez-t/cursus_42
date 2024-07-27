/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:28:02 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 11:10:55 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
    int arr1[] = {1, 2, 3, 4, 5};
    size_t N = 5;

    std::cout << "arr1: " << std::endl;
    iter(arr1, N, &print);

    double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};

    std::cout << std::endl;
    std::cout << "arr2: " << std::endl;
    iter(arr2, N, &print);

    char arr3[] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << std::endl;
    std::cout << "arr3: " << std::endl;
    iter(arr3, N, &print);

    std::string arr4[] = {"one", "two", "three", "four", "five"};
    std::cout << std::endl;
    std::cout << "arr4: " << std::endl;
    iter(arr4, N, &print);

    return (0);
    
}