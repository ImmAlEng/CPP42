/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 17:39:38 by iengels           #+#    #+#             */
/*   Updated: 2023/09/26 18:39:44 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA
{

    private:
        Weapon _weapon;
        std::string name;

    public:
        HumanA();
        HumanA();
        ~HumanA();
        std::string gettype();
        void settype();

};

#endif