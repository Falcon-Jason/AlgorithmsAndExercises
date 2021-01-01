#include <iostream>
using namespace std;

class Matrix
{
  private:
    struct SubMatrix
    {
        Matrix &matrix_;
        int rowBegin_;
        int rowEnd_;
        int colBegin_;
        int colEnd_;

        SubMatrix(Matrix &matrix, int rowBegin, int rowEnd, int colBegin, int colEnd)
            : matrix_{matrix}
        {
            rowBegin_ = rowBegin;
            rowEnd_ = rowEnd;
            colBegin_ = colBegin;
            colEnd_ = colEnd;
        }

        int size() { return rowEnd_ - rowBegin_; }

        int &at(int i, int j) { return matrix_.at(rowBegin_ + i, colBegin_ + j); }

        SubMatrix &operator=(SubMatrix &rhs)
        {
            int sz = rowEnd_ - rowBegin_;
            for (int i = 0; i < sz; i++)
            {
                for (int j = 0; j < sz; j++)
                {
                    at(i, j) = rhs.at(i, j);
                }
            }
            return *this;
        }

        SubMatrix &operator=(Matrix &&rhs)
        {
            int sz = rowEnd_ - rowBegin_;
            for (int i = 0; i < sz; i++)
            {
                for (int j = 0; j < sz; j++)
                {
                    at(i, j) = rhs.at(i, j);
                }
            }
            return *this;
        }
    };

    struct MatrixPartition
    {
        SubMatrix part[4];
        MatrixPartition(SubMatrix &matrix, int mid)
            : part{
                  {matrix.matrix_,
                   matrix.rowBegin_,
                   matrix.rowBegin_ + mid,
                   matrix.colBegin_,
                   matrix.colBegin_ + mid},
                  {matrix.matrix_,
                   matrix.rowBegin_,
                   matrix.rowBegin_ + mid,
                   matrix.colBegin_ + mid,
                   matrix.colEnd_},
                  {matrix.matrix_,
                   matrix.rowBegin_ + mid,
                   matrix.rowEnd_,
                   matrix.colBegin_,
                   matrix.colBegin_ + mid},
                  {matrix.matrix_,
                   matrix.rowBegin_ + mid,
                   matrix.rowEnd_,
                   matrix.colBegin_ + mid,
                   matrix.colEnd_}} {}

        SubMatrix &operator[](int i)
        {
            return part[i];
        }
    };

    friend Matrix operator+(Matrix a, Matrix b)
    {
        int sz = a.size_;
        Matrix m{sz};
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                m.at(i, j) = a.at(i, j) + b.at(i, j);
            }
        }
        return m;
    }

    friend Matrix operator*(SubMatrix &a, SubMatrix &b)
    {
        int n = a.size();
        Matrix c{n};

        if (n == 1)
        {
            c.at(0, 0) = a.at(0, 0) * b.at(0, 0);
        }
        else
        {
            SubMatrix cSub{c, 0, n, 0, n};
            MatrixPartition ap{a, n / 2};
            MatrixPartition bp{b, n / 2};
            MatrixPartition cp{cSub, n / 2};

            // cout << n / 2 << endl;

            cp[0] = ap[0] * bp[0] + ap[1] * bp[2];
            cp[1] = ap[0] * bp[1] + ap[1] * bp[3];
            cp[2] = ap[2] * bp[0] + ap[3] * bp[2];
            cp[3] = ap[2] * bp[1] + ap[3] * bp[3];
        }

        return c;
    }

    int *data_;
    int size_;
    int capacity_;

  public:
    Matrix(int size)
    {
        size_ = size;
        for (capacity_ = 1; capacity_ < size; capacity_*=2)
            ;
        data_ = new int[capacity_ * capacity_];
    }

    ~Matrix()
    {
        delete[] data_;
    }

    int &at(int i, int j) { return data_[i * size_ + j]; }

    Matrix operator*(Matrix &rhs)
    {
        if (size_ == 0)
            return Matrix{0};

        SubMatrix a{*this, 0, capacity_, 0, capacity_};
        SubMatrix b{rhs, 0, rhs.capacity_, 0, rhs.capacity_};
        return a * b;
    }

    Matrix operator=(Matrix &rhs)
    {
        for (int i = 0; i < size_; i++)
        {
            for (int j = 0; j < size_; j++)
            {
                at(i, j) = rhs.at(i, j);
            }
        }
        return *this;
    }
};

int main()
{
    using namespace std;

    int size;
    cin >> size;

    Matrix a{size}, b{size};
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> a.at(i, j);
        }
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cin >> b.at(i, j);
        }
    }

    Matrix c = a * b;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << c.at(i, j) << " ";
        }
        cout << endl;
    }
}