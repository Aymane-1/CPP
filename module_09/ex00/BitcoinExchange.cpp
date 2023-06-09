/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:42:14 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/08 21:05:26 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	isWhiteSpaces(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	whiteSpacesSkipper(std::string str, size_t &index)
{
	while (str[index] && isWhiteSpaces(str[index]))
		index++;
}

void	digitsSkipper(std::string str, size_t &index)
{
	while (str[index] && isdigit(str[index]))
		index++;
}

void	alphaSkipper(std::string str, size_t &index)
{
	while (str[index] && isalpha(str[index]))
		index++;
}

void	whiteSpacesEraser(std::string &str, size_t index)
{
	while (str[index] && isWhiteSpaces(str[index]))
		str.erase(index--);
}

void storeData(std::map<std::string, double, std::greater<std::string> > &data)
{
	std::ifstream	dataFile;
	std::string		line;
	dataFile.open("./data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Could not open database.");
	std::getline(dataFile, line);
	if (line.empty())
		throw std::runtime_error("database is empty.");
	while (std::getline(dataFile, line))
	{
		std::string	date = line.substr(0, line.find(","));
		double 		test = std::atof(line.substr(line.find(",") + 1, line.length()).c_str());
		data.insert(std::make_pair(date, test));
	}
	dataFile.close();
}

void	printMap(std::map<std::string, double, std::greater<std::string> > data)
{
	std::map<std::string, double, std::greater<std::string> >::iterator it = data.begin();
	while (it != data.end())
	{
		std::cout << it->first << " | " << it->second << std::endl;
		it++;
	}
}

void		processInput(char *argument, std::map<std::string, double, std::greater<std::string> > &data)
{
	std::ifstream	inputFile;
	std::string		line;

	inputFile.open(argument);
	if (!inputFile.is_open())
		throw std::runtime_error("Could not open file.");
	while(std::getline(inputFile, line) && line.empty())
		;
	if (checkHeader(line) == -1)
	{
		std::cout << "Error: check header!" << std::endl;
		return ;
	}
	while(std::getline(inputFile, line))
	{
		if (line.empty())
			continue;
		int pipeIndex = line.find("|");
		processLine(line, pipeIndex, data);
	}
}

void	processLine(std::string line, int pipeIndex, std::map<std::string, double, std::greater<std::string> > &data)
{
	if (pipeIndex == -1)
		std::cout << "Error: bad input => " << line << std::endl;
	else
	{
		if (checkSyntax(line) == -1)
			return ;
		std::string		date = checkDate(line);
		double			value;
		if (date != "Error")
				value = checkValue(line);
		if (date == "Error" || value == -1)
			return ;
		else
			getExchangeRate(date, value, data);
	}
}

int	checkHeader(std::string line)
{
	size_t startIndex = 0; // parse "date" part
	whiteSpacesEraser(line, line.length() - 1);
	whiteSpacesSkipper(line, startIndex);
	size_t endIndex = startIndex;
	alphaSkipper(line, endIndex);
	std ::string part1 = line.substr(startIndex, endIndex);
	whiteSpacesEraser(part1, part1.length() - 1);
	
	startIndex = line.find("|") + 1; // parse "value" part
	whiteSpacesSkipper(line, startIndex);
	endIndex = startIndex;
	alphaSkipper(line, endIndex);
	std ::string part2 = line.substr(startIndex, endIndex);
	whiteSpacesEraser(part2, part2.length() - 1);
	
	std::string header = part1 + " | " + part2; // concatenate parts
	if (header == "date | value")
		return (0);
	return (-1);
}

int	checkSyntax(std::string line)
{
	for (size_t i = 0; i < line.length(); i++) // check existance of invalid characters
	{
		if (!isdigit(line[i]) && !isWhiteSpaces(line[i]) \
				&& line[i] != '-' && line[i] != '|' && line[i] != '.' && line[i] != 'f')
			return (std::cout << "Error: bad input => " << line << std::endl, -1);
	}
	return (0);
}

std::string checkDate(std::string line)
{
	size_t startIndex = 0;
	size_t pipeIndex = line.find("|"); // check pipe existence
	if (pipeIndex == std::string::npos)
		return (std::cout << "Error: bad input => " << line << std::endl, "Error");
		
	std::string date = line.substr(0, pipeIndex); // check hyphen existence
	int hyphenIndex = date.find("-");
	if ((date[hyphenIndex] != '-' && date[hyphenIndex + 3] != '-'))
		return (std::cout << "Error: bad input => " << line << std::endl, "Error");
		
	whiteSpacesSkipper(date, startIndex); // check date format
	digitsSkipper(date, startIndex);
	size_t endIndex =  hyphenIndex + 6;
	startIndex = endIndex;
	whiteSpacesSkipper(date, startIndex);
	
	if (startIndex != date.length())
		return (std::cout << "Error: bad input => " << line << std::endl, "Error");
		
	size_t i = 0; // convert date and check its compliance
	whiteSpacesSkipper(date, i);
	int year = std::stoi(date.substr(i, date.find("-")));
	int month = std::stoi(date.substr(date.find("-") + 1, date.find("-") + 2));
	int day = std::stoi(date.substr(date.find("-") + 4, endIndex));
	
	if (checkDateCompliance(line, year, month, day) == -1)
		return ("Error");
	return (date.substr(i, endIndex));
}

int		checkDateCompliance(std::string line, int year, int month, int day)
{
	if (year < 2009 || month > 12 || month < 1 || day < 1 || day > 31)
		return (std::cout << "Error: bad input => " << line << std::endl, -1);
	if (day == 31 && (month == 2 || month == 4 || month == 6 || month == 9 || month == 11))
		return (std::cout << "Error: the month in question has only 30 days! => " << line << std::endl,	-1);
	if (day == 29 && month == 2 && \
		!(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) // check leap year
		return (std::cout << "Error: Non-existant date! => " << line << std::endl, -1);
	return (0);
}

int	isFloat(std::string input)
{
	size_t index = 0;
	digitsSkipper(input, index);
	if (input[index] == '.')
	{
		index++;
		digitsSkipper(input, index);
		if (input[index] == 'f')
		{
			index++;
			whiteSpacesSkipper(input, index);
			if (index == input.length())
				return (1);
		}
	}
	return (0);
}

double			checkValue(std::string line)
{
	size_t startIndex = line.find("|") + 1;
	whiteSpacesSkipper(line, startIndex);
	std::string	sValue = line.substr(startIndex, line.length());
	startIndex = 0;
	if (sValue[startIndex] == '-') // check negative value case
		startIndex++;
	digitsSkipper(sValue, startIndex);
	if (sValue[startIndex] == '.') // check float case
	{
		startIndex++;
		digitsSkipper(sValue, startIndex);
	}
	
	whiteSpacesSkipper(sValue, startIndex); // check value format
	if (startIndex != sValue.length() && !isFloat(sValue))
		return (std::cout << "Error: bad input => " << line << std::endl, -1);
		
	if (!sValue[0])
		return (std::cout << "Error: bad input => " << line << std::endl, -1);
		
	double value = std::atof(sValue.c_str()); // convert value and check it's range
	if (value < 0)
		return (std::cout << "Error: not a positive number." << std::endl, -1);
	if (value > 1000)
		return (std::cout << "Error: too large number." << std::endl, -1);
	return (value);
}

void	getExchangeRate(std::string date, double value, std::map<std::string, double, std::greater<std::string> > &data)
{
	whiteSpacesEraser(date, date.length() - 1);
	std::map<std::string, double, std::greater<std::string> >::iterator it = data.lower_bound(date);
	if (it != data.end())
		std::cout << date << " => " << value << " = "  << it->second * value << std::endl;		
 }
