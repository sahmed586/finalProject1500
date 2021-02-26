// Sadia Ahmed
// CSC 1501 Assignment 14 
// Message decryption (problem 1) 

#include<iostream>
using namespace std;

int main()
{
    char code[100], mess;
    int i, key = 10;
    cout << "Enter Message for Decryption: ";
    cin.getline(code, 100);

    for (i = 0; code[i] != '\0'; ++i)
    {
        mess = code[i];
        if (mess >= 'a' && mess <= 'z')
        {
            mess = mess - key;
            if (mess < 'a')
            {
                mess = mess + 'z' - 'a' + 1;
            }
            code[i] = mess;
        }
        else if (mess >= 'A' && mess <= 'Z')
        {
            mess = mess - key;
            if (mess > 'a')
            {
                mess = mess + 'Z' - 'A' + 1;
            }
            code[i] = mess;
        }
    }
    cout << "Decrypted message: " << code;
    return 0;
}