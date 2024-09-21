/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:16:04 by laura             #+#    #+#             */
/*   Updated: 2024/09/21 15:30:02 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//Obtenir les noms respectifs des conteneurs utilises
template <typename T>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> > () {return ("vector<int>");}

template <>
std::string getContainerName<std::deque<int> > () {return ("deque<int>");}

template <typename T>
PmergeMe<T>::PmergeMe() : _data(), last(-1), time(0) {}

//Verifie la validite des entrees avant de les convertir en entier et de les inserer dans le conteneur
template <typename T>
PmergeMe<T>::PmergeMe(char **data) : _data()
{
    time = 0;
    last = -1;

    for (size_t i = 0; data[i]; i++)
    {
        if (!isValid(data[i]))
            throw(std::invalid_argument("Error"));
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

//Genere une sequence d indices bases sur la formule de Jacobsthal. Il determine les positions d insertion des paires une fois triees
template <typename T>
int_vect PmergeMe<T>::index(size_t n)
{
    int_vect inds;
    int v[n + 1];

    v[0] = 0; //condition initiale
    v[1] = 1; //condition initiale
    int last_v = 2;

    for (size_t i = 2; inds.size() < n; i++)
    {
        v[i] = v[i - 1] + 2 * v[i - 2]; //relation de recurrence de Jacobsthal
        i != 2 ? inds.push_back(v[i]) : (void)0;

        for (int j = v[i] - 1; j > last_v; j--)
        {
            inds.push_back(j); //insertion des indices intermediaires entre deux indices de la suite
        }
        
        last_v = v[i];
    }

    return (inds);
}

//Separe le conteneur en paires de valeurs. Si nb impair, dernier element = last, chaque paire contient le plus grand element en premier
template <typename T>
typename PmergeMe<T>::vect PmergeMe<T>::pairs(T &data)
{
    vect pairs;

    if (data.size() % 2 != 0)
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

//Tri recursif (tri par fusion) sur chaque paire en se basant sur la premiere valeur de chaque paire
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

//Recherche binaire dans data pour trouver la position d insertion de l element target. Si valeur n existe pas, retourne l index ou elle devrait etre inseree pour maintenir le tri
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

//Divise les donnees en paires, trie les paires, insere les paires au bon index avec recherche binaire, mesure le temps de process
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

//Affiche le contenu de data
template <typename T>
void PmergeMe<T>::print_vec() const
{
    for (size_t i = 0; i < _data.size(); i++)
        std::cout << _data[i] << " ";
    std::cout << std::endl;
}

//Affiche le temps de process selon le conteneur utilise
template <typename T>
void PmergeMe<T>::time_usage() const
{
    std::cout << "Time to process a range of " << _data.size() << " elements with std::" << getContainerName<T>() << " : " << std::fixed << std::setprecision(5) << time << " us" << std::endl;
}

//Verifie si la chaine donnee contient des entiers positifs
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

//Convertit une chaine de caracteres en entier
template <typename T>
int PmergeMe<T>::ft_stoa(const char *str)
{
    std::istringstream ss(str);
    int value;

    ss >> value;

    return (value);
}

//Instancie des objets de type vector et deque
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;


