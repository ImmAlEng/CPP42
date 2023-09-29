/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:43:20 by iengels           #+#    #+#             */
/*   Updated: 2023/09/30 01:39:30 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int error(char *txt)
{
    std::cout << "Error: " << txt << " could not be opened!" << std::endl;
    return 1;
}

int infile(std::string &str, char *txt)
{
    std::ifstream in;
    char temp;

    in.open(txt);
    if (in.fail())
        return error(txt);
    while (!in.eof() && in >> std::noskipws >> temp)
        str += temp;
    in.close();
    return 0;
}

int outfile(std::string &str, char *txt, char **av)
{
    std::ofstream out;
    int i;
    int length;
    int check;

    out.open(txt);
    if (out.fail())
        return error(txt);
    length = (int)str.length();
    std::cout << length << std::endl;
    while (i < length)
    {
        check = str.find(av[2], i);
        if (check != std::string::npos && check == i)
        {
            out << av[3];
            i += std::string(av[2]).length() - 1;
        }
        else
            out << str[i];
        i++;
    }
    out.close();
    return 0;
}

int main(int ac, char **av)
{
    std::string str;

    if (ac != 4)
    {
        std::cout << "Usage: ./edit <file> old_word new_word" << std::endl;
        return 1;
    }
    if (infile(str, av[1]) || outfile(str, av[1], av))
        return 1;
    return 1;
}