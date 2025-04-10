#include <iostream>
using namespace std;

class Matrix2x2;

class MatrixHelper {
public:
    void updateElement(Matrix2x2& matrix, int row, int col, int value);
};

class Matrix2x2 {
private:
    int a, b, c, d;

public:
    Matrix2x2(int a = 0, int b = 0, int c = 0, int d = 0)
        : a(a), b(b), c(c), d(d) {}

    void display() const {
        cout << "| " << a << " " << b << " |\n";
        cout << "| " << c << " " << d << " |\n";
    }

    Matrix2x2 operator+(const Matrix2x2& other) const {
        return Matrix2x2(a + other.a, b + other.b,
                         c + other.c, d + other.d);
    }

    Matrix2x2 operator-(const Matrix2x2& other) const {
        return Matrix2x2(a - other.a, b - other.b,
                         c - other.c, d - other.d);
    }

    Matrix2x2 operator*(const Matrix2x2& other) const {
        return Matrix2x2(
            a * other.a + b * other.c, a * other.b + b * other.d,
            c * other.a + d * other.c, c * other.b + d * other.d
        );
    }

    friend int determinant(const Matrix2x2& matrix);
    friend class MatrixHelper;
};

int determinant(const Matrix2x2& matrix) {
    return matrix.a * matrix.d - matrix.b * matrix.c;
}

void MatrixHelper::updateElement(Matrix2x2& matrix, int row, int col, int value) {
    if (row == 0 && col == 0) matrix.a = value;
    else if (row == 0 && col == 1) matrix.b = value;
    else if (row == 1 && col == 0) matrix.c = value;
    else if (row == 1 && col == 1) matrix.d = value;
    else cout << "Invalid index!\n";
}

int main() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);

    cout << "Matrix 1:\n";
    m1.display();

    cout << "Matrix 2:\n";
    m2.display();

    Matrix2x2 sum = m1 + m2;
    cout << "Sum:\n";
    sum.display();

    Matrix2x2 diff = m1 - m2;
    cout << "Difference:\n";
    diff.display();

    Matrix2x2 prod = m1 * m2;
    cout << "Product:\n";
    prod.display();

    cout << "Determinant of Matrix 1: " << determinant(m1) << endl;

    MatrixHelper helper;
    helper.updateElement(m1, 0, 1, 10);
    cout << "Matrix 1 after update:\n";
    m1.display();

    return 0;
}
