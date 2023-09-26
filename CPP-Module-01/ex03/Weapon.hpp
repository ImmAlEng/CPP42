/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:48 by iengels           #+#    #+#             */
/*   Updated: 2023/09/26 18:39:02 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
    private:
        std::string type;
        
    public:
        Weapon(std::string name);
        Weapon();
        ~Weapon();

        const std::string& Weapon::getType()  const;
        void setType(const std::string type);
};

#endif