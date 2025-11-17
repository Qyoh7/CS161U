#pragma once
#include <iostream>
using std::cout;
/*
		"1) Is a number odd or even?\n"
		"2) Is a number positive or negative?\n"
		"3) How many digits are in a number?\n"
		"4) What digit is at a specific position?\n"
		"5) Display the addition table.\n"
		"6) Display the multiplication table.\n"
		"7) Exit\n\n";
*/

int getData();
void displayMenu(int& menuChoice);
void processMenuChoice(int menuChoice);
void isOddEven(int num);
void isPosNeg(int num);
void findNumDigits(int num);
void findDigitAtPosition(int pos);
void displayAdditionTable();
void displayMultiplicationTable();
