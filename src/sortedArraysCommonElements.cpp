/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

bool stringCompare(char *str1, char *str2){
	int i = 0;
	while (str1[i] != '\0' || str2[i] != '\0'){
		if (str1[i] != str2[i])
			return false;
		i++;
	}
	if (str1[i] == '\0' && str2[i] == '\0')
		return true;
	return false;
}

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	transaction * ans = NULL;
	if (A == NULL || B == NULL)
		return NULL;
	int len = 0, i = 0, j = 0;
	while (i < ALen && j < BLen){
		if (A[i].amount < B[j].amount){
			i++;
		}
		else if (A[i].amount > B[j].amount){
			j++;
		}
		else{
			if (stringCompare(A[i].date, B[j].date) && stringCompare(A[i].description, B[j].description))
			{
				len++;
				ans = (transaction*)realloc(ans, sizeof(transaction)*len);
				ans[len - 1] = A[i];
				i++; j++;
			}
		}
	}
	return ans;
}