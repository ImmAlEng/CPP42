/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 00:43:20 by iengels           #+#    #+#             */
/*   Updated: 2023/10/05 16:55:06 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int error(char *files)
{
    std::cout << "Error: " << files << " could not be opened!" << std::endl;
    return 1;
}

int reading(std::string &str, char *name)
{
    std::ifstream in;
    int size;

    in.open(name);
    if (in.fail())
        return error(name);
    in.seekg(1, std::ios::end);
	size = in.tellg();
	str.resize(size);
	in.seekg(0, std::ios::beg);
	in.read(&str[0], size);
    in.close();
    return 0;
}

int writing(std::string &str, char *name, char **av)
{
    std::ofstream out;
    int i;
    int length;
    int check;
    std::string temp = std::string(name) + ".replace";
    const char *outfile = temp.c_str();

    i = 0;
    out.open(outfile);
    if (out.fail())
        return error((char*)outfile);
    length = (int)str.length();
    while (i < length)
    {
        check = str.find(av[2], i);
        if (check != (int)std::string::npos && check == i)
        {
            out << av[3];
            i += std::string(av[2]).length() - 1;
        }
        else if (str[i] == '\0');
        else
            out << str[i];
        i++;
    }
    out.close();
    return 0;
}

int main(int ac, char **av)
{
    std::string temp;

    if (ac != 4)
    {
        std::cout << "Usage: ./edit <file> old_word new_word" << std::endl;
        return 1;
    }
    if (reading(temp, av[1]) || writing(temp, av[1], av))
        return 1;
    return 1;
}
