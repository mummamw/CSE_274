#include "encrypt.h"
#include <iostream>
#include <fstream>
#include <bitset>

using namespace std;

/**
 * Add your own code to the main function below, as specified there.
 */

void test1() {
	RSAint i = chars2RSAint("ABC.", strlen("ABC.")+1);
    cout << "i: (should print 776159809) " << i << endl;
   
    char * s = (char*)malloc(strlen("ABC.")*sizeof(char) + sizeof(char));
    RSAint2chars(i, s, strlen("ABC.")+1);
    cout << "Should print ABC.: " << s << endl;
}

void test2() {
	RSAint i = chars2RSAint("ABCD.", strlen("ABCD.")+1);
    cout << "i: (should print 198713754177) " << i << endl;
   
    char * s = (char*)malloc(strlen("ABCD.")*sizeof(char) + sizeof(char));
    RSAint2chars(i, s, strlen("ABCD.")+1);
    cout << "Should print ABCD.: " << s << endl;
}

int main() {
	// for testing and grading - do not change!
	test1();
	test2();

	/**
	 * Write your code below this comment.
	 *	- Read the public key components n and e from the file keys.txt. (n is listed first.)
	 *	- Read the contents of the file encrypted.txt, containing a sequence of RSAints 
	 *		separated by spaces (which was produced by applying the encryption algorithm to a file) 
	 *		using the public key (e,n) you just read in. 
	 *	- Crack the encryption and print out the original message.
	 */
	//read public key part a and e from file keys.txt
	
	char* keys = "keys.txt";
	int size = 10;

	ifstream myFile(keys);
	if (myFile.is_open()){
		while (myFile.good()){
			RSAint x;
			myFile >> x;
			size++;
		}
	}
	myFile.close();
	RSAint* fileContents = (RSAint*)malloc(size*(sizeof(RSAint)));
	ifstream fileRead(keys);
	if (fileRead.is_open()){
		for (int i = 0; i<size; i++){
			RSAint x;
			fileRead >> x;
			fileContents[i] = x;
		}
	}
	fileRead.close();
	RSAint n = fileContents[0];
	RSAint e = fileContents[1];

	//D depends on e and n
	RSAint d = RSACracker(e, n);
	int encSize = 0;
	char* encrypted = "encrypted.txt";

	ifstream encFile(encrypted);
	if (encFile.is_open()){
		while (encFile.good()){
			RSAint y;
			encFile >> y;
			encSize++;
		}
	}
	encFile.close();  //Keeps breaking it?
	RSAint* encContents = (RSAint*)malloc((encSize - 1)*(sizeof(RSAint)));
	ifstream encRead(encrypted);
	if (encRead.is_open()){
		for (int i = 0; i<encSize - 1; i++){
			RSAint y;
			encRead >> y;
			encContents[i] = y;
		}
	}
	fileRead.close();

	int secretMessageSize;
	char* message = RSAdecrypt(encContents, encSize - 1, &secretMessageSize, d, n);
	cout << message;

	return 0;
}
