/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TargetGenerator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnunez-t <lnunez-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 16:23:27 by lnunez-t          #+#    #+#             */
/*   Updated: 2024/08/19 16:30:04 by lnunez-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TARGETGENERATOR_HPP
# define TARGETGENERATOR_HPP

# include <iostream>
# include "ATarget.hpp"
# include <map>

class TargetGenerator
{
    private:
        TargetGenerator(const TargetGenerator& cpy);
        TargetGenerator& operator=(const TargetGenerator& oth);
        std::map<std::string, ATarget*> _target;
    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget*);
        void forgetTargetType(std::string const &);
        ATarget* createTarget(std::string const &);
        
};

#endif