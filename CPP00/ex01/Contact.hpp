/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:41:00 by donghank          #+#    #+#             */
/*   Updated: 2024/11/03 19:53:23 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
#  define CONTACT_HPP

// prevent to apply multiple header file (same)
# pragma once

/* standard library */
#include <iostream>
#include <string>

/* define the class */
class Contact {
	private:
			std::string	firstname;
			std::string	lastname;
			std::string	nickname;
			std::string	secret;
			std::string	number;
	public:
			// Constructor and deconstructor
			Contact(void);
			~Contact(void);
			// getter part
			const std::string&	getFirstname(void) const; // read-only
			const std::string&	getLastname(void) const; // read-only
			const std::string&	getNickname(void) const; // read-only
			const std::string&	getSecret(void) const; // read-only
			const std::string&	getNumber(void) const; // read-only

			// setter part
			void				setFirstname(std::string firstname); // write-only
			void				setLastname(std::string lastname); // wirte-only
			void				setNickname(std::string nickname); // write-only
			void				setSecret(std::string secret); // write-only
			void				setNumber(std::string number); // write-only
};

# endif
