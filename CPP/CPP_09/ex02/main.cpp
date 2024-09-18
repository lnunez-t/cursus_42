/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:08 by laura             #+#    #+#             */
/*   Updated: 2024/09/18 16:14:44 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "Error: bad number of arguments" << std::endl;
        return (1);
    }
    
    try{
        PmergeMe<std::vector <int> > v(av + 1);
        
        std::cout << "Before:\t"; 
        v.print_vec();

        v.sort();

        PmergeMe<std::deque <int> > dq(av + 1);

        dq.sort();
        
        std::cout << "After:\t"; 
        dq.print_vec();

        v.time_usage();
        dq.time_usage();
        
    } catch(const std::exception& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}