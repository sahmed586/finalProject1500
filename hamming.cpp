// Sadia Ahmed 
// CSC 1501 Assignment 14
// Problem 3

#include<iostream>
#include<string>
using namespace std;

int main() {
    
    string input;
    cout << "Enter the 4 bits: ";
    getline(cin, input);

    cout << endl;

    int hCode[8];

    hCode[3] = (input[0] - '0');
    hCode[5] = (input[1] - '0');
    hCode[6] = (input[2] - '0');
    hCode[7] = (input[3] - '0');

    hCode[1] = (hCode[3] ^ hCode[5] ^ hCode[7]);
    hCode[2] = (hCode[3] ^ hCode[6] ^ hCode[7]);
    hCode[4] = (hCode[5] ^ hCode[6] ^ hCode[7]);


    cout << "Hamming Code of the Input: " << endl;
    for (int i = 1; i < 8; i++)
        cout << hCode[i] << " ";

    cout << endl;

    cout << "Error in 7th Slot." << endl;
    if (hCode[7] == 0)
        hCode[7] = 1;
    else
        hCode[7] = 0;


    cout << "\nHamming code after changing the 7th bit : ";
    for (int i = 1; i < 8; i++)
        cout << hCode[i] << " ";


    int firstParity = hCode[1] ^ hCode[3] ^ hCode[5] ^ hCode[7];
    int secParity = hCode[2] ^ hCode[3] ^ hCode[6] ^ hCode[7];
    int thirdParity = hCode[4] ^ hCode[5] ^ hCode[6] ^ hCode[7];

    int parity = firstParity + (secParity * 2) + (thirdParity * 4);


    if (parity == 0)

        cout << "No Error FOund in Code" << endl;


    else

        cout << "\n\nThere's an error at position: " << parity << endl;


    if (hCode[parity] == 0)

        hCode[parity] = 1;


    else
        hCode[parity] = 0;

   
    cout << "\nDisplaying the code in decimal after correcting the error : ";
    int org_msg = hCode[7] + (hCode[6] * 2) + (hCode[5] * 4) + (hCode[3] * 8);
    cout << org_msg;
}