/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:07 by donghank          #+#    #+#             */
/*   Updated: 2025/02/03 22:52:53 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define RED "\033[31m"
#define END "\033[0m"

// ./PmergeMe $(shuf -i 1-10000 -n 3000 | tr "\n" " ") test with 3000 numbers
int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << RED << "Error: Invalid argline" << END << std::endl;
		return 1;
	}
	try {
		PmergeMe<std::vector<int> > v(argv + 1);

		std::cout << "Before:\t";
		v.printData();

		v.sort();

		PmergeMe<std::list<int> > list(argv + 1);
		list.sort();

		std::cout << "After:\t";

		list.printData();

		v.timeTable();
		list.timeTable();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
