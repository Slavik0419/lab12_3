#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;
struct Elem {
    Elem* next,
        * prev;
    Info info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL) {
        last->next = tmp;
    }
    tmp->prev = last;
    last = tmp;
    if (first == NULL) {
        first = tmp;
    }
}

Info dequeue(Elem*& first, Elem*& last) {
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL) {
        last = NULL;
    }
    else {
        first->prev = NULL;
    }
    return value;
}

void Print(Elem* L) {
    cout << "Spisok: ";
    while (L != nullptr) {
        cout << L->info << "; ";
        L = L->next;
    }
}

void insert(Elem* L, Info v1, Info v2) {
    while (L != NULL && L->next != NULL) {
        if (L->next->info == v1) {
            Elem* tmp = new Elem;
            tmp->info = v2;
            tmp->next = L->next;
            tmp->prev = L;
            tmp->next->prev = tmp;
            L->next = tmp;
            L = L->next;
        }
        L = L->next;
    }
}
int main() {

    srand((unsigned)time(nullptr));
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);

    Elem* first = NULL,
        * last = NULL;

    for (int i = 0; i < 10; i++) {
        int random = (rand() % 13) - 6;
        enqueue(first, last, random);
    }

    Print(first);
    cout << endl;
    Info v1, v2;
    cout << "¬вед≥ть значенн€, перед €ким ви хочете поставити V2: "; cin >> v1;
    cout << "¬вед≥ть значенн€ V2: "; cin >> v2;
    insert(first, v1, v2);
    Print(first);
    dequeue(first, last);

    return 0;
}
