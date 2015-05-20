#include "BST.h"
#include <string>
#include <iostream>
#include <time.h>

using namespace std;
/*  //apperently not needed as we are inserting strings.
string gen_random() {
    int nameLength = rand() % 20;
    string name = "";
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < nameLength; i++) {
        char insert = rand() % (sizeof(alphabet) - 1);
        name += (alphabet[insert]);
    }
    return name;
}
*/
void tester(){
    clock_t start, end;
    start = clock();

    BST<int, int> myTree;
    cout << "Tree created" << endl;

    cout << "Loop is starting" << endl;
    int last = 0;
    for (int i = 0; i < 100000; i++){
        last = rand() % 10000;
        myTree.insert(last , rand() % 999999999 + 100000000);
    }

    cout << "Loop has ended" << endl;

    end = clock();
    int time = ((float)(end - start) / (float)(CLOCKS_PER_SEC));
    cout << "This opperation took " << time << " seconds " << endl;

    //find the value with last
    cout << "The last key entered was" << last << " and the SSN of " << last << " is ";
    cout << myTree.find(last) << endl;
}

int main(){
    tester();
	return 0;
}
