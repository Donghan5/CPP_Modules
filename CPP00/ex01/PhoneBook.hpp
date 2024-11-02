/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:02:58 by donghank          #+#    #+#             */
/*   Updated: 2024/11/02 17:29:36 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HPP

// prevent to apply multiple header file (same)
# pragma once

// define the error msg
# define GETLINE_ERR "There's not an input"

/* standard library */
# include <iostream>
# include <string>
# include <cstdlib> // for the exit function
# include "Contact.hpp"

/* define the class */
class PhoneBook {
	private:
		Contact contacts[8];
		int		size;
		int		index;
	public:
		PhoneBook(void); // constructor
		~PhoneBook(void); //decnostructor
		int		getSize(void) const; // get the size
		void	addContact(std::string data[5]); // put the infos in the class
		void	displayContact(int i) const;
		void	displayPhonebook(void) const;
};

# endif
