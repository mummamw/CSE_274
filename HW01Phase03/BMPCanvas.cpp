#include <iostream>
#include <fstream>
#include <string>

#include "BMPCanvas.h"
#include "Fractal.h"

using namespace std;

/* 
 * Purpose: This constructor sets fileName, width, and height. It then allocates space for image.
 *          This version of the constructor does NOT try to read <fileName>.bmp
 *
 *          Note that the the user does *not* provide the ".bmp" in his filename string.  (That is,
 *          the user might pass the value "test", and the result will be the creation of a "test.bmp"
 *          file.)  Your code will add the .bmp.
 */
BMPCanvas::BMPCanvas(string iFileName, int iWidth, int iHeight){
	fileName = iFileName;
	width = iWidth;
	height = iHeight;

	image = new Color[width*height];
}

/*
 * Purpose: This constructor sets fileName, and then tries to read <fileName>.bmp. If the file does not
 *          exist, your program is allowed to fail.
 * Hint: Just use BMPCanvas::read() to read in the image.
 *
 *       Again: the user does note pass a ".bmp" -- your code adds it.
 */
BMPCanvas::BMPCanvas(string iFileName){
	fileName = iFileName;
	image = new Color[1]; //a dummy for read()
	read();
}

/* Purpose: This is the default constructor. Set width = height = 0, image = NULL, and fileName = "" */
BMPCanvas::BMPCanvas(){
	fileName = "";
	width = height = 0; 
	
	image = NULL;
}


/*
 * Purpose: The purpose of this destructor is to make sure that the array pointed to by image is not leaked
 *          Remember that, at the end of any function call for BMPCanvas, image should point to a valid array 
 *          of Colors, or should set to NULL
 */
BMPCanvas::~BMPCanvas(){
	delete[] image; 

	image = NULL;
}

/*
 * Purpose: Attempt to read the file named <fileName>.bmp into image.
 * Side effects: The old image should be de-allocated, the new size read into width and height,
 *               and then image should be re-allocated to be the right size.
 * Error handling: If file does not exist, or if there is any other error (such as not enough input, or
 *                 and improperly formatted input file) your program is allowed to fail: You do not need to handle it.
 * Hint: Don't forget to set the mode to (ios::in | ios::binary), and use the read() method of ifstream to
 *       read in the data. Also, don't forget to call readHeader as appropriate.
 */
void BMPCanvas::read(){
	string extendedFileName = fileName + ".bmp";
	ifstream inFile(extendedFileName, ios::in | ios::binary);

	int iWidth, iHeight;
	readHeader(inFile, iWidth, iHeight);
	setDims(iWidth, iHeight);

	unsigned char blue;
	unsigned char green;
	unsigned char red;

	for (int x=0; x < width; x++){
		for (int y=0; y < height; y++){
			
			inFile.read((char*)&blue, 1);
			inFile.read((char*)&green, 1);
			inFile.read((char*)&red, 1);

			setPixel(x, y, Color(blue, green, red));
		}
	}

	inFile.close();
}

/*
 * Purpose: Write the image to a file named <fileName>.bmp in BMP format.
 * Side effect: If a file of that name already exists, it is overwritten.
 */
void BMPCanvas::writeBMP(){
	string extendedFileName = fileName + ".bmp";
	ofstream outFile(extendedFileName, ios::out | ios::binary);

	writeHeader(outFile, width, height);
	Color crtPixel;

	for (int y=0; y < height; y++){
		for (int x=0; x < width; x++){
			crtPixel = getPixel(x, y);
			outFile.write((char*)&crtPixel.blue, 1);
			outFile.write((char*)&crtPixel.green, 1);
			outFile.write((char*)&crtPixel.red, 1);
		}
	}
	
	outFile.close();
}
	
/*
 * Purpose: Sets the width and height of the Canvas, and re-allocates image
 *          so that it is the appropriate size.
 * Side effects: All data in the original image is deleted.  
 */
void BMPCanvas::setDims(int iWidth, int iHeight){
	width = iWidth;
	height = iHeight;

	delete[] image;
	image = new Color[width*height];
}

/*
 * Purpose: Getters for the width and height
 */
int BMPCanvas::getWidth() {
	return width;
}

int BMPCanvas::getHeight(){
	return height;
}

/*
 * Purpose: Set the pixel at coordinates (x,y) to color t.
 * Error handling: If (x,y) is not within range, then do nothing.
 */
void BMPCanvas::setPixel(int x, int y, Color c){
	if (x >= 0 && x < width && y >= 0 && y < height){
		image[y*width + x] = c;
	}
}

/*
 * Purpose: Get the pixel value at coordinate (x,y).
 * Error handling: If (x,y) is not within range, then return black (Color(0,0,0)).
 */
Color BMPCanvas::getPixel(int x, int y){
	if (x >= 0 && x < width && y >= 0 && y < height){
		return image[y*width+x];
	}

	return Color(0,0,0);
}

/* 
 * Purpose: Reset canvas by setting all bits to either black or white.
 * Set to white if white==true, black otherwise.
 *
 */
 void BMPCanvas::blank(bool white){
	 for (int i = 0; i < width*height; i++) {
		 if (white) {
			 image[i] = Color(255,255,255);
		 } else {
			 image[i] = Color(0,0,0);
		 }
	 }
 }


/*
 * Purpose: Getter and Setter for the fileName variable
 */
string BMPCanvas::getFileName(){
	return fileName;
}

void BMPCanvas::setFileName(string iFileName){
	fileName = iFileName;
}