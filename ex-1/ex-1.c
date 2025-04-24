#include<stdio.h>


int compute_sum(int n)
{
	int i;
	int result = 0;
	for (i = 1; i <= n; i++)
		result += i;
	return result;

}

int main(void)
{
	int sum;
	sum = compute_sum(100);
	
	printf("sum = %d\n", sum);
}