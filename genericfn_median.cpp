#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Median{

private:
    int size;
    vector<int> values;

public:
    void input() {
        cout << "Enter the size : ";
        cin >> size;
        cout << "Enter the values :\n";
        for (int i = 0; i < size; i++) {
            int value;
            cin >> value;
            values.push_back(value);
        }
        sort(values.begin(), values.end());
    }

    //calculating the median
    int calculateMedian() {
        if (size % 2 == 1) {
            // For odd-sized vector, return middle element
            return values[size / 2];
        }
        else {
            // For even-sized vector, return average of two middle elements
            return (values[size / 2 - 1] + values[size / 2]) / 2;
        }
    }
};

int main() {
    Median data;
    data.input();
    int median = data.calculateMedian();
    cout << "Median : " << median << std::endl;
    return 0;
}
