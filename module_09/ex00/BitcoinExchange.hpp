/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechafii <aechafii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 23:40:59 by aechafii          #+#    #+#             */
/*   Updated: 2023/06/08 18:58:57 by aechafii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <exception>
#include <map>
#include <string>
#include <algorithm>

void				printMap(std::map<std::string, double, std::greater<std::string> > data);
void				storeData(std::map<std::string, double, std::greater<std::string> > &data);
void				processInput(char *argument, std::map<std::string, double, std::greater<std::string> > &data);
void				processLine(std::string line, int pipeIndex, std::map<std::string, double, std::greater<std::string> > &data);
void				getExchangeRate(std::string date, double value, std::map<std::string, double, std::greater<std::string> > &data);
void				whiteSpacesSkipper(std::string str, size_t &index);
void				digitsSkipper(std::string str, size_t &index);
void				alphaSkipper(std::string str, size_t &index);
void				whiteSpacesEraser(std::string &str, size_t index);
int					checkHeader(std::string line);
int					checkSyntax(std::string line);
double				checkValue(std::string line);
std::string			checkDate(std::string line);
int					checkDateCompliance(std::string line, int year, int month, int day);
int					isFloat(std::string input);
int					isWhiteSpaces(char c);

#endif