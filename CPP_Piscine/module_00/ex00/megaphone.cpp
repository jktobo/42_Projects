/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 08:10:35 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/30 16:29:21 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[])
{
	int i;
	int j;

	i = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		while (argv[++i])
		{
			j = -1;
			while (argv[i][++j])
				std::cout << (char)toupper(argv[i][j]);
			if (i < argc - 1)
				std::cout << " ";
			
		}	
	}
	std::cout << std::endl;
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
// 			std::cout << " ";
// 		}	
// 	}
// 	std::cout << std::endl;
// 	return (0);
// }