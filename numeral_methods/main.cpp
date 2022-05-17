#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;
/*
z = cosh(1+sqrt(1+x))*cos(sqrt(1+x-x^2))
phi = cosh(1+sqrt(1+x))=		| g = cos(sqrt(1+x-x^2)) =
= Sum(1+sqrt(1+x)^2k)/2k!)	| = Sum(pow(-1,k)*pow(sqrt(1+x-x*x),2*k)/(2k)!)
                       f = phi * z
3.9 < phi < 4.13				| 0.50 < g < 0.51
df/d(phi) = g					| df/d(g) = phi
|df/d(phi)|<=0.51 = 5.1*1e-1	| |df/d(g)| <= 3.9 
c_1 = 5.1 * 1e(-1)				| c_2 = 3.9
eps_1 = 1e-6/(3 * 5.1 * 1e-1)=  | eps_2 = 1e-6 / (3 * 4.12) = 
= 1e-5 / 15.3                   | =1e-6 / 12,39
                       eps_3 = 1e-6 / 3

*/
constexpr auto EPS1 = 1E-5 / 15.3;
constexpr auto EPS2 = 1E-6 / 12.39;
constexpr auto EPS3 = 1E-5 / 3;


double Z(double x) {
	return cosh(1+sqrt(1+x))*cos(sqrt(1+x-pow(x,2)));
}
double Z_Te(long double x) {
	long double g_sum = 0,phi_sum = 0;
	int k = 0;
	long double phi = pow((1 + sqrt(1 + x)), 2 * k);
	while (abs( phi) > EPS1) {
		k++;
		phi_sum += phi;
		
		phi = pow((1 + sqrt(1 + x)), 2 * k);
		for (int i = 1; i < 2 * k + 1; i++) // реализация деления на факториал, поскольку нужен факториал большого числа, которое не влезает ни в один тип данных
			phi /= i;
	}
	k = 0;
	double g = pow(-1, k) * pow(sqrt(1 + x - x * x), 2 * k) ;
	while (abs(g) > EPS2) {
		k++;
		g_sum += g;
		g = pow(-1, k) * pow(sqrt(1 + x - x * x), 2 * k) ;
		for (int i = 1; i < 2 * k + 1; i++) 
			g /= i;
	}
	return phi_sum * g_sum;
}

int main() {
	
	cout<<setw(15) << "x" << "|" << setw(15) << "Z(x)" << "|" << setw(15) << "Z_Te(x)"<< "|" << setw(15) << "delta:" << endl;
	for (long double x = 0.1; x <= 0.205; x += 0.01) {
		long double z = Z(x),z_t = Z_Te(x);
		cout << setw(15) << setprecision(9) << x <<"|" << setw(15) << z <<"|" << setw(15) << z_t << "|" << setw(15) << abs(z-z_t) << endl;
	}

	return 0;
}
