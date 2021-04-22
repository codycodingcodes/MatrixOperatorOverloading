// Matrix.cpp : 9 Different Operations for Matrix Math
// 1. Addition (+) 2. Subtraction (-) 3. Multiplication (*)
// 4-5. Post and Pre Increment (++)
// 5-6. Post and Pre Decrement (--)
// 7. Transpose (~) 8. Positive Exponent (^)
// 
// Cody McKinney
// 4.7.2021

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int d;

// matrix class that contains all the operator overloaded methods to do math on matrix
class matrix
{
public:
    int** marr; // matrix array 1 and 2 pointer to a pointer
    int** marr2;

    /*
    * allocate() takes an int as the dimensions to an array we allocate memory for
    */
    int** allocate(int d)
    {
        int** new_matrix = new int* [d];

        for (int i = 0; i < d; i++)
        {
            new_matrix[i] = new int[d];
        }

        return new_matrix;
    }

    /*
    * matrix() constructor asks for matrix dimensions and allocates memory for 2 matrices of the same size
    */
    matrix()
    {
        cout << "Enter matrix dimension: ";
        cin >> d;
        marr = allocate(d);
        marr2 = allocate(d);

        cout << "\nEnter a " << d << "x" << d << " set of numbers for the matrix:" << endl;

        // take input and fill matrix array with #s
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cin >> marr[i][j];
            }
        }
    }

    /*
    * operator+() is operator overloading method for matrix addition
    */
    void operator+()
    {
        cout << "\nMATRIX ADDITION" << endl;
        cout << "Enter a " << d << "x" << d << " set of numbers for the 2nd matrix:" << endl;

        // take input and fill 2nd matrix array with #s
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cin >> marr2[i][j];
            }
        }

        // code for addition of 2 matrices
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr[i][j] + marr2[i][j];
            }
        }
    }

    /*
    * operator-() is operator overloading method for matrix subtraction
    */
    void operator-()
    {
        cout << "\nMATRIX SUBTRACTION" << endl;
        cout << "Enter a " << d << "x" << d << " set of numbers for the 2nd matrix:" << endl;

        // take input and fill 2nd matrix array with #s
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cin >> marr2[i][j];
            }
        }

        // code for subtraction of 2 matrices
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr[i][j] - marr2[i][j];
            }
        }
    }

    /*
    * operator*() is operator overloading method for matrix multiplication
    */
    void operator*()
    {
        cout << "\nMATRIX MULTIPLICATION" << endl;
        cout << "Enter a " << d << "x" << d << " set of numbers for the 2nd matrix:" << endl;

        // take input and fill 2nd matrix array with #s
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                cin >> marr2[i][j];
            }
        }

        // allocate an empty array for resultant matrix from multiplication
        int** multmarr;
        multmarr = allocate(d);
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                multmarr[i][j] = 0;
            }
        }

        // code for matrix multiplication
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                for (int k = 0; k < d; k++)
                {
                    multmarr[i][j] += marr[i][k] * marr2[k][j]; // multiplies (0,0) with (0,0) then (0,1) with (1,0) ... while adding them up for a row
                }
            }
        }

        // change our main matrix array to the resultant matrix from multiplication
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = multmarr[i][j];
            }
        }

        // release the memory of our multiplication array
        delete[] multmarr;
    }

    // pre increment by 1
    void operator++()
    {
        cout << "\nPRE-INCREMENT MATRIX" << endl;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr[i][j] + 1;
            }
        }
    }

    // post increment by 1
    void operator++(int)
    {
        cout << "\nPOST-INCREMENT MATRIX" << endl;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr[i][j] + 1;
            }
        }
    }

    // pre decrement by 1
    void operator--()
    {
        cout << "\nPRE-DECREMENT MATRIX" << endl;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr[i][j] - 1;
            }
        }
    }

    // post decrement by 1
    void operator--(int)
    {
        cout << "\nPOST-DECREMENT MATRIX" << endl;
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr[i][j] - 1;
            }
        }
    }

    /*
    * operator~() transposes our matrix (flips the rows with the columns)
    */
    void operator~()
    {
        // allocate an empty array for the flipped matrix from transpose operation
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr2[i][j] = 0;
            }
        }

        // transposed array switches the rows with the columns
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr2[i][j] = marr[j][i];
            }
        }

        // store the contents of the transpose array in our main matrix
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr[i][j] = marr2[i][j];
            }
        }
    }

    void operator^(int e)
    {
        // allocate an empty array for resultant matrix from exponents
        int** expomarr;
        expomarr = allocate(d);
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                expomarr[i][j] = 0;
            }
        }

        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                marr2[i][j] = marr[i][j];
            }
        }

        int x = 1;
        // code for matrix exponents
        do
        {
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    for (int k = 0; k < d; k++)
                    {
                        expomarr[i][j] += marr[i][k] * marr2[k][j]; // multiplies (0,0) with (0,0) then (0,1) with (1,0) ... while adding them up for a row
                    }
                }
            }

            // change our main matrix array to the resultant matrix from exponent and empty the exponent matrix array for the next exponential iteration if needed
            for (int i = 0; i < d; i++)
            {
                for (int j = 0; j < d; j++)
                {
                    marr[i][j] = expomarr[i][j];
                    expomarr[i][j] = 0;
                }
            }

            x++;
        } while (x != e);

        // release the memory of our exponential array
        delete[] expomarr;
    }

    /*
    * ostream& operator<<() overloads the << operator for our matrix class
    * when << is called it will now print our formatted output for the matrix
    */
    friend ostream& operator<<(ostream& output, matrix& m)
    {
        cout << "\n\tOUTPUT\n============================================\n";
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                output << setw(4) << m.marr[i][j] << "\t";
            }
            output << endl;
        }
        return output;
    }

    // release the memory of our 2 matrix arrays
    void release_memory()
    {
        delete[] marr;
        delete[] marr2;
    }
};

int main()
{
    matrix m;
    // menu options for matrix math
    cout << "\n\tOPERATIONS" << endl;
    cout << "1: Addition\n2: Subtraction\n3: Multiplication" << endl;
    cout << "4: Pre-Increment\n5: Post-Increment" << endl;
    cout << "6: Pre-Decrement\n7: Post-Decrement" << endl;
    cout << "8: Transpose\n9: Exponential" << endl;
    cout << "\nEnter the operation #";

    // c is the choice variable
    int c;
    cin >> c;

    switch (c)
    {
    case 1: // addition
        +m;
        cout << m;
        break;
    case 2: // subtraction
        -m;
        cout << m;
        break;
    case 3: // multiplication
        *m;
        cout << m;
        break;
    case 4: // pre increment
        ++m;
        cout << m;
        break;
    case 5: // post increment
        m++;
        cout << m;
        break;
    case 6: // pre decrement
        --m;
        cout << m;
        break;
    case 7: // post decrement
        m--;
        cout << m;
        break;
    case 8: // transpose
        ~m;
        cout << m;
        break;
    case 9: // exponent
        int e;
        cout << "To what power would you like to raise this matrix: ";
        cin >> e;
        m ^ (e);
        cout << m;
        break;
    default: // error handling in menu
        cout << "Invalid Input." << endl;
        break;
    }

    // release memory of all 2d arrays
    m.release_memory();
}