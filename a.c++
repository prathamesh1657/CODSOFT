#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    if (operation == '+') {
        result = num1 + num2;
        cout << num1 << " + " << num2 << " = " << result << endl;
    } else if (operation == '-') {
        result = num1 - num2;
        cout << num1 << " - " << num2 << " = " << result << endl;
    } else if (operation == '*') {
        result = num1 * num2;
        cout << num1 << " * " << num2 << " = " << result << endl;
    } else if (operation == '/') {
        if (num2 != 0) {
            result = num1 / num2;
            cout << num1 << " / " << num2 << " = " << result << endl;
        } else {
            cout << "Error: Division by zero is not allowed." << endl;
        }
    } else {
        cout << "Invalid operation." << endl;
    }

    return 0;
}