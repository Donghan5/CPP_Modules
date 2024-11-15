#ifndef BRAIN_HPP
#define BRAIN_HPP
#pragma once

#include <iostream>
#include <string>

class Brain {
	private:
		std::string		_ideas[100];
		unsigned int	size;
	public:
		Brain();
		Brain(const Brain &rightSide);
		Brain	&operator=(const Brain &rightSide);
		~Brain();
		const std::string	&getIdeas(unsigned int size) const;
		void				addIdeas(const std::string &idea);
};

#endif
