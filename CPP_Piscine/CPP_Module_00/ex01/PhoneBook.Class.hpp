/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.Class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkaratae <dkaratae@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 10:06:29 by dkaratae          #+#    #+#             */
/*   Updated: 2023/04/25 13:17:16 by dkaratae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "Contact.Class.hpp"

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