/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:20:19 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:16:51 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#pragma once

class Intern
{
    public:
        Intern(void);
        Intern(Intern const &copy);
        ~Intern();

        Intern const &operator=(Intern const &copy);

        AForm *makeForm(const std::string &name, const std::string &target) const;
        AForm *makeRobo(const std::string &target) const;
        AForm *makePresident(const std::string &target) const;
        AForm *makeShrub(const std::string &target) const;
};

#endif
