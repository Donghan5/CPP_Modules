/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:41:00 by donghank          #+#    #+#             */
/*   Updated: 2024/10/31 23:36:36 by donghank         ###   ########.fr       */
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
			// getter part
			const std::string&	get_firstname(void) const; // read-only
			const std::string&	get_lastname(void) const; // read-only
			const std::string&	get_nickname(void) const; // read-only
			const std::string&	get_secret(void) const; // read-only
			const std::string&	get_number(void) const; // read-only

			// setter part
			void				set_firstname(std::string firstname); // write-only
			void				set_lastname(std::string lastname); // wirte-only
			void				set_nickname(std::string nickname); // write-only
			void				set_secret(std::string secret); // write-only
			void				set_number(std::string number); // write-only
};

# endif
