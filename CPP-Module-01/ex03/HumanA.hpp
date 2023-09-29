/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:38 by iengels           #+#    #+#             */
/*   Updated: 2023/09/29 15:24:43 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#pragma once

class HumanA
{

private:
    Weapon weapon;
    std::string name;

public:
    HumanA(std::string name, Weapon weapon);
    HumanA(void);
    ~HumanA();
    void attack();
    void setWeapon(Weapon weapon);
};

#endif