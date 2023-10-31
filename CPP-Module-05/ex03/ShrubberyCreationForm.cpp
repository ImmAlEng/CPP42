/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 23:25:37 by iengels           #+#    #+#             */
/*   Updated: 2023/10/31 18:56:39 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("default")
{
    std::cout << "ShrubberyCreationForm default constructor is called - " << getName() << " ShrubberyCreationForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm normal constructor is called - " << getName() << " ShrubberyCreationForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy.getName(), copy.getSignGrade(), copy.getExecGrade()), target(copy.target)
{
    std::cout << "ShrubberyCreationForm copy constructor is called - " << getName() << " ShrubberyCreationForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was created. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
    *this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm deconstructor is called - " << getName() << " ShrubberyCreationForm  with sign_grade "
              << getSignGrade() << " and exec_grade " << getExecGrade() << " was destroyed. Signed? " << (getIsSigned() ? "Yes" : "No")
              << "! Target: " << target << std::endl;
}

ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &copy)
{
    std::cout << "ShrubberyCreationForm assignment operator is called" << std::endl;
    if (this != &copy)
    {
        AForm::operator=(copy);
    }
    return (*this);
}

void ShrubberyCreationForm::execute_ok(void) const
{
    std::ofstream ofs;

    ofs.open((this->target + "_shrubbery").c_str(), std::ofstream::out | std::ofstream::app);

    if (ofs.is_open())
    {
        ofs << "\n"
                     "                  # #### ####                           # #### ####                 \n"
                     "              ### \\/#|### |/####                   ### \\/#|### |/####             \n"
                     "             ##\\/#/ \\||/##/_/##/_#                ##\\/#/ \\||/##/_/##/_#          \n"
                     "           ###  \\/###|/ \\/ # ###                ###  \\/###|/ \\/ # ###            \n"
                     "         ##_\\_#\\_\\## | #/###_/_####           ##_\\_#\\_\\## | #/###_/_####        \n"
                     "        ## #### # \\ #| /  #### ##/##          ## #### # \\ #| /  #### ##/##         \n"
                     "         __#_--###`  |{,###---###-~            __#_--###`  |{,###---###-~           \n"
                     "                   \\ }{                                  \\ }{                      \n"
                     "                    }}{                                   }{{                       \n"
                     "                    }{{                                   }{{                       \n"
                     "                    }{}                                   }{}                       \n"
                     "              , -=-~} .-^- _                        , -=-~} .-^- _                  \n"
                     "\n"
                  << std::endl;
    }
}
