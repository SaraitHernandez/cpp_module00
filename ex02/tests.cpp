#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int main(void) {
	Account::displayAccountsInfos();
	
	Account account1(42);
	Account account2(54);
	Account account3(957);
	Account account4(432);
	Account account5(1234);
	Account account6(0);
	Account account7(754);
	Account account8(1654);
	
	Account::displayAccountsInfos();
	
	account1.makeDeposit(5);
	account1.makeDeposit(765);
	account1.makeWithdrawal(19);
	account1.makeWithdrawal(34);
	account1.makeWithdrawal(657);
	
	account2.makeDeposit(50);
	account2.makeDeposit(765);
	account2.makeWithdrawal(19);
	account2.makeWithdrawal(34);
	account2.makeWithdrawal(657);
	
	account3.makeDeposit(5);
	account3.makeDeposit(765);
	account3.makeWithdrawal(19);
	account3.makeWithdrawal(34);
	account3.makeWithdrawal(657);
	
	account4.makeDeposit(5);
	account4.makeDeposit(765);
	account4.makeWithdrawal(19);
	account4.makeWithdrawal(34);
	account4.makeWithdrawal(657);
	
	account5.makeDeposit(5);
	account5.makeDeposit(765);
	account5.makeWithdrawal(19);
	account5.makeWithdrawal(34);
	account5.makeWithdrawal(657);
	
	account6.makeDeposit(5);
	account6.makeDeposit(765);
	account6.makeWithdrawal(19);
	account6.makeWithdrawal(34);
	account6.makeWithdrawal(657);
	
	account7.makeDeposit(5);
	account7.makeDeposit(765);
	account7.makeWithdrawal(19);
	account7.makeWithdrawal(34);
	account7.makeWithdrawal(657);
	
	account8.makeDeposit(5);
	account8.makeDeposit(765);
	account8.makeWithdrawal(19);
	account8.makeWithdrawal(34);
	account8.makeWithdrawal(657);
	
	Account::displayAccountsInfos();
	return 0;
} 