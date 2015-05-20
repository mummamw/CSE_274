/*****
 * Author   : brinkmwj and karroje
 * Date     : 2009-10-04, 2011-03-10
 * Modified : inclezd (3/15/2015)
 * Sources  : All code is original
 * Purpose  : The purpose of this file is to do some VERY rudimentary timing of your increaseCount
 *            method. For the QUALITY measures I am also going to test getCount and getNthPopulat, 
 *            so you might want to design some way to test out the running time of your getCount as well!
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <mmsystem.h>
#include <algorithm>

#include "MyTrends.h"


#pragma comment (lib, "winmm.lib") 

/*
 * The following two functions are for the purpose of removing punctuation from either end of the
 * word and making all letters lower-case, allowing us to count the words "Here", "here", and "herE."
 * all as the same word in terms of trends.
 */
bool nonAscii(char c) {
  return !(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}

string reduceWord(string& s) {
  string::iterator last = remove_if(s.begin(), s.end(), nonAscii);
  transform(s.begin(), last, s.begin(), ::tolower);
  return s.substr(0, last-s.begin());
}


/*
 * processFile should:
 *  1) Create a new instance of your MyTrends class
 *  2) Read in the file whose words you want to count: The file name is passed in as fname
 *  3) Add all words to the Trends data structure, and calculate the time per call to addtoTrends
 *  4) Use getNthPopular and getCount to print out the total results in fname + ".out"
 */
int processFile(const char* fname){
	Trends* tr = new MyTrends();

	// First, read in the file
	ifstream in(fname);
	string s;
	vector<string> wordlist;

	while(in >> s){
	  s = reduceWord(s);
	  if (s.size() > 0)
	    wordlist.push_back(s);
	}

	// We only want to time how long addToTrends takes, so we get
	// the starting time, which is the clock time, in milliseconds
	int start = timeGetTime();

	// Now add all the words to the Trends data structure
	for(unsigned int i=0; i<wordlist.size(); i++){
		tr->increaseCount(wordlist[i],1);
	}

	// Now get the end time
	int end = timeGetTime();
	std::cout << "Time: " << ((1000.0*(end - start))/wordlist.size()) << " microseconds per word" << endl;

	// Now we will print out the complete results. This could be REALLY slow, if
	// your getNthPopular is not a little bit smart.
	int p = ((string)fname).rfind('.');
	string outfname = ((string)fname).substr(0, p) + ".out";
	ofstream out(outfname.c_str());
	for(int i=0; i< tr->numEntries(); i++){
		string s = tr->getNthPopular(i);
		out << tr->getCount(s) << ": " << s << endl;
	}
	out.close();

	delete tr;

	return end - start;
}

/*
 * The only purpose of main() is to call processFile with increasingingly larger and larger
 * files. A larger file will give a more accurate sense of how fast addToTrends is, but at some
 * point it may take so long to do the getNthPopular, that we aren't willing to wait for it to finish.
 */
int main(int argc, char** argv){
	/* Most of these files are books from project Gutenberg. I have provided the inputs
	 * in the starter files. The outputs are provided in the file ExampleInputAndOutput.zip. */
	
	/* NOTE: You may want to comment out some of the following lines!
	 * Unless your program is very speedy on all operations, some of these will never finish.
	 * Leave uncommented the line
	 *     processFile("test.txt");
	 * The file test.txt is a short file that can be used for testing. It contains a small portion of 
	 * the book in file 46.txt.
	 */
	processFile("test.txt");
	//processFile("28885.txt");
	//processFile("46.txt");

	return 0;
}
