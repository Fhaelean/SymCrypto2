#include "Header.h"

#define SIZE 200000

int module(int chislo)
{
	while (chislo < 0)
	{
		chislo = chislo + 961;
	}
	while (chislo >= 961)
	{
		chislo = chislo - 961;
	}
	return chislo;
}

void extendedEuclid(int a, int b, int *d, int *x, int *y) // где б это модуль
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
int comparison(int *a, int *b, int *module)
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
		return result;
	}
	if (nod > 1 && (funkB % nod) != 0)
	{
		//cout << "comparison the comparison has no solutions" << endl;
		return 0;
	}
	if (nod > 1 && (funkB % nod) == 0)
	{
		int i = 0;
		int i2 = 0;
		int a1 = funkA / nod;
		int b1 = funkB / nod;
		int funkModule1 = funkModule / nod;
		while (i2 != nod)
		{
			if (i == 0)
			{
				result = (obrA*b1) % funkModule1;
				return result;
				i++;
			}
			i2++;
		}
	}
}

void bigrams()
{
	//int openBi[] = { 545, 417, 572, 403, 168 };     // ст, но, то, на, ен
	int openBi[] = { 168, 403, 572, 417, 545 };      //обратный порядок
	int *textbi = new int[SIZE];
	char cbi;
	int nbi = 0;

	FILE * doc = fopen("02.txt", "r");
	while (fscanf(doc, "%c", &cbi) != EOF)
	{
		if (cbi != ' ' && cbi != '\t' && cbi != '\n')
		{
			if (cbi == 'а')
				textbi[nbi] = 0;
			if (cbi == 'б')
				textbi[nbi] = 1;
			if (cbi == 'в')
				textbi[nbi] = 2;
			if (cbi == 'г')
				textbi[nbi] = 3;
			if (cbi == 'д')
				textbi[nbi] = 4;
			if (cbi == 'е')
				textbi[nbi] = 5;
			if (cbi == 'ж')
				textbi[nbi] = 6;
			if (cbi == 'з')
				textbi[nbi] = 7;
			if (cbi == 'и')
				textbi[nbi] = 8;
			if (cbi == 'й')
				textbi[nbi] = 9;
			if (cbi == 'к')
				textbi[nbi] = 10;
			if (cbi == 'л')
				textbi[nbi] = 11;
			if (cbi == 'м')
				textbi[nbi] = 12;
			if (cbi == 'н')
				textbi[nbi] = 13;
			if (cbi == 'о')
				textbi[nbi] = 14;
			if (cbi == 'п')
				textbi[nbi] = 15;
			if (cbi == 'р')
				textbi[nbi] = 16;
			if (cbi == 'с')
				textbi[nbi] = 17;
			if (cbi == 'т')
				textbi[nbi] = 18;
			if (cbi == 'у')
				textbi[nbi] = 19;
			if (cbi == 'ф')
				textbi[nbi] = 20;
			if (cbi == 'х')
				textbi[nbi] = 21;
			if (cbi == 'ц')
				textbi[nbi] = 22;
			if (cbi == 'ч')
				textbi[nbi] = 23;
			if (cbi == 'ш')
				textbi[nbi] = 24;
			if (cbi == 'щ')
				textbi[nbi] = 25;
			if (cbi == 'ь')
				textbi[nbi] = 26;
			if (cbi == 'ы')
				textbi[nbi] = 27;
			if (cbi == 'э')
				textbi[nbi] = 28;
			if (cbi == 'ю')
				textbi[nbi] = 29;
			if (cbi == 'я')
				textbi[nbi] = 30;
			nbi++;
		}
	}
	fclose(doc);
	int *decryptText = new int[nbi];
	int *decrypt = new int[nbi / 2];
	for (int i = 0; i < nbi; i += 2)
	{
		decrypt[i / 2] = textbi[i] * 31 + textbi[i + 1];
	}
	freopen("out.txt", "w", stdout);
	float *bi = new float[961];
	for (int i = 0; i < 961; ++i)
	{
		bi[i] = 0;
	}
	for (int i = 0; i < nbi; i += 2)
	{
		bi[textbi[i] * 31 + textbi[i + 1]]++;
	}
	for (int i = 0; i < 961; i++)
	{
		bi[i] = bi[i] / (float)(nbi);
	}

	multimap <float, int> big;
	for (int i = 0; i < 961; i++)
	{
		big.insert(pair <float, int>(bi[i], i));
	}
	/*for (auto i = big.begin(); i != big.end(); i++)
	{
		cout << i->second << " ";
		cout << (char)(i->second / 31 - 32);
		cout << (char)(i->second % 31 - 32) << "\t" << i->first << endl;
	}*/
	
	int *maxarr = new int[961];
	int maxBi[5] = {};
	int iterat = 0;
	for (auto i = big.begin(); i != big.end(); i++)
	{
		maxarr[iterat] = i->second;
		iterat++;
	}

	int j = 0;
	for (int i = 956; i < 961; i++)
	{
		maxBi[j] = maxarr[i];
		j++;
	}
	cout << "5 most popular bigrams: " << endl;
	for (int i = 0; i < 5; i++)
	{
		//cout << maxBi[i];
		if (maxBi[i] / 31 > -4 + 32)
		cout << (char)(maxBi[i] / 31 - 31);
		else
		cout << (char)(maxBi[i] / 31 - 32);

		if (maxBi[i] % 31 > -4 + 32)
		cout << (char)(maxBi[i] % 31 - 31) << endl;
		else
		cout << (char)(maxBi[i] % 31 - 32) << endl;
	}

	for (int i = 4; i > -1; i--)
	{
		if (i == 0)
		break;
		for (int j = i - 1; j > -1; j--)
		{
			//cout << "ch1 = " << maxBi[i] << " " << "ch2 = " << maxBi[j] << endl;
			int counti = i;
			int countj = j;
			for (int k = 0; k < 3; k++)
			{
				//cout << "op1 = " << openBi[counti] << " " << "op2 = " << openBi[countj] << endl;

				int open = module(openBi[counti] - openBi[countj]);
				int chiph = module(maxBi[j] - maxBi[i]);

				int modul = 961;
				int nod;
				int bigcof;
				int smallcof;
				extendedEuclid(open, modul, &nod, &bigcof, &smallcof);
				int obr;
				obrat(&smallcof, &nod, &modul, &obr);
				int resA = comparison(&open, &chiph, &modul);
				int resB = module(maxBi[j] - (openBi[counti] * resA));

				extendedEuclid(resA, modul, &nod, &bigcof, &smallcof);
				int obrA;
				obrat(&smallcof, &nod, &modul, &obrA);

				int txtc = 0;
				for (int i = 0; i < nbi / 2; i++)
				{
					int dec = module(obrA*(decrypt[i] - resB));
					if (dec / 31 > 28)
					{
						decryptText[txtc] = (dec / 31 - 31);
					}
					else
					{
						if (((char)(dec / 31 - 32)) == 'ь')
							decryptText[txtc] = -3;
						else
							decryptText[txtc] = (dec / 31 - 32);
					}

					if (dec % 31 > 28)
						decryptText[txtc + 1] = (dec % 31 - 31);
					else
						decryptText[txtc + 1] = (dec % 31 - 32); 
					
					txtc += 2;
				}
				counti--;
				countj--;
			
				int space = 0;
				map <char, int> charss;
				map <char, int>::iterator begins, ats, ends;

				for (unsigned int i = 0; i < nbi; i += 2)
				{
					if (decryptText[i] != ' ')
					{
						charss[decryptText[i]]++;
						charss[decryptText[i + 1]]++;
					}
					else space++;
				}
				begins = charss.begin();
				ends = charss.end();
				for (ats = begins; ats != ends; ats++)
				{
					if (ats->first == 'о' && (1.0 * (ats->second) / (nbi - space)) > 0.100000 && (1.0 * (ats->second) / (nbi - space)) < 0.110000)
					{
						cout << "a = " << resA << " b = " << resB << endl;
						for (int z = 0; z < nbi; z += 2)
						{
							cout << (char)decryptText[z] << (char)decryptText[z + 1];
						}
						goto label;
					}
				}
			}
		}
	}
	fclose(stdout);
	label: exit(0);
}

int main()
{
setlocale(LC_ALL, "Russian");

bigrams();

return EXIT_SUCCESS;
}