#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    freopen("ids.txt", "r", stdin);

    vector<string> ids;
    string id;
    while (cin >> id) {
        ids.push_back(id);
    }

    string alp = "bcdfghjklmnpqrstvwxyz";
    int temp1 = time(nullptr) % 21;
    int temp2 = (time(nullptr) + 3) % 21;
    int temp3 = (time(nullptr) + 314) % 21;
    int temp4 = (time(nullptr) + 31415) % 21;
    int temp5 = (time(nullptr) + 3141592) % 21;
    string newID;
    int ctr1 = 2;
    int ctr2 = 27;
    int ctr3 = 271;
    int ctr4 = 2718;
    int ctr5 = 27182;

    string cmd = argv[1];
    if (cmd == "note") {
        newID += alp[temp1];
        newID += alp[temp2];
        newID += alp[temp3];

        while (find(ids.begin(), ids.end(), newID) != ids.end()) {
            newID[0] = alp[(temp1 + ctr1) % 21];
            newID[1] = alp[(temp2 + ctr2) % 21];
            newID[2] = alp[(temp3 + ctr3) % 21];
            ctr1++;
            ctr2++;
            ctr3 += 2;
        }
    } else if (cmd == "section") {
        newID += alp[temp1];
        newID += alp[temp2];
        newID += alp[temp3];
        newID += alp[temp4];
        newID += alp[temp5];

        while (find(ids.begin(), ids.end(), newID) != ids.end()) {
            newID[0] = alp[(temp1 + ctr1) % 21];
            newID[1] = alp[(temp2 + ctr2) % 21];
            newID[2] = alp[(temp3 + ctr3) % 21];
            newID[3] = alp[(temp4 + ctr4) % 21];
            newID[4] = alp[(temp5 + ctr5) % 21];
            ctr1++;
            ctr2++;
            ctr3 += 2;
            ctr4 += 3;
            ctr5 += 5;
        }
    } else {
        return 1;
    }
    ids.push_back(newID);

    cout << newID << "\n";
    freopen("ids.txt", "w", stdout);
    for (int i = 0; i < ids.size(); i++) {
        cout << ids[i] << "\n";
    }

    return 0;
}


