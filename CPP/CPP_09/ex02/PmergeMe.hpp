/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:01 by laura             #+#    #+#             */
/*   Updated: 2024/09/18 17:25:24 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <ctime>
# include <sstream>
# include <algorithm>

template <typename T>
class PmergeMe
{
public:
    typedef typename T::val_type val_type;
    typedef typename T::size_type size_type;
    typedef std::pair <val_type, val_type> type_pair;
    typedef std::vector<type_pair> vect;
private:
    T _data;
    double time;
    val_type last;

    bool isValid(const std::string& str);
    int ft_stoa(const char *str);
public:
    PmergeMe();
    explicit PmergeMe(char **data);
    PmergeMe(const PmergeMe& cpy);
    PmergeMe& operator=(const PmergeMe &oth);
    ~PmergeMe();
    
    void sort();
    void print_vec();
    void time_usage();
};



#endif