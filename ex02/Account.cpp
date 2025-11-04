// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Initialize static variables
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit) : _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    this->_accountIndex = this->_nbAccounts;
    this->_nbAccounts++;
    this->_totalAmount += initial_deposit;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
}

// Destructor
Account::~Account(void) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

// Static getter methods
int Account::getNbAccounts(void) {
    return Account::_nbAccounts;
}

int Account::getTotalAmount(void) {
    return Account::_totalAmount;
}

int Account::getNbDeposits(void) {
    return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return Account::_totalNbWithdrawals;
}

// Display accounts info (static method)
void Account::displayAccountsInfos(void) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts 
              << ";total:" << Account::_totalAmount 
              << ";deposits:" << Account::_totalNbDeposits 
              << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

// Make deposit
void Account::makeDeposit(int deposit) {
    int p_amount = this->_amount;
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << p_amount 
              << ";deposit:" << deposit 
              << ";amount:" << this->_amount 
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

// Make withdrawal
bool Account::makeWithdrawal(int withdrawal) {
    int p_amount = this->_amount;
    
    if (withdrawal > this->_amount) {
        Account::_displayTimestamp();
        std::cout << "index:" << this->_accountIndex 
                  << ";p_amount:" << p_amount 
                  << ";withdrawal:refused" << std::endl;
        return false;
    }
    
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";p_amount:" << p_amount 
              << ";withdrawal:" << withdrawal 
              << ";amount:" << this->_amount 
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return true;
}

// Check amount
int Account::checkAmount(void) const {
    return this->_amount;
}

// Display status
void Account::displayStatus(void) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex 
              << ";amount:" << this->_amount 
              << ";deposits:" << this->_nbDeposits 
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Display timestamp (private static method)
void Account::_displayTimestamp(void) {
    std::time_t now = std::time(0);
    std::tm* timeinfo = std::localtime(&now);
    
    std::cout << "[" << (1900 + timeinfo->tm_year)
              << std::setfill('0') << std::setw(2) << (1 + timeinfo->tm_mon)
              << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
              << "_"
              << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
              << std::setfill('0') << std::setw(2) << timeinfo->tm_min
              << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
              << "] ";
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
