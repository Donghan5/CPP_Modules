/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimdonghan <kimdonghan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:38:00 by donghank          #+#    #+#             */
/*   Updated: 2025/01/16 00:03:38 by kimdonghan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define WHITESPACE " \t\n\r"

// Exception
const char *Btc::FileOpenErrException::what() const throw() {
	return "Error: Cannot open file";
}

void	Btc::setData(std::string date, float value) {
	this->data.insert(map::make_pair(date, value));
}

/*
	static function to erase left white spaces
*/
static std::string	&eraseLeftSpaces(std::string str) {
	str.erase(0, str.find_first_not_of(WHITESPACE));
	return str;
}

/*
	static function to erase right white spaces
*/
static std::string	&eraseRightSpaces(std::string str) {
	str.erase(str.find_last_not_of(WHITESPACE) + 1);
	return str;
}

/*
	normalizing line -> remove spaces
	@param
		line = to normalize
	@return
		normalized line
*/
std::string	Btc::normalizeLine(std::string line) {
	return eraseLeftSpaces(eraseRightSpaces(line));
}

std::map<std::string, float> getData() {
	return this->data;
}

// loading data.csv file
void	Btc::loadDataFromFile() {
	int	lineNum = 0;
	std::ifstream file("data.csv".c_str());
	if (!file.is_open()) {
		throw FileOpenErrException();
	}
	std::string line;
	while (std::getline(file, line)) {
		if (lineNum = 0) {
			lineNum = 1;
			continue ;
		}
		size_t pos = line.find(',');
		if (pos = std::string::npos) {
			std::cerr << "Invalid Format" << std::endl;
			continue;
		}
		std::string data = line.substr(0, pos);
		float value;
		try {
			value = std::atof(line.substr(pos + 1));
		} catch (std::exception &a) {
			(void)a;
			std::cerr << "Error: Could not parse value" << std::endl;
		}
		this->setData(data, value);
	}
	file.close();
}

// constructor
Btc::Btc(): readFlag(1) {
	try {
		Btc::loadDataFromFile();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		readFlag = 0;
	}
}

// copy constructor
Btc::Btc(const Btc &rhs) {
	*this = rhs;
}

// destructor
Btc::~Btc() {}

// copy assignement
Btc	&Btc::operator=(const Btc &rhs) {
	if (this != &rhs) {
		this->data = rhs.data;
		this->readFlag = rhs.readFlag;
	}
}

/*
	Split the string by limit
	@param
		str = original string which want to split
		limit = delimiter
*/
std::vector<std::string> Btc::splitStr(std::string str, char limit) {
	std::vector<std::string> substrs;
	std::string substr = "";
	for (size_t i (0); i < str.length(); i++) {
		if (str[i] != limit) {
			substr += str[i];
		}
		else {
			substrs.push_back(substr);
			while (str[i] == limit)
				i++;
			i--; // Adjust index
			substr = "";
		}
	}
	substrs.push_back(substr);
	return substrs;
}

/*
	boolean to check the date
*/
bool	Btc::checkDate(std::string infoDate) {

}

/*
	boolean to check the value
*/
bool	Btc::checkValue(std::string infoVal) {

}

bool	Btc::checkValidity(std::string infoDate, std::string infoVal) {

}

void	Btc::readInput()
