#include <bits/stdc++.h>
using namespace std;
#define MAX 100

struct Stack {
    int top;
    int a[MAX];
};

int pow_int(int x, int y) {
    int ans = 1;
    for (int i = 1; i <= y; i++) ans *= x;
    return ans;
}

void push(Stack *s, int val) {
    s->a[++s->top] = val;
}

int pop(Stack *s) {
    return s->a[s->top--];
}

void display(Stack *st) {
    for (int i = 0; i <= st->top; i++) cout << st->a[i] << " ";
    cout << endl;
}

int evaluation(vector<string>& tokens) {
    Stack st;
    st.top = -1;

    // Process from right to left
    for (int i = tokens.size() - 1; i >= 0; i--) {
        string token = tokens[i];
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1)) {
            push(&st, stoi(token));
        } else {
            int x = pop(&st);
            int y = pop(&st);
            if (token == "+") push(&st, x + y);
            else if (token == "-") push(&st, x - y);
            else if (token == "*") push(&st, x * y);
            else if (token == "/") push(&st, x / y);
            else if (token == "^") push(&st, pow_int(x, y));
        }
        display(&st);
    }
    return pop(&st);
}

int main() {
    string line;
    cout << "Enter prefix expression:\n";
    getline(cin, line);

    vector<string> tokens;
    string token = "";
    //jodi ','dey taile c==',' hobe

    for (char c : line) {
        if (c == ' ') {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
            }
        } else {
            token += c;
        }
    }
        tokens.push_back(token);
    int result = evaluation(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
