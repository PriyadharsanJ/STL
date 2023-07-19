#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

// Function to perform matrix multiplication
vector<vector<int>> Multiplication(const vector<int>& A, const vector<int>& B, int rA, int cA, int cB)
{
    vector<vector<int>> c(rA, vector<int>(cB, 0));

    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            for (int k = 0; k < cA; k++)
            {
                c[i][j] += A[i * cA + k] * B[k * cB + j];
            }
        }
    }

    return c;
}

// Displaying a matrix
void display(const vector<vector<int>>& matrix)
{
    for (const vector<int>& row : matrix)
    {
        for (int val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int rA, cA, rB, cB;
    cout << "Enter the number of rows and columns for matrix A : ";
    cin >> rA >> cA;
    cout << "Enter the number of rows and columns for matrix B : ";
    cin >> rB >> cB;
    if (cA != rB)
    {
        cout << "Matrix multiplication is not possible!" << endl;
        return 1;
    }
    vector<int> A(rA * cA);
    vector<int> B(rB * cB);
    //taking inputs for matrix A and B
    cout << "Enter the elements of matrix A :" << endl;
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cA; j++)
        {
            cout<<"Enter the element["<<i<<"]"<<"["<<j<<"] : ";
            cin >> A[ (i * cA) + j];
        }
    }
    cout << "Enter the elements of matrix B :" << endl;
    for (int i = 0; i < rB; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            cout<<"Enter the element["<<i<<"]"<<"["<<j<<"] : ";
            cin >> B[i * cB + j];
        }
    }
    vector<vector<int>> c = Multiplication(A, B, rA, cA, cB);

    //printing matrix A
    cout<<"Matrix A : "<<endl;
    for (int i = 0; i < rA; i++)
    {
        for (int j = 0; j < cA; j++)
        {
            cout << A[(i * cA) + j]<<" ";
        }
        cout<<endl;
    }

    //printing matrix B
    cout << "Matrix B :" << endl;
    for (int i = 0; i < rB; i++)
    {
        for (int j = 0; j < cB; j++)
        {
            cout << B[(i * cB) + j]<<" ";
        }
        cout<<endl;
    }

    cout << "Matrix multiplication : " << endl;
    //calling the display function to display the multiplied matrix
    display(c);
    return 0;
}

