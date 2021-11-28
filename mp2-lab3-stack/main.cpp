#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

#include "TCalc.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    setlocale(LC_NUMERIC, "eng");

    TCalc calculator;
    string line;

    while (true) {
        cout << "Enter your expression: ";
        getline(cin, line);

        calculator.set_expr(line);
        cout << "\n########################\n";
        cout << "Expression: " << calculator.get_expr() << "\n\n";

        if (calculator.check_expr()) {
            cout << "Braces are correct.\n\n";
        }
        else {
            cout << "Braces are incorrect.\n\n";
            continue;
        }

        cout << "Postfix: ";
        calculator.to_pstfix();
        cout << calculator.get_pstfix() << "\n\n";

        try {
            cout << "Result (calc_pstfix): " << calculator.calc_pstfix() << "\n";
            cout << "Result (calc): " << calculator.calc() << "\n";
        }
        catch (...) {
            cout << "Exception\n";
        }
        cout << "########################\n\n";
    }

    return 0;
}