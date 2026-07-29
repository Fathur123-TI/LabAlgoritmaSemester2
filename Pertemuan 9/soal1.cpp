#include <iostream>
using namespace std;

#define MAX 5

int stack[MAX];
int top = -1;

void push(int data) {
    if (top == MAX - 1) {
        cout << "Stack Penuh!" << endl;
    } else {
        top++;
        stack[top] = data;
    }
}

void tampil() {
    if (top == -1) {
        cout << "Stack Kosong!" << endl;
        return;
    }
 
    cout << "Data Stack" << endl;
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {

    
    push(621);
    push(999);
    push(201);
    push(94);
    push(124);

    tampil();

    return 0;
}
