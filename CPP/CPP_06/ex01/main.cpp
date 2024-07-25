/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:29:26 by laura             #+#    #+#             */
/*   Updated: 2024/07/25 14:55:22 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
    Data* data = new Data;
    
    data->name = "lnunez-t";
    data->age = 26;

    std::cout << "Original values: " << std::endl;
    std::cout << "Name: " << data->name << std::endl;
    std::cout << "Age: " << data->age << std ::endl;

    std::cout << "Values returned after serialization and deserialization: " << std::endl;
    std::cout << "Name: " << Serializer::deserialize(Serializer::serialize(data))->name << std::endl;
    std::cout << "Age: " << Serializer::deserialize(Serializer::serialize(data))->age << std::endl;

    delete(data);

    return(0);
}