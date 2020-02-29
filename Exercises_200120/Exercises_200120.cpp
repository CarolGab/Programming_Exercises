#include <iostream>
using namespace std;


//from least efficient to more efficient

int isPrime(long long n) //linear algorithm
{
	if (n <= 1) 
	{
		return -2;
	}
	for (long i = 2; i < n / 2; i++)
	{
		if (n % i == 0)
		{
			return -1;
		}

	}
	return 0;
}

int primeNumber1(long long n) //linear algorithm
{
	if (n > 1) 
	{
		long long i;
		for (i = 2; (n % i != 0) && (i < n); i++) {}
		if (i >= n) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return -2;
	}

}

int primeNumber2(long long n) 
{
	if (n > 1)
	{
		long long i;
		for (i = 2; (n % i != 0) && (i <= sqrt(n)); i++) {}
		if (i >= sqrt(n)) {
			return 0;
		}
		else {
			return -1;
		}
	}
	else {
		return -2;
	}
}

int main()
{
	long long numb;
    std::cout << "Type in a number: ";
	std::cin >> numb;
	int r = primeNumber2(numb);
	switch (r)
	{
	case 0: {cout << numb << " is a prime"; cout << endl; break; }
	case -1: {cout << numb << " is not a prime"; cout << endl; break; }
	case -2: {cout << numb << " is not bigger than 1"; cout << endl; break; }
	default:
		break;
	}
}