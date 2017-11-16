#include "Header.h"

int module(int module, int modul)
{
	while (module > modul)
	{
		module = module - modul;
	}
	while (module < 0)
	{
		module = module + modul;
	}
	return module;
}
void extendedEuclid(int a, int b, int *d, int *x, int *y)
{
	int q;
	int r;
	int x1;
	int x2;
	int y1;
	int y2;
	if (b == 0)
	{
		*d = a;
		*x = 1;
		*y = 0;
	}
	if (a == 0)
	{
		*d = b;
		*x = 0;
		*y = 1;
	}
	x1 = 0; x2 = 1; y2 = 0; y1 = 1;
	while (b > 0)
	{
		q = a / b;
		r = a - q*b;
		*x = x2 - q *x1;
		*y = y2 - q*y1;
		a = b;
		b = r;
		x2 = x1;
		x1 = *x;
		y2 = y1;
		y1 = *y;
	}
	if (a < b)
	{
		*d = a;
		*x = x2;
		*y = y2;
	}
	if (a > b)
	{
		*d = a;
		*x = y2;
		*y = x2;
	}
}
void obrat(int *d, int *x, int *b, int *obr)
{
	int d2 = *x;
	if (d2 != 1)
	{
		*obr = *d;
	}
	else
	{
		*obr = *d;
		*obr = (*obr % *b + *b) % *b;
	}
}
void comparison(int *a, int *b, int *module)
{
	int funkA = *a;
	int funkB = *b;
	int funkModule = *module;
	int nod;
	int bigcof;
	int smallcof;

	extendedEuclid(funkA, funkModule, &nod, &bigcof, &smallcof);
	int obrA;
	obrat(&smallcof, &nod, &funkModule, &obrA);
	int result;
	if (nod == 1)
	{
		result = (obrA*funkB) % funkModule;
		cout << funkA << "*x = " << funkB << "mod" << funkModule << endl;
		cout << "x = " << result;
	}
	if (nod > 1 && (funkB % nod) != 0)
	{
		cout << "comparison the comparison has no solutions" << endl;
	}
	if (nod > 1 && (funkB % nod) == 0)
	{
		int i = 0;
		int i2 = 0;
		int a1 = funkA / nod;
		int b1 = funkB / nod;
		int funkModule1 = funkModule / nod;
		cout << funkA << "*x = " << funkB << "mod" << funkModule << endl;
		cout << "x = ";
		while (i2 != nod)
		{
			if (i == 0)
			{
				result = (obrA*b1) % funkModule1;
				cout << result;
				i++;
			}
			if (i < nod && i2 != 0)
			{
				result = result + funkModule1;
				cout << ", " << result;
			}
			i2++;
		}
	}
}
int main()
{
	int a;
	int modul;
	cout << "a = ";
	cin >> a;
	cout << "mod = ";
	cin >> modul;
	int nod;
	int bigcof;
	int smallcof;
	a = module(a, modul);
	extendedEuclid(a, modul, &nod, &bigcof, &smallcof);

	int obr;
	obrat(&smallcof, &nod, &modul, &obr);
	cout << "Inverse element = " << obr << endl;
	int b;
	cout << "b = ";
	cin >> b;
	system("cls");
	comparison(&a, &b, &modul);
	cout << "(mod " << modul << ")" << endl;
	system("pause");
}
