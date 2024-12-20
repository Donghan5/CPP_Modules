#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#pragma once

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat {
	private:
		const std::string	_name;
		int					_grade;
		static const int	maxGrade = 1;
		static const int	minGrade = 150;
	public:
		// constructor and desturctor
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &rightSide);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &rightSide);

		// Member function
		void	incrementGrade(void);
		void	decrementGrade(void);

		// getter
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		// Exception
		class GradeTooHighException: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual char const	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif
