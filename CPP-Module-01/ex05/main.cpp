/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:28:41 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 22:29:36 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl Test;

	Test.complain("DEBUG");
	Test.complain("INFO");
	Test.complain("WARNING");
	Test.complain("ERROR");
	return (0);
}
