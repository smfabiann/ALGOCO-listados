#include <iostream>
#include <vector>
using namespace std;


vector<int> gen_deco() {
    vector<int> v(256);
    for (int byte_original = 0; byte_original < 256; ++byte_original) {
        int byte_desordenado = (byte_original ^ (byte_original << 1)) & 0xFF;

        v[byte_desordenado] = byte_original;
    }
    return v;
}

int main() {
    vector<int> decodificador = gen_deco();

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int scrambled_byte;
        cin >> scrambled_byte;

        int byte_original = decodificador[scrambled_byte];

        cout << byte_original << (i == n - 1 ? "" : " ");
    }

    cout << endl;

    return 0;
}

