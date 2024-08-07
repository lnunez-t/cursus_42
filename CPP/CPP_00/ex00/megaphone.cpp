/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:59:12 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 07:18:24 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **argv)
{
    int i = 1;
    int j = 0;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        while (argv[i]) 
        {
            while (argv[i][j])
            {
                std::cout << (char) toupper(argv[i][j]);
                j++;
            }
            if (i < ac - 1)
                std::cout << ' ';
            i++;
        }
    }
    std::cout << std::endl;
    return (0);
}