

#include <stdio.h>
#include <vector>
using std::vector;
void print_matrix(vector<vector<int> >& matrix, vector<int>& res) {
    if (matrix.size() == 0 || matrix[0].size() == 0)  return;
    int left = 0;
    int top = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    while (left <= right && top <= bottom) {
        for (int i = left; i <= right; ++i) {
            res.push_back(matrix[top][i]);
        }
        for (int i = top + 1; i <= bottom; ++i) {
            res.push_back(matrix[i][right]);
        }
        
        if (top != bottom) {
            for (int i = right - 1; i >= left; --i) {
                res.push_back(matrix[bottom][i]);
            }
        }
        if (left != right) {
            for (int i = bottom - 1; i > top; --i) {
                res.push_back(matrix[i][left]);
            }
        }
        left++;
        top++;
        right--;
        bottom--;
    }

    return;
}

int main(const int argc, const char *argv[])
{
    vector<vector<int> > matrix;
    matrix.push_back({1,2,3,4});
    matrix.push_back({5,6,7,8});
    matrix.push_back({9,10,11,12});
    matrix.push_back({13,14,15,16});

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    vector<int> res;
    print_matrix(matrix, res);
    for (size_t i = 0; i < res.size(); ++i) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}
