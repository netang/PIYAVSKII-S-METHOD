#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return 3*x*x*x*x/4+12*x*x*x+66*x*x+144*x+3;
}

double GetLipschitzConst(double a, double b)
{
	double tmpL, L = 0;
	double h = fabs(b - a)/10000;
	for(double cur = a + h; cur <= b; cur += h)
	{
		tmpL = fabs( f(cur) - f(cur - h) ) / h;
		if(tmpL > L) { L = tmpL; }
	}
	return L;
}

double GetPointIntersection(double Lx, double Rx, double L)
{
	return (f(Lx) - f(Rx))/(2*L) + (Lx + Rx)/2;
}

int main()
{
	double a = -7;
	double b = -1;
	double Lx = a;
	double Rx = b;
	double PIx, PILx, PIRx;
	double L = GetLipschitzConst(a, b);
	for(int i = 0; i < 26; i++)
	{
		PIx = GetPointIntersection(Lx, Rx, L);
		PILx = GetPointIntersection(Lx, PIx, L);
		PIRx = GetPointIntersection(PIx, Rx, L);
		if(f(PILx) <= f(PIRx))
		{
			Rx = PIx;
		}
		else
		{
			Lx = PIx;
		}
	}
	cout << GetPointIntersection(Lx, Rx, L) << endl;
	system("pause");
	return 0;
}