/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<stdlib.h>

bool checkInHashTable(int * hash,int len, int numb){
	for (int i = 0; i < len; i++){
		if (hash[i] == numb)
			return true;
	}
	return false;
}

int findSingleOccurenceNumber(int *A, int len) {
	if (A == NULL || len <= 0)
		return -1;
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += A[i];
	int ans = sum % 3;
	if (ans != 0)
		return ans;
	else{
		int *hash = NULL, count = 0;
		for (int i = 0; i < len; i++){
			if (!checkInHashTable(hash, count, A[i]))
			{
				count++;
				hash = (int*)realloc(hash, sizeof(int)*count);
				hash[count - 1] = A[i];
			}
		}
		int sum1 = 0;
		for (int i = 0; i < count; i++)
			sum1 += hash[i];
		int temp = (sum - sum1) / 2;
		return sum1 - temp;
	}

}