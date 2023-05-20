/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:47:33 by aechafii          #+#    #+#             */
/*   Updated: 2023/05/20 13:43:48 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("SomeRandomDocument"), gradeToSign(150),gradeToExec(150)
{
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const std::string &namee, const int GradeToSign, const int GradeToExec):name(namee), gradeToSign(GradeToSign) ,gradeToExec(GradeToExec)
{
	std::cout << "AForm parametrized constructor called" << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &obj): name(obj.name), gradeToSign(obj.gradeToSign) ,gradeToExec(obj.gradeToExec)
{
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	*this = obj;
}

AForm	&AForm::operator=(const AForm &obj)
{
	if (this != &obj)
	{
		this->Signed = obj.Signed;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &output, AForm &obj)
{
	if (obj.getSignedState())
		std::cout << "Name: " << obj.getName() << " GradeSignedRequired "<< obj.getGradeToSign() << " GradeExecRequired " << obj.getGradeToExec() << " State: true" << std::endl;
	else
		std::cout << "Name: " << obj.getName() << " GradeSignedRequired "<< obj.getGradeToSign() << " GradeExecRequired " << obj.getGradeToExec() << " State: false" << std::endl;
	return (output);
}

std::string	AForm::getName() const
{
	return (name);
}

bool	AForm::getSignedState(void) const
{
	return (Signed);	
}

int	AForm::getGradeToSign(void) const
{
	return (gradeToSign);
}

int	AForm::getGradeToExec(void) const
{
	return (gradeToExec);
}

void	AForm::beSigned(Bureaucrat &obj)
{
	if (obj.getGrade() > this->gradeToSign)
		throw GradeTooLowException();
	else
		Signed = true;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}