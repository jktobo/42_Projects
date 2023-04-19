/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:10:35 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/19 19:44:00 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char* argv[])
{
	int i;
	int j;
	char c;

	i = 0;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);	
	}
	else
	{
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)toupper(argv[i][j]);
		}	
		std::cout << std::endl;
	}
	return (0);
}
// int main(int argc, char* argv[])
// {
// 	int i;
// 	int j;
// 	char c;

// 	i = 0;
// 	if (argc == 1)
// 		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
// 	else
// 	{
// 		while (argv[++i])
// 		{
// 			j = -1;
// 			while (argv[i][++j])
// 			{
// 				c = argv[i][j];
// 				if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
// 					c -= 32;
// 				std::cout << c;
// 			}
// 		}	
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }