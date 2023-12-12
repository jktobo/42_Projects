/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:23:15 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 18:24:14 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;
//     return 0;
// }

// int main()
// {
//     int count = 2;
//     Animal *animals[count];
    
//     for (int i = 0; i < count; i++)
//     {
//         if (i % count == 0)
//         {
//             animals[i] = new Dog();
//             animals[i]->getType();
// 		    animals[i]->makeSound();
//         }
//         else
//         {
//             std::cout << i << std::endl;
//             animals[i]->getType();
// 		    animals[i]->makeSound();
//         }
//     }
//     for (int i = 0; i < count; i++)
//     {
//         delete animals[i];
//     }
// }

int main() {
	std::cout << "-----------------------------------" << std::endl;
	Cat *cat1 = new Cat();

	std::cout << "-----------------------------------" << std::endl;
	cat1->getBrain()->setIdea("I am a FELIX");
	cat1->getBrain()->setIdea("I like sleeping");
	cat1->getBrain()->setIdea("I like running");
	cat1->getBrain()->setIdea("I like playing");
	cat1->getBrain()->printIdeas();

	std::cout << "\n-------------COPY------------------" << std::endl;
	Cat *cat2 = new Cat(*cat1);
	std::cout << "\n-----------ASSIGNMENT--------------" << std::endl;
	cat2->getBrain()->setIdea("I am a OSCAR");
	cat2->getBrain()->printIdeas();
	std::cout << "-----------------------------------" << std::endl;
	
	std::cout << "-----------------------------------" << std::endl;
	Cat *cat3 = new Cat();
	cat3->operator=(*cat1);
	std::cout << "-----------------------------------" << std::endl;
	cat3->getBrain()->printIdeas();
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "\n-----------DESTRUCTOR------------" << std::endl;
	delete (cat1);
	delete (cat2);
	delete (cat3);
	/*-------------------------------------------------*/
	return 0;
}

// int main() {
// 	std::cout << "-----------------------------------" << std::endl;
// 	Dog *dog1 = new Dog();

// 	std::cout << "-----------------------------------" << std::endl;
// 	dog1->getBrain()->setIdea("I am a REX");
// 	dog1->getBrain()->setIdea("I like sleeping");
// 	dog1->getBrain()->setIdea("I like running");
// 	dog1->getBrain()->setIdea("I like playing");
// 	dog1->getBrain()->printIdeas();

// 	std::cout << "\n-------------COPY------------------" << std::endl;
// 	Dog *dog2 = new Dog(*dog1);
// 	std::cout << "\n-----------ASSIGNMENT--------------" << std::endl;
// 	dog2->getBrain()->setIdea("I am a BOSS");
// 	dog2->getBrain()->printIdeas();
// 	std::cout << "-----------------------------------" << std::endl;
	
// 	std::cout << "-----------------------------------" << std::endl;
// 	Dog *dog3 = new Dog();
// 	dog3->operator=(*dog1);
// 	std::cout << "-----------------------------------" << std::endl;
// 	dog3->getBrain()->printIdeas();
// 	std::cout << "-----------------------------------" << std::endl;

// 	std::cout << "\n-----------DESTRUCTOR------------" << std::endl;
// 	delete (dog1);
// 	delete (dog2);
// 	delete (dog3);
// 	/*-------------------------------------------------*/
// 	return 0;
// }