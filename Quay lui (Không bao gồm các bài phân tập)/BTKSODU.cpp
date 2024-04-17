#include <iostream>

using namespace std;

#define N 10

bool Find_Unassigned_Location(int gird[N][N], int &row, int &colunm);
bool is_Safe(int gird[N][N], int row, int colunm, int num);

bool slove_Sudoku(int gird[N][N]) {
    int row, colunm;
    if (!Find_Unassigned_Location(gird, row, colunm)) return true;

    for(int num=1; num<=9; ++num)
        if (is_Safe(gird, row, colunm, num)) {
            gird[row][colunm] = num;
            if (slove_Sudoku(gird)) return true;
            gird[row][colunm] = 0;
        }
    return false;
}

bool Find_Unassigned_Location(int gird[N][N], int &row, int &colunm) {
    for(row = 1; row <= 9; ++row)
    for(colunm = 1; colunm <= 9; ++colunm)
        if (gird[row][colunm] == 0) return true;
    return false;
}

bool used_in_row(int gird[N][N], int row, int num) {
    for(int colunm = 1; colunm <= 9; ++colunm)
        if (gird[row][colunm] == num) return true;
    return false;
}

bool used_in_colunm(int gird[N][N], int colunm, int num) {
    for(int row = 1; row <= 9; ++row)
        if (gird[row][colunm] == num) return true;
    return false;
}

bool used_in_box(int gird[N][N], int box_start_row, int box_start_colunm, int num) {
    for(int i=1; i<=3; ++i)
    for(int j=1; j<=3; ++j)
        if (gird[i + box_start_row][j + box_start_colunm] == num) return true;
    return false;
}

bool is_Safe(int gird[N][N], int row, int colunm, int num) {
    return  !used_in_colunm(gird, colunm, num)
            && !used_in_box(gird, (row - 1) - (row - 1) % 3, (colunm - 1) - (colunm - 1) % 3, num)
            && !used_in_row(gird, row, num)
            && gird[row][colunm] == 0;
}

int a[10][10];

int main() {
    for(int i=1; i<=9; ++i)
    for(int j=1; j<=9; ++j) scanf("%d", &a[i][j]);
    slove_Sudoku(a);
    for(int i=1; i<=9; ++i) {
        for(int j=1; j<9; ++j) cout << a[i][j] << " ";
        cout << a[i][9];
        if (i < 9) cout << "\n";
    }
    return 0;
}
    
