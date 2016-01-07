/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

bool verifyDate(char * date){
	if (date[2] != '-' || date[5] != '-')
		return 1;
	int month = (date[3] - '0') * 10 + date[4] - '0';
	if (month<0 || month>12)
		return false;
	int day = (date[0] - '0') * 10 + date[1] - '0';
	if (day<0 && day>31)
		return false;
	bool flag_for_leap;
	//----------Verify Year-------------
	//----------Leap Year---------------
	int year = (date[9] - '0') + (date[8] - '0') * 10 + (date[7] - '0') * 100 + (date[6] - '0') * 1000;
	if (year % 4 == 0){
		if (year % 100 == 0){
			flag_for_leap = true;
		}
		flag_for_leap = true;
	}
	else
		flag_for_leap = false;
	//---------Checking Dates-------------
	if (month == 2){
		if (flag_for_leap){
			if (day > 29)
				return false;
		}
		else{
			if (day > 28)
				return false;
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if (day > 31)
			return false;
	}
	else{
		if (day > 30)
			return false;
	}
	return true;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (!verifyDate(date))
		return NULL;
	int count = 0;
	bool compl = false;
	//--------First compare year-----------
	for (int i = 0; i < len; i++)
	{
		compl = false;
		for (int j = 6; j <= 9; j++){
			if (date[j] > Arr[i].date[j]){
				compl = true;
				break;
			}
			else if (date[j] < Arr[i].date[j]){
				count++;
				compl = true;
				break;
			}
		}
		if (compl != true){
			for (int j = 3; j <= 4; j++){
				if (date[j] > Arr[i].date[j]){
					compl = true;
					break;
				}
				else if (date[j] < Arr[i].date[j]){
					count++;
					compl = true;
					break;
				}
			}
		}
		if (compl != true){
			for (int j = 0; j <= 1; j++){
				if (date[j] > Arr[i].date[j]){
					compl = true;
					break;
				}
				else if (date[j] < Arr[i].date[j]){
					count++;
					compl = true;
					break;
				}
			}
		}
	}
	return count;
}