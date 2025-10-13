#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string wff;
    
    while (cin >> wff && wff != "0") {
        bool tautologia = true;
        int valores[5];

        for (int i = 0; i < 32; ++i) {
            valores[0] = (i >> 4) & 1;
            valores[1] = (i >> 3) & 1;
            valores[2] = (i >> 2) & 1;
            valores[3] = (i >> 1) & 1;
            valores[4] = (i >> 0) & 1;

            stack<int> pila;

            for (int j = wff.length() - 1; j >= 0; --j) {
                char simb = wff[j];

                if (simb >= 'p' && simb <= 't') {
                    pila.push(valores[simb - 'p']); 
                }
                else if (simb == 'N') {
                    int op = pila.top();
                    pila.pop();
                    pila.push(!op);
                }
                else {
                    int op1 = pila.top(); pila.pop();
                    int op2 = pila.top(); pila.pop();

                    if (simb == 'K') pila.push(op1 && op2);
                    if (simb == 'A') pila.push(op1 || op2);
                    if (simb == 'C') pila.push(!op1 || op2);
                    if (simb == 'E') pila.push(op1 == op2);
                }
            }

            if (pila.top() == 0) {
                tautologia = false;
                break;
            }
        }

        if (tautologia) {
            cout << "tautology" << endl;
        } else {
            cout << "not" << endl;
        }
    }

    return 0;
}