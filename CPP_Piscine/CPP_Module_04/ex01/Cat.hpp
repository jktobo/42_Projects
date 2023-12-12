/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:22:48 by dkaratae          #+#    #+#             */
/*   Updated: 2023/06/11 18:22:51 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        Cat(const std::string& name);
        Cat(const Cat& other);
        Cat& operator=(const Cat& other);
        virtual ~Cat();
        void makeSound() const;
        Brain *getBrain() const;
    private:
        Brain *_brain;
};
#endif