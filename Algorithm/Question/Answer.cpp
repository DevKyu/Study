#include <iostream>
using namespace std;

/* Question 1 */
bool reverse(int N)
{
	int sum = 0;
	int num = N;

	while (num > 0)
	{
		sum = sum * 10 + num % 10;
		num /= 10;
	}

	if (N == sum)
		return true;
	else
		return false;
}

int Palindrome(int n, int m)
{
	int answer = 0;

	for (int num = n; num <= m; num++)
		answer += reverse(num);

	return answer;
}

/* Question 2 */
int Tournament(int n, int a, int b)
{
	int* arr = new int[n]();
	int round = 1;

	for(int i = 0; i < n; i++)
		arr[i] = i + 1;

	while (n != 1)
	{
		int idx = 0;
		for (int i = 0; i < n; i += 2)
		{
			if ((arr[i] == a || arr[i] == b) && (arr[i+1] == a || arr[i+1] == b))
				return round;
			else if (arr[i+1] == a || arr[i+1] == b)
				arr[idx++] = arr[i+1];
			else 
				arr[idx++] = arr[i];
		}

		n /= 2;
		round++;
	}
}