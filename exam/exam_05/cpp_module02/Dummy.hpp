/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dummy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:22:31 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:23:37 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DUMMY_HPP
# define DUMMY_HPP

# include <iostream>
# include "ATarget.hpp"

class Dummy : public ATarget
{
    public:
        Dummy();
        ~Dummy();
        ATarget* clone() const;
};

#endif