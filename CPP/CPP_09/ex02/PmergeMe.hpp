/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:01 by laura             #+#    #+#             */
/*   Updated: 2024/09/19 15:28:50 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <sstream>
# include <iomanip>

typedef std::vector<int> int_vect;

template <typename T>
class PmergeMe
{
public:
    typedef typename T::value_type value_type;
    typedef typename T::size_type size_type;
    typedef std::pair <value_type, value_type> type_pair;
    typedef std::vector<type_pair> vect;
private:
    T _data;
    value_type last;
    double time;

    bool isValid(const std::string& str);
    int ft_stoa(const char *str);
    int_vect index(size_t n);
    vect pairs(T &data);
    void sort_pairs(vect &pairs);
    int bin_search(int target);
public:
    PmergeMe();
    explicit PmergeMe(char **data);
    PmergeMe(const PmergeMe& cpy);
    PmergeMe& operator=(const PmergeMe &oth);
    ~PmergeMe();
    
    void sort();
    void print_vec() const;
    void time_usage() const;
};



#endif