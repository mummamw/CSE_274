
#include "Experiment.h"
#include <fstream>
#include <iomanip>
#include "Deck.h"
#include <sstream>
#include <iostream>

#define MAXNUMSHUFFLES 15

using namespace std;

/*
* DO NOT CHANGE THIS FUNCTION! Add all your code after this!
*/
double chiSquared(long* rowHead, int rowLength){
	long rowTotal = 0;
	double expected = 0.0;
	double chiSq = 0.0;
	for (int i = 0; i<rowLength; i++){
		rowTotal += rowHead[i];
	}
	expected = ((double)rowTotal) / ((double)rowLength);

	for (int i = 0; i<rowLength; i++){
		chiSq = chiSq + (((rowHead[i] - expected)*(rowHead[i] - expected)) / expected);
	}

	return chiSq;
}

/*
* Add your doOneExperiment here
*/

double doOneExperiment(int numshuffles){
	int* countMatrix = new int[52 * 52];
	for (int i = 0; i<52 * 52; i++){
		countMatrix[i] = 0;
	}

	for (int j = 0; j<NUMEXPERIMENTS; j++){
		Deck* oneExperiment = new Deck();
		for (int k = 0; k<numshuffles; k++){
			oneExperiment->shuffle();
		}
		IntListNode* start = oneExperiment->getListHead();
		for (int l = 0; l<52; l++){
			int data = start->data;
			countMatrix[data * 52 + l] = countMatrix[data * 52 + l] + 1;
			start = start->next;
		}
		delete oneExperiment;
	}
	ofstream textFile;
	char* num = new char[3];
	itoa(numshuffles, num, 10);
	string fileName = "table";
	fileName = fileName + num;
	fileName = fileName + ".txt";
	textFile.open(fileName, ios::out);

	char* display = new char[6];
	for (int i = 0; i<(52 * 52); i++){
		itoa(countMatrix[i], display, 10);
		textFile << display << "	";
		if ((i + 1) % 52 == 0){
			textFile << endl;
		}
	}
	delete[] display;
	delete[] num;

	textFile.close();
	double chiSqValue = chiSquared((long*)countMatrix, 52);
	delete[] countMatrix;
	if (chiSqValue<CRITICALVALUE){
		cout << numshuffles << " shuffles was fair, with chi^2 = " << chiSqValue << endl;
	}
	else{
		cout << numshuffles << " shuffles was biased, with chi^2 = " << chiSqValue << endl;
	}
	return chiSqValue;
}

/*
* Add your doExperimentRun here
*/

void doExperimentRun(){
	double chiSq = CRITICALVALUE;
	int numShuffles = 0;
	while (chiSq >= CRITICALVALUE){
		chiSq = doOneExperiment(numShuffles);
		numShuffles++;
	}
}