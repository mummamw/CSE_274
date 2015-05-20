/*****
 * Author      : karroje (modification of code written by brinkmfwj)
 * Date        : 2012-01-17
 * Modified by : inclezd (1/22/2015)
 * Purpose     : These functions are utility functions for generating random-dot stereograms.
 * Note        : DO NOT CHANGE THIS FILE!!! All implementations of these functions should be in Fractal.cpp
 *****/
#include <iostream>
#include <string>
#include <complex>

#pragma once

using namespace std;

typedef complex<double> Complex;   // For convenience.

#define PHI 1.6180339

/* Purpose: Seed the random number generator.  MUST BE CALLED EXACTLY ONCE, before 
 *          making any calls to the randomNumber function.  
 */
void seedRNG(long seed = 0);

/*
 * Purpose: Return a random integer with a uniform probability from the half-open interval [i,j).  
 *          Note: This means that it can return any number from i up to *but not including* j.
 *          Note also that the Random Number Generator must be seeded, and for a given seed you 
 *          will always get an identical sequence of numbers.  (Which is actually useful when debugging.)
 */
int randomNumber(int i, int j);


/*
 * Purpose: When writing a BMP file, call this function before you start writing your pixel data. You must
 *          create an instance of the class ofstream to be used for reading in the file, and you pass it,
 *          along with the width and height of the image, to writeHeader.
 *          Don't forget:
 *          1) You must use ios::out | ios::binary when creating your ofstream instance. Then pass your ofstream
 *             instance to this method, along with width and height.
 *          2) width must be a multiple of 4, or else the file will not be viewable in Windows.
 */
void writeHeader(ostream& out, int width, int height);

/*
 * Purpose: When reading a BMP file, call this function before you start reading the pixel data. You must
 *          create an ifstream for reading in the file. Be sure to use the mode ios::in | ios::binary when
 *          creating the ifstream object.
 *          Also: You will pass two variables to readHeader for width and height. Whatever variables you pass
 *          will get updated to contain the actual width and height of the input file. 
 */
void readHeader(istream& in, int& width, int& height);



/***
 * The functions below this line must be implemented by you
 ***/

/**
 * Phase: 01
 */

/*
 * Purpose: Print "Hello, World!" to cout (without the quotes)
 */
void helloworld();



/**
 * Phase: 02
 **/

/*
 * Purpose: This function should use a BMPCanvas object to create an image of a white square on a black background.
 *          It should then save this image as square256.bmp. 
 * Coloring rule: The pixel at (x,y) should be white only if x >= 64,  x < 192, y >= 64, and y < 192
 */
void MakeSquare256();

/*
 * Purpose: This function should use a BMPCanvas object to create an image of a "sphere" on a black background.
 *          It should save the image as sphere256.bmp. 
 
 Coloring rule: The center of the sphere will be at (128, 128). 
 The color of the pixel should be given by the following code:

	int distanceSquared = (x-128)*(x-128) + (y-128)*(y-128);
	int color_value = 0;
	if (distanceSquared <= (90*90)){	        
		color_value = (255*((90*90)-distanceSquared))/(90*90);
	}
	Color C = Color(color_value, color_value, color_value);   // Keeping all values the same dictates a shade of grey

 *          In other words, the color starts off white at the center, then falls off linearly with the squared 
 *          distance from the center
 */
void MakeSphere256();



/**
 * Phase: 03
 **/

/* 
 * Purpose: Convert point coordinates to a complex number.
 *          Used to convert a screen coordinate into a coordinate on the complex plane, where:
 *          * x,y are the coordinates of the point to be converted
 *          * reMin and reMax are the minimum and maximum values of the real component to be represented
 *          * imMin and imMax are the minimum and maximum values of the imaginary component to be represented
 *          * width and height are the dimensions of the canvas.
 *          The function will return the complex number a + bi where:
 *                  a = reMin + x*(reMax-reMin)/(width - 1.0)
 *                  b = imMin + y*(imMax-imMin)/(height - 1.0)
 *        
 *          NOTE: This function will be required for the generation of Julia and Mandelbrot fractals.  You will
 *                *NOT* need it for Sierpinski.
 */
Complex Point2Complex(int i, int j, double reMin, double reMax, int width, double imMin, double imMax, int height);

/*
 * Purpose: Determine how fast the "fractal function" f diverges by finding the smallest i such that z(i,c) > 2,
 *          but returning numIterations if z(j,c) <= 2 for all j from 0 to numIterations.
 *          As defined in the documentation, the "fractal function" z is calculated as follows:
 *               z(0,c) = c
 *               z(1,c) = z(0,c)*z(0,c) + k
 *               z(2,c) = z(1,c)*z(1,c) + k
 *               ...
 *               z(i,c) = z(i-1,c)*z(i-1,c) + k
 *          The function will return the first i such that z(i,c) > 2, or return numIterations if it finds that 
 *          z(i,c) <= 2 for all i < numIterations.
 * Important: when you compare a complex number to a real number (e.g., z(i, c) > 2 ), you should
 *            actually compare the absolute value of that complex number to the real number (e.g., abs(z(i,c)) > 2).
 */
int FractalDivergeCount(Complex c, Complex k, int numIterations);

/*
 * Purpose: Generate Sierpinski's Triangle by generating n points under the construction algorithm
 *          and using the points (0,0) and (xMax,0) as the lower points in the equilateral triangle.
 */
void Sierpinski(string fileName, int width, int n);

/*
 * Purpose: Generate a Julia set on a canvas with the adjustment value k.
 *          -- Canvas dimensions of 1000x1000
 *          -- Map this on the complex plane using reMin = imMin = -1.5 and reMax = imMax = 1.6
 *          -- Get this working in black-and-white, then add color.
 *
 * Black-and-white: For each point on the canvas, convert it to the appropriate complex number c and call
 *                  f = FractalDivergeCount(c, k, 100).  Plot a black point if < 100, and a white
 *                  point otherwise.
 *
 * Grey: We can add in shades of grey if we modify the intensity of the color by multiplying 255 by an "intensity
 *      modifier" -- a value between 0 and 1.  Two suggested modifiers that will work well are:
 *                     double intensity = f/100.0
 *      and
 *                     double intensity = pow( sin((double)f), 2) 
 *      now plot each point with color (255*intensity, 255*intensity, 255*intensity), where intensity is recalculated
 *      for each point.
 *
 * Color: Adding color just means making the intensity different for the different color fields.  For example:
 *        Using color (255*intensity, 0, 0) will result in shades of blue
 *        Using color (0, 255*intensity*intensity, 255*intensity) will results in shades of yellow.
 *        Or you could get really complicated:
 *                  Color col;
 *                  if (f < 50) {
 *                      col = Color(0, 9, 5*f);
 *					} else {
 *                      col = Color(f - 50, 10*(f - 50), 255);
 *                  }
 *        (There is no rationale for this last -- it just produces nice pictures.)
 */
void Julia(string fileName, Complex k);


/*
 * Purpose: Generate the image of a colored Mandelbrot set on an canvas of the specified height and weight.
 *          This is exactly like a Julia image, except that the call for complex number c, you set
 *          k = c.  (Hence call FractalDivergeCount(c, c, 100).)
 *          -- Canvas dimensions should still be 1000x1000.
 *          -- Use reMin = -2.0, reMax = 1.0, imMin = -1.5, imMax = 1.5
 * 
 *          Come up with a diferent coloring scheme than you used for the Julia sets.
 */
void Mandelbrot(string fileName);
