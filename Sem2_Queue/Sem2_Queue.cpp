#include<iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

struct Queue {
    int size = 0;
    Node* head;
    Node* tail;
};

void init_que(Queue& q, const char a) {
    Node* new_node = new Node;
    new_node->data = a;
    q.head = new_node;
    q.tail = new_node;
    q.size = 1;
}

void push(Queue& q, char a) {
    Node* new_node = new Node;
    q.size++;
    new_node->data = a;
    new_node->next = nullptr;
    q.tail->next = new_node;
    q.tail = new_node;
}

void print(Queue& q) {
    Node* tmp = q.head;
    cout << "начало-> ";
    while (tmp != nullptr) {
        cout << tmp->data << "->";
        tmp = tmp->next;
    }
    cout << "конец";
}

void insertAfter(Queue& q, char key, char newElement, int k) {
    Node* current = q.head;
    while (current != nullptr) {
        if (current->data == key) {
            for (int i = 0; i < k; ++i) {
                if (current->next == nullptr) {
                    push(q, newElement);
                    break;
                }
                Node* new_node = new Node;
                new_node->data = newElement;
                new_node->next = current->next;
                current->next = new_node;
                current = new_node;
            }
            return;
        }
        current = current->next;
    }
    cout << "Ключ '" << key << "' не найден в очереди." << endl;
}

void new_que(Queue& q, int n) {
    char a;
    cout << "Введите первый элемент в очереди: ";
    cin >> a;
    init_que(q, a);
    for (int i = 1; i < n; i++) {
        cout << "Введите элемент в очереди: ";
        cin >> a;
        push(q, a);
    }
}

int main() {
    setlocale(LC_ALL, "Rus");
    Queue q;
    int n;
    cout << "Введите размер очереди: ";
    cin >> n;
    new_que(q, n);
    cout << "Очередь выглядит так: ";
    print(q);

    char key, newElement;
    int k;
    cout << endl << "Введите элемент, после которого нужно добавить: ";
    cin >> key;
    cout << "Введите новый элемент: ";
    cin >> newElement;
    cout << "Введите количество элементов, которые нужно добавить: ";
    cin >> k;

    insertAfter(q, key, newElement, k);

    cout << endl << "Полученная очередь: ";
    print(q);
    return 0;
}