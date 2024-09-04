// coding=utf-8
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdio.h>
#include <iomanip>
#define MAXSIZE 1000
using namespace std;
// This is a easy calculator for the probability of StarRail
class sample
{
public:
	char date[20];
	int TiLi;
	int zise;
	int lanse;
	int luse;
};
int Sum(sample a[], int n)
{
	double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
	for (int i = 0; i < n; i++)
	{
		sum1 += a[i].TiLi;
		sum2 += a[i].zise;
		sum3 += a[i].lanse;
		sum4 += a[i].luse;
	}
	int times = sum1 / 10;

	cout << "�ܼƴ����� " << times << endl;
	cout << "��ɫ������ " << sum2 << endl;
	cout << "��ɫ������ " << sum3 << endl;
	cout << "��ɫ������ " << sum4 << endl;
	cout << endl;
	cout << "ͳ����ɫ���ʣ� " << fixed << setprecision(2) << 100 * sum2 / times << "%" << endl;
	cout << "ͳ����ɫ���ʣ� " << fixed << setprecision(2) << 100 * sum3 / times << "%" << endl;
	cout << "ͳ����ɫ���ʣ� " << fixed << setprecision(2) << 100 * sum4 / times << "%" << endl;
	return 0;
}

int main()
{
	sample a[MAXSIZE];
	// cin >> a.date >> a.TiLi >> a.zise >> a.lanse >> a.luse;
	FILE *pf = fopen("C:\\Users\\AnteRay\\Desktop\\test.txt", "r");
	if (pf == NULL)
	{
		perror("fopen()");
		return 1;
	}
	int i = 0;
	while (!feof(pf))
	{
		fscanf(pf, "%s %d  %d %d %d", &a[i].date, &a[i].TiLi, &a[i].zise, &a[i].lanse, &a[i].luse);
		i++;
	}
	Sum(a, i);
	fclose(pf);
	pf = NULL;

	system("pause");
	return 0;
}
