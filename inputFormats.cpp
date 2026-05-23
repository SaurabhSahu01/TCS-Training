#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;
/*
    Function to read input array given as a space separated string
    Input: "1 2 3 4 5" -> a string representing the array
    Output : [1, 2, 3, 4, 5] -> an array
*/

vector<int> stringToArray(string s, char delimiter){
    vector<int> result;

    // logic goes here
    stringstream ss(s);
    string token;

    while(getline(ss, token, delimiter)){
        result.push_back(stoi(token));
    }


    return result;
}

/*
    Function to read "string input array with brackets"
    Input : "[1, 2, 3, 4, 5]"
    Ouput : [1, 2, 3, 4, 5]
*/
vector<int> stringBracketToArray(string s){
    // main logic goes here
    replace(s.begin(), s.end(), '[', ' ');
    replace(s.begin(), s.end(), ']', ' ');

    vector<int> result = stringToArray(s, ',');

    return result;
}

/*
    Function to read "string input array with brackets and construct a 2D array"
    Input : rows = 2,
            cols = 3,
            Input Array String = "[1, 2, 3, 4, 5, 6]"
    
    Output : [[1,2,3], [4,5,6]] -> 2D array of dimension (rows x cols)
*/
vector<vector<int>> create2DArray(int rows, int cols, string s){
    vector<vector<int>> result(rows, vector<int>(cols, 0)); // 2D array of dimension (rows x cols)

    vector<int> formattedArray = stringBracketToArray(s);

    int k = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = formattedArray[k++];
        }
    }

    return result;
}

/*

*/

vector<vector<int>> create2DArrayNoDimension(string s){
    // find the dimensions
    int rows = 0, cols = 0, totalElements = 0;

    for(auto ch : s){
        if(ch == '[') rows++;
    }
    rows = rows - 1;

    // pre-processing of string
    replace(s.begin(), s.end(), '[', ' ');
    replace(s.begin(), s.end(), ']', ' ');

    vector<int> ans = stringToArray(s, ',');

    totalElements = ans.size();
    cols = totalElements / rows;

    vector<vector<int>> result(rows, vector<int>(cols, 0));
    int k = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = ans[k++];
        }
    }
    return result;
}

int main(){
    // int rows, cols;
    // cin >> rows >> cols;

    // cin.ignore(); // important
    
    string s;
    getline(cin, s);
    
    vector<vector<int>> ans = create2DArrayNoDimension(s);
    for(auto row : ans){
        for(auto elem : row)
            cout << elem << " ";
        cout << endl;
    }
    return 0;
}