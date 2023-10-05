/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:33:53 by iengels           #+#    #+#             */
/*   Updated: 2023/10/03 19:42:03 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap st("Scav");
    ScavTrap sp = st;

    st.takeDamage(60);
    st.beRepaired(1);
    std::cout << std::endl;
    sp.guardGate();
    std::cout << std::endl;
    for (int i = 0; i < 50; i++){
        st.attack("someone");
    }
    st.beRepaired(10);
    st.guardGate();
    st.attack("someone");
    st.takeDamage(60);
    st.attack("someone");
    st.guardGate();
    st.takeDamage(10);

    return 0;
}