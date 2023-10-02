/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 20:55:55 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 20:18:27 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie(std::string name);
        Zombie(void);
        ~Zombie();
        void    give_name(std::string name);
        void    announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif
