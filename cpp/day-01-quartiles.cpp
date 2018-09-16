#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
vector<int> split_string(string);

double get_median(vector<int> &nums){
    double median = 0.0;
    if(nums.size() % 2 == 0){
        int beforeMid   = (nums.size() / 2) - 1;
        int afterMid    = (nums.size() / 2);
        median = ((double)nums[beforeMid] + nums[afterMid]) / 2;
    } else {
        median = nums[nums.size() / 2];
    }
    return median;
}

int main() {
    int number_count = 0; cin >> number_count; cin.ignore();
    string nums_str = ""; getline(cin, nums_str);
    vector<int> nums = split_string(nums_str);
    sort(nums.begin(), nums.end());
    
    double q1, q2, q3;
    if(nums.size() % 2 != 0)
    { // if we have a median - exclude it from L, U.
        vector<int> l(nums.begin(), (nums.begin() + (nums.size() / 2)));
        vector<int> u(nums.begin() + ((nums.size() / 2) + 1), nums.end());
        q1 = get_median(l);
        q2 = get_median(nums);
        q3 = get_median(u);
    } 
    else
    { // calculates the quartiles if we don't have a natural median
        vector<int> l(nums.begin(), (nums.begin() + (nums.size() / 2)));
        vector<int> u(nums.begin() + (nums.size() / 2), nums.end());
        q1 = get_median(l);
        q2 = get_median(nums);
        q3 = get_median(u);
    }
    
    cout << q1 << endl
        << q2 << endl
        << q3 << endl;
    
    return 0;
}

vector<int> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
        input_string.pop_back();

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
