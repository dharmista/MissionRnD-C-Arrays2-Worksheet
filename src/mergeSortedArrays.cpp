/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	int i = 0, j = 0, len = 0;
	transaction * ans = NULL;
	while (i != ALen && j != BLen){
		if (A[i].amount < B[j].amount){
			len++;
			ans = (transaction*)realloc(ans, sizeof(transaction)*len);
			ans[len - 1] = A[i];
			i++;
		}
		else if (A[i].amount > B[j].amount){
			len++;
			ans = (transaction*)realloc(ans, sizeof(transaction)*len);
			ans[len - 1] = B[j];
			j++;
		}
		else{
			len+=2;
			ans = (transaction*)realloc(ans, sizeof(transaction)*len);
			ans[len - 1] = A[i];
			ans[len - 2] = B[j];
			i++; j++;
		}
	}
	if (i != ALen){
		while (i != ALen){
			len++;
			ans = (transaction*)realloc(ans, sizeof(transaction)*len);
			ans[len - 1] = A[i];
			i++;
		}
	}
	else{
		while (j != BLen){
			len++;
			ans = (transaction*)realloc(ans, sizeof(transaction)*len);
			ans[len - 1] = B[j];
			j++;
		}
	}
	return ans;
}