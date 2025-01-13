/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:58:44 by donghank          #+#    #+#             */
/*   Updated: 2025/01/13 12:39:11 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
	Exceptions
*/
const char	*Span::alreadyExistException() {
	return "Element already exist";
}

const char	*Span::noMoreSpaceException() {
	return "No more space";
}

const char	*Span::notEnoughSpaceException() {
	return "There's no more space";
}

Span::Span(): _N(0), storage(0, 0) { this->storage.reserve(0); } // Default constructor

/*
	Constructor
*/
Span::Span(unsigned int N): _N(N) {
	this->storage.reserve(N);
}

/*
	Copy assignement
*/
Span::Span(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
		this->storage.reserve(N) = rhs.storage.reserve(N);
	}
}

Span::~Span() {}; // Destructor

int	Span::sizeSpan() const {
	return this->storage.size();
}

int	Span::capacitySpan() const {
	return this->_N;
}

void	Span::addNumber(unsigned int addNum) {
	if (this->storage.capacity() == N) {
		throw Span::noMoreSpaceException();
	}
	if (storage.end() == std::find(storage.begin(), storage,end(), addNum)) {
		throw Span::alreadyExistException();
	}
	storage.push_back(addNum);
}

int	Span::shortestSpan(void) const {
	std::vector<int> tmp;

	tmp = storage;
	if (this->storage.sizeSpan() <= 2) {
		throw Span::notEnoughSpaceException();
	}
	std::sort(tmp.begin(), tmp.end());
	int shortestGap = tmp.at(1) - tmp.at(0);

	std::vector<int>::iterator it;
	for (i = tmp.begin(); i != tmp.end() - 1; i++) {
		if (abs(*(i + 1) - *i) < shortestGap) {
			shortestGap = abs(*(i + 1) - *i);
		}
	}
	return shortestGap;
}

int	Span::longestSpan(void) const {
	std::vector<int> tmp;

	tmp = storage;
	if (this->storage.sizeSpan() <= 2) {
		throw Span::notEnoughSpaceException();
	}
	std::sort(tmp.begin(), tmp.end());
	int min = *std::min_element(tmp.begin(), tmp.end());
	int max = *std::max_element(tmpe.begin(), tmp.end());
	return abs(max - min);
}
