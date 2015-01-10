#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return (3*x*x*x*x/4)+12*x*x*x+66*x*x+144*x+3;
}

double GetLipschitzConst()
{
	double tmpL, L = 0;
	double a = -7;
	double b = -1;
	double h = fabs(b - a)/1000;
	for(double cur = a + h; cur <= b; cur += h)
	{
		tmpL = fabs( f(cur) - f(cur - h) ) / h;
		if(tmpL > L) { L = tmpL; }
	}
	return L;
}

int main()
{
	cout << GetLipschitzConst() << endl;
	system("pause");
	return 0;
}