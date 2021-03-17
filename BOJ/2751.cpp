#include <iostream>
#include <stdio.h>

using namespace std;

typedef int Base;

void MergeSortArray(Base * arr, int left, int right);
void Combine(Base * arr, int left, int mid, int right);

void MergeSortArray(Base * arr, int left, int right)
{
	int mid = (left + right) / 2;

	if (left < right) {
		MergeSortArray(arr, left, mid);	MergeSortArray(arr, mid + 1, right);
		Combine(arr, left, mid, right);
	}
}
void Combine(Base * arr, int left, int mid, int right)

{
	int i = left;
	int lL = left, rL = mid + 1;

	Base * tempArr = (Base *)malloc(sizeof(Base)*(right + 1));

	while (lL <= mid && rL <= right)
	{
		if (arr[lL] <= arr[rL])
			tempArr[i] = arr[lL++];
		else
			tempArr[i] = arr[rL++];

		i++;
	}


	if (lL <= mid)
		while (i <= right)
			tempArr[i++] = arr[lL++];
	else
		while (i <= right)
			tempArr[i++] = arr[rL++];

	for (i = left; i <= right; i++)
		arr[i] = tempArr[i];

	free(tempArr);
}

int main()
{
	int * A;
	int n;
	int i;
	
	//A = (int *)malloc(sizeof(int) * 1000000);

	cin >> n;
	A = (int *)malloc(sizeof(int) * n);
	
	for (i = 0; i < n; ++i)
		cin >> A[i];

	MergeSortArray(A, 0, n-1);

	for (i = 0; i < n; ++i)
		printf("%d \n",A[i]);
	
	free(A);

	return 0;
}
