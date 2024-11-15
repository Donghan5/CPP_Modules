#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Default constructor of Brain has been called." << std::endl;
	size = 0;
}

Brain::Brain(const Brain &rightSide) {
	std::cout << "Copy-constructor of Brain has been called." << std::endl;
	*this = rightSide;
}

Brain	&Brain::operator=(const Brain &rightSide) {
	std::cout << "Copy-assingnement of Brain has been called." << std::endl;
	if (this != &rightSide) {
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rightSide._ideas[i];
	}
	this->size = rightSide.size;
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "Destructor of Brain has been called." << std::endl;
}

const std::string	&Brain::getIdeas(unsigned int size) const {
	return (this->_ideas[size]);
}

void	Brain::addIdeas(const std::string &idea) {
	if (size == 100) {
		std::cout << "No more place!" << std::endl;
		return ;
	}
	this->_ideas[size++] = idea;
}
