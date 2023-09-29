/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:42 by iengels           #+#    #+#             */
/*   Updated: 2023/09/29 15:25:44 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# pragma once

class HumanB
{
    private:
        Weapon weapon;
        std::string name;

    public:
        HumanB(std::string name);
        HumanB(void);
        ~HumanB();
        void attack();
        void setWeapon(Weapon weapon);
};

#endif