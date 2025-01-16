/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:37:57 by donghank          #+#    #+#             */
/*   Updated: 2025/01/16 12:43:36 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

/*
	Description of the loadDataFromFile
	- it reads data.csv file, it occur in constructor.
*/
class Btc {
	private:
		std::map<std::string, float> data;
		int	readFlag;
		void	loadDataFromFile(void); // data.csv

	public:
		Btc();
		Btc(const Btc &rhs);
		~Btc();
		Btc &operator=(const Btc &rhs);

		void setData(std::string date, float value); // store data.csv --> class

		// check input integrity and read
		bool checkDate(std::string infoDate);
		bool checkValue(std::string infoVal);
		bool checkValidity(std::string infoDate, std::string infoVal);
		void parseData(std::string infoLine);
		void readInput(std::string inputPath); // input.txt

		std::map<std::string, float> getData();
		std::vector<std::string> splitStr(std::string str, char limit);
		std::string	normalizeLine(std::string line);

		//Exception
		class FileOpenErrException: public std::exception {
			virtual const char *what(void) const throw();
		};

};


#endif
