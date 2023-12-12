/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 17:24:05 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 17:24:06 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
        Dog();
        Dog(const std::string& name);
        Dog(const Dog& other);
        Dog& operator=(const Dog& other);
        virtual ~Dog();
        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain *_brain;
};
#endif