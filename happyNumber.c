#include <stdio.h>
int isHappy(int n) {
	int lastOne = 0, nextNum = 0;

	if (n == 1)
		return 1;
	else if (n == 0 || n == 2 || n == 3)
		return 0;
	else
	{
		while (n)
		{
			lastOne = n % 10;
			nextNum += lastOne * lastOne;
			n = n / 10;
		}
		printf("%d\n", nextNum);
		return isHappy(nextNum);
	}
}
int main()
{
	//happy number
	isHappy(4);
}