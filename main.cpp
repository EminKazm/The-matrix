#include <iostream>
#include <vector>
using namespace std;


 void setZeroMatrix(vector<vector<int>> &matrix, int m, int n) {
    vector<vector<int>> ans;

    // initializing all elements of answer array as 1
    for (int i = 0; i < m; i++) {
        vector<int> curr;
        for (int j = 0; j < n; j++) {
            curr.push_back(1);
        }
        ans.push_back(curr);
    }

    // Traverse row major
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < n; k++) {
                    ans[i][k] = 0;
                }
                break;
            }
        }
    }

    // Traverse column major
    for (int j = 0; j < n; j++) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] == 0) {
                for (int k = 0; k < m; k++) {
                    ans[k][j] = 0;
                }
            }
        }
    }

    // Update the elements in matrix array
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
}
int main() {
    //matrix example
    vector<vector<int>> matrix{{5, 3, 4, 0}, {6, 7, 4, 8}, {3, 2, 0, 9}};
    int m = matrix.size();

    int n = matrix[0].size();
    cout<<"first matrix:"<<endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"last version of the matrix:"<<endl;
    setZeroMatrix(matrix, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

