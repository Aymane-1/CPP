/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassMemberFunc.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 02:45:37 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/12 21:27:20 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//-----------------------*** Contact Class member functions ***-----------------------//

std::string	Contact::get_FirstName(void)
{
	return Contact::FirstName;
}

std::string	Contact::get_LastName(void)
{
	return Contact::LastName;
}

std::string	Contact::get_NickName(void)
{
	return Contact::NickName;
}

std::string	Contact::get_PhoneNumber(void)
{
	return Contact::PhoneNumber;
}

std::string	Contact::get_DarkestSecret(void)
{
	return Contact::DarkestSecret;
}

void	Contact::set_FirstName(std::string s)
{
	Contact::FirstName = s;
}

void	Contact::set_LastName(std::string s)
{
	Contact::LastName = s;
}

void	Contact::set_NickName(std::string s)
{
	Contact::NickName = s;
}

void	Contact::set_PhoneNumber(std::string s)
{
	Contact::PhoneNumber = s;
}

void	Contact::set_DarkestSecret(std::string s)
{
	Contact::DarkestSecret = s;
}

//-----------------------*** PhoneBook Class member functions ***-----------------------//

// std::string	PhoneBook::get_Contact(void)
// {
// 	return (PhoneBook::contacts[0].get_FirstName());
// }

// void	PhoneBook::set_Contact(void)
// {
// 	PhoneBook::contacts[0].set_FirstName();
// }