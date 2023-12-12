/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:54:13 by dkaratae          #+#    #+#             */
/*   Updated: 2023/11/13 14:54:15 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"


int main() {
    Base * base = generate();
    identify(base);
    identify(*base);
    delete base;
    return (0);
}