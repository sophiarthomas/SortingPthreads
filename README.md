# 325Prog4_Pthread
This assignment uses pthreads to perform parallel processing – allowing you to speed up your sort program
substantially. This sample program below shows 4 threads. You should use 10 threads in your program.

Your program will read in 1 million unsorted numbers from numbers.dat into an array. 
Then you will logically split the array into 10 sections – each section will have 100,000 numbers. 
You will call pthread_create( ) 10 times and pass each section of the array to the thread to sort using the sort algorithm you used in the previous assignment. 
Once all the threads have returned, you will merge 2 adjacent sections into a sorted super section,
and continue to do that until all the smaller sorted sections are in one large sorted section – which will be the entire array of 1 million numbers. 
Then print the array to a file. Then you will call sort -c to verify the output file is sorted.

In fact you can use the same sortrace.sh script file for this assignment. You should see substantial improvement in your sorting times.
You will run this shell file (sortRace.sh – that you wrote) and submit a screenshot of the results

What to submit:
1) Your new pthread program source code for the sort (mySort.cpp)
2) Your generate.cpp program (same one you used in Prog 3.
3) The log file that sortrace.sh produced
