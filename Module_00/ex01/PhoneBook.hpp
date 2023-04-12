/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:02:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/04/12 21:45:18 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook{
	private:
	Contact contacts[8];
	public:
	int			check_input(std::string s);
	void		entry_display(void);
	// void		Add(Contact &NewContact);
	void		Search(void);
	void		Exit(void);
	void		prompt(void);
	void		set_Contact(int index);
	void		PhoneBookList(void);
	void		TextTraiter(void);
	// std::string	get_Contact(void);
};

#endif