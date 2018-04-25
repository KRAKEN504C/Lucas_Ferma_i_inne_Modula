#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include <cmath>
#include <stdio.h>

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






int lucasik(int n,int q)
{
	// declaring base values
	// for positions 0 and 1
	int a = 2, b = 1, c, i;

	if (n == 0)
		return a;

	// generating number
	for (i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}




int main()
{
	cout << mod(1897, 16, 16112) << endl;

	Dodatek_do_Fermata();

	//cout << lucas(297) << endl;

	system("Pause");

	return 0;
}