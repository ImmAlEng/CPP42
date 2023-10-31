/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:18:02 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 19:10:39 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    // Create a bureaucrat
    Bureaucrat bureaucrat("John Doe", 1);

    // Create an intern
    Intern intern;

    // Test creating different forms with the intern
    AForm *form1 = intern.makeForm("robotomy request", "Target1");
    AForm *form2 = intern.makeForm("shrubbery request", "Target2");
    AForm *form3 = intern.makeForm("presidential request", "Target3");
    AForm *form4 = intern.makeForm("invalid form", "Target4");

    // Try to execute the forms
    bureaucrat.signAForm(*form1);
    bureaucrat.signAForm(*form2);
    bureaucrat.signAForm(*form3);
    bureaucrat.executeForm(*form1);
    bureaucrat.executeForm(*form2);
    bureaucrat.executeForm(*form3);

    // Clean up memory
    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
