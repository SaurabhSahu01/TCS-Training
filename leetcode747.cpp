#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

// Function to read the input and convert it into the correct format
/*
    Input : "[1,2,3,4,5]" -> string representing an array
    Output : [1,2,3,4,5] -> array of integers
*/
vector<int> stringToArray(string s){
    vector<int> result;

    // main logic goes here

    // remove the brackets
    replace(s.begin(), s.end(), '[', ' ');
    replace(s.begin(), s.end(), ']', ' ');
    // " 1,2,3,4,5 "

    stringstream ss(s);
    string token;
    while(getline(ss, token, ',')){
        result.push_back(stoi(token));
    }

    return result;
}

int dominantIndex(vector<int>& nums) {
        int largest = INT_MIN, secondLargest = INT_MIN;
        int lidx = -1, slidx = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > largest){
                secondLargest = largest;
                largest = nums[i];
                slidx = lidx;
                lidx = i;
            }
            else if(nums[i] > secondLargest){
                secondLargest = nums[i];
                slidx = i;
            }
        }
        return (largest >= 2*secondLargest) ? lidx : -1;
}

int main(){
    string s;
    getline(cin, s);

    vector<int> formattedInput = stringToArray(s);

    cout << dominantIndex(formattedInput);

    return 0;
}