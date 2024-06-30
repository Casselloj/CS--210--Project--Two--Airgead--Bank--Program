/* 
Name: Joseph Cassello Jr.
Date: June 9, 2024
Purpose: Program for Airgead Banking Investment Calculator
*/

#include "InvestmentCalculator.h"
#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

double getValidDoubleInput(const string& prompt) {
	double value;
	cout << prompt;
	while (!(cin >> value) || value < 0) {
		cout << "Invalid input. Please enter a positive number: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return value;
}

int getValidIntInput(const string& prompt) {
	int value;
	cout << prompt;
	while (!(cin >> value) || value <= 0) {
		cout << "Invalid input. Please enter a positive integer: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return value;
}

int main() {
	InvestmentCalculator calculator;
	char continueTesting = 'y';

	while (continueTesting == 'y' || continueTesting == 'Y') {
		/* Displays menu to the user */
		cout << "**********************************" << endl;
		cout << "********* Data Input *************" << endl;
		cout << "Initial Investment Amount: " << endl;
		cout << "Monthly Deposit: " << endl;
		cout << "Annual Interest: " << endl;
		cout << "Number of years: " << endl;
		system("PAUSE");

		/* Gather user input */
		cout << "**********************************" << endl;
		cout << "********* Data Input *************" << endl;
		double initialInvestment = getValidDoubleInput("Initial Investment Amount: $");
		double monthlyDeposit = getValidDoubleInput("Monthly Deposit: $");
		double annualInterest = getValidDoubleInput("Annual Interest: %");
		int years = getValidIntInput("Number of years: ");
		system("PAUSE");

		/* Sets values in calculator */
		calculator.setInitialInvestment(initialInvestment);
		calculator.setMonthlyDeposit(monthlyDeposit);
		calculator.setAnnualInterest(annualInterest);
		calculator.setYears(years);

		calculator.calculateYearEndBalanceNoDeposits();
		calculator.calculateYearEndBalanceWithDeposits();

		calculator.displayResults(); /* Display results */

		cout << "\nWould you like to teset different values? (y/n): "; /* Ask user to test different values or exit program */
		cin >> continueTesting;
	}

	cout << "Thank you for using the Airgead Banking Investment Calculator! Goodbye!\n";

	return 0;
}