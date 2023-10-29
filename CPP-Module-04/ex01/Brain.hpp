/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 23:03:47 by iengels           #+#    #+#             */
/*   Updated: 2023/10/28 23:23:27 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#pragma once

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain(void);
        ~Brain();
        Brain(Brain const& copy);

        Brain& operator=(Brain const &copy);
};

#endif