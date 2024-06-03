/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 08:47:45 by laura             #+#    #+#             */
/*   Updated: 2024/06/01 08:57:13 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Use : ./Sed <filename> <s1> <s2>." << std::endl;
        return (EXIT_FAILURE);
    }
    else
    {
        
    }

    return (EXIT_SUCCESS);
}