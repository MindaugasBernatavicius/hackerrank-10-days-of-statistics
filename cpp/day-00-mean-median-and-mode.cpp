#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;
vector<int> split_string(string);

int main() {
    int numberCount = 0; cin >> numberCount; cin.ignore();
    string numbersString = ""; getline(cin, numbersString);
    vector<int> nums = split_string(numbersString);
    
    // average - sum all and divide by how many are there
    int sum = 0;
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        sum += * it;
    
    cout << setprecision(1) << fixed << ((double)sum / nums.size()) << endl;
    
    // median - the middle value of sorted set, or the average of two middle values
    sort(nums.begin(), nums.end());
    
    if(nums.size() % 2 == 0){
        int beforeMid = (nums.size() / 2) - 1;
        int afterMid =  (nums.size() / 2);
        cout << setprecision(1) << fixed 
            << ((double)nums[beforeMid] + nums[afterMid]) / 2 << endl;
    } else {
        int mid = nums.size() / 2;
        cout << setprecision(1) << fixed << nums[mid] << endl;
    }
        
    // mode - the most frequently occuring number in a set, smallest one if equally occuring
    int most_frequent_num = nums[0];
    int max_occurrences = 1; 
    for(vector<int>::size_type i = 1; i != nums.size();) {
        int occurrences = 1;
        int j = i - 1;
        while(nums[j] == nums[j + 1]){
            occurrences++;
            j++;
        }
        if(occurrences > max_occurrences){
            max_occurrences = occurrences;
            most_frequent_num = nums[j];
        }
        // We know that we have a sorted array,
        // so we do not check for the smallest of two
        // numbers that occur equallly. If it occurs first,
        // we know it's the smallest
        
        (i < j) ? i = j : i++;
    }
    
    // TODO :: we can optimize by implementing a custom sort
    // and which while sorting would do addition and possibly
    // frequency tracking for us! This way, we could do all the 
    // operations while traversing the array once, possibly, 
    // although the summation can be hard to implement if we have
    // a non-linear sorting algorithm
    
    cout << most_frequent_num << endl;
    
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
