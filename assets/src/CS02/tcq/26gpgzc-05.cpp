/**
 * Enoch Yu
 * 2016 USACO Third Bronze
 * Problem 1. Milk Pails
 *
 * numY = 0, 1, ..., X/Y
 */


#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int X, Y, M;
    cin >> X >> Y >> M;
    
    int MAX = 0;
    int temp;
    for (int i = 0; i <= M/Y; i++) {
        temp = i*Y + X*floor((M - i*Y)/X);
        MAX = max(MAX, temp);
    }
    cout << MAX;

    return 0;
}


