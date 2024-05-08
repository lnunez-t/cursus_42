/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:59:12 by laura             #+#    #+#             */
/*   Updated: 2024/04/27 16:49:07 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **argv)
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; argv[i]; i++) {
            for (int j = 0; argv[i][j]; j++)
                std::cout << (char) toupper(argv[i][j]);
            if (i < ac - 1)
                std::cout << ' ';
        }
    }
    std::cout << std::endl;
    return (0);
}