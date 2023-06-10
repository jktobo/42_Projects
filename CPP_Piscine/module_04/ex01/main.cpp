/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:53:28 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 13:49:28 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;
//     return 0;
// }

int main()
{
    int count = 2;
    Animal *animals[count];
    
    for (int i = 0; i < count; i++)
    {
        if (i % count == 0)
        {
            std::cout << i << std::endl;
            animals[i] = new Dog();
        }
        else
        {
            std::cout << i << std::endl;
            animals[i] = new Cat();
        }
    }

    for (int i = 0; i < count; i++)
    {
        delete animals[i];
    }

}