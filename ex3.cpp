
#include <iostream>

using namespace std;

int* Merge(int* A, int* B, size_t n1, size_t n2);
void PrintArray(int* A, size_t n);

void MergeSort(int* A, size_t n)
{
	if (n <= 1) return;
	if (n == 2) 
	{
		if (A[0] > A[1]) 
		{
			int temp = A[0];
			A[0] = A[1];
			A[1] = temp;
		}
	}
	else 
	{
		size_t n1 = n / 2;
		size_t n2 = n - n1;
		int* B = new int[n1];
		int* C = new int[n2];
		for (size_t i = 0; i < n1; i++)
		{
			B[i] = A[i];
		}
		for (size_t i = 0; i < n2; i++)
		{
			C[i] = A[i + n1];
		}
		//PrintArray(B, n1);
		//PrintArray(C, n2);
		MergeSort(B, n1);
		MergeSort(C, n2);
		int* merge = Merge(B, C, n1, n2);
		for (size_t i = 0; i < n; i++)
		{
			A[i] = merge[i];
		}
		delete[] B;
		delete[] C;
		delete[] merge;
	}
}

int* Merge(int* A, int* B, size_t n1, size_t n2)
{
	size_t n3 = n1 + n2;
	int* C = new int[n3] {};
	int pointerA = 0;
	int pointerB = 0;
	int pointerC = 0;
	while (n1 != pointerA || n2 != pointerB)
	{
		if (n1 == pointerA) 
		{
			for (; pointerB < n2; pointerB++)
			{
				C[pointerC] = B[pointerB];
				pointerC++;
			}
		}
		else if (n2 == pointerB)
		{
			for (; pointerA < n1; pointerA++)
			{
				C[pointerC] = A[pointerA];
				pointerC++;
			}
		}
		else
		{
			if (A[pointerA] < B[pointerB])
			{
				C[pointerC] = A[pointerA];
				pointerA++;
				
			}
			else
			{
				C[pointerC] = B[pointerB];
				pointerB++;
			}
			pointerC++;
		}
		
	}
	PrintArray(C, n3);
	return C;
}

void PrintArray(int* A, size_t n) 
{
	for (int i = 0; i < n; i++) 
	{
		cout << A[i] << " ";
	}
	cout << "\n";
}



int main()				   
{						   
	int A[1] = { 1 };  
	int B[7] = { 5, 1, 3, 8, 9, 1, 2 };  
						  
	PrintArray(B, size(B));
	MergeSort(B, size(B));
	PrintArray(B, size(B));
}

