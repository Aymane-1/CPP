/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:58:17 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/25 18:28:59 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//---------------------------*** constructors ***---------------------------

PresidentialPardonForm::PresidentialPardonForm(): AForm("SomeType", 25, 5)
{
	std::cout << "PresidentialPardonForm default constructor called." << std::endl;
	target = "someTarget";
}

PresidentialPardonForm::PresidentialPardonForm(std::string targett) \
 : AForm(targett, 25, 5)
{
	target = targett;
	std::cout << "PresidentialPardonForm parametrized constructor called." << std::endl;
}

//---------------------------*** copy constructor ***---------------------------

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &obj)
{
	*this= obj;
}

//---------------------------*** copy assignment ***---------------------------

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}

//---------------------------*** member functions ***---------------------------

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSignedState())
		throw FormUnsignedException();
	else if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();	
	std::cout << target << " has been pardoned by Zaphod Beeblerox." << std::endl;	
}

//---------------------------*** destructor ***---------------------------

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}
