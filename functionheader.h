#include <iostream>
#include <iomanip>
#include <cmath>
#include "Bitmap_Helper.h"


using namespace std;

// function to convert double pointer double into double pointer of uint8_t
uint8_t** ptrConverter(double** arr, int nRow, int nCol) {
    
    // create dynamic 2D array for uint8_t
    uint8_t** arrPtr = new uint8_t*[nRow];
    for (int i = 0; i < nRow; i++) {
        arrPtr[i] = new uint8_t[nCol];
    }

    // iterate through arr to assign arr values into arrPtr
    for (int i = 0; i < nRow; i++) {
        for (int j = 0; j < nCol; j++) {
            // Clamp the value to the range [0, 255]
            double clampedValue = max(0.0, min(255.0, arr[i][j]));
            // cast clampedValue to int, then uint8_t
            arrPtr[i][j] = static_cast<uint8_t>((int)(clampedValue));
        }
    }
    return arrPtr;
}

double** create2DGrid(int rows, int cols){
    
    // creating double pointer pointing to array of pointers
    double** arr = new double* [rows];
    for (int i=0; i<rows; i++){
        // creating double array that array of pointers point to
        arr[i] = new double[cols];
        // initializing all values to 0
        for (int j=0; j<cols; j++){
            arr [i][j] = 0;
        }
    }
    return arr;
}

void deleteGrid(double** arr, int rows){
    // deleting all arrays
    for (int i=0; i<rows; i++){
        delete[] arr[i];
    }
    // deleting array of pointers
    delete [] arr;
}

void displayGrid(double **arr, int rows, int cols){
    // grid header formatting
    cout << "   ";
    for (int i=0; i<cols; i++){
        cout << setw(6) << i+1 << " ";
    } cout << endl << "  ";
    for (int i=0; i<cols; i++){
        cout << "--------";
    } cout << endl;
    
    // iterating through array to print grid
    for (int i=0; i<rows; i++){
        // grid formatting
        cout << i+1 << "| ";
        for (int j=0; j<cols; j++){
            cout << fixed << setprecision(5) << setw(6) << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void setBoundaryConditions(double **arr, int rows, int cols, int top, int bottom,int left, int right){
    
    // initializing top row
    for (int i=0; i<cols; i++){
        arr[0][i] = top;
    }
    //initializing bottom row
    for (int i=0; i<cols; i++){
        arr[rows-1][i] = bottom;
    }
    // initializing leftmost column
    for (int i=1; i<rows-1; i++){
        arr[i][0] = left;
    }
    // initializing rightmost column
    for (int i=1; i<rows-1; i++){
        arr[i][cols-1] = right;
    }
}

// changing the value of one interior point in the 2D array
void stimulateGrid (double **arr, int x, int y, int temp){
    
    arr[y-1][x-1] = temp;
}

// stimulating thermal distribution until temperatures stay within tolerance value
void stimulateThermalDissipation (double **arr, int rows, int cols, double tol){
    bool passTol = false;
    
    // while loop repeats while the max difference exceeds tolerance value
    while (!passTol){
        passTol = false;
        double maxdiff = 0;
        
        // iterating through interior points of the 2D array
        for (int i=1; i<rows-1; i++){
            for (int j=1; j<cols-1; j++){
                
                // calculating average of top, bottom, left, right values
                double temp = (arr[i-1][j]+arr[i+1][j]+arr[i][j-1]+arr[i][j+1])/4;
                
                // calculating the diff btwn the old and new temp of each point
                double diff = abs(arr[i][j] - temp);
                // finding the maximum difference in one interation through the grid
                if (diff > maxdiff){
                    maxdiff = diff;
                }
                
                // calculated "temp" is assigned to each interior point
                arr[i][j] = temp;
            }
        }
        // condition to end while loop
        if (maxdiff <= tol)
            passTol = true;
    }
    // use given header file to create thermal image stored in thermalImg.bmp
    const char* filename = "thermalImg.bmp";
    uint8_t** imageData = ptrConverter(arr, rows, cols);
    writeBitmap(filename, imageData, cols, rows);
    
}
