#include<iostream>
#include<sstream>
#include<algorithm>
#include<vector>


using namespace std;

vector<int> stringToArray(string s){
    vector<int> result;

    // main logic goes here
    stringstream ss(s);
    string token;
    while(getline(ss, token, ' ')){
        result.push_back(stoi(token));
    }

    return result;
}

void printArray(vector<int> arr){
    for(auto elem : arr)
        cout << elem << " ";
    cout << endl;
}

int main(){
    // read and pre-process the input
    string s1, s2;
    getline(cin, s1); // DON'T use cin for taking input to the string
    getline(cin, s2);

    vector<int> arr1 = stringToArray(s1);
    vector<int> arr2 = stringToArray(s2);

    // print both the arrays
    printArray(arr1);
    printArray(arr2);

    int finalSize = arr1.size() + arr2.size();
    vector<int> result(finalSize, 0);

    // main logic
    int i = 0, j = 0, k = 0;
    while(i < arr1.size() && j < arr2.size()){
        if(arr1[i] < arr2[j]){
            result[k++] = arr1[i++];
        }
        else{
            result[k++] = arr2[j++];
        }
    }
    while(i < arr1.size()){
        result[k++] = arr1[i++];
    }
    while(j < arr2.size()){
        result[k++] = arr2[j++];
    }

    // print the final array
    printArray(result);
    return 0;
}