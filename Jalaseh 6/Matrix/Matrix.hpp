/*
--------------------------------------------------
Name    : Matrix
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 17/Apr/2021
--------------------------------------------------
*/
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
template <class T>
class Matrix;
template <class T>
std::ostream &operator<<(std::ostream &, Matrix<T> &);
template <class T>
std::istream &operator>>(std::istream &, Matrix<T> &);
template <class T>
class Matrix {
 private:
  std::vector<std::vector<T>> matrix;

 public:
  Matrix(std::vector<std::vector<T>> m);
  Matrix(void);
  ~Matrix();
  std::vector<T> &operator[](int row);
  Matrix<T> &operator=(const Matrix<T> &m);
  T &operator()(int row, int col);
  Matrix<T> operator*(const Matrix<T> &m);
  Matrix<T> operator+(const Matrix<T> &m);
  Matrix<T> operator-(const Matrix<T> &m);
  Matrix<T> &operator*=(const Matrix<T> &m);
  Matrix<T> &operator+=(const Matrix<T> &m);
  Matrix<T> &operator-=(const Matrix<T> &m);
  Matrix<T> operator*(int num);
  Matrix<T> &operator*=(int num);
  Matrix<T> operator/(int num);
  Matrix<T> &operator/=(int num);
  Matrix<T> operator+(int num);
  Matrix<T> &operator+=(int num);
  Matrix<T> operator-(int num);
  Matrix<T> &operator-=(int num);
  Matrix<T> &operator++(void);
  Matrix<T> operator++(int);
  Matrix<T> &operator--(void);
  Matrix<T> operator--(int);
  bool operator==(const Matrix<T> &m);
  bool operator!=(const Matrix<T> &m);
  friend std::istream &operator>><T>(std::istream &in, Matrix<T> &m);
  friend std::ostream &operator<<<T>(std::ostream &out, Matrix<T> &m);
};
template <>
class Matrix<char *> {
 private:
  std::vector<std::vector<char *>> matrix;

 public:
  Matrix(std::vector<std::vector<char *>> matrix);
  Matrix(void);
  ~Matrix();
  std::vector<char *> &operator[](int row);
  Matrix<char *> &operator=(const Matrix<char *> &m);
  char *operator()(int row, int col);
  Matrix<char *> operator+(const Matrix<char *> &m);
  Matrix<char *> &operator+=(const Matrix<char *> &m);
  bool operator==(const Matrix<char *> &m);
  bool operator!=(const Matrix<char *> &m);
  friend std::istream &operator>>(std::istream &in, Matrix<char *> &m);
  friend std::ostream &operator<<(std::ostream &out, Matrix<char *> &m);
};
template <class T>
Matrix<T>::Matrix(std::vector<std::vector<T>> m) {
  matrix = m;
}
template <class T>
Matrix<T>::Matrix(void) {}
template <class T>
Matrix<T>::~Matrix(void) {}
template <class T>
std::vector<T> &Matrix<T>::operator[](int row) {
  assert(row <= matrix.size());
  return matrix[row];
}
template <class T>
Matrix<T> &Matrix<T>::operator=(const Matrix<T> &m) {
  matrix = m.matrix;
  return *this;
}
template <class T>
T &Matrix<T>::operator()(int row, int col) {
  assert(col <= matrix[row].size());
  assert(row <= matrix.size());
  return matrix[row][col];
}
template <class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix.size());
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(m.matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < m.matrix[0].size(); j++) {
      for (int k = 0; k < matrix[0].size(); k++) {
        result[i][j] += matrix[i][k] * m.matrix[k][j];
      }
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix.size());
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(m.matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < m.matrix[0].size(); j++) {
      for (int k = 0; k < matrix[0].size(); k++) {
        result[i][j] += matrix[i][k] * m.matrix[k][j];
      }
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] + m.matrix[i][j];
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] + m.matrix[i][j];
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] - m.matrix[i][j];
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] - m.matrix[i][j];
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator*(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] * num;
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator*=(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] * num;
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator/(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] / num;
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator/=(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] / num;
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator+(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] + num;
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator+=(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] + num;
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator-(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] - num;
    }
  }
  Matrix<T> res(result);
  return res;
}
template <class T>
Matrix<T> &Matrix<T>::operator-=(int num) {
  std::vector<std::vector<T>> result(matrix.size(),
                                     std::vector<T>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      result[i][j] = matrix[i][j] - num;
    }
  }
  matrix = result;
  return *this;
}
template <class T>
Matrix<T> &Matrix<T>::operator++(void) {
  this->operator+=(1);
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator++(int) {
  Matrix<T> returnObject(matrix);
  this->operator+=(1);
  return returnObject;
}
template <class T>
Matrix<T> &Matrix<T>::operator--(void) {
  this->operator-=(1);
  return *this;
}
template <class T>
Matrix<T> Matrix<T>::operator--(int) {
  Matrix<T> returnObject(matrix);
  this->operator+=(1);
  return returnObject;
}
template <class T>
bool Matrix<T>::operator==(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] != m.matrix[i][j]) {
        return false;
      }
    }
  }
  return true;
}
template <class T>
bool Matrix<T>::operator!=(const Matrix<T> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (matrix[i][j] != m.matrix[i][j]) {
        return true;
      }
    }
  }
  return false;
}
template <class T>
std::istream &operator>>(std::istream &in, Matrix<T> &m) {
  m.matrix.clear();
  int colSize, rowSize;
  std::cout << "Please Enter Number of Columns:" << std::endl;
  in >> colSize;
  std::cout << "Please Enter Number of Rows:" << std::endl;
  in >> rowSize;
  std::cout << "Please Enter The Matrix:" << std::endl;
  for (int i = 0; i < colSize; i++) {
    std::vector<T> col;
    for (int j = 0; j < rowSize; j++) {
      T input;
      in >> input;
      col.push_back(input);
    }
    m.matrix.push_back(col);
  }
  return in;
}
template <class T>
std::ostream &operator<<(std::ostream &out, Matrix<T> &m) {
  for (int i = 0; i < m.matrix.size(); i++) {
    for (int j = 0; j < m.matrix[0].size(); j++) {
      out << m.matrix[i][j] << " ";
    }
    out << std::endl;
  }
  return out;
}
Matrix<char *>::Matrix(std::vector<std::vector<char *>> m) { matrix = m; }
Matrix<char *>::Matrix(void) {}
Matrix<char *>::~Matrix(void) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      delete matrix[i][j];
    }
  }
}
std::vector<char *> &Matrix<char *>::operator[](int row) {
  assert(row <= matrix.size());
  return matrix[row];
}
Matrix<char *> &Matrix<char *>::operator=(const Matrix<char *> &m) {
  matrix = m.matrix;
  return *this;
}
char *Matrix<char *>::operator()(int row, int col) {
  assert(col <= matrix[row].size());
  assert(row <= matrix.size());
  return matrix[row][col];
}
Matrix<char *> Matrix<char *>::operator+(const Matrix<char *> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  std::vector<std::vector<char *>> result(
      matrix.size(), std::vector<char *>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      int size = strlen(matrix[i][j]) + strlen(m.matrix[i][j]) + 1;
      result[i][j] = new char[size];
      std::strcpy(result[i][j], matrix[i][j]);
      std::strcat(result[i][j], m.matrix[i][j]);
    }
  }
  Matrix<char *> res(result);
  return res;
}
Matrix<char *> &Matrix<char *>::operator+=(const Matrix<char *> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  std::vector<std::vector<char *>> result(
      matrix.size(), std::vector<char *>(matrix[0].size()));
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      int size = strlen(matrix[i][j]) + strlen(m.matrix[i][j]) + 1;
      result[i][j] = new char[size];
      std::strcpy(result[i][j], matrix[i][j]);
      std::strcat(result[i][j], m.matrix[i][j]);
    }
  }
  matrix = result;
  return *this;
}
bool Matrix<char *>::operator==(const Matrix<char *> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (strcmp(matrix[i][j], m.matrix[i][j])) {
        return false;
      }
    }
  }
  return true;
}
bool Matrix<char *>::operator!=(const Matrix<char *> &m) {
  assert(matrix[0].size() == m.matrix[0].size());
  assert(matrix.size() == m.matrix.size());
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      if (strcmp(matrix[i][j], m.matrix[i][j])) {
        return true;
      }
    }
  }
  return false;
}
std::istream &operator>>(std::istream &in, Matrix<char *> &m) {
  m.matrix.clear();
  int colSize, rowSize;
  std::cout << "Please Enter Number of Columns:" << std::endl;
  in >> colSize;
  std::cout << "Please Enter Number of Rows:" << std::endl;
  in >> rowSize;
  for (int i = 0; i < colSize; i++) {
    std::vector<char *> col;
    for (int j = 0; j < rowSize; j++) {
      std::string input;
      in >> input;
      char *cInput = new char[input.length()];
      std::strcpy(cInput, input.c_str());
      col.push_back(cInput);
    }
    m.matrix.push_back(col);
  }
  return in;
}
std::ostream &operator<<(std::ostream &out, Matrix<char *> &m) {
  for (int i = 0; i < m.matrix.size(); i++) {
    for (int j = 0; j < m.matrix[0].size(); j++) {
      out << m.matrix[i][j] << " ";
    }
    out << std::endl;
  }
  return out;
}