#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<int> split_string(string);

int main() {
    int count = 0; cin >> count; cin.ignore();
    string numbers_str = ""; getline(cin, numbers_str);
    string weights_str = ""; getline(cin, weights_str);
    vector<int> nums = split_string(numbers_str);
    vector<int> weights = split_string(weights_str);
    
    int weighted_sum = 0;
    int sum_of_weights = 0;
    
    for(vector<int>::size_type i = 0; i != nums.size(); ++i) {
        weighted_sum += nums[i] * weights[i];
        sum_of_weights += weights[i];
    }
    
    cout << setprecision(1) << fixed << (double)weighted_sum / sum_of_weights << endl;
    
    return 0;
}

vector<int> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<int> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(stoi(input_string.substr(i, pos - i)));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(stoi(input_string.substr(i, min(pos, input_string.length()) - i + 1)));

    return splits;
}
