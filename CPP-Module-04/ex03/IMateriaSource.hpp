/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 00:52:25 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:52:56 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "AMateria.hpp"

#pragma once

class IMateriaSource
{
    public:
        IMateriaSource(void);
        IMateriaSource(IMateriaSource const &copy);
        virtual ~IMateriaSource();
        
        IMateriaSource& operator= (IMateriaSource const &copy);
        
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
