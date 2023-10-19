#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

const int MaxSize = 100;
 
int* strToArr(string line){
    static int lineArr[100];
    string currNum = "";
    int itr = 0;
    int spot = 0;

    while (line[itr]){
        currNum += line[itr];
        if (line[itr] == ' '){
            lineArr[spot] = stoi(currNum);
            spot++;
            currNum = "";
        }
        itr++;
    }
    lineArr[spot] = stoi(currNum);

    return lineArr;
}


void printMatrix(int size, int matrix[MaxSize][MaxSize]){
    int maxDigits = 0;
    for (int i = 0; i < size; i++){
        for (int j = 0; j< size; j++){
            int digits = (log10(matrix[i][j]));
            digits++;
            if (digits> maxDigits){
                maxDigits = digits;
            }
        }
    }

    for (int i = 0; i < size; i++){
        for (int j = 0; j< size; j++){
            cout<<setw(maxDigits)<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void addMatrix(int size, int m1[MaxSize][MaxSize], int m2[MaxSize][MaxSize]){
    int sum[MaxSize][MaxSize];
    for (int i = 0; i < size; i++){
        for (int j = 0; j< size; j++){
            sum[i][j] = m1[i][j] + m2 [i][j];
        }
    }
    printMatrix(size, sum);

}

void subMatrix(int size, int m1[MaxSize][MaxSize], int m2[MaxSize][MaxSize]){
    int sum[MaxSize][MaxSize];
    for (int i = 0; i < size; i++){
        for (int j = 0; j< size; j++){
            sum[i][j] = m1[i][j] - m2 [i][j];
        }
    }
    printMatrix(size, sum);

}

void multMatrix(int size, int m1[MaxSize][MaxSize], int m2[MaxSize][MaxSize]){
    int product[MaxSize][MaxSize];
    for (int i = 0; i < size; i++){
        for (int j = 0; j< size; j++){
            int sum = 0;
            for (int c = 0; c < size; c++){
                sum += m1[i][c] * m2[c][j];
            }
            product[i][j] = sum;
        }
    }
    printMatrix(size, product);
}

int main(){
    string filename;
    ifstream file;
    while(1){
        cout << "Enter a filename: ";
        cin >> filename;
        cout << "\n";

        file.open(filename);
        if (file){break;}
        else {cout<<"Please enter a valid filename.\n";}
    }
    string line = "";
    getline(file, line);
    int size = stoi(line);

    int matrix1[MaxSize][MaxSize];
    int matrix2[MaxSize][MaxSize];
    int* arrPtr;

    for (int i = 0; i < size; i++){
        getline(file, line);
        arrPtr = strToArr(line);
        for (int j = 0; j < size; j++){
            matrix1[i][j] = arrPtr[j];
        }
    }

    for (int i = 0; i < size; i++){
        getline(file, line);
        arrPtr = strToArr(line);
        for (int j = 0; j < size; j++){
            matrix2[i][j] = arrPtr[j];
        }
    }
    cout<<"Matrix A: \n";
    printMatrix(size, matrix1);

    cout<<"Matrix B: \n";
    printMatrix(size, matrix2);

    cout<<"Matrix Sum (A+B):\n";
    addMatrix(size, matrix1, matrix2);

    cout<<"Matrix Product (A*B):\n";
    multMatrix(size, matrix1, matrix2);

    cout<<"Matrix Difference (A-B):\n";
    subMatrix(size, matrix1, matrix2);

    return 1;
}
