#include <iostream>
#include <stack>
using namespace std;

struct Stack
{
	int index = 0;
	int capacity = 1000;
	int data[1000];

	void push(int value)
	{
		if (index < capacity)
			data[index++] = value;
		else
			cout << "Stack is full, element not added!" << endl;
	}

	int pop()
	{
		if (index > 0)
			return data[--index];
		else
		{
			cout << "Stack is empty, returned element invalid!" << endl;
			return INT_MIN;
		}
	}

	bool isEmpty()
	{
		return !index;
	}
};

bool checkParity(string text)
{
	Stack zasobnik;

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == '(')
			zasobnik.push(text[i]);

		if (text[i] == ')')
		{
			if (zasobnik.isEmpty())
				return false;

			zasobnik.pop();
		}
	}

	return zasobnik.isEmpty();
}

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int maxVPole(int *arr, int size)
{
	int n = INT_MIN;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > n)
		{
			n = arr[i];
		}
	}
	return n;
}

int isUnique(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int k = 0; k < size; k++)
		{
			if (arr[i] == arr[k] && i != k)
			{
				return false;
			}
		}
	}
	return true;
}

int isUnique2(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int k = i + 1; k < size; k++)
		{
			if (arr[i] == arr[k])
			{
				return false;
			}
		}
	}
	return true;
}

// Ⅿ∑∈

// Ⅿ(N) = 1 + Ⅿ(N-1) = 2 + Ⅿ(N-2) = 3 + Ⅿ(N-3) = 4 + Ⅿ(N-4) = i + Ⅿ(N-i) = N + Ⅿ(N-N) = N + Ⅿ(0) = N ∈ O(N)
// Ⅿ(N-1) = 1 + Ⅿ(N-2)
// Ⅿ(N-2) = 1 + M(N-3)
// Ⅿ(0) = 0
// i = N
int factorial(int n)
{
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

// Ⅿ(N) = Ⅿ(N-1) + 1 + Ⅿ(N-1) = 2Ⅿ(N-1) + 1
// Ⅿ(N-1) = 2Ⅿ(N-2) + 1
// Ⅿ(N) = 4Ⅿ(N-2) + 2 + 1
// M(N-2) = 2M(N-3) + 1
// Ⅿ(N) = 8Ⅿ(N-3) + 4 + 2 + 1
// Ⅿ(N-3) = 2Ⅿ(N-4) + 1
// M(N) = 16Ⅿ(N-4) + 8 + 4 + 2 + 1
// M(N) = 2^i * Ⅿ(N-i) + ... + 2^2 + 2^1 + 2^0
// Ⅿ(1) = 1
// i = N-1
// Ⅿ(N) = 2^(N-1) + 2^(N-2) + 2^(N-3) + ... + 2^2 + 2^1 + 2^0
// Предыдущий растёт быстрее чем следующий, поэтому
// M(N) = 2^N - 1 = 2^N ∈ O(2^N)
struct Towers
{
	stack<int> A;
	stack<int> B;
	stack<int> C;

	int noDisks = 4;

	Towers()
	{
		for (int i = noDisks; i > 0; i--)
		{
			A.push(i);
		}
	}

	void print()
	{
		print(A, B, C);
	}

	void print(stack<int> A, stack<int> B, stack<int> C)
	{
		for (int i = noDisks; i > 0; i--)
		{
			if (A.size() >= i)
			{
				cout << A.top() << "\t";
				A.pop();
			}
			else
			{
				cout << "|\t";
			}
		}
		for (int i = noDisks; i > 0; i--)
		{
			if (B.size() >= i)
			{
				cout << B.top() << "\t";
				B.pop();
			}
			else
			{
				cout << "|\t";
			}
		}
		for (int i = noDisks; i > 0; i--)
		{
			if (C.size() >= i)
			{
				cout << C.top() << "\t" << endl;
				C.pop();
			}
			else
			{
				cout << "|\t" << endl;;
			}
		}
	}

	void moveDisk(stack<int>& A, stack<int>& C)
	{
		if (isMoveValid(A, C))
		{
			C.push(A.top());
			A.pop();
		}
		else
		{
			A.push(C.top());
			C.pop();
		}

		print();
	}

	void solve()
	{
		solve(A, B, C, noDisks);
	}

	void solve(stack<int>& A, stack<int>& B, stack<int>& C, int noDisks)
	{
		if (noDisks == 1)
		{
			moveDisk(A, C);
			return;
		}

		solve(A, C, B, noDisks - 1);
		moveDisk(A, C);
		solve(B, A, C, noDisks - 1);
	}

	bool isMoveValid(stack<int>& A, stack<int>& C)
	{
		return (!A.empty() && (C.empty() || A.top() < C.top()));
	}
};

int main()
{
	Towers towers;
	towers.print();
	towers.solve();

	return 0;
}