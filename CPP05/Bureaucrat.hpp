#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#pragma once

#include <iostream>

class BureauCrat {
	private:
		const std::string	_name;
		int					_grade;
	public:
		// constructor and desturctor
		BureauCrat();
		BureauCrat(const std::string &name, int grade);
		BureauCrat(const BureauCrat &rightSide);
		~BureauCrat();

		BureauCrat	&operator=(const BureauCrat &rightSide);

		// Member function
		void	incrementGrade(void);
		void	decrementGrade(void);

		// getter
		const std::string	&getName(void);
		int					getGrade(void);

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

std::ostream	&operator<<(std::ostream &str, BureauCrat const &bureauCrat);

#endif
