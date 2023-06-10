/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:53:28 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/10 17:11:19 by dkaratae         ###   ########.fr       */
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
    animals[0]->setIdeass("sleep");
    // animals[0]->setIdeass("play");
    // animals[0]->setIdeass("run");
    
    
    for (int i = 0; i < count; i++)
    {
        delete animals[i];
    }

}