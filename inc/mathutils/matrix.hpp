#pragma once

#include <iostream>
#include <cmath>

namespace math {
    template<typename T, int N, int M>
    struct MasWrapper {
        T mas[N][M];
    };

    template<typename T, int N, int M>
    class Matrix {
    public:
        Matrix() {
            m_n = N;
            m_m = M;
            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                    m_mat[i][j] = 0;
        }

        Matrix(const T mas[N][M]) {
            m_n = N;
            m_m = M;
            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                    m_mat[i][j] = mas[i][j];
        }

        Matrix(const MasWrapper<T, N, M> &mas) {
            m_n = N;
            m_m = M;
            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                    m_mat[i][j] = mas.mas[i][j];
        }

        Matrix(const Matrix<T, N, M> &mat) {
            m_n = mat.m_n;
            m_m = mat.m_m;

            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                    m_mat[i][j] = mat.m_mat[i][j];
        }

        int getN() const { return m_n; }

        int getM() const { return m_m; }

        T get(int i, int j) const { return m_mat[i][j]; }

        void set(int i, int j, T data) { m_mat[i][j] = data; }

        template<typename t, int n, int m>
        Matrix<t, n, m> &operator=(const Matrix<t, n, m> &mat) {

            m_n = mat.getN();
            m_m = mat.getM();

            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                    m_mat[i][j] = mat.get(i, j);

            return *this;
        }

        bool operator==(const Matrix<T, N, M> &mat) {
            if (this->getN() != mat.getN() or this->getM() != mat.getM())
                return false;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if (this->get(i, j) != mat.get(i, j))
                        return false;
                }
            }
            return true;
        }

        template<typename t, int n, int m>
        Matrix<t, n, m> operator+(const Matrix<t, n, m> &mat) {
            Matrix<t, n, m> tmp;
            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < m_m; j++)
                    tmp.m_mat[i][j] = m_mat[i][j] + mat.m_mat[i][j];
            return tmp;
        }

        template<typename t, int n, int m>
        Matrix<t, n, m> operator*(const Matrix<t, n, m> &mat) {
            Matrix<t, n, m> tmp;

            for (int i = 0; i < m_n; i++)
                for (int j = 0; j < mat.getM(); j++) {
                    T sum = 0;
                    for (int k = 0; k < m_m; k++)
                        sum += m_mat[i][k] * mat.get(k, j);
                    tmp.set(i, j, sum);
                }

            return tmp;
        }


        float getDet() {
            if (m_n == m_m) {
                if (m_n == 2)
                    return m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
                else if (m_n == 3)
                    return m_mat[0][0] * m_mat[1][1] * m_mat[2][2] +
                           m_mat[0][1] * m_mat[1][2] * m_mat[2][0]
                           + m_mat[1][0] * m_mat[2][1] * m_mat[0][2] -
                           m_mat[2][0] * m_mat[1][1] * m_mat[0][2] -
                           m_mat[2][1] * m_mat[1][2] * m_mat[0][0] -
                           m_mat[1][0] * m_mat[0][1] * m_mat[2][2];
                else {
                    std::cout << "Not supported\n";
                    return {};
                }
            } else {
                std::cout << "Not supported\n";
                return {};
            }
        }

        template<typename t, int n, int m>
        void inverse() {
            if (m_n == m_m) {
                double det = this->getDet();
                if (m_n == 2) {
                    Matrix<t, n - 1, m - 1> tmp;
                    for (int i = 0; i < m_n; i++) {
                        for (int j = 0; j < m_m; j++) {
                            tmp.set(j, i, (1 / det) * std::pow(-1, 2 + i + j) * m_mat[1 - j][1 - i]);
                        }
                    }
                    for (int i = 0; i < m_n; i++) {
                        for (int j = 0; j < m_m; j++) {
                            this->set(i, j, tmp.get(i, j));
                        }
                    }
                } else if (m_n == 3) {
                    Matrix<t, n, m> tmp1;
                    for (int i = 0; i < m_n; i++) {
                        for (int j = 0; j < m_m; j++) {
                            Matrix<t, n - 1, m - 1> tmp;
                            int x = 0;
                            for (int k = 0; k < 3; k++) {
                                int y = 0;
                                if (k == i)
                                    continue;
                                for (int l = 0; l < 3; l++) {
                                    if (l == j)
                                        continue;
                                    tmp.set(x, y, m_mat[k][l]);
                                    y++;
                                }
                                x++;
                            }
                            tmp1.set(j, i, (1 / det) * std::pow(-1, 2 + i + j) * tmp.getDet());
                        }
                    }

                    for (int i = 0; i < m_n; i++) {
                        for (int j = 0; j < m_m; j++) {
                            this->set(i, j, tmp1.get(i, j));
                        }
                    }
                }

            } else {
                std::cout << "Not supported\n";
            }
        }

        void transposition() {
            if (N != M) {
                Matrix<T, M, N> tmp;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < M; j++) {
                        tmp.set(j, i, this->get(i, j));
                    }
                }
                T m_mat[M][N];
                m_n = M;
                m_m = N;

                for (int i = 0; i < m_n; i++) {
                    for (int j = 0; j < m_m; j++) {
                        this->set(i, j, tmp.get(i, j));
                    }
                }
            } else {
                for (int i = 0; i < N; i++) {
                    for (int j = i + 1; j < M; j++) {
                        std::swap(m_mat[i][j], m_mat[j][i]);
                    }
                }
            }
        }

        ~Matrix() {}

        template<typename t, int n, int m>
        friend std::istream &operator>>(std::istream &os, Matrix<t, n, m> &mat);

        template<typename t, int n, int m>
        friend std::ostream &operator<<(std::ostream &os, const Matrix<t, n, m> &mat);

    private:
        int m_n, m_m;
        T m_mat[N][M];
    };

    template<typename T, int N, int M>
    std::istream &operator>>(std::istream &in, Matrix<T, N, M> &mat) {
        for (int i = 0; i < mat.m_n; i++)
            for (int j = 0; j < mat.m_m; j++)
                in >> mat.m_mat[i][j];
        return in;
    }

    template<typename T, int N, int M>
    std::ostream &operator<<(std::ostream &out, const Matrix<T, N, M> &mat) {
        out << "Matrix " << mat.m_n << "x" << mat.m_m << std::endl;
        for (int i = 0; i < mat.m_n; i++) {
            for (int j = 0; j < mat.m_m; j++)
                out << mat.m_mat[i][j] << " ";
            out << std::endl;
        }
        return out;
    }

    using Vec2i = Matrix<int, 2, 1>;
    using Vec2d = Matrix<double, 2, 1>;
    using Mat22i = Matrix<int, 2, 2>;
    using Mat22d = Matrix<double, 2, 2>;
    using Mat33d = Matrix<double, 3, 3>;
    using Mat33i = Matrix<int, 3, 3>;
}