/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:19:38 by iengels           #+#    #+#             */
/*   Updated: 2023/11/09 17:04:41 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"
#include <stdint.h>
#pragma once

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &copy);
        ~Serializer();

        Serializer &operator=(const Serializer &copy);
        
    public:
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);

};

#endif
