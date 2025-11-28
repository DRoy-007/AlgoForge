#include <bits/stdc++.h>
#include <termios.h>
using namespace std;

char _getch(){
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    char ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
// the above _getch() is made with the help of ChatGPT to replicate _getch() in conio.h library of windows

bool luhnValidator(const string cardNumberInStr){
    int sum = 0;
    bool doublingDigit = false;

    for (int i = cardNumberInStr.size() - 1; i >= 0; --i){
        int digit = cardNumberInStr[i] - '0';

        if (doublingDigit){
            digit *= 2;
            if (digit > 9) digit -= 9;
        }

        sum += digit;
        doublingDigit = !doublingDigit;
    }

    return (sum % 10 == 0);
}

int main(){
    const int LEN = 16;
    string cardNumberInStr;
    
    cout << "Enter the card number: ";

    while (cardNumberInStr.length() < LEN){
        char ch = _getch();

        // the following block handles backspace
        if (ch == 127 || ch == '\b'){
            if (!cardNumberInStr.empty()) {
                cardNumberInStr.pop_back();
                cout << "\b \b";
                cout.flush();
            }
            continue;
        }

        if (isdigit(ch)){
            cardNumberInStr += ch;
            cout << ch;
            cout.flush();
        }
    }
    cout << endl << endl;

    if (luhnValidator(cardNumberInStr)) cout << "Valid" << endl;
    else cout << "Invalid" << endl;
    
    return 0;
}