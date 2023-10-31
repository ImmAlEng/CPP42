/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 00:18:02 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 02:10:58 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("John", 1); // Highest grade bureaucrat
        ShrubberyCreationForm shrubberyForm("Garden");
        PresidentialPardonForm presidentialForm("John Doe");
        RobotomyRequestForm robotomyForm("RoboTarget");

        std::cout << bureaucrat << std::endl;
        std::cout << shrubberyForm << std::endl;
        std::cout << presidentialForm << std::endl;
        std::cout << robotomyForm << std::endl;

        std::cout << "----- Testing the ShrubberyCreationForm -----" << std::endl;
        bureaucrat.signAForm(shrubberyForm);
        shrubberyForm.execute(bureaucrat);

        std::cout << "----- Testing the PresidentialPardonForm -----" << std::endl;
        bureaucrat.signAForm(presidentialForm);
        presidentialForm.execute(bureaucrat);

        std::cout << "----- Testing the RobotomyRequestForm -----" << std::endl;
        bureaucrat.signAForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        // Testing exceptions

        Bureaucrat badBureaucrat("Bad Guy", 150); // Lowest grade bureaucrat
        badBureaucrat.signAForm(shrubberyForm); // This should throw a GradeTooLowException
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
