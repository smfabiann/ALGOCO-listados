#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {
    map<char, vector<int>> mapita, input;


    for (int i = 0; i < 4; i++) {
        string temp;
        getline(cin, temp);
        int j = 0;
        for (char c : temp) {
            input[c] = {i, j++};
        };
    }
    string abc = "ABCDEFGHIJKLMNO.";

    for(int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            char c = abc[i * 4 + j];
            mapita[c] = {i, j};
        }
    }

    int resultado = 0;
    

    cout << endl;
    return 0;
}