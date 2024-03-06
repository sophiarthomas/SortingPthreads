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

struct numbers{
    int *array; //pointer to the starting array element
    int size;   //100,000 
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


void *bridge(void *ptr) {
    numbers *arg = (numbers *) ptr; 
    bubbleSort(arg -> array, arg->size);
    return NULL; 
}

int merge(int a1[], int s1, int a2[], int s2) {
    /*
    Edge case: one of the arrays run out of space i.e. the index > size 
    */
    int tempSize = s1+s2; 
    int* temp = new int[tempSize]; //create a temp array 
    int p1 = 0, p2 = 0;  
    int i = 0;

    while (p1 < s1 && p2 < s2) {
        if (a1[p1] < a2[p2]){
            temp[i] = a1[p1];
            p1++;
        } else {
            temp[i] = a2[p2];
            p2++;
        }
        i++;
    }
    while (p1 < s1) {
        temp[i] = a1[p1];
        p1++;
        i++;
    }
    while (p2 < s2) {
        temp[i] = a2[p2];
        p2++;
        i++;
    }

    //copy the temp array into the original array 
    for (int i = 0; i < tempSize; i++) {
        a1[i] = temp[i];
    }
    delete[] temp; 
    return tempSize;
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
		cout << "argv["<<i<<"]:"<<argv[i]<< endl;
	
	int max = 1000000;
    int arraySize = -1; 
    int* sorting_arr = new int[max]; 

    //opening input file to determine the array size and input integers from file to dynamic array 
    ifstream NumberFile(argv[1]); 
    for (int i = 0; i <= max; i++) {
        if ( NumberFile.eof()) {
            break;
        } else
            NumberFile >> sorting_arr[i];
            arraySize++;
    }
    NumberFile.close();

    int threads = 10;
    numbers argList[threads];
    int sectionSize = arraySize/threads;
    for (int i = 0; i < threads; i++) {
        argList[i].array = sorting_arr+(i*sectionSize); 
        argList[i].size = sectionSize; 
    }
    int remainder = arraySize - (sectionSize + ((threads-1)*sectionSize));
    if (remainder != 0) {
        argList[threads-1].size += remainder;
    }

    pthread_t thread0, thread1, thread2, thread3, thread4, thread5, thread6, thread7, thread8, thread9;
    int iret0, iret1, iret2, iret3, iret4, iret5, iret6, iret7, iret8, iret9;


    //Create independent threads each of which will execute function
    iret0 = pthread_create( &thread0, NULL, bridge, (void*) &argList[0]);
    iret1 = pthread_create( &thread1, NULL, bridge, (void*) &argList[1]);
    iret2 = pthread_create( &thread2, NULL, bridge, (void*) &argList[2]);
    iret3 = pthread_create( &thread3, NULL, bridge, (void*) &argList[3]);
    iret4 = pthread_create( &thread4, NULL, bridge, (void*) &argList[4]);
    iret5 = pthread_create( &thread5, NULL, bridge, (void*) &argList[5]);
    iret6 = pthread_create( &thread6, NULL, bridge, (void*) &argList[6]);
    iret7 = pthread_create( &thread7, NULL, bridge, (void*) &argList[7]);
    iret8 = pthread_create( &thread8, NULL, bridge, (void*) &argList[8]);
    iret9 = pthread_create( &thread9, NULL, bridge, (void*) &argList[9]);
    

    /*wait till threads are completed before main continues*/
    pthread_join(thread0, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    pthread_join(thread5, NULL);
    pthread_join(thread6, NULL);
    pthread_join(thread7, NULL);
    pthread_join(thread8, NULL);
    pthread_join(thread9, NULL);

    //Merge Function - merge adjacent pthreads, using pthread_create?
    int mergeSize;
    mergeSize = merge(argList[0].array, argList[0].size, argList[1].array, argList[1].size);
    for (int i = 2; i < threads; i++)
        mergeSize = merge(argList[0].array, mergeSize, argList[i].array, argList[i].size);


    ofstream fout;
	fout.open(argv[2], ios::out);
	for (int i=0; i<arraySize; i++)
	{
		fout << sorting_arr[i] << endl;
	}
	fout.close();
    delete [] sorting_arr; 
    return 0;
}