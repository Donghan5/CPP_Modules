#include "Bureaucrat.hpp"

/*
	exception function
	@return
		msg to throw
*/
const char	*BureauCrat::GradeTooLowException::what() const throw() {
	return ("Grade is lower than minimum!");
}

/*
	exception function
	@return
		msg to throw
*/
const char	*BureauCrat::GradeTooHighException::what() const throw() {
	return ("Grade is higher than maximum!");
}

/*
	Default constructor
*/
BureauCrat::BureauCrat(): _name("Default"), _grade(150) {
	std::cout << "Default constructor has been called" << std::endl;
}

/*
	Type constructor
	@param
		name: name of the class
		grade: grade of the name
*/
BureauCrat::BureauCrat(const std::string &name, int grade): _name(name) {
	if (grade < 1)
		throw(BureauCrat::GradeTooHighException());
	if (grade > 150)
		throw(BureauCrat::GradeTooLowException());
	this->_grade = grade;
}

/*
	copy constructor
	@param
		rightSide: copy src
*/
BureauCrat::BureauCrat(const BureauCrat &rightSide): _name(rightSide._name), _grade(rightSide._grade) {
	std::cout << "Copy constructor " << this->_name << " has been called" << std::endl;
}

/*
	Destructor
*/
BureauCrat::~BureauCrat() {
	std::cout << "Destructor " << this->_name << " has been called" << std::endl;
}

/*
	Copy assingement
	@param
		rightSide: copy src
	@return
		this: self-pointer of the class
*/
BureauCrat	&BureauCrat::operator=(const BureauCrat &rightSide) {
	if (this != &rightSide) {
		std::cout << "Copy assignement has been called" << std::endl;
		this->_grade = rightSide._grade;
	}
	return *this;
}

/*
	increment grade --> lowest grade is 150
*/
void	BureauCrat::incrementGrade(void) {
	if (this->_grade == 1)
		throw GradeTooHighException();
	this->_grade--;
}

/*
	decrement grade --> hight=est grade is 1
*/
void	BureauCrat::decrementGrade(void) {
	if (this->_grade == 150)
		throw GradeTooLowException();
	this->_grade++;
}

/*
	getter
	@return
		this->_name: type of class
*/
const std::string	&BureauCrat::getName(void) {
	return this->_name;
}

/*
	getter
	@return
		this->_grade: grade
*/
int	BureauCrat::getGrade(void) {
	return this->_grade;
}

/*
	@param
		str: string to print
		bureauCrat: class to take name and grade
*/
std::ostream	&operator<<(std::ostream &str, BureauCrat &bureauCrat) {
	str << bureauCrat.getName() << ", bureaucrat grade " << bureauCrat.getGrade();
	return str;
}
