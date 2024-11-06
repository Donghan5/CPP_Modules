#ifndef SED_HPP
# define SED_HPP

#pragma once
// standard lib
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class Sed {

	private:
		std::string	_inFile;
		std::string	_outFile;

	public:
		Sed(std::string filename);
		~Sed();
	void	replace(std::string s1, std::string s2);
};

#endif
