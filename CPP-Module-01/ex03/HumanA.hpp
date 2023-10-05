/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:38 by iengels           #+#    #+#             */
/*   Updated: 2023/10/05 16:10:28 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#pragma once

class HumanA
{

private:
    Weapon &weapon;
    std::string name;

public:
    HumanA(std::string name, Weapon &weapon);
    ~HumanA();
    void attack();
    void setWeapon(Weapon weapon);
};

#endif
