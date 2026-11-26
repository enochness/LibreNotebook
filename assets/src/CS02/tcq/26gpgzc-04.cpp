/**
 * Enoch Yu
 * 2020 USACO Third Bronze
 * Problem 1. Triangles
 *
 * Pick head node
 * Pick next node in the same column
 * Pick another node in the same row as the second node
 * iterate
 */


#include <array>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N;
    cin >> N;
    vector<array<int, 2>> coord(N);
    for (int i = 0; i < N; i++) {
        cin >> coord[i][0] >> coord[i][1];
    }

    int h, w;
    int MAX = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                for (int k = 0; k < N; k++) {
                    if (i != k && j != k) {
                        if (coord[i][0] == coord[j][0] &&
                            coord[i][1] == coord[k][1]) {
                            w = abs(coord[i][0] - coord[k][0]);
                            h = abs(coord[i][1] - coord[j][1]);
                            MAX = max(MAX, h * w);
                        } else if (coord[i][0] == coord[j][0] &&
                                   coord[j][1] == coord[k][1]) {
                            w = abs(coord[j][0] - coord[k][0]);
                            h = abs(coord[i][1] - coord[j][1]);
                            MAX = max(MAX, h * w);
                        } else if (coord[i][0] == coord[k][0] &&
                                   coord[i][1] == coord[j][1]) {
                            w = abs(coord[i][0] - coord[j][0]);
                            h = abs(coord[i][1] - coord[k][1]);
                            MAX = max(MAX, h * w);
                        } else if (coord[i][0] == coord[k][0] &&
                                   coord[k][1] == coord[j][1]) {
                            w = abs(coord[k][0] - coord[j][0]);
                            h = abs(coord[i][1] - coord[k][1]);
                            MAX = max(MAX, h * w);
                        } else if (coord[j][0] == coord[k][0] &&
                                   coord[j][1] == coord[i][1]) {
                            w = abs(coord[j][0] - coord[i][0]);
                            h = abs(coord[j][1] - coord[k][1]);
                            MAX = max(MAX, h * w);
                        } else if (coord[j][0] == coord[k][0] &&
                                   coord[k][1] == coord[i][1]) {
                            w = abs(coord[k][0] - coord[i][0]);
                            h = abs(coord[j][1] - coord[k][1]);
                            MAX = max(MAX, h * w);
                        }
                    }
                }
            }
        }
    }
    cout << MAX;

    return 0;
}


