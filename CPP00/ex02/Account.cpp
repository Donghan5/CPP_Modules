/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghank <donghank@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:38:10 by donghank          #+#    #+#             */
/*   Updated: 2024/11/03 01:54:20 by donghank         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

/*
	variable initialize
*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
	define getter functions
*/
int	Account::getNbAccounts(void) {
	return (_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (_totalNbWithdrawals);
}

/*
	Show the timestamp of account
	To fit the form of the timestamp
*/
void	Account::_displayTimestamp(void) {
	time_t		curr_time;
	struct tm	*tm_local;

	time(&curr_time);
	tm_local = localtime(&curr_time);
	std::cout << "[" << (tm_local->tm_year + 1900) ;
	if (tm_local->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_mon + 1);
	if (tm_local->tm_mday < 10)
		std::cout << "0";
	std::cout << tm_local->tm_mday << "_";
	if (tm_local->tm_hour < 10)
		std::cout << "0";
	std::cout << tm_local->tm_hour;
	if (tm_local->tm_min < 10)
		std::cout << "0";
	std::cout << tm_local->tm_min;
	if (tm_local->tm_sec < 10)
		std::cout << "0";
	std::cout << (tm_local->tm_sec) << "]";
}

/*
	display the all infos of the Account
	to get current time from time_t and time struct
	like timeval in C
*/
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "Account: " << _nbAccounts << ";";
	std::cout << "Total: " << _totalAmount << ";";
	std::cout << "Deposits: " << _totalNbDeposits << ";";
	std::cout << "Withdrawals: " << _nbWithdrawals << std::endl;
}

/*
	constructors
*/
Account::Account(int initial_deposit) {
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "amount: " << this->_amount << ";";
	std::cout << "created" << std::endl;
}

/*
	deconstructors
*/
Account::~Account() {
	std::cout << "index: " << this->_accountIndex << ";";
	std::cout << "amount" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	
}

bool	Account::makeWithdrawal(int withdrawal) {

}

int	Account::checkAmount() const {
	return (this->_amount);
}

void	Account::displayStatus() const {

}
