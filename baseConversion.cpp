//Sadia Ahmed 
// CSC 1501: Final Assignment 
// This code converts any decimal value to a base 7 number

#include <string.h>
#include <stdio.h>
#include <iostream>

char value(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void conv(char* str)
{
	int length = strlen(str);
	int i;
	for (i = 0; i < length / 2; i++)
	{
		char temp = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = temp;
	}
}

char* fromDecimal(char res[], int base, int inputVal)
{
	int index = 0;

	while (inputVal > 0)
	{
		res[index++] = value(inputVal % base);
		inputVal /= base;
	}
	res[index] = '\0';


	conv(res);

	return res;
}

int main()
{
	int inValue, base;

	printf("Please enter the decimal number: ");
	scanf_s("%d", &inValue);

	printf("Please enter the base you would like to convert to: ");
	scanf_s("%d", &base);

	char res[100];
	printf("The Equivalent of %d in base %d is: "
		" %s\n", inValue, base, fromDecimal(res, base, inValue));


	return 0;
}
