/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 22:02:58 by donghank          #+#    #+#             */
/*   Updated: 2024/10/31 23:36:25 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
#  define PHONEBOOK_HPP

// prevent to apply multiple header file (same)
# pragma once

/* standard library */
# include <iostream>
# include <string>
# include "Contact.hpp"

/* define the class */
class PhoneBook {
	private:
		Contact contacts[8];
		int		size;
		int		index;
	public:
		PhoneBook() : size(0), index(0) {}; // constructor
		int		get_size(void) const; // get the size
		void	add_contact(std::string data[5]); // put the infos in the class
		void	display_contact(int i) const;
		void	display_phonebook(void) const;
}

# endif
