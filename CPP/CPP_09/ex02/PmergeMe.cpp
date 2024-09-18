/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:04 by laura             #+#    #+#             */
/*   Updated: 2024/09/18 17:37:30 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> > () {return ("vector<int>");}

template <>
std::string getContainerName<std::deque<int> > () {return ("deque<int>");}

template <typename T>
PmergeMe<T>::PmergeMe() : data(), last(-1), time(0) {}

template <typename T>
PmergeMe<T>::PmergeMe(char **data) : data()
{
    time = 0;
    last = -1;

    for (size_t i = 0; data[i]; i++)
    {
        if (!isValid(data[i]))
            throw(std::invalid_argument("Error : not a valid number"));
        _data.push_back(ft_stoa(data[i]));
    }
}

template <typename T>
PmergeMe<T>::~PmergeMe() {}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& cpy)
{
    _data = cpy._data;
}

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe& oth)
{
    if (this != &oth)
    {
        this->_data = oth._data;
        this->last = oth.last;
        this->time = oth.time;
    }
    return (*this);
}

template <typename T>
void PmergeMe<T>::sort()
{
    
}

template <typename T>
void PmergeMe<T>::print_vec()
{
    for (int v : vect)
        std::cout << v << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::time_usage()
{
    std::cout << "Time to process a range of " << << " elements with std::[...] : " << time << " us";
}

