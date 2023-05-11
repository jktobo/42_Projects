/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:03:04 by dkaratae          #+#    #+#             */
/*   Updated: 2023/05/11 17:32:23 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Error! You need to enter next one command: debug, info, warning, error" << std::cout;
        return (1);
    }
    Harl harl;
    harl.complain(argv[1]);
    return (0);
}