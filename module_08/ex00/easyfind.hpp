/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 21:36:22 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/03 04:45:00 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename containerT>
void	easyfind(containerT data, int num)
{
	std::vector<int>::iterator it;
	it = std::find(data.begin(), data.end(), num);
	if (it != data.end())		
		std::cout << "Element found." << std::endl;
	else
		throw std::invalid_argument("Element not found!");
}

#endif