#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

// pass the string by reference
void reverseString(vector<char>& s){
    // logic goes here

    return;
}

vector<char> stringToArray(string s){
    // write the logic
}

int main(){
    string input;
    // read the input string
    getline(cin, input);

    // pre-processing the input to convert into an array of character
    vector<char> processedInput = stringToArray(input);

    reverseString(processedInput);

    for(auto ch : processedInput)
        cout << ch << " ";


    return 0;
}