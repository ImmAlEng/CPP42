/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:17:22 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:17:06 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#pragma once

class PresidentialPardonForm : public AForm
{
    private:
        std::string target;
        
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(PresidentialPardonForm const &copy);
        ~PresidentialPardonForm();

        PresidentialPardonForm const &operator=(PresidentialPardonForm const &copy);

        void execute_ok(void) const;
};

#endif
