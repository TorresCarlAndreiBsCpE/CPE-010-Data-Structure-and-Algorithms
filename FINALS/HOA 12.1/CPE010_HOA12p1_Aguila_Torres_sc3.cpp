#include <iostream>
#include <vector>
#include <string>

int M, N;                                   
std::vector<std::vector<int>> mat;          
std::vector<std::vector<std::vector<int>>> memo;   
int calls1 = 0, calls2 = 0;                 


//returns number of paths from (i, j) to the last cell with total cost = cost
int countPaths(int i, int j, int cost) {
    calls1++;

    if (i >= M || j >= N || cost < 0)
        return 0;

    if (i == M - 1 && j == N - 1) {
        if (cost == mat[i][j])
            return 1;
        return 0;
    }

    int down = countPaths(i + 1, j, cost - mat[i][j]);
    int right = countPaths(i, j + 1, cost - mat[i][j]);
    return down + right;
}

//this is recursion + memoization (so we don't solve the same subproblem again)
int countPathsMemo(int i, int j, int cost) {
    calls2++;

    if (i >= M || j >= N || cost < 0)
        return 0;

    if (i == M - 1 && j == N - 1) {
        if (cost == mat[i][j])
            return 1;
        return 0;
    }

    if (memo[i][j][cost] != -1)
        return memo[i][j][cost];

    int down = countPathsMemo(i + 1, j, cost - mat[i][j]);
    int right = countPathsMemo(i, j + 1, cost - mat[i][j]);
    memo[i][j][cost] = down + right;
    return memo[i][j][cost];
}

//dp[i][j][c] = number of paths from (0,0) to (i,j) with total cost c
int countPathsDP(int K) {
    std::vector<std::vector<std::vector<int>>> dp(
        M, std::vector<std::vector<int>>(N, std::vector<int>(K + 1, 0)));

    if (mat[0][0] <= K)
        dp[0][0][mat[0][0]] = 1;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int c = 0; c <= K; c++) {
                if (i == 0 && j == 0)
                    continue;                      
                if (c < mat[i][j])
                    continue;                      
                int before = c - mat[i][j];
                if (i > 0)
                    dp[i][j][c] += dp[i - 1][j][before];   
                if (j > 0)
                    dp[i][j][c] += dp[i][j - 1][before];   
            }
        }
    }
    return dp[M - 1][N - 1][K];
}

//print every path that has the given cost
void printPaths(int i, int j, int cost, std::string path) {
    if (i >= M || j >= N || cost < 0)
        return;

    path += std::to_string(mat[i][j]);

    if (i == M - 1 && j == N - 1) {
        if (cost == mat[i][j])
            std::cout << "  " << path << "\n";
        return;
    }

    path += " -> ";
    printPaths(i + 1, j, cost - mat[i][j], path);
    printPaths(i, j + 1, cost - mat[i][j], path);
}

int main() {
    int K;

    std::cout << "Enter number of rows and columns: ";
    std::cin >> M >> N;

    mat.assign(M, std::vector<int>(N));
    std::cout << "Enter the matrix:\n";
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            std::cin >> mat[i][j];

    std::cout << "Enter the target cost: ";
    std::cin >> K;

    memo.assign(M, std::vector<std::vector<int>>(N, std::vector<int>(K + 1, -1)));

    int r1 = countPaths(0, 0, K);
    int r2 = countPathsMemo(0, 0, K);
    int r3 = countPathsDP(K);

    std::cout << "\nRecursion      : " << r1 << " path(s), " << calls1 << " calls\n";
    std::cout << "Memoization    : " << r2 << " path(s), " << calls2 << " calls\n";
    std::cout << "Bottom-up DP   : " << r3 << " path(s)\n";

    std::cout << "\nPaths with cost " << K << ":\n";
    printPaths(0, 0, K, "");

    return 0;
}