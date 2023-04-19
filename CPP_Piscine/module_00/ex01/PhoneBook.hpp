/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joldosh <joldosh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:06:29 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/19 15:44:38 by joldosh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact array[8];
		int countContact;
	public:
		PhoneBook();
		~PhoneBook();
		void showCommand(void);
		void addContact(void);
		void printContacts(void);
		void searchCommand(void);
};

#endif 