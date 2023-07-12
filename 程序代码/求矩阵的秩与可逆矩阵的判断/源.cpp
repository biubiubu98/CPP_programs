#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double EPS = 1e-10;

int matrixRank(vector<vector<double>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int rank = 0;
    vector<bool> row_selected(n, false);

    for (int i = 0; i < m; ++i) {
        int r = -1;
        for (int j = 0; j < n; ++j) {
            if (!row_selected[j] && abs(matrix[j][i]) > EPS) {
                r = j;
                break;
            }
        }

        if (r != -1) {
            ++rank;
            row_selected[r] = true;
            for (int p = i + 1; p < m; ++p) {
                matrix[r][p] /= matrix[r][i];
            }
            for (int k = 0; k < n; ++k) {
                if (k != r && abs(matrix[k][i]) > EPS) {
                    for (int p = i + 1; p < m; ++p) {
                        matrix[k][p] -= matrix[k][i] * matrix[r][p];
                    }
                }
            }
        }
    }

    return rank;
}

bool isMatrixInvertible(vector<vector<double>> matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    return n == m && matrixRank(matrix) == n;
}

int main() {
    vector<vector<double>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rank = matrixRank(matrix);
    bool invertible = isMatrixInvertible(matrix);

    cout << "Matrix rank: " << rank << endl;
    cout << "Matrix is " << (invertible ? "invertible" : "not invertible") << endl;
    system("pause");
    return 0;
}