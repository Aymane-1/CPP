/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 02:45:14 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/03 21:52:41 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		std::string input;
		int i, j;

		i = 1;
		while (argv[i])
		{
			j = 0;
			input = argv[i];
			while (input[j]) 
			{
				input[j] = toupper(input[j]);
				j++;	
			}
			i++;
			std::cout << input;
		}
		std::cout << std::endl;
	}
}