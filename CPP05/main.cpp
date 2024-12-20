#include "Bureaucrat.hpp"

void	incrementTest()
{
	try {
		Bureaucrat	bureauCrat("John", 1);

		std::cout << bureauCrat << std::endl;
		bureauCrat.incrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	decrementTest()
{
	try {
		Bureaucrat bureauCrat("Bob", 150);

		std::cout << bureauCrat << std::endl;
		bureauCrat.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

int main(void) {
	std::cout << "====== This is increment test ======" << std::endl;
	incrementTest();

	std::cout << "====== This is decrement test ======" << std::endl;
	decrementTest();

	return 0;
}
