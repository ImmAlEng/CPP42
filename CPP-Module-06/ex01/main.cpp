/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:22:10 by iengels           #+#    #+#             */
/*   Updated: 2023/11/09 16:39:14 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main(void) {
    Data* originalData = new Data();
    originalData->intValue = 42;
    originalData->floatValue = 3.14f;
    originalData->stringValue = "Hello, World!";

    std::cout << "Original Data" << std::endl;    
    std::cout << "Int Value: " << originalData->intValue << std::endl;
    std::cout << "Float Value: " << originalData->floatValue << std::endl;
    std::cout << "String Value: " << originalData->stringValue << std::endl;
    std::cout << std::endl;

    uintptr_t serialized = Serializer::serialize(originalData);

    Data* deserializedData = Serializer::deserialize(serialized);

    std::cout << "Serialized Data" << std::endl;
    std::cout << serialized << std::endl << std::endl;

    std::cout << "Deserialized Data" << std::endl;
    std::cout << "Int Value: " << deserializedData->intValue << std::endl;
    std::cout << "Float Value: " << deserializedData->floatValue << std::endl;
    std::cout << "String Value: " << deserializedData->stringValue << std::endl;
    std::cout << std::endl;

    std::cout << "Is Serialized Data equal to Original Data? " << ((deserializedData == originalData) ? "Yes" : "No") << std::endl;

    delete originalData;

    return 0;
}
