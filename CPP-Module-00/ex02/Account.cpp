/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 23:15:14 by iengels           #+#    #+#             */
/*   Updated: 2023/10/02 00:34:04 by iengels          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(void) {}

Account::~Account(void)
{
    _displayTimestamp();

    _nbAccounts--;
	std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
}

Account::Account(int initial_deposit)
{
    _displayTimestamp();
    
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount() << ";created" << std::endl;
}


int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

int Account::checkAmount() const
{
    return _amount; 
}

void Account::_displayTimestamp() 
{
    std::time_t local = std::time(NULL);
    char timestamp[18];
    struct tm* convert = std::localtime(&local);
    
    std::strftime(timestamp, sizeof(timestamp), "[%Y%m%d_%H%M%S]", convert);
    std::cout << timestamp << " ";
}


void Account::displayAccountsInfos()
{
    _displayTimestamp();

    std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount();
    std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    
    std::cout << "index:" << _accountIndex << ";amount:" << checkAmount();
    std::cout << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;
    std::cout << ";amount:" << _amount + deposit << ";nb_deposits:" << ++_nbDeposits << std::endl;
    
    _amount += deposit;
    _totalNbDeposits++;
    _totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();

    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
    if (withdrawal > checkAmount()) 
    {
        std::cout << "refused" << std::endl;
        return false;
    }

    std::cout << withdrawal << ";amount:" << checkAmount() - withdrawal << ";nb_withdrawals:" << ++_nbWithdrawals << std::endl;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    
    return true;
}
