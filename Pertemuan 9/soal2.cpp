#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class DoublyLinkedList {
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert(int nilai) {
        Node *baru = new Node;
        baru->data = nilai;
        baru->prev = NULL;
        baru->next = NULL;

        if (head == NULL) {
            head = tail = baru;
        } else {
            baru->prev = tail;
            tail->next = baru;
            tail = baru;
        }
    }

    void print() {
        Node *temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insert(24);
    list.insert(10);
    list.insert(33);
    list.insert(33);

    cout << "Isi Doubly Linked List : ";
    list.print();

    return 0;
}
