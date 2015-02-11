// William McCarty
// Simple program to determine the number of flips of a coin required to get a certain amount of Heads in a row.

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <array>

using namespace std;

// Function prototypes
int flipCoin();
void buildArray(int flips[], int largeFlips[], int testNum, int size);
void testPrint(int flips[], int size);
void numOfFlips(int flips[], int size, int testNum, int result[]);
void printResult(int result[], int search, int size);     // Prints location of sequences
void description();         // Outputs program information
int userInput();            // Return Test Number

// *************** MAIN **************
int main() {
    // Variables
    int flips[1000];
    int largeFlips[15000];
    int search;
    int resultArray[50];
    int size;
    
    // Describe program
    description();
    
    // Get User Input
    cout << "Enter your search term: ";
    search = userInput();
    
    // Result Loop
    while (search != 999){
        // Build the array of random numbers
        
        if (search < 5){
            size = 1000;
            buildArray(flips, largeFlips, search, size);
            numOfFlips(flips, size, search, resultArray);
            printResult(resultArray, search, size);
        }
        else if (search >= 5 && search != 888 && (search != 9 || search != 10)){
            size = 15000;
            buildArray(flips, largeFlips, search, size);
            numOfFlips(largeFlips, size, search, resultArray);
            printResult(resultArray, search, size);

        }
        else if (search == 9 || search == 10){
            for (int i = 0; i < 4; i++){
            size = 15000;
            buildArray(flips, largeFlips, search, size);
            numOfFlips(largeFlips, size, search, resultArray);
            printResult(resultArray, search, size);
            }
        }
        
        // Show table of Heads and Tails
        else if (search == 888){
            int choice;
            cout << "How many random flips? ";
            cin >> choice;
            if (choice < 1 || choice > 10000){
                cout << "\ninvalid choice\n";
            }
            else if (choice > 1000){
                buildArray(flips, largeFlips, 6, choice);
                testPrint(largeFlips, choice);
            }
            else if (choice < 1000){
                buildArray(flips, largeFlips, 4, choice);
                testPrint(flips, choice);
            }
        }
        // Try again
        cout << "\nTry again: ";
        search = userInput();
    }
    
    // End of Main
    cout << endl;
    return 0;
}

// ************ FUNCTIONS *********

// Build an array containing the data from the coin flips
void buildArray(int flips[], int largeFlips[], int testNum, int size){
    if (testNum < 5){
        for (int i = 0; i < size; i++){
            int num = flipCoin();
            flips[i] = num;
        }
    }
    else if (testNum >= 5){
        for (int i = 0; i < size; i++){
            int num = flipCoin();
            largeFlips[i] = num;
        }
    }
}

// Generate a random coin flip
int flipCoin(){
    int num;
    num = rand()%2;
    return num;
}

// Test Print to make sure the array is built randomly
void testPrint(int flips[], int size){
    int count = 1;
    for (int i = 0; i < size; i++){
        if (flips[i] == 0)
            cout << "H ";
        else if (flips[i] == 1)
            cout << "T ";
        
        // Formatting
        if (i != 0 && i%100 == 0){
            cout << endl << count * 100 << " trials\n\n";
            count++;
        }
    }
    cout << endl;
}

// Get the number of heads in a row from the user
int userInput(){
    int testNum;
    cin >> testNum;
    cout << endl;
    
    while (testNum < 1 || (testNum > 10 && testNum != 999 && testNum != 888)){
        cout << "Sorry. Your number is not valid. Please Try Again: ";
        cin >> testNum;
    }
    return testNum;
}

// Print End results of Search for a specified number of Heads
void printResult(int result[], int search, int size){
    if (search <= 8){
        cout << "The coin was flippled " << size << " times." << " There were ";
        cout << result[0] -1 << " succesful trials with " << search << " heads in a row:\n\n";
        for (int i = 1; i < result[0]; i++){
            if (result[i] > 1 && result[i] < size && result[i] > search){
                cout << result[i];
                // Formatting
                if (i < result[0] && i%10 != 0)
                    cout << " ";
                else if (i%10 == 0)
                    cout << endl;
                else if (i == result[0])
                    cout << endl;
            }
        }
        cout << endl;
    }
    else if (search == 9 || search == 10){
        for (int i = 1; i < result[0]; i++){
            if (result[i] > 1 && result[i] < size && result[i] > search){
                cout << result[i];
                
                // Formatting
                if (i < result[0] && i%10 != 0)
                    cout << " ";
                else if (i%10 == 0)
                    cout << endl;
                else if (i == result[0])
                    cout << endl;
            }
        }
    }
}

// Count the number of flips to reach a certain amount in a row
void numOfFlips(int flips[], int size, int testNum, int result[]){
    int counter = 0;        // Count of total number of flips
    int resultCounter = 1;  // move through result Array
    for (int i = 0; i < size; i++){
        switch (testNum)
        {
            case 10:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1 && flips[i-4] == 1 && flips[i-5] == 1 && flips[i-6] ==1 && flips[i-7] == 1 && flips[i-8] == 1 && flips[i-9] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 9:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1 && flips[i-4] == 1 && flips[i-5] == 1 && flips[i-6] ==1 && flips[i-7] == 1 && flips[i-8] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 8:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1 && flips[i-4] == 1 && flips[i-5] == 1 && flips[i-6] ==1 && flips[i-7] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 7:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1 && flips[i-4] == 1 && flips[i-5] == 1 && flips[i-6] ==1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 6:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1 && flips[i-4] == 1 && flips[i-5] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 5:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1 && flips[i-4] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 4:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1 && flips[i-3] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;
                
            case 3:
                if(flips[i] == 1 && flips[i-1] == 1 && flips[i-2] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;

            case 2:
                if(flips[i] == 1 && flips[i-1] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;

            case 1:
                if(flips[i] == 1){
                    result[resultCounter] = counter + 1;
                    counter = 0;
                    flips[i] = 0;
                    resultCounter++;
                }
                else
                    counter ++;
                break;

        }
    }
    result[0] = resultCounter;
    if (resultCounter == 0)
        cout << "No Result\n";
}

// Program Description
void description(){
    cout << " This program will generate an array of random coin flips. You can search through that list for a series of up to 10 heads in a row.\n";
    cout << " The numbers represent how many flips were required before a sequence of n Heads were found in a row.\n";
    cout << " The program assumes that counting restarts when a sequence is found.\n";
    cout << " To See a representation of the Heads and Tails that were randomly generated, enter '888'\n";
    cout << " This can print up to 10,000 letters. You have been warned.\n";
    for (int i = 0; i < 100; i++){
        cout << "_";
    }
    cout << "\n";
}






