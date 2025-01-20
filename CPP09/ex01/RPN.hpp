/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 23:48:45 by donghank          #+#    #+#             */
/*   Updated: 2025/01/19 15:08:55 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>

/*
	Basic formula of RPN
		num of value = num of operator + 1
*/
class Rpn {
	private:
		std::stack<double> _number; // stack of the values which are converted
		std::stack<std::string> _splitStr; // stack of the argument line element separated by white spaces
		std::string	_strArg;
		int	numOfVal;

		Rpn();
		bool	isOperator(char op);
		void	validateInput(std::string line);
		double	doOperation(double a, double b, char op);
		void	calculateStore(void);
		void	splitStrStock(void);

	public:
		Rpn(std::string strArg);
		Rpn(const Rpn &rhs);
		~Rpn();

		Rpn &operator=(const Rpn &rhs);

		void printResultOfRpn(void);

		class InvalidInputException: public std::exception {
			public:
				const char *what() const throw();
		};

		class CalculateException: public std::exception {
			public:
				const char *what() const throw();
		};

		class NotEnoughException: public std::exception {
			public:
				const char *what() const throw();
		};

		class RuleRpnException: public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
