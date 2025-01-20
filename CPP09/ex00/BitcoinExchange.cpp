/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:38:00 by donghank          #+#    #+#             */
/*   Updated: 2025/01/16 23:47:10 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define WHITESPACE " \t\n\r"

// Exception
const char *Btc::FileOpenErrException::what() const throw() {
	return "Error: Cannot open file";
}

void	Btc::setData(std::string date, float value) {
	this->data.insert(std::make_pair(date, value));
}

/*
	static function to erase left white spaces
*/
static std::string	&eraseLeftSpaces(std::string &str) {
	str.erase(0, str.find_first_not_of(WHITESPACE));
	return str;
}

/*
	static function to erase right white spaces
*/
static std::string	&eraseRightSpaces(std::string &str) {
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

std::map<std::string, float> Btc::getData() {
	return this->data;
}

// loading data.csv file
void	Btc::loadDataFromFile() {
	int	lineNum = 0;
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		throw FileOpenErrException();
	}
	std::string line;
	while (std::getline(file, line)) {
		if (lineNum == 0) {
			lineNum = 1;
			continue ;
		}
		size_t pos = line.find(',');
		if (pos == std::string::npos) {
			std::cerr << "Invalid Format" << std::endl;
			continue;
		}
		std::string data = line.substr(0, pos);
		float value;
		try {
			value = std::atof(line.substr(pos + 1).c_str());
		} catch (std::exception &a) {
			(void)a;
			std::cerr << "Error: Could not parse value" << std::endl;
			continue ;
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
	return *this;
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
	std::vector<std::string> dates = splitStr(infoDate, '-');
	int year, month, day;
	try {
		year = std::atoi(dates[0].c_str());
		month = std::atoi(dates[1].c_str());
		day = std::atoi(dates[2].c_str());
	} catch (const std::exception &e) {
		(void)e;
		std::cerr << "Error: parsing date" << std::endl;
		return false;
	}
	if (year < 1000 || year > 9999) {
		// std::cerr << "Error: Year has to be XXXX" << std::endl;
		return false;
	}
	if (month < 1 || month > 12) {
		// std::cerr << "Error: Invalid month" << std::endl;
		return false;
	}
	if (day < 1 || day > 31) {
		// std::cerr << "Error: Invalid day" << std::endl;
		return false;
	}
	if ((day == 31) && (month == 4 || month == 6 || month == 9 || month == 11)) {
		// std::cerr << "Error: Invalid format of day" << std::endl;
		return false;
	}
	if (year % 4 == 0 && ((year % 100 != 0 ) || (year % 400 == 0))) {
		if (month == 2 && day > 29) {
			// std::cerr << "Error: Invalid format of month (feb, leap year)" << std::endl;
			return false;
		}
	} else if (month == 2 && day > 28) {
		// std::cerr << "Error: Invalid format of month (feb, normal year)" << std::endl;
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
		value = std::atof(infoVal.c_str());
	} catch (const std::exception &e) {
		(void)e;
		std::cerr << "Cannot convert value." << std::endl;
		return false;
	}
	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

bool	Btc::checkValidity(std::string infoDate, std::string infoVal) {
	if (checkDate(infoDate) == false) {
		std::cerr << "Error: bad input =>  " << infoDate << std::endl;
		return false;
	}
	if (checkValue(infoVal) == false) {
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
	while (getline(inputFile, line)) {
		if (lineNum == 0) {
			lineNum = 1;
			continue ;
		}
		std::vector<std::string> lineInfo = this->splitStr(line, '|');
		if (lineInfo[1].length() == 0 || lineInfo.size() < 2) {
			std::cerr << "Error: bad input => " << lineInfo[0] << std::endl;
			continue ;
		}
		std::map<std::string, float>::iterator it = this->data.upper_bound(normalizeLine(lineInfo[0]));
		if (it != this->data.end()) { // making pair data
			std::pair<std::string, float> p = *(--it);
			try {
				if (checkValidity(lineInfo[0], lineInfo[1]) == false) {
					continue ;
				}
				else
					std::cout << lineInfo[0] << "=>" << lineInfo[1] << " = " << std::atof(lineInfo[1].c_str()) * p.second << std::endl;
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
	}
}
