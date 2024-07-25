/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 11:33:20 by laura             #+#    #+#             */
/*   Updated: 2024/07/25 14:31:55 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"
# include <string>
# include <stdint.h>

typedef std::string str;

class Serializer
{
private:
    Serializer();
    Serializer(Serializer const& src);
    ~Serializer();

    Serializer& operator=(Serializer const& cpy);
public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


#endif