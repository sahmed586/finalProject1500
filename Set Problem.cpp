#include <iostream>
#include <string>

using namespace std;


int findUnion(int* set1, int a, int* set2, int b, int Result[]);
int findIntersect(int* set1, int a, int* set2, int b, int Result[]);
int findSubtraction(int* set1, int a, int* set2, int b, int Result[]);

int main(void)
{
    int resultant;

    // each set of elements declared here 
    cout << "Set Theory Solution" << endl;
    int Universal[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    int A[6] = { 1, 2, 3, 5, 8, 13};
    int B[10] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 }; 
    int C[9] = { 1, 2, 3, 5, 7, 11, 13, 17, 19 };
    int R[50]; // resultant set for each problem 


   //  ((A UNION B) INTERSECT C)

    cout << "\n ((A UNION B) INTERSECT C)" << endl;
    cout << "----------------------------------";

    resultant = findUnion(A, 6, B, 10, R);
    resultant = findIntersect(R, resultant, C, 9, R);

    cout << "\n Resultant: \n\n\t\t { ";

    for (int i = 0; i < resultant; i++)
    {
        cout << R[i] << " ";
    }

    cout << "}" << endl;
    cout << endl << endl;


    system("pause");

}

int findUnion(int* set1, int a, int* set2, int b, int Result[])
{

    int k = 0;
    int i, j, final;
    //compute union

    for (i = 0; i < a; i++)
    {
        Result[i] = set1[i];
        k++;
    }
    //int found;
    int e = k;

    for (i = 0; i < b; i++)
    {
        final = 0;
        for (j = 0; j < e; j++)
        {
            if (set2[i] == set1[j])
            {
                final = 1;
                break;
            }
        }
        if (final == 0)
        {
            Result[k] = set2[i];
            k++;
        }
    }

    return k;
}

int findIntersect(int* set1, int a, int* set2, int b, int Result[])
{
    int i, j, k = 0;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (set1[i] == set2[j])
            {

                Result[k] = set1[i];
                k++;
            }
        }
    }
    return k;

}


int findSubtraction(int* set1, int a, int* set2, int b, int Result[])
{
    int i, j, k = 0, found;
    cout << "\n\n";
    for (i = 0; i < a; i++)
    {
        found = 0;
        for (j = 0; j < b; j++)
        {

            if (set1[i] == set2[j])
            {
                found = 1;
                break;

            }
        }
        if (found == 0)
        {
            Result[k] = set1[i];
            k++;

        }

    }

    for (i = 0; i < b; i++)
    {
        int found = 0;
        for (j = 0; j < a; j++)
        {

            if (set2[i] == set1[j])
            {
                found = 1;
                break;

            }
        }
        if (found == 0)
        {
            Result[k] = set2[i];
            k++;

        }

    }
    return k;
}