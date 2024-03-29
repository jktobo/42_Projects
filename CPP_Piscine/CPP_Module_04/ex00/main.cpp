/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 12:53:18 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 18:14:26 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

// int main()
// {
//     const WrongAnimal* meta = new WrongAnimal();
//     const WrongAnimal* i = new WrongCat("CAT");
    
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     meta->makeSound();
//     delete meta;
//     delete i;
//     return 0;
// }

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog("DOG");
    const Animal* i = new Cat("CAT");
    
    std::cout << j->getType() << " " << std::endl;
    j->makeSound();
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    meta->makeSound();
    delete meta;
    delete j;
    delete i;
    return 0;
}