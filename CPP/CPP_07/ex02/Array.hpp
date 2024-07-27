/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laura <laura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:19:50 by laura             #+#    #+#             */
/*   Updated: 2024/07/27 11:55:59 by laura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
    private:
        T* array;
        unsigned int _size;
    
    public:
        Array(void) : array(new T()), _size(0) {};
        Array(unsigned int n) : array(new T[n]), _size(n) {};
        Array(const Array& cpy) : array(new T[cpy.size()]), _size(cpy.size())
        {
            for (unsigned int i = 0; i < _size; i++)
                array[i] = cpy.array[i];
        };
        
        Array& operator=(const Array& cpy)
        {
            if (this != &cpy)
            {
                delete [] array;
                array = new T[cpy.size()];
                _size = cpy._size;
                for (unsigned int i = 0; i < _size; i++)
                    array[i] = cpy.array[i];
            }
            return (*this);
        };

        T& operator[](unsigned int i) const
        {
            if (i >= _size)
                throw OutOfBoundsException();
            return (array[i]);
        };

        unsigned int size(void) const
        {
            return (_size);
        };

        ~Array(void) {delete [] array;};

        class OutOfBoundsException : public std::exception
        {
            public :
                virtual const char* what() const throw()
                {
                    return ("Index is out of bounds");
                }
        };
        
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Array<T>& array)
{
    for (unsigned int i = 0; i < array.size(); i++)
        out << array[i] << " ";
    return out;
}

#endif