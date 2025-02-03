/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 15:16:01 by donghank          #+#    #+#             */
/*   Updated: 2025/02/03 23:25:50 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#define RED "\033[31m"
#define END "\033[0m"

template <typename Container>
const char *PmergeMe<Container>::InvalidInputException::what() const throw() {
	return "Error";
}

template <typename Container>
std::string getContainerName();

template <>
std::string getContainerName<std::vector<int> >() {
	return "vector<int>";
}

template <>
std::string getContainerName<std::list<int> >() {
	return "list<int>";

}

template <typename Container>
PmergeMe<Container>::PmergeMe(char **data): _data() {
	_time = 0;
	_last = 1;

	for (size_t i (0); data[i]; i++) {
		if (!isNum(data[i])) {
			throw PmergeMe::InvalidInputException();
		}
		_data.push_back(ftStoa(data[i]));
	}
}

template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe &rhs) {
	this->_data = rhs._data;
}

template <typename Container>
PmergeMe<Container> &PmergeMe<Container>::operator=(const PmergeMe &rhs) {
	if (this != &rhs) {
		this->_data = rhs._data;
		this->_last = rhs._last;
		this->_time = rhs._time;
	}
	return *this;
}

template <typename Container>
PmergeMe<Container>::~PmergeMe() {}

template <typename Container>
int PmergeMe<Container>::ftStoa(const char *str) {
	std::istringstream ss(str);
	int number;

	ss >> number; // Convert the string
	return (number);
}

template <typename Container>
bool PmergeMe<Container>::isNum(const std::string &s) {
	if (s.empty() || s[0] == '-') return false;
	size_t i = 0;
	if (s[0] == '+' && s.length() == 1) return false;
	else if (s[0] == '+') i++;
	for (; i < s.length(); i++) {
		if (!std::isdigit(s[i])) {
			return false;
		}
	}

	return true;
}

template <typename Container>
typename PmergeMe<Container>::pair_vector PmergeMe<Container>::generatePairs(Container &data) {
	pair_vector pairs;

	if (data.size() % 2 != 0) { // If the amount of data is odd, add one more data
		this->_last = data.back();
		data.pop_back();
	}

	typename Container::iterator it = data.begin();
	while (it != data.end()) {
		typename Container::iterator first = it;
		typename Container::iterator second = first;
		++second;

		if (second == data.end()) break;

		if (*first < *second) {
			std::swap(*first, *second);
		}

		pairs.push_back(std::make_pair(*first, *second));
		std::advance(it, 2);
	}

	return pairs;
}

template <typename Container>
void PmergeMe<Container>::sortPairs(pair_vector &pairs) {
	if (pairs.size() <= 1) return ; // nothing to sort

	size_type middle = pairs.size() / 2;
	pair_vector leftHalf(pairs.begin(), pairs.begin() + middle);
	pair_vector rightHalf(pairs.begin() + middle, pairs.end());

	// sorting the element
	sortPairs(leftHalf);
	sortPairs(rightHalf);

	size_type leftIdx = 0;
	size_type rightIdx = 0;
	size_type idx = 0;

	// increment left or right index
	while (leftIdx < leftHalf.size() && rightIdx < rightHalf.size()) {
		pairs[idx++] = leftHalf[leftIdx].first < rightHalf[rightIdx].first ? leftHalf[leftIdx++] : rightHalf[rightIdx++];
	}

	// increment total index
	while (leftIdx < leftHalf.size()) {
		pairs[idx++] = leftHalf[leftIdx++];
	}
	while (rightIdx < rightHalf.size()) {
		pairs[idx++] = rightHalf[rightIdx++];
	}
}

/*
	Do operator binary search (very very short ver.)
	1. divide by two side
	2. search left side
	3. search right side
	4. repeat this action
	@param
		target: want to find
*/
template <typename Container>
int PmergeMe<Container>::binarySearch(int target) {
	int left = 0;
	int right = _data.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		typename Container::iterator midIt = _data.begin();
		std::advance(midIt, mid);

		if (*midIt == target) return mid;
		else if (*midIt < target) left = mid + 1;
		else right = mid - 1;
	}

	return left;
}

/*
	What is Jacobsthal sequence?
		Generally, it increase 2 times of fibonacci, but little bit different
		Equtation: J(n) = J(n - 1) + 2 * J(n - 2)
		first value: J(0) = 0, J(1) = 1
	- it help to search the position properly (like binary)
*/
template <typename Container>
int_vector PmergeMe<Container>::generateIndexes(size_t size) {
	int_vector indexes;
	int jacobsthalSeq[size + 1];

	jacobsthalSeq[0] = 0;
	jacobsthalSeq[1] = 1;
	int lastJacobsthalNumber = 2;
	for (size_t i = 2; indexes.size() < size; i++) {
		jacobsthalSeq[i] = jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2];

		// push the jacobsthal num to sequence
		i != 2 ? indexes.push_back(jacobsthalSeq[i]) : (void)0;

		for (int j = jacobsthalSeq[i] - 1; j > lastJacobsthalNumber; j--)
			indexes.push_back(j);

		lastJacobsthalNumber = jacobsthalSeq[i];
	}
	return indexes;
}

template <typename Container>
void PmergeMe<Container>::printData() const {
	typename Container::const_iterator it = _data.begin();
	for (; it != _data.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe<Container>::timeTable() const {
	std::cout << "Time to process range of " << _data.size() << " element with std::" << getContainerName< Container >() << " : " << std::fixed << std::setprecision(5) << _time << " us" << std::endl;
}

template <typename Container>
void PmergeMe<Container>::sort() {
	clock_t start = clock();

	pair_vector pairs = generatePairs(_data);
	int_vector insertionIndexes = generateIndexes(_data.size());

	if (pairs.size() == 0) {
		_data.push_back(_last);
		_time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
		return;
	}

	sortPairs(pairs);

	_data.clear();

	_data.push_back(pairs[0].second);

	for (size_type i = 0; i < pairs.size(); i++) {
		_data.push_back(pairs[i].first);
	}

	for (size_t i = 0; i < insertionIndexes.size(); i++) {
		if (size_t(insertionIndexes[i] - 1) >= pairs.size()) continue ;

		int index = binarySearch(pairs[insertionIndexes[i] - 1].second);

		// if the case of the list --> advance
		typename Container::iterator insertIt = _data.begin();
		std::advance(insertIt, index);
		_data.insert(insertIt, pairs[insertionIndexes[i] - 1].second);
	}

	if (_last != -1) {
		int index = binarySearch(_last);
		typename Container::iterator insertIt = _data.begin();
		std::advance(insertIt, index);
		_data.insert(insertIt, _last);
	}

	_time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;
}

// Excplicit instantiation
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::list<int> >;
