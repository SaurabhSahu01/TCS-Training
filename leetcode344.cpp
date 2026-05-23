/*
    How to run : 
    step 1 : compile the program : g++ <program_name> -o <executable_name>
            e.g. g++ leetcode344.cpp -o output
    
    step 2. run the executable with indirected input 
            ./<executable_name> < <input_file>
            e.g. ./output < input.txt
        Note : make sure all the files are in the same directory

    NOTE : commands may vary in Windows system. Will work on linux and unix based systems.
*/

#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

// pass the string by reference
void reverseString(vector<char>& s){
    int i = 0, j = s.size() -1;
    while(i < j){
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return;
}

/*
    Input Format : ["a", "b", "c", "d"] -> string
    Ouput Format : [a, b, c, d] -> array of characters
*/
vector<char> stringToArray(string s){
    vector<char> result;

    // remove both the brackets
    replace(s.begin(), s.end(), ']', ' ');
    replace(s.begin(), s.end(), '[', ' ');
    // remove the double quotes
    replace(s.begin(), s.end(), '\"', ' ');

    stringstream ss(s);
    string token;

    while(getline(ss, token, ',')){
        for(auto ch : token){
            if(ch != ' ')
                result.push_back(ch);
        }
    }

    return result;
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