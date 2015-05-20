/*****
 * Author        : brinkmwj and karroje
 * Date          : 2012-01-17
 * Modified by   : inclezd (2015-01-22)
 * Sources       : All code is original
 * Purpose       : This class is designed to manage the reading and writing of image files in BMP format. 
 *                 See the notes below for more information on BMP format.
 * Note         : DO NOT CHANGE THIS FILE!!! All implementations of these functions should be in BMPCanvas.cpp
 *****/
#pragma once
//#pragma comment (lib, "math")

#include <string>
#include <iostream>

using namespace std;

/***
 * Color : A simple class to help track BMP color triplets.
 * This is intended to help keep track of the tree color components, and is only an aid to programming --
 * not a full class.  Hence the data attributes have been left public, with the intent of being accessed directly.
 * The constructors are provided for convenience.  
 * Note that, for a 24-bit BMP, the order of color components is blue, then red, then green.
 ***/
class Color {
public:
  Color() {}  // WARNING: If you use this, the colors will not be set to any particular value!
  Color(unsigned char iBlue, unsigned char iGreen, unsigned char iRed) { 
	  blue = iBlue; green = iGreen; red = iRed;
  } 

  unsigned char blue;
  unsigned char green;
  unsigned char red;
};




/***
 * BMP : The Windows Bitmap image format
 * BMP files are binary files that represent color images. In this assignment you won't need to know much
 * about them, except for the following:
 * A BMP file consists of a 54-byte header, followed by 3*width*height bytes of data.
 * I have provided two methods, readHeader and writeHeader, which should handle the header: You should not
 * have to worry about it. As for the rest: Each pixel of the image is represented by 3 bytes of data.
 * A byte is an 8-bit integer, so each byte represents a number between 0 and 255. Each pixel is made up
 * of a triple of these: For a 24-bit BMP, first is blue, then green, then red. 
 * So, for example, the triple (0, 0, 0) represents black, (255, 255, 255) represents white, 
 * (255, 0, 0) represents blue, (0, 255, 255) represents yellow, and so on.
 * Much more about RGB colors can be found by searching online.
 *
 * The key point is that, for each pixel of the image, you will want to call the write() method of your ofstream
 * three times, printing the three color values that will define the point's color.
 ***/

class BMPCanvas {

public:
	/* 
	 * Purpose: This constructor sets fileName, width, and height. It then allocates space for image.
	 *          This version of the constructor does NOT try to read <fileName>.bmp
	 *
	 *          Note that the the user does *not* provide the ".bmp" in his filename string.  (That is,
	 *          the user might pass the value "test", and the result will be the creation of a "test.bmp"
	 *          file.)  Your code will add the .bmp.
	 */
	BMPCanvas(string iFileName, int iWidth, int iHeight);

	/*
	 * Purpose: This constructor sets fileName, and then tries to read <fileName>.bmp. If the file does not
	 *          exist, your program is allowed to fail.
	 * Hint: Just use BMPCanvas::read() to read in the image.
	 *
	 *       Again: the user does note pass a ".bmp" -- your code adds it.
	 */
	BMPCanvas(string iFileName);

	/* Purpose: This is the default constructor. Set width = height = 0, image = NULL, and fileName = "" */
	BMPCanvas();

	/*
	 * Purpose: The purpose of this destructor is to make sure that the array pointed to by image is not leaked
	 *          Remember that, at the end of any function call for BMPCanvas, image should point to a valid array 
	 *          of Colors, or should set to NULL
	 */
	virtual ~BMPCanvas();

	/*
	 * Purpose: Attempt to read the file named <fileName>.bmp into image.
	 * Side effects: The old image should be de-allocated, the new size read into width and height,
	 *               and then image should be re-allocated to be the right size.
	 * Error handling: If file does not exist, or if there is any other error (such as not enough input, or
	 *                 an improperly formatted input file) your program is allowed to fail: You do not need to handle it.
	 * Hint: Don't forget to set the mode to (ios::in | ios::binary), and use the read() method of ifstream to
	 *       read in the data. Also, don't forget to call readHeader as appropriate.
	 */
	void read();

	/*
	 * Purpose: Write the image to a file named <fileName>.bmp in BMP format.
	 * Side effect: If a file of that name already exists, it is overwritten.
	 */
	void writeBMP();
	
	/*
	 * Purpose: Sets the width and height of the Canvas, and re-allocates image
	 *          so that it is the appropriate size.
	 * Side effects: All data in the original image is deleted. 
	 */
	void setDims(int iWidth, int iHeight);

	/*
	 * Purpose: Getters for the width and height
	 */
	int getWidth();
	int getHeight();

	/*
	 * Purpose: Set the pixel at coordinates (x,y) to color t.
	 * Error handling: If (x,y) is not within range, then do nothing.
	 */
	void setPixel(int x, int y, Color c);

	/*
	 * Purpose: Get the pixel value at coordinate (x,y).
	 * Error handling: If (x,y) is not within range, then return black (Color(0,0,0)).
	 */
	Color getPixel(int x, int y);

	/* 
	 * Purpose: Reset canvas by setting all bits to either black or white.
     * Set to white if white==true, black otherwise.
     *
	 */
	 void blank(bool white);

	/*
	 * Purpose: Getter and Setter for the fileName variable
	 */
	string getFileName();
	void setFileName(string iFileName);

private:
	int width;
	int height;
	//Note: This should NEVER include the file extension. The extension will be added in read() or write()
	string fileName;

	//Note: The image is stored in row-major order, so coordinate (x,y) corresponds to image[y*width+x]
	//Assert: At the end of any function call for BMPCanvas, image should point to a valid array of chars, or should
	//        be set to NULL
	Color* image;	
};
