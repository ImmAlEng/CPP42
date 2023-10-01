/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 00:28:36 by iengels           #+#    #+#             */
/*   Updated: 2023/10/01 00:45:40 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Position
{
    private:
        int x;
        int y;
    public:
        Position(void) {};
        Position(int x, int y) :x(x), y(y) {};
        ~Position() {};

        Position operator + (Position pos)
        {
            Position new_position;
            new_position.x = x + pos.x;
            new_position.y = y + pos.y;
            return new_position;
        }
        bool operator == (Position pos)
        {
            if (x == pos.x && y == pos.y)
                return true;
            return false;
        }
};

int main(void)
{
    Position pos1(10,20), pos2(20,40);
    Position pos3, pos4, pos5;

    pos3 = pos1 + pos1;
    pos4 = pos2 + pos2;
    pos5 = pos1 + pos2;

    if (pos3 == pos2)
        std::cout << "Nice" << std::endl; 
    else
        std::cout << "WTF" << std::endl;


    // std::cout << pos1 <<std::endl;
    // std::cout << pos2 <<std::endl;
    // std::cout << pos3 <<std::endl;
    // std::cout << pos4 <<std::endl;
    // std::cout << pos5 <<std::endl;
    return 0;
}