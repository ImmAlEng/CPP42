/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 02:05:42 by iengels           #+#    #+#             */
/*   Updated: 2023/11/21 17:25:52 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    //try Stack
    try
    { 
        // Test 1: Basic Stack Operations
        MutantStack< int > mstack;

        mstack.push(5);
        mstack.push(17);
        std::cout << "Top: " << mstack.top() << std::endl;
        mstack.pop();
        std::cout << "Size: " << mstack.size() << std::endl;

        // Test 2: Iterator Usage
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        mstack.push(42);
        mstack.push(42);
        mstack.push(42);
        mstack.push(42);
        mstack.push(1291);
        mstack.push(1291);
        mstack.push(0);

        MutantStack< int >::iterator it = mstack.begin();
        MutantStack< int >::iterator ite = mstack.end();

        // Test 2: Iterator Usage (Forward)
        std::cout << "Contents using iterators ++:" << std::endl;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }

        it = mstack.begin();
        --ite;
        // Test 2: Iterator Usage (Backward)
        std::cout << "Contents using iterators --:" << std::endl;
        while (it != ite)
        {
            std::cout << *ite << std::endl;
            --ite;
        }

        // Test 3: Copy Constructor
        MutantStack< int > mstackCopy(mstack);

        // Test 4: Assignment Operator
        MutantStack< int > anotherStack;
        anotherStack = mstack;

        // Test 5: Empty Stack
        MutantStack< int > emptyStack;
        std::cout << "Size of empty stack: " << emptyStack.size() << std::endl;

        // Test 6: Const Stack
        const MutantStack< int > mstackConst(mstack);
        MutantStack< int >::c_iterator cit = mstackConst.cbegin();
        MutantStack< int >::c_iterator cite = mstackConst.cend();
        for (; cit != cite; cit++)
            std::cout << *cit << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
