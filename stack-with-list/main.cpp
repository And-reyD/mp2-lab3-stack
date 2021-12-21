#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

#include "TLStack.h"
#include "TLCalc.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "russian");
    setlocale(LC_NUMERIC, "eng");

    TLStack<int> st;
    cout << "st: " << st << "\nEmpty = " << st.empty() << "\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << i << " pushed:\n";
        st.push(i);
        cout << st << "\nEmpty = " << st.empty() << "\n\n";
    }
    cout << "\n";

    cout << "Assign st to st2 and clear st:\n";
    TLStack<int> st2 = st;
    st.clear();
    cout << "st: " << st << "\nEmpty = " << st.empty() << "\n\n";
    cout << "st2: " << st2 << "\nEmpty = " << st2.empty() << "\n\n";


    cout << "We can't pop from st again:\n";
    try {
        st.pop();
    }
    catch (...) {
        cout << "Exception\n\n";
    }

    cout << "Then we continue with st2.\n\n";

    for (int i = 1; i <= 3; i++) {
        cout << st2.pop() << " popped:\n";
        cout << st2 << "\nEmpty = " << st2.empty() << "\n\n";
    }
    cout << "\n";


    for (int i = 4; i <= 6; i++) {
        cout << i << " pushed:\n";
        st2.push(i);
        cout << st2 << "\nEmpty = " << st2.empty() << "\n\n";
    }

    cout << "Other tests:\n\n";
    TLStack<int> st3(st2);

    cout << "st2: " << st2 << "\nEmpty = " << st2.empty() << "\n\n";
    cout << "st3(st2): " << st3 << "\nEmpty = " << st3.empty() << "\n\n";

    cout << "(st3 == st2) = " << (st3 == st2) << "\n\n";

    cout << st2.pop() << " popped from st2:\n";
    cout << "st2: " << st2 << "\nEmpty = " << st2.empty() << "\n\n";

    cout << "(st3 == st2) = " << (st3 == st2) << "\n";

    TLCalc calculator;
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