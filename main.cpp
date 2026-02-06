#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> history;

void showMenu() {
    cout << "===== CALCULATOR PRO =====" << endl;
    cout << "1. Hesabla" << endl;
    cout << "2. Tarixçəni göstər" << endl;
    cout << "3. Təmizlə" << endl;
    cout << "0. Çıxış" << endl;
    cout << "Seçim: ";
}

void addToHistory(int a, char op, int b, int result) {
    history.push_back(to_string(a) + " " + op + " " + to_string(b) + " = " + to_string(result));
}

void showHistory() {
    if(history.empty()) {
        cout << "Tarixçə boşdur." << endl;
        return;
    }
    for(auto &line : history) {
        cout << line << endl;
    }
}

int calculate() {
    int x, y;
    char op;
    cout << "Əməliyyat seç (+ - * /): ";
    cin >> op;
    cout << "Birinci ədəd: ";
    cin >> x;
    cout << "İkinci ədəd: ";
    cin >> y;

    if(op == '/' && y == 0) {
        cout << "0-a bölmək olmaz!" << endl;
        return 0;
    }

    int result;
    switch(op) {
        case '+': result = x + y; break;
        case '-': result = x - y; break;
        case '*': result = x * y; break;
        case '/': result = x / y; break;
        default:
            cout << "Yanlış əməliyyat!" << endl;
            return 0;
    }

    addToHistory(x, op, y, result);
    cout << "Nəticə: " << result << endl;
    return result;
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;
        switch(choice) {
            case 1: calculate(); break;
            case 2: showHistory(); break;
            case 3: history.clear(); 
                    cout << "Tarixçə təmizləndi." << endl;
                    break;
            case 0: cout << "Çıxılır..." << endl; break;
            default: cout << "Yanlış seçim!" << endl;
        }
    } while(choice != 0);

    return 0;
}
