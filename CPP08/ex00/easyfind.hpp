/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:07:06 by donghank          #+#    #+#             */
/*   Updated: 2025/01/11 16:35:54 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define ESAYFIND_HPP
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <set>

template < typename T >
typename T::iterator	easyfind(T &container, int n) {
	typename T::iterator iter = std::find(container.begin(), container.end(), n);
	if (iter == container.end()) {
		throw std::runtime_error("Run time error: doesn't find the element");
	}
	return iter;
}

#endif
