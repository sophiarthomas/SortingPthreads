// 	Sophia Thomas
//	CECS 325-02
//	Prog 4 - PThreads
// 	10/24/2023
//
//          I certify that this program is my own original work. I did not copy any part of this program from
//          any other source. I further certify that I typed each and every line of code in this program.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <thread>
#include <iostream> 
#include <fstream>
#include <unistd.h>
using namespace std;

struct numbers{//??
    int *array; 
    int index; 
    int wait; 
};

void bubbleSort(int arr[], int arrSize) { //(array, number of elements)
    bool swapped;
    for (int i = 0; i < arrSize - 1 ; i++) {
        swapped = false;
        for (int k = 0; k < arrSize - i - 1; k ++) {
            if (arr[k] > arr[k+1]) {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

void *bridge(void *ptr){
    //split the array into 10 sections of 100,000
    numbers *arg = (numbers *) ptr; 
    cout << arg->array<<endl;
    return NULL; 
}



int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout<<"Please enter 2 parameters:\n";
        cout<<"     Parameter 1: INPUT FILE\n";
        cout<<"     Parameter 2: OUTPUT FILE\n";
        cout<<"Example: \n";
        exit(EXIT_SUCCESS);
    }
    for (int i=0; i<argc; i++)
	{
		cout << "argv["<<i<<"]:"<<argv[i]<< endl;
	}
    string inputFile = argv[1];
	string outputFile = argv[2];
	
    int myNumbers;
    int arraySize = 0;

    //opening input file to determine the array size
    ifstream NumberFile(inputFile); 
    while(NumberFile >> myNumbers) {
        arraySize++;
    }
    NumberFile.close();
    //opening input file to insert the data into an array 
    ifstream NumberFile2(inputFile); 
    int sorting_arr[arraySize];
    int loc = 0; 
    while(NumberFile2 >> myNumbers) {
         sorting_arr[loc] = myNumbers;
         loc++;
    }
    NumberFile.close();

    //Begin
   

    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;

    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7, iret8, iret9;

    //Create independent threads each of which will execute function
    // iret0 = pthread_create( &thread0, NULL, bridge, (void*) &argList[0]);
    //... iret9 = pthread_create();




}