// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United               		  //
//                Created on  : Thu Jul 08 13:41:45 2021                      //
//                Last update : Fri Jan 08 21:59:06 2021                      //
//                Made by : Roman "Roms" Bitetti <roman@gbu.com>              //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*
** Initialization of the static variables to 0.
*/

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/*
** Constructor of the Account class.
** We initialize some variables using the initialization list.
** Then we print a timestamp and a log message.
** We increment the number total of account.
** And we update the ammount total of all the accounts with
** the value initial_deposit passed in parameter.
*/

Account::Account( int initial_deposit ) :
	_accountIndex(_nbAccounts), _amount(initial_deposit),
	_nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";created" << std::endl;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
}

/*
** Constructor of the Account class.
** We initialize some variables using the initialization list.
** We increment the number total of account and nothing more
** since there is no initial deposit.
*/

Account::Account( void ) :
	_accountIndex(_nbAccounts), _amount(0),
	_nbDeposits(0), _nbWithdrawals(0)
{
	Account::_nbAccounts++;
}

/*
** Destructor of the Account class.
** We print a timestamp and a log message.
** We decrement the number total of account.
** We update the amount total by substracting the amount of the account
** pointed by _amount.
*/

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:";
	std::cout << this->_amount << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= this->_amount;
}

/*
** Return the static int _nbAccounts of the class Account.
*/

int	Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}

/*
** Return the static int _totalAmount of the class Account.
*/

int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}

/*
** Return the static int _totalNbDeposits of the class Account.
*/

int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}

/*
** Return the static int _totalNbWithdrawals of the class Account.
*/

int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

/*
** Function to print a log message.
*/

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:"; 
	std::cout << Account::_totalAmount << ";deposits:";
	std::cout << Account::_totalNbDeposits << ";withdrawals:";
	std::cout << Account::_totalNbWithdrawals << std::endl;
}

/*
** Function to print the current date and time. (timestamp)
*/

void	Account::_displayTimestamp()
{
	time_t now = time(0);

	tm *ltm = localtime(&now);
	if ((1 + ltm->tm_mon) < 10)
		std::cout << "[" << 1900 + ltm->tm_year << "0" << 1 + ltm->tm_mon;
	else
		std::cout << "[" << 1900 + ltm->tm_year << 1 + ltm->tm_mon;
	if (ltm->tm_mday < 10)
		std::cout << "0" << ltm->tm_mday << "_";
	else
		std::cout << ltm->tm_mday << "_";
	if ((ltm->tm_hour) < 10)
		std::cout << "0" << ltm->tm_hour;
	else
		std::cout << ltm->tm_hour;
	if (ltm->tm_min < 10)
		std::cout << "0" << ltm->tm_min;
	else
		std::cout << ltm->tm_min;
	if (ltm->tm_sec < 10)
		std::cout << "0" << ltm->tm_sec << "] ";
	else
		std::cout << ltm->tm_sec << "] ";
}

/*
** This method calculs the new amount of the account by adding the previous
** amount and the deposit.
** Then a log message is printed and the values are updated.
*/

void	Account::makeDeposit( int deposit )
{
	int newAmount;

	newAmount = this->_amount + deposit;
	this->_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:";
	std::cout << this->_amount << ";deposit:" << deposit << ";amount:";
	std::cout << newAmount << ";nb_deposits:" << this->_nbDeposits;
	std::cout << std::endl;
	this->_amount = newAmount;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
}

/*
** This method calculs the new amount of the account by substracting the
** previous amount and the withdraw.
** If the new amount is more or equal to 0, then the withdraw is possible.
** A log message is printed and the values are updated.
** Otherwise, if the amount is negative, the withdraw is not possible.
** The withdraw is rejected.
*/

bool	Account::makeWithdrawal( int withdrawal )
{
	int newAmount;

	newAmount = this->_amount - withdrawal;
	_displayTimestamp();
	if (newAmount >= 0)
	{
		this->_nbWithdrawals++;
		std::cout << "index:" << this->_accountIndex << ";p_amount:";
		std::cout << this->_amount << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << newAmount << ";nb_withdrawals:";
		std::cout << this->_nbWithdrawals << std::endl;
		this->_amount = newAmount;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	else
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:";
		std::cout << this->_amount << ";withdrawal:refused" << std::endl;
		return (false);
	}
}

/*
** Bastard function.
*/

int		Account::checkAmount( void ) const
{
	if (this->_amount > 0)
		return (1);
	else
		return (0);
}

/*
** Function to print a log message.
*/

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";deposits:" << this->_nbDeposits << ";withdrawals:";
	std::cout << this->_nbWithdrawals << std::endl;
}
