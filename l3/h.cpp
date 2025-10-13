#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
long long memoria[101][3][3][2];

bool es_vocal(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

long long aaaaaa(int idx, int vocales, int consonantes, bool tiene_L) {
    if (vocales >= 3 || consonantes >= 3) {
        return 0;
    }
    if (idx == s.length()) {
        return tiene_L ? 1 : 0;
    }

    if (memoria[idx][vocales][consonantes][tiene_L] != -1) {
        return memoria[idx][vocales][consonantes][tiene_L];
    }

    long long combinaciones = 0;
    char char_actual = s[idx];

    if (char_actual == '_') {

        combinaciones += 5 * aaaaaa(idx + 1, vocales + 1, 0, tiene_L);

        combinaciones += 1 * aaaaaa(idx + 1, 0, consonantes + 1, true);

        combinaciones += 20 * aaaaaa(idx + 1, 0, consonantes + 1, tiene_L);

    } else {
        if (es_vocal(char_actual)) {
            combinaciones += aaaaaa(idx + 1, vocales + 1, 0, tiene_L);
        } else {
            bool temp = tiene_L || (char_actual == 'L');
            combinaciones += aaaaaa(idx + 1, 0, consonantes + 1, temp);
        }
    }

    return memoria[idx][vocales][consonantes][tiene_L] = combinaciones;
}

int main() {
    cin >> s;

    for (int i = 0; i < 101; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                for (int l = 0; l < 2; ++l)
                    memoria[i][j][k][l] = -1;

    cout << aaaaaa(0, 0, 0, false) << endl;

    return 0;
}