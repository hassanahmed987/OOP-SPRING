#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// Custom exception for dimension mismatch
class DimensionException : public exception {
    string msg;
public:
    DimensionException(int r1, int c1, int r2, int c2) {
        msg = "Mismatch Dimension of matrix 1 " + to_string(r1) + "x" + to_string(c1)
            + " and matrix 2 " + to_string(r2) + "x" + to_string(c2);
    }

    const char* what() const noexcept override {
        return msg.c_str();
    }
};

template <typename T>
class Matrix {
    int rows, cols;
    T** data;

public:
    // Constructor from 2D array
    Matrix(int r, int c, T** arr) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new T[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = arr[i][j];
            }
        }
    }

    // Constructor with dimensions only (zero-initialized)
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols]();
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    // Matrix addition
    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionException(rows, cols, other.rows, other.cols);
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    // Print matrix
    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

// Utility to convert static array to dynamic for demonstration
int** toDynamicArray(int arr[][3], int rows, int cols) {
    int** dynArr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        dynArr[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            dynArr[i][j] = arr[i][j];
        }
    }
    return dynArr;
}

void deleteDynamicArray(int** arr, int rows) {
    for (int i = 0; i < rows; ++i)
        delete[] arr[i];
    delete[] arr;
}

int main() {
    int Matrix1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int Matrix2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int** dyn1 = toDynamicArray(Matrix1, 2, 3);
    int** dyn2 = toDynamicArray(Matrix2, 3, 3);

    try {
        Matrix<int> A(2, 3, dyn1);
        Matrix<int> B(3, 3, dyn2);

        Matrix<int> C = A + B; // Will throw exception
        C.print();
    } catch (const DimensionException& e) {
        cout << "Exception: " << e.what() << endl;
    }

    deleteDynamicArray(dyn1, 2);
    deleteDynamicArray(dyn2, 3);

    return 0;
}
