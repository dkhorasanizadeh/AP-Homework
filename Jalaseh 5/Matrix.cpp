/*
--------------------------------------------------
Name    : Matrix
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 12/Apr/2021
--------------------------------------------------
*/
#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>
template <class T>
class Matrix
{
private:
    std::vector<std::vector<T>> matrix;

public:
    Matrix(std::vector<std::vector<T>> m);
    Matrix(void);
    ~Matrix();
    std::vector<T> getRow(int row);
    std::vector<std::vector<T>> getMatrix(void);
    T getElement(int row, int col);
    void setRow(std::vector<T> row, int rowNum);
    void setElement(T element, int row, int col);
    Matrix<T> multiplication(Matrix<T> m);
    Matrix<T> addition(Matrix<T> m);
    Matrix<T> subtraction(Matrix<T> m);
    Matrix<T> integerMultiplication(int num);
    Matrix<T> integerDivision(int num);
    bool isEqual(Matrix<T> m);
    bool isNotEqual(Matrix<T> m);
    void matrixCin(int rowSize, int colSize);
    void matrixCout(void);
};
template <>
class Matrix<char *>
{
private:
    std::vector<std::vector<char *>> matrix;

public:
    Matrix(std::vector<std::vector<char *>> matrix);
    Matrix(void);
    ~Matrix();
    std::vector<char *> getRow(int row);
    std::vector<std::vector<char *>> getMatrix(void);
    char *getElement(int row, int col);
    void setRow(std::vector<char *> row, int rowNum);
    void setElement(char *element, int row, int col);
    Matrix<char *> addition(Matrix<char *> m);
    bool isEqual(Matrix<char *> m);
    bool isNotEqual(Matrix<char *> m);
    void matrixCin(int rowSize, int colSize);
    void matrixCout(void);
};
template <class T>
Matrix<T>::Matrix(std::vector<std::vector<T>> m)
{
    matrix = m;
}
template <class T>
Matrix<T>::Matrix(void)
{
}
template <class T>
Matrix<T>::~Matrix(void)
{
}
template <class T>
std::vector<T> Matrix<T>::getRow(int row)
{
    assert(row - 1 <= matrix.size());
    return matrix[row - 1];
}
template <class T>
std::vector<std::vector<T>> Matrix<T>::getMatrix(void)
{
    return matrix;
}
template <class T>
T Matrix<T>::getElement(int row, int col)
{
    assert(col - 1 <= matrix[row].size());
    assert(row - 1 <= matrix.size());
    return matrix[row - 1][col - 1];
}
template <class T>
void Matrix<T>::setRow(std::vector<T> row, int rowNum)
{
    assert(rowNum - 1 <= matrix.size());
    assert(row.size() == matrix[rowNum - 1].size());
    matrix[rowNum - 1] = row;
}
template <class T>
void Matrix<T>::setElement(T element, int row, int col)
{
    assert(col - 1 <= matrix[row].size());
    assert(row - 1 <= matrix.size());
    matrix[row - 1][col - 1] = element;
}
template <class T>
Matrix<T> Matrix<T>::multiplication(Matrix<T> m)
{
    assert(matrix[0].size() == m.matrix.size());
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(m.matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < m.matrix[0].size(); j++)
        {
            for (int k = 0; k < matrix[0].size(); k++)
            {
                result[i][j] += matrix[i][k] * m.matrix[k][j];
            }
        }
    }
    Matrix<T> res(result);
    return res;
}
template <class T>
Matrix<T> Matrix<T>::addition(Matrix<T> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[i][j] = matrix[i][j] + m.matrix[i][j];
        }
    }
    Matrix<T> res(result);
    return res;
}
template <class T>
Matrix<T> Matrix<T>::subtraction(Matrix<T> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[i][j] = matrix[i][j] - m.matrix[i][j];
        }
    }
    Matrix<T> res(result);
    return res;
}
template <class T>
Matrix<T> Matrix<T>::integerMultiplication(int num)
{
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[i][j] = matrix[i][j] * num;
        }
    }
    Matrix<T> res(result);
    return res;
}
template <class T>
Matrix<T> Matrix<T>::integerDivision(int num)
{
    std::vector<std::vector<T>> result(matrix.size(), std::vector<T>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            result[i][j] = matrix[i][j] / num;
        }
    }
    Matrix<T> res(result);
    return res;
}
template <class T>
bool Matrix<T>::isEqual(Matrix<T> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != m.matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
template <class T>
bool Matrix<T>::isNotEqual(Matrix<T> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (matrix[i][j] != m.matrix[i][j])
            {
                return true;
            }
        }
    }
    return false;
}
template <class T>
void Matrix<T>::matrixCin(int rowSize, int colSize)
{
    matrix.clear();
    for (int i = 0; i < colSize; i++)
    {
        std::vector<T> col;
        for (int j = 0; j < rowSize; j++)
        {
            T input;
            std::cin >> input;
            col.push_back(input);
        }
        matrix.push_back(col);
    }
}
template <class T>
void Matrix<T>::matrixCout(void)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
Matrix<char *>::Matrix(std::vector<std::vector<char *>> m)
{
    matrix = m;
}
Matrix<char *>::Matrix(void)
{
}
Matrix<char *>::~Matrix(void)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            delete matrix[i][j];
        }
    }
}
std::vector<char *> Matrix<char *>::getRow(int row)
{
    assert(row - 1 <= matrix.size());
    return matrix[row - 1];
}
std::vector<std::vector<char *>> Matrix<char *>::getMatrix(void)
{
    return matrix;
}
char *Matrix<char *>::getElement(int row, int col)
{
    assert(col - 1 <= matrix[row].size());
    assert(row - 1 <= matrix.size());
    return matrix[row - 1][col - 1];
}
void Matrix<char *>::setRow(std::vector<char *> row, int rowNum)
{
    assert(rowNum - 1 <= matrix.size());
    assert(row.size() == matrix[rowNum - 1].size());
    matrix[rowNum - 1] = row;
}
void Matrix<char *>::setElement(char *element, int row, int col)
{
    assert(col - 1 < matrix[row - 1].size());
    assert(row - 1 < matrix.size());
    matrix[row - 1][col - 1] = element;
}
Matrix<char *> Matrix<char *>::addition(Matrix<char *> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    std::vector<std::vector<char *>> result(matrix.size(), std::vector<char *>(matrix[0].size()));
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            int size = strlen(matrix[i][j]) + strlen(m.matrix[i][j]) + 1;
            result[i][j] = new char[size];
            std::strcpy(result[i][j], matrix[i][j]);
            std::strcat(result[i][j], m.matrix[i][j]);
        }
    }
    Matrix<char *> res(result);
    return res;
}
bool Matrix<char *>::isEqual(Matrix<char *> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (strcmp(matrix[i][j], m.matrix[i][j]))
            {
                return false;
            }
        }
    }
    return true;
}
bool Matrix<char *>::isNotEqual(Matrix<char *> m)
{
    assert(matrix[0].size() == m.matrix[0].size());
    assert(matrix.size() == m.matrix.size());
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (strcmp(matrix[i][j], m.matrix[i][j]))
            {
                return true;
            }
        }
    }
    return false;
}
void Matrix<char *>::matrixCin(int rowSize, int colSize)
{
    matrix.clear();
    for (int i = 0; i < colSize; i++)
    {
        std::vector<char *> col;
        for (int j = 0; j < rowSize; j++)
        {
            std::string input;
            std::cin >> input;
            char *cInput = new char[input.length()];
            std::strcpy(cInput, input.c_str());
            col.push_back(cInput);
        }
        matrix.push_back(col);
    }
}
void Matrix<char *>::matrixCout(void)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
int main(void)
{
    return 0;
}