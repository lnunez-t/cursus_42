/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:59:51 by laura             #+#    #+#             */
/*   Updated: 2024/07/10 13:04:47 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain(const Brain& cpy);
    Brain& operator=(const Brain& rhs);
};


#endif