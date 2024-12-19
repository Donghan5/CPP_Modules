#include "Bureaucrat.hpp"

void	incrementTest()
{
	try {
		BureauCrat	bureauCrat("John", 1);

		std::cout << bureauCrat << std::endl;
		bureauCrat.incrementGrade();
	}
	catch (BureauCrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	decrementTest()
{
	try {
		BureauCrat bureauCrat("Bob", 150);

		std::cout << bureauCrat << std::endl;
		bureauCrat.decrementGrade();
	}
	catch (BureauCrat::GradeTooHighException &e) {
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
