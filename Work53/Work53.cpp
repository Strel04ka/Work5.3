#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double h(const double x);

int main()
{
	double rp, rk, z;
	int n = 0;

	cout << "rp = "; cin >> rp;
	cout << "rk = "; cin >> rk;
	cout << "n = "; cin >> n;

	double r = rp;
	double dr = (rk - rp) / n;
	cout << "--------------------" << endl;
	cout << "| "<<setw(2) << "r" << setw(3) << " | " << setw(6)<<  "z" << setw(6)<<" |" << endl;
	cout << "--------------------" << endl;
	while (r <= rk)
	{
		z = h(r + 1) + pow(h(r * r + 1),2) + 1;
		cout <<"| " << setw(2)<<setprecision(2) << r << " |  " << setw(3) <<setprecision(4)<< z <<setw(2)<<" |"<< endl;
		r += dr;
	}
	cout << "--------------------" << endl;
}
double h(const double x) 
{
	if (abs(x) >= 1 && x == 0)
		return  (cos(x) + 1) / exp(x);
	else {
		double S = 0;
		int N = 0;
		double a = x*x;
		S = a;
		do {
			N++;    
			double R = pow(x, 4) / 6;
			a *= R;
			S += a;
		} while (N <= 6);
		return S;
	}
}	