/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrickWall.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:46:42 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 15:47:14 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRICKWALL_HPP
# define BRICKWALL_HPP

# include <iostream>
# include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
        BrickWall();
        ~BrickWall();
        ATarget* clone() const;
};

#endif