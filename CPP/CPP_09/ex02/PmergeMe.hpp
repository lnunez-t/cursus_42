/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:01 by laura             #+#    #+#             */
/*   Updated: 2024/09/21 15:18:59 by lnunez-t         ###   ########.fr       */
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
    T _data; //contient les donnees
    value_type last; //garde une trace du dernier element si nb impair d elements
    double time; //temps pris pour le tri

    bool isValid(const std::string& str);
    int ft_stoa(const char *str);
    int_vect index(size_t n);
    vect pairs(T &data);
    void sort_pairs(vect &pairs);
    int bin_search(int target);
public:
    PmergeMe();
    explicit PmergeMe(char **data); //explicit empeche la conversion implicite du compilateur de data en objet PmergeMe, plus securise car evite des conversions accidentelles
    PmergeMe(const PmergeMe& cpy);
    PmergeMe& operator=(const PmergeMe &oth);
    ~PmergeMe();
    
    void sort();
    void print_vec() const;
    void time_usage() const;
};



#endif