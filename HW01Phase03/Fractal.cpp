/*****
 * Author   : inclezd (modification of code from karroje and brinkmfwj) 
 * Date     : 2013-08-30
 * Purpose  : These functions are utility functions for generating bmp formatted fractals.
 * NOTES    : DO NOT MODIFY ANY OF THE CODE PROVIDED! Write your code below the line at the bottom of this file.
 *****/
#include <iostream>
#include <fstream>

//Windows.h is only needed for readHeader and writeHeader.
#include <Windows.h>
#include "BMPCanvas.h"
#include "Fractal.h"
#include <math.h>
#include <complex>

#pragma comment (lib, "winmm.lib")

using namespace std;

/**
 * Provided functions. DO NOT MODIFY!!!
 **/

// Random Number Generator seed: Seed the random number generator.  Seeds
// from clock if seed_value = 0.
void seedRNG(long seed_value) {
  if (seed_value > 0) 
	  srand(seed_value);
  else {
     double x = timeGetTime();  
     while (x == timeGetTime() );   // BETTER solution: get process ID
    srand(timeGetTime());
  }
}


// Return a random integer in the half-open interval [i,j).
// (Meaning: it returns a number ranging from i up to BUT NOT INCLUDING j.)
int randomNumber(int i, int j) {
	return (int)((j-i)*((1.0*rand()) / (RAND_MAX+1))) + i;
}

//Information on BMP format was provided by www.fileformat.info/format/bmp/egff.htm
void writeHeader(ostream& out, int width, int height){
  if (width % 4 != 0) {
    cerr << "ERROR: There is a windows-imposed requirement on BMP that the width be a multiple of 4.\n";
    cerr << "Your width does not meet this requirement, hence this will fail.  You can fix this\n";
    cerr << "by increasing the width to a multiple of 4." << endl;
    exit(1);
  }

	BITMAPFILEHEADER tWBFH;
	tWBFH.bfType = 0x4d42;
	tWBFH.bfSize = 14 + 40 + (width*height*3);
	tWBFH.bfReserved1 = 0;
	tWBFH.bfReserved2 = 0;
	tWBFH.bfOffBits = 14 + 40;

	BITMAPINFOHEADER tW2BH;
	memset(&tW2BH,0,40);
	tW2BH.biSize = 40;
	tW2BH.biWidth = width;
	tW2BH.biHeight = height;
	tW2BH.biPlanes = 1;
	tW2BH.biBitCount = 24;
	tW2BH.biCompression = 0;

	out.write((char*)(&tWBFH),14);
	out.write((char*)(&tW2BH),40);
}

//Information on BMP format was provided by www.fileformat.info/format/bmp/egff.htm
void readHeader(istream& in, int& width, int& height){
	BITMAPFILEHEADER tWBFH;
	BITMAPINFOHEADER tW2BH;
	in.read((char*)(&tWBFH),14);
	in.read((char*)(&tW2BH),40);

	width = tW2BH.biWidth;
	height = tW2BH.biHeight;
}

/*****************************************************************************************************/
/**
 * End of provided functions, your work goes below here. You may modify anything below this line, but
 * do NOT modify anything above this line.
 **/


/**
 * Functions for Phase02
 */

const Color WHITE = Color(255,255,255);
const Color BLACK = Color(0,0,0);

/*
 * Purpose: This function should use a BMPCanvas object to create an image of a white square on a black background.
 *          It should then save this image as square256.bmp. 
 * Coloring rule: The pixel at (x,y) should be white only if x >= 64,  x < 192, y >= 64, and y < 192
 */
void MakeSquare256(){
	BMPCanvas myImage("square256", 256, 256); 

	for (int x=0; x<256; x++) {
		for (int y=0; y <256; y++) {
			if ((x >= 64) && (x < 192) && (y >= 64) && (y <192)) {
				myImage.setPixel(x, y, WHITE);
			} else {
				myImage.setPixel(x, y, BLACK);
			}
		}
	}

	myImage.writeBMP();
}


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
void MakeSphere256() {
	BMPCanvas myImage("sphere256", 256, 256);
	
	for (int x=0; x<256; x++) {
		for (int y=0; y <256; y++) {
			int distanceSquared = (x-128)*(x-128) + (y-128)*(y-128);
			int color_value = 0;
			if(distanceSquared <= (90*90)){	        
				color_value = (255*((90*90)-distanceSquared))/(90*90);
			}
			Color c = Color(color_value, color_value, color_value);
			myImage.setPixel(x, y, c);
		}
	}

	myImage.writeBMP();
}


//Phase 03

Complex Point2Complex(int i, int j, double reMin, double reMax, int width, double imMin, double imMax, int height){
	 double a = reMin + i*(reMax-reMin)/(width - 1.0);
	 double b = imMin + j*(imMax-imMin)/(height - 1.0);
	 return Complex(a,b);
}

int FractalDivergeCount(Complex c, Complex k, int numIterations){
	Complex z = c;                          //cast it as a complex that is same as the first number.
	for (int i = 0; i < 100; i++){          //for loop used for keeping the function under running 100 times
		z = z*z + k;
			if (abs(z) > 2) {               //using abs() to check if it is over even if its postive or negative.
				return i;
			}	
	}
	return numIterations;
}


void Sierpinski(string fileName, int width, int n)	{
	BMPCanvas sierpinski(fileName, width, width);

	double xP1, yP1, xP2, yP2, xP3, yP3;
	//sets first point in the bottom left
	xP1 = 0;
	yP1 = 0;
	//sets second point in the bottom right
	xP2 = (width - 1);
	yP2 = 0;
	//sets third pointer in the center of the two
	xP3 = width / 2;
	yP3 = sqrt(3)*width / 2;

	double x = 0, y = 0;

	for (int i = 0; i < n; i++){
		int randVar = randomNumber(1, 4);

		if (randVar == 1) {
			x = (xP1 + x) / 2;
			y = (yP1 + y) / 2;
		}
		if (randVar == 2) {
			x = (xP2 + x) / 2;
			y = (yP2 + y) / 2;
		}
		if (randVar == 3) {
			x = (xP3 + x) / 2;
			y = (yP3 + y) / 2;
		}
		sierpinski.setPixel(x, y, BLACK);
	}
	sierpinski.writeBMP();
}

void Julia(string fileName, Complex k){

	BMPCanvas julia(fileName, 1000, 1000);
	const Color BLACK = Color(255, 255, 255);
	const Color WHITE = Color(0, 0, 0);
	

	for (int row = 0; row < julia.getWidth(); row++){
		for (int height = 0; height < julia.getHeight(); height++){
			Complex c = Point2Complex(row, height, -1.5 , 1.6, 1000, -1.5, 1.6, 1000);
            
			int z = FractalDivergeCount(c, k, 100);

			//double intensity = pow(sin((double)z), 2);
			//const Color GREY = Color (255.0 * intensity, 255.0 * intensity, 255.0 * intensity);
			
			if (z < 100) {
				julia.setPixel(row, height, BLACK);
			}
			else
				julia.setPixel(row, height, WHITE);
		}
	}
	julia.writeBMP();

}

void Mandelbrot(string fileName){
	BMPCanvas mandleBrot(fileName, 1000, 1000);
	const Color BLACK = Color(255, 255, 255);
	const Color WHITE = Color(0, 0, 0);

	for (int row = 0; row < mandleBrot.getWidth(); row++){
		for (int height = 0; height < mandleBrot.getHeight(); height++){
			Complex c = Point2Complex(row, height, -1.5, 1.6, 1000, -1.5, 1.6, 1000);

			int z = FractalDivergeCount(c, c, 100);

			if (z < 100) {
				mandleBrot.setPixel(row, height, BLACK);
			}
			else
				mandleBrot.setPixel(row, height, WHITE);
		}
	}
	mandleBrot.writeBMP();

}

