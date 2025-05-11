#include <iostream>
#include <exception>
#include <sstream>
using namespace std;

class DimensionMismatchException : public exception {
    string message;
public:
    DimensionMismatchException(int rows1, int cols1, int rows2, int cols2) {
        ostringstream oss;
        oss << "DimensionMismatchException\nMatrices must have same dimensions ("
            << rows1 << "x" << cols1 << " vs " << rows2 << "x" << cols2 << ")!";
        message = oss.str();
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template<typename T>
class Matrix {
private:
    int rows, cols;
    T** data;

public:
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new T*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new T[cols];
    }

    ~Matrix() {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }

    void set(int r, int c, T value) {
        data[r][c] = value;
    }

    T get(int r, int c) const {
        return data[r][c];
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    Matrix<T> operator+(const Matrix<T>& other) const {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException(rows, cols, other.rows, other.cols);

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.set(i, j, data[i][j] + other.get(i, j));

        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << data[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    cout << "---- Invalid Addition (2x2 + 3x3) ----" << endl;
    try {
        Matrix<int> A(2, 2);
        Matrix<int> B(3, 3);

        A.set(0, 0, 1); A.set(0, 1, 2);
        A.set(1, 0, 3); A.set(1, 1, 4);

        B.set(0, 0, 5); B.set(0, 1, 6); B.set(0, 2, 7);
        B.set(1, 0, 8); B.set(1, 1, 9); B.set(1, 2, 10);
        B.set(2, 0, 11); B.set(2, 1, 12); B.set(2, 2, 13);

        Matrix<int> C = A + B;
        C.print();
    }
    catch (const DimensionMismatchException& e) {
        cerr << e.what() << endl;
    }

    cout << "\n---- Valid Addition (2x2 + 2x2) ----" << endl;
    try {
        Matrix<int> X(2, 2);
        Matrix<int> Y(2, 2);

        X.set(0, 0, 10); X.set(0, 1, 20);
        X.set(1, 0, 30); X.set(1, 1, 40);

        Y.set(0, 0, 1); Y.set(0, 1, 2);
        Y.set(1, 0, 3); Y.set(1, 1, 4);

        Matrix<int> Z = X + Y;
        Z.print();
    }
    catch (const DimensionMismatchException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
