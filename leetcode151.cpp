#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    // read and pre-process the input
    string s;
    getline(cin, s);

    vector<string> processedString;

    stringstream ss(s);
    string token;
    while(getline(ss, token, ' ')){
        if(token.size() != 0)
            processedString.push_back(token);
    }
    for(int i = processedString.size() -1 ; i >= 0; i--){
        if(i != 0)
            cout << processedString[i] << " ";
        else
            cout << processedString[i];
    }
    return 0;
}