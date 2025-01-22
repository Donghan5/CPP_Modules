/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:07 by donghank          #+#    #+#             */
/*   Updated: 2025/01/21 23:49:17 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#define RED "\033[31m"
#define END "\033[0m"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << RED << "Error: Invalid argline" << END << std::endl;
		return 1;
	}
	PmergeMe sorting(argc, *argv);
	sorting.play(argc, argv);
	return 0;
}
