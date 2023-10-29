/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 01:05:58 by iengels           #+#    #+#             */
/*   Updated: 2023/10/29 10:51:01 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#pragma once

class Cure : public AMateria
{
    public:
        Cure(void);
        Cure(Cure const &copy);
        ~Cure(void);

        Cure &operator= (Cure const &copy);
};

#endif
