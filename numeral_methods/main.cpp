#include <iostream>
#include <cmath>


using namespace std;
/*
z = cosh(1+sqrt(1+x^2))*cos(sqrt(1+x-x^2))
phi = cosh(1+sqrt(1+x^2))=		| g = cos(sqrt(1+x-x^2)) =
= Sum(1+sqrt(1+x^2)^2k)2k!
                       f = phi * z
3.7 < phi < 3.9					| 0.50 < g < 0.51
df/d(phi) = g					| df/d(g) = phi
|df/d(phi)|<=0.51 = 5.1*1e-1	| |df/d(g)| <= 3.9 
c_1 = 5.1 * 1e(-1)				| c_2 = 3.9
eps_1 = 1e-6/(3 * 5.1 * 1e-1)=  | eps_2 = 1e-6 / (3 * 3.9) = 
= 1e-5 / 15.3                   | =1e-6 / 11.7
                       eps_3 = 1e-6 / 3

*/
constexpr auto EPS1 = 1E-5 / 15.3;
constexpr auto EPS2 = 1E-6 / 11.3;
constexpr auto EPS3 = 1E-5 / 3;

double Z(double x) {
	return cosh(1+sqrt(1+pow(x,2)))*cos(sqrt(1+x-pow(x,2)));
}
double Z_Te(double x) {
	double g_sum = 0,phi_sum = 0;
	pair<double, double> phi = make_pair(0., 0.);
	while (abs(phi.second - phi.first) > EPS1) {}
	
	return phi_sum * g_sum;
}

int main() {
	for (double x = 0.1; x <= 0.205; x += 0.01) {
		cout << x <<": " << Z(x) << endl;
	}
	return 0;
}