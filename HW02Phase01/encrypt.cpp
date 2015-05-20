#include <stdlib.h>
#include <string.h>
#include "rsa_functions.h"
#include <string.h>
#include <bitset>
#include <cassert>
#include "encrypt.h"
#include <fstream>
#include <iostream>

using namespace std;

/*RSAint chars2RSAint(char* str, int c);
void RSAint2chars(RSAint enc, char* str, int c);
void generateKey(RSAint p, RSAint q, RSAint* e, RSAint* d, RSAint* n);
RSAint* RSAencrypt(char* msg, int size, int* newSize, RSAint e, RSAint n);
char* RSAdecrypt(RSAint* encoding, int size, int* newSize, RSAint d, RSAint n);
RSAint RSACracker(RSAint e, RSAint n);
*/

RSAint chars2RSAint(char* str, int c){
	assert(str != NULL && 0 <= c && c <= sizeof(RSAint));
	RSAint rsa = 0;
	RSAint temp = 0;
	for (int i = 0; i < c; i++){
		temp = str[i];
		rsa = (rsa << 8) | temp;
	}
	return rsa;
}

void RSAint2chars(RSAint enc, char* str, int c){
	assert(enc >= 0 && c >= 0 && str != NULL);
	for (int i = c - 1; i >= 0; i--){

		str[i] = enc;
		enc = enc >> 8;

	}
	str[c] = '\0';
}


void generateKey(RSAint p, RSAint q, RSAint* e, RSAint* d, RSAint* n){
	assert(e != NULL && d != NULL && n != NULL && p > minPrimeLimit && p < maxPrimeLimit
		&& q > minPrimeLimit && q < maxPrimeLimit && p != q);
}

RSAint* RSAencrypt(char* msg, int size, int* newSize, RSAint e, RSAint n){
	assert(msg != NULL && newSize != NULL && size>0);
	if (size % 3 != 0){
		*newSize = (size / 3) + 1;
	}
	else{
		*newSize = (size / 3);
	}
	RSAint* encrypted = (RSAint*)malloc(*newSize*(sizeof(RSAint)));

	//Get msg in chuncks of 3.
	int i;

	for (i = 0; i < size / 3; i++)
	{
		int index = 3 * i;
		char* temp = (char*)malloc(3 * sizeof(char));
		temp[0] = msg[index + 2];
		temp[1] = msg[index + 1];
		temp[2] = msg[index];
		encrypted[i] = modular_power(chars2RSAint(temp, 3), e, n);
		free(temp);
	}
	int remainder = size - (3 * i);
	if (remainder == 2){
		char* temp1 = (char*)malloc(2 * sizeof(char));
		temp1[0] = msg[3 * i + 1];
		temp1[1] = msg[3 * i];
		encrypted[i] = modular_power(chars2RSAint(temp1, 2), e, n);
		free(temp1);
	}
	else{
		char* temp2 = (char*)malloc(sizeof(char));
		temp2[0] = msg[3 * i];
		encrypted[i] = modular_power(chars2RSAint(temp2, 1), e, n);
		free(temp2);
	}
	return encrypted;
}

char* RSAdecrypt(RSAint* encoding, int size, int* newSize, RSAint d, RSAint n){
	assert(encoding != NULL && newSize != NULL && size>0);
	*newSize = 3 * size;
	char* plain = (char*)malloc(*newSize*sizeof(char));
	int inc = 0;
	char* charTemp = (char*)malloc(3 * sizeof(char));
	for (int i = 0; i<size; i++){
		RSAint temp = modular_power(encoding[i], d, n);
		RSAint2chars(temp, charTemp, 3);
		if (charTemp[0] == 0){
			if (charTemp[1] == 0){
				plain[inc] = charTemp[2];
				plain[inc + 1] = '\0';
			}
			else{
				plain[inc] = charTemp[2];
				plain[inc + 1] = charTemp[1];
				plain[inc + 2] = '\0';
			}
		}
		else{
			plain[inc] = charTemp[2];
			plain[inc + 1] = charTemp[1];
			plain[inc + 2] = charTemp[0];
		}


		inc += 3;
	}

	plain[*newSize] = '\0';
	return plain;
}

RSAint RSACracker(RSAint e, RSAint n){
	RSAint d;
	RSAint p;
	RSAint q;
	RSAint totient;
	bool cont;
	int i = 2;
	do{
		cont = false;
		//the first prime number
		p = i;
		i++;
		q = n / p;
		//calculate or generate random p and q until below conditions are met. 
		totient = (p - 1)*(q - 1);
		if (n == p*q && isCoPrime(e, totient) && p != q && isPrime(p) && isPrime(q) && n%p == 0){
			cont = true;
		}
	} while (!cont);
	d = multiplicative_inverse(e, totient);
	return d;
}