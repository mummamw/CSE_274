#include "BMPCanvas.h"
#include "Fractal.h"

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

unsigned char blue = 0, green = 0, red = 0;


	BMPCanvas::BMPCanvas(string iFileName, int iWidth, int iHeight){     //needs write header and ofstream 
	  string extendedFileName = fileName + ".bmp";
	  ofstream outFile(extendedFileName, ios::out | ios::binary);

	  image = new Color[width*height];

	  writeHeader(outFile, iWidth, iHeight); 
	}

	BMPCanvas::BMPCanvas(string iFileName){							   //needs read
		//string extendedFileName = iFileName + ".bmp";
		image = new Color[width*height];
		//BMPCanvas::read(extendedFileName);
	}

	BMPCanvas::BMPCanvas(){
		int width = 0, height = 0;
		Color* image  = NULL;
		string fileName = "";
	}
	 
	BMPCanvas::~BMPCanvas(){
		delete[] image;
		image = NULL;
	}

	void BMPCanvas::read(){
		string extendedFileName = fileName + ".bmp";
		ofstream inFile(extendedFileName, ios::in | ios::binary);
	};

	void BMPCanvas::writeBMP(){
		string extendedFileName = fileName + ".bmp";
		ofstream outFile(extendedFileName, ios::out | ios::binary);

		writeHeader(outFile, width, height);
		for (int row = 0; row < width; row++){ // row == 0 is the bottom row
			for (int col = 0; col < height; col++){ // col == 0 is the leftmost column
				outFile.write((char*)&blue, 1);
				outFile.write((char*)&green, 1);
				outFile.write((char*)&red, 1);
			}
		}
	
	};

	void BMPCanvas::setDims(int iWidth, int iHeight){
		width = iWidth;
		height = iHeight;
	};

	int BMPCanvas::getWidth(){
		return width;
	};

	int BMPCanvas::getHeight(){
		return height;
	};

	void BMPCanvas::setPixel(int x, int y, Color c){
		if (x*y > width*height); //return black
		else{
			//outFile.write((char*)&blue, 1);
		}


	}; 

	Color BMPCanvas::getPixel(int x, int y){
		return image[y*width + x];
	};

	void BMPCanvas::blank(bool white){
		string extendedFileName = fileName + ".bmp";
		ofstream outFile(extendedFileName, ios::out | ios::binary);

		if (white){
			unsigned char blue = 0, green = 0, red = 0;
			BMPCanvas::read();
			for (int row = 0; row < width; row++){ // row == 0 is the bottom row
				for (int col = 0; col < height; col++){ // col == 0 is the leftmost column
					outFile.write((char*)&blue, 1);
					outFile.write((char*)&green, 1);
					outFile.write((char*)&red, 1);
				}
			}
		}
		else {
			unsigned char blue = 255, green = 255, red = 255;
			BMPCanvas::read();
			for (int row = 0; row < width; row++){ // row == 0 is the bottom row
				for (int col = 0; col < height; col++){ // col == 0 is the leftmost column
					outFile.write((char*)&blue, 1);
					outFile.write((char*)&green, 1);
					outFile.write((char*)&red, 1);
				}
			}
		}
	};


	string BMPCanvas::getFileName(){
		return BMPCanvas::fileName;
	};

	void BMPCanvas::setFileName(string iFileName){
		BMPCanvas::fileName = iFileName;
	};

