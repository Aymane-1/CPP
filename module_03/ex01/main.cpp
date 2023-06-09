/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:51:16 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/08 14:59:30 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	// ClapTrap Warrior("Napoleon");
	ScavTrap Lord("Genkhis khan");
	Lord.attack("Soldier");
	std::cout << Lord.GetClpTrpName() << " EnergyPoints are: " << Lord.GetClpTrpEnergyPoints() << std::endl;
	Lord.guardGate();
}