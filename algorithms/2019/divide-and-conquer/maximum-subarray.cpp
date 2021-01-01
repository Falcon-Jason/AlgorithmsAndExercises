#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
struct subarray
{
    int *low;
    int *high;
    int sum;

    subarray(int *low, int *high, int sum);
    subarray &operator=(subarray &rhs);
    bool operator<(const subarray &rhs) const;
    friend ostream &operator<<(ostream &out, const subarray &subarr);
};

subarray maxCrossingSubarray(int *low, int *mid, int *high);
subarray maxSubarray(int *low, int *high);
vector<int> &readArray();

int main()
{
    vector<int> &arr = readArray();
    subarray subarr = maxSubarray(arr.data(), arr.data() + arr.size() - 1);
    std::cout << subarr.sum << std::endl;
    std::cout << subarr << endl;
    delete &arr;
    return 0;
}

subarray maxSubarray(int *low, int *high)
{
    if (high == low)
        return subarray(low, high, *low);

    int *mid = low + (high - low) / 2;

    subarray leftMaxSubarray = maxSubarray(low, mid);
    subarray rightMaxSubarray = maxSubarray(mid + 1, high);
    subarray crossMaxSubarray = maxCrossingSubarray(low, mid, high);

    return max(max(leftMaxSubarray, rightMaxSubarray), crossMaxSubarray);
}

subarray maxCrossingSubarray(int *low, int *mid, int *high)
{
    int leftSum = 0;
    int *leftPointer = mid;
    int rightSum = 0;
    int *rightPointer = mid;

    int sum = 0;
    if (mid != low)
    {
        for (int *i = mid; i >= low; --i)
        {
            sum += *i;
            if (sum > leftSum)
            {
                leftSum = sum;
                leftPointer = i;
            }
        }
    }

    sum = 0;
    for (int *i = mid + 1; i < high; ++i)
    {
        sum += *i;
        if (sum > rightSum)
        {
            rightSum = sum;
            rightPointer = i;
        }
    }

    return subarray(leftPointer, rightPointer, leftSum + rightSum);
}

subarray::subarray(int *low, int *high, int sum)
{
    this->low = low;
    this->high = high;
    this->sum = sum;
}

subarray &subarray::operator=(subarray &rhs)
{
    this->low = rhs.low;
    this->high = rhs.high;
    this->sum = rhs.sum;
    return *this;
}

bool subarray::operator<(const subarray &rhs) const
{
    return sum < rhs.sum;
}

vector<int> &readArray()
{
    vector<int> *vec = new vector<int>{};
    vec->clear();

    string line;
    getline(cin, line);
    istringstream in{line};
    int i;

    while (in >> i)
    {
        vec->push_back(i);
    }
    return *vec;
}

ostream &operator<<(ostream &out, const subarray &subarr)
{
    cout << *subarr.low;
    for (int *i = subarr.low + 1; i <= subarr.high; i++)
        cout << " " << *i;
    return out;
}