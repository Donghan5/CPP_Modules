/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:40:04 by donghank          #+#    #+#             */
/*   Updated: 2025/01/13 21:34:02 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define RED "\033[31m"
#define END "\033[0m"
#define BIGNUM 10000

int main(void) {
	{
		std::cout << RED << "=========== Subject test ===========" << END << std::endl;
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		std::cout << RED << "=========== Custom test ===========" << END << std::endl;
		std::cout << "Big number test" << std::endl;
		std::cout << RED << "[INFO]" << END << "It can provoque the error rarely(already exist): using random number" << std::endl;
		Span sp = Span(BIGNUM);
		srand(time(NULL));
		try {
			for (int i (0); i < BIGNUM; i++) {
				sp.addNumber(rand());
			}
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
		{
		std::cout << RED << "=========== Custom test ===========" << END << std::endl;
		std::cout << "To check not enough case: error intented" << std::endl;
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			sp.addNumber(10);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}	{
		std::cout << RED << "=========== Custom test ===========" << END << std::endl;
		std::cout << "To check same number case: error intented" << std::endl;
		Span sp = Span(5);
		try {
			sp.addNumber(6);
			sp.addNumber(6);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
