#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    Constraint: rows, cols >= 2
    0 <= arr[i][j] or arr[i][j] <= 0 ( elements could be positive or negative or zero )
*/

vector<vector<int>> constructMatrixFromString(int rows, int cols, string s){
    vector<vector<int>> result(rows, vector<int>(cols, 0));

    // remove the brackets
    replace(s.begin(), s.end(), '[', ' ');
    replace(s.begin(), s.end(), ']', ' ');

    stringstream ss(s);
    string token;

    vector<int> parsedString;

    while(getline(ss, token, ',')){
        parsedString.push_back(stoi(token));
    }

    int k = 0;
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = parsedString[k++];
        }
    }

    return result;
}

int sumOfWindow(int sr, int er, int sc, int ec, vector<vector<int>> mat){
    int sum = 0;
    for(int i = sr; i <= er; i++){
        for(int j = sc; j <= ec; j++){
            sum += mat[i][j];
        }
    }
    return sum;
}

int maxSumUsing2x2Window(int rows, int cols, vector<vector<int>> mat){
    int maxSum = INT_MIN;
    for(int er = 1; er < rows; er++){
        int initialRowSum = sumOfWindow(er-1, er, 0, 1, mat);
        maxSum = max(maxSum, initialRowSum);
        for(int ec = 2; ec < cols; ec++){
            initialRowSum = initialRowSum - mat[er][ec-2] - mat[er-1][ec-2] + mat[er][ec] + mat[er-1][ec];
            maxSum = max(maxSum, initialRowSum);
        }
    }
    return maxSum;
}

void printMatrix(int rows, int cols, vector<vector<int>> mat){
    for(auto row : mat){
        for(auto elem : row)
            cout << elem << "   ";
        cout << endl;
    } 

    cout << "\n\n";
}


int main(){
    string r, c;
    cin >> r >> c;
    int rows = stoi(r);
    int cols = stoi(c);

    cin.ignore();

    string s;
    getline(cin, s);

    vector<vector<int>> mat = constructMatrixFromString(rows, cols, s);

    int result = maxSumUsing2x2Window(rows, cols, mat);

    printMatrix(rows, cols, mat);

    cout << result;

    return 0;
}