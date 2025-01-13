/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 23:58:44 by donghank          #+#    #+#             */
/*   Updated: 2025/01/13 00:08:45 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span(): _N(0) { this->storage.reserve(0); } // Default constructor

Span(unsigned int N): _N(N) {
	this->storage.reserve(N);
}

Span(const Span &rhs) {
	if (this != &rhs) {
		this->_N = rhs._N;
		this->storage.reserve(N) = rhs.storage.reserve(N);
	}
}
