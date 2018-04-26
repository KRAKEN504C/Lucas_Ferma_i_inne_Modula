#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <cmath>
#include <stdio.h>
#include <math.h>

using namespace std;

vector<int> to_binary(int a)
{
	vector<int> bin;
	double n = log2(a);

	if (a == 0) bin.push_back(0);
	for (int i = n; i >= 0; --i)
	{
		if (a >= pow(2, i))
		{
			bin.push_back(1);
			a -= pow(2, i);
		}
		else bin.push_back(0);
	}
	return bin;
}

int modulo(int a, int b)
{
	while (a < 0) a += b;
	a %= b;
	return a;
}

int mod(int a, int to_bin, int c)
{
	vector<int> b;
	b = to_binary(to_bin);
	vector<int> liczby;
	int wynik = 1;

	liczby.push_back(a);
	liczby[0] = modulo(liczby[0], c);
	for (int i = 1; i < b.size(); ++i)
	{
		liczby.push_back(pow(liczby[i - 1], 2));
		liczby[i] = modulo(liczby[i], c);
	}
	for (int i = 0; i < b.size(); ++i)
	{
		if (b[i] == 1)
		{
			wynik *= liczby[b.size() - i - 1];
			wynik = modulo(wynik, c);
		}
	}

	return wynik;
}


void Fermat(unsigned int p)
{
	unsigned long long x, y, z, m, n;

	x = (unsigned long long)ceil(sqrt(p));
	do
	{
		z = x * x - p;
		y = (unsigned long long)floor(sqrt(z));
		if (z == y * y)
		{
			m = x + y;
			n = x - y;
			if (n == 1) break;
			Fermat(m);
			Fermat(n);
			return;
		}
		x++;
	} while (x + y < p);
	cout << p << " ";


}

void Dodatek_do_Fermata()
{
	unsigned int p;

	cin >> p;
	while (p % 2 == 0)
	{
		p /= 2;
		cout << 2 << " ";
	}
	if (p > 1) Fermat(p);
	cout << endl;
}




int rozklad_na_czynniki(int n, vector <int> &wynik_rozkladu)
{
	int pierw, pom;

	pierw = sqrt(n);

	cout << "Czynniki pierwsze liczby " << n << ": ";

	int k = 2; //ustawiamy k na pierwsz¹ liczbê pierwsz¹

			   //rozk³ad liczby na czynniki pierwsze
	while (n>1 && k <= pierw)
	{
		while (n%k == 0) //dopóki liczba jest podzielna przez k
		{
			wynik_rozkladu.push_back(k);
			cout << k << " ";
			n /= k;
		}
		++k;
	}

	if (n>1)
		cout << n;
	cout << endl;
	return 0;
}

int lucasik(int n,int q)
{
	vector <int> rozklad;
	bool krok1 = 0, krok2 = 0;
	if (pow(q, n - 1) == 1 % n)
	{
		krok1 = 1;

		rozklad_na_czynniki(n - 1, rozklad);

		for (int i = 0; i < rozklad.size; i++)
		{
			cout << "Lucas w wiktorze" << endl;
			cout << rozklad[i];
		}

	}
	return 0;
}




int main()
{
	cout << mod(1897, 16, 16112) << endl;

	Dodatek_do_Fermata();

	//cout << lucas(297) << endl;

	//rozklad_na_czynniki(2296);

	system("Pause");

	return 0;
}




//#include <math.h>
//#include <stdio.h>
//#include <limits.h>
//#pragma precision=log10l(ULLONG_MAX)/2
//
//typedef enum { FALSE = 0, TRUE = 1 } BOOL;
//
//BOOL is_prime(int p) {
//	if (p == 2) return TRUE;
//	else if (p <= 1 || p % 2 == 0) return FALSE;
//	else {
//		BOOL prime = TRUE;
//		const int to = sqrt(p);
//		int i;
//		for (i = 3; i <= to; i += 2)
//			if (!(prime == p % i))break;
//		return prime;
//	}
//}
//
//BOOL is_mersenne_prime(int p) {
//	if (p == 2) return TRUE;
//	else {
//		const long long unsigned m_p = (1LLU << p) - 1;
//		long long unsigned s = 4;
//		int i;
//		for (i = 3; i <= p; i++) {
//			s = (s * s - 2) % m_p;
//		}
//		if (s == 0) {return FALSE;}
//	}
//}
//
//int main(int argc, char **argv) {
//
//	const int upb = log2l(ULLONG_MAX) / 2;
//	int p;
//	printf(" Mersenne primes:\n");
//	for (p = 2; p <= upb; p += 1) {
//		if (is_prime(p) && is_mersenne_prime(p)) {
//			printf(" %u", p);
//		}
//	}
//	printf("\n");
//
//	system("Pause");
//}