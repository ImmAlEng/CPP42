/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 08:44:59 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 15:03:33 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#pragma once


class MateriaSource : public IMateriaSource
{
    private:
        AMateria *materiabook[4];
    public:
        MateriaSource(void);
        ~MateriaSource();
        MateriaSource(MateriaSource const &copy);
        
        MateriaSource &operator=(MateriaSource const &copy);
        
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
};

#endif
