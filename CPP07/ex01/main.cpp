/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 12:52:11 by donghank          #+#    #+#             */
/*   Updated: 2025/01/10 13:18:18 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#define N 5

int main(void) {
	int arr1[] = {1, 2, 3, 4, 5};
	std::cout << "========== arr1 type int test ==========" << std::endl;
	iter(arr1, N, &printA);

	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "========== arr2 type double test ==========" << std::endl;
	iter(arr2, N, &printA);

	float arr3[] = {1.11f, 2.22f, 3.33f, 4.44f, 5.55f};
	std::cout << "========== arr3 type float test ==========" << std::endl;
	iter(arr3, N, &printA);

	char arr4[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "========== arr4 type char test ==========" << std::endl;
	iter(arr4, N, &printA);
}
