#include "Fractal.h"

#include <fstream>

int main(){

	// Code added by the instructor to test your functions
	// Point2Complex and FractalDivergeCount
	cout << endl << "Tests for Point2Complex" << endl;

	Complex c1 = Point2Complex(100, 100, -1.5, 1.6, 1000, -1.5, 1.6, 1000);
	cout << "TEST 1:  real: " << c1.real() << " imag: " << c1.imag() << endl;

	Complex c2 = Point2Complex(100, 100, -2.0, 1.0, 1000, -1.5, 1.5, 1000);
	cout << "TEST 2:  real: " << c2.real() << " imag: " << c2.imag() << endl;

	cout << "Tests for FractalDivergeCount" << endl;

	cout << "TEST 1: " << FractalDivergeCount(Complex(0, 0), Complex(0, 0), 100) << endl;
	
	cout << "TEST 2: " << FractalDivergeCount(Complex(0, 0), PHI - 1, 100) << endl;

	//YOUR CODE STARTS HERE
	Sierpinski("sierpinski", 1000, 1000000);
	Julia("Julia1", Complex(0.285,.01));
	Julia("Julia2", Complex(PHI - 2, PHI - 1));
	Mandelbrot("MandelBrot");
	//YOUR CODE ENDS HERE

	return 0;
}
