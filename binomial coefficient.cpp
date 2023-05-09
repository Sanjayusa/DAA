// A Naive Recursive Implementation
#include <stdio.h>

// Returns value of Binomial Coefficient C(n, k)
int binomialCoeff(int n, int k)
{
	// Base Cases
	if (k > n)
		return 0;
	if (k == 0 || k == n)
		return 1;

	// Recur
	return binomialCoeff(n - 1, k - 1)
		+ binomialCoeff(n - 1, k);
}

/* Driver program to test above function*/
int main()
{
	int n,k;
	printf("enter the n :",n);
	scanf("%d",&n);
	printf("enter the k :");
	scanf("%d",&k);
	printf("Value of C(%d, %d) is %d ", n, k,
		binomialCoeff(n, k));
	return 0;
}

