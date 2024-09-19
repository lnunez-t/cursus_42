/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:04 by laura             #+#    #+#             */
/*   Updated: 2024/09/19 15:21:57 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> > () {return ("vector<int>");}

template <>
std::string getContainerName<std::deque<int> > () {return ("deque<int>");}

template <typename T>
PmergeMe<T>::PmergeMe() : _data(), last(-1), time(0) {}

template <typename T>
PmergeMe<T>::PmergeMe(char **data) : _data()
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
int_vect PmergeMe<T>::index(size_t n)
{
    int_vect inds;
    int v[n + 1];

    v[0] = 0;
    v[1] = 1;
    int last_v = 2;

    for (size_t i = 2; inds.size() < n; i++)
    {
        v[i] = v[i - 1] + 2 * v[i - 2];
        i != 2 ? inds.push_back(v[i]) : (void)0;

        for (int j = v[i] - 1; j > last_v; j++)
        {
            inds.push_back(j);
        }
        
        last_v = v[i];
    }

    return (inds);
}

template <typename T>
typename PmergeMe<T>::vect PmergeMe<T>::pairs(T &data)
{
    vect pairs;

    if (data.size() % 2 == 0)
    {
        last = data.back();
        data.pop_back();
    }

    for (size_type i = 0; i < data.size(); i += 2)
    {
        if (data[i] < data[i + 1])
            std::swap(data[i], data[i + 1]);
        pairs.push_back(std::make_pair(data[i], data[i + 1]));
    }

    return (pairs);
}

template <typename T>
void PmergeMe<T>::sort_pairs(vect &pairs)
{
    if (pairs.size() <= 1)
        return ;
    size_type middle = pairs.size() / 2;
    vect left(pairs.begin(), pairs.begin() + middle);
    vect right(pairs.begin() + middle, pairs.end());

    sort_pairs(left);
    sort_pairs(right);

    size_type leftInd = 0;
    size_type rightInd = 0;
    size_type ind = 0;

    while (leftInd < left.size() && rightInd < right.size())
        pairs[ind++] = left[leftInd].first < right[rightInd].first ? left[leftInd++] : right[rightInd++];
    
    while (leftInd < left.size())
        pairs[ind++] = left[leftInd++];
    
    while (rightInd < right.size())
        pairs[ind++] = right[rightInd++];
}

template <typename T>
int PmergeMe<T>::bin_search(int target)
{
    int left = 0;
    int right = _data.size() - 1;

    while (left <= right)
    {
        int middle = (right + left) / 2;

        if (_data[middle] == target)
            return (middle);
        else if (_data[middle] < target)
            left = middle + 1;
        else if (_data[middle] > target)
            right = middle - 1;
    }

    return (left);
}


template <typename T>
void PmergeMe<T>::sort()
{
    std::clock_t start = std::clock();
    vect v_pairs = pairs(_data);
    int_vect insertIndex = index(_data.size()); 

    if (v_pairs.size() == 0)
    {
        _data.push_back(last);
        time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
        return ;
    }

    sort_pairs(v_pairs);
    
    _data.clear();
    _data.push_back(v_pairs[0].second);
    for (size_type i = 0; i < v_pairs.size(); i++)
        _data.push_back(v_pairs[i].first);
    
    for (size_t i = 0; i < insertIndex.size(); i++)
    {
        if (size_t(insertIndex[i] - 1) >= v_pairs.size())
            continue;
        int index = bin_search(v_pairs[insertIndex[i] - 1].second);
        _data.insert(_data.begin() + index, v_pairs[insertIndex[i] - 1].second);
    }

    if (last != -1)
    {
        int index = bin_search(last);
        _data.insert(_data.begin() + index, last);
    }

    time = static_cast<double>(std::clock() - start) / CLOCKS_PER_SEC;
}

template <typename T>
void PmergeMe<T>::print_vec() const
{
    for (size_t i = 0; i < _data.size(); i++)
        std::cout << _data[i] << " ";
    std::cout << std::endl;
}

template <typename T>
void PmergeMe<T>::time_usage() const
{
    std::cout << "Time to process a range of " << _data.size() << " elements with std::" << getContainerName<T>() << " : " << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

template <typename T>
bool PmergeMe<T>::isValid(const std::string& str)
{
    if (str.empty() || str[0] == '-')
        return (false);
    size_t i = 0;
    if (str[0] == '+' && str.length() == 1)
        return (false);
    else if (str[0] == '+')
        i++;
    for (; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]))
            return (false);
    }
    return (true);
}

template <typename T>
int PmergeMe<T>::ft_stoa(const char *str)
{
    std::istringstream ss(str);
    int value;

    ss >> value;

    return (value);
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;


