/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:18:35 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 12:04:40 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


#define SIZE 10

int main(void)
{
    Array<float> test;

    Array<int>intArray(SIZE);
    Array<int>intArray2(SIZE - 5);
    
    for (unsigned int i = 0; i < intArray.size(); i++)
        intArray[i] = i * 2;
    
    std::cout << "intArray: " << intArray << std::endl;

    intArray2 = intArray;

    std::cout << "intArray2: " << intArray2 << std::endl;
    
    try
    {
        std::cout << "Accessing valid index: " << intArray[3] << std::endl;
        std::cout << "Accessing invalid index: " << intArray[SIZE] << std::endl;
    }
    catch(Array<int>::OutOfBoundsException& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}