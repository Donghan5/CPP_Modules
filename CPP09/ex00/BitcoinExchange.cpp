/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:38:00 by donghank          #+#    #+#             */
/*   Updated: 2025/01/16 12:47:34 by donghank         ###   ########.fr       */
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
	std::vector<std::strging> dates = splitStr(infoDate, '-');
	int year, month, day;
	try {
		year = std::atoi(dates[0]);
		month = std::atoi(dates[1]);
		day = std::atoi(dates[2]);
	} catch (const std::exception &e) {
		std::cerr << "Error: Cannot convert to int (checkDate)" << std::endl;
		return false;
	}
	if (year < 1000 || year > 9999) {
		throw std::logic_error("Error: Year has to be XXXX");
		return false;
	}
	if (month < 1 || month > 12) {
		throw std::logic_error("Error: Invalid month");
		return false;
	}
	if (day < 1 || day > 31) {
		throw std::logic_error("Error: Invalid day");
		return false;
	}
	if ((day == 31) && (month == 4 || month == 6 || month == 9 || month == 11)) {
		throw std::logic_error("Error: Invalid format of day");
		return false;
	}
	if (year % 4 == 0 && ((year % 100 != 0 ) || (year % 400 == 0))) {
		if (month == 2 && day > 29) {
			throw std::logic_error("Error: Invalid format of month (feb, leap year)");
			return false;
		}
	} else if (month == 2 && day > 28) {
		throw std::logic_error("Error: Invalid format of month (feb, normal year)");
		return false;
	}
	return true;
}

/*
	boolean to check the value
*/
bool	Btc::checkValue(std::string infoVal) {
	float value;

	try {
		value = std::atof(infoVal);
	} catch (const std::exception &e) {
		throw logic_error("Cannot convert value");
		return false;
	}
	if (value < 0 || value > 1000) {
		throw std::logic_error("Invalid value");
		return false;
	}
	return true;
}

bool	Btc::checkValidity(std::string infoDate, std::string infoVal) {
	if (checkDate(infoDate) == false) {
		std::cerr << "Error: error found in date format" << std::endl;
		return false;
	}
	if (checkValue(infoVal) == false) {
		std::cerr << "Error: error found in value format" << std::endl;
		return false;
	}
	return true;
}

void	Btc::readInput(std::string inputPath) {
	std::ifstream inputFile(inputPath.c_str());
	std::string	line;

	if (!inputFile.is_open()) {
		throw FileOpenErrException();
	}
	if (inputFile.peek() == std::ifstream::traits_type::eof()) {
		std::cout << "File reached eof of file is empty" << std::endl;
	}
	// index of line
	int lineNum = 0;
	try {
		while (getline(inputFile, line)) {
			if (lineNum == 0) {
				lineNum = 1;
				continue ;
			}
			std::vector<std::string> lineInfo = splitStr(line, '|');
			std::map<std::string, float>::iterator it = this->data.upper_bound(normalizeLine(lineInfo[0]));
			if (it != data.end()) { // making pair data
				std::pair<std::string, float> p = *(--it);
			}
			if (checkValidity(lineInfo[0], lineInfo[1]) == false) {
				throw std::logic_error("Error: error found");
			}
			std::cout << lineInfo[0] << "=>" << lineInfo[1] << "=" << std::atof(lineInfo[1].c_str()) * p.second << std::endl;
		}
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
