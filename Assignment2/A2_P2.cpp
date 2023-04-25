//
//  main.cpp
//  p3
//
//  Created by Fatma Ahmed on 14/05/2022.
#include <iostream>

using namespace std;

template<class t>
class queue {
    struct node {
        t number;
        node *next;
    };
    node *head = NULL;

    int size = 0;

public:
    int SIZE() {
        return size;
    }

    bool isempty() {
        return head == NULL;
    }

    void pushback(t value) {
        size++;
        node *newnode;
        node *last;
        newnode = new node;
        newnode->number = value;

        if (head == NULL) {
            head = newnode;
            newnode->next = NULL;
        } else {
            last = head;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = newnode;
            newnode->next = NULL;

        }
    }

    void pop() {
        if (head == NULL) {

//            cout << "linked list is empty";
        } else {

            size--;
            node *first;
            first = head;
            head = first->next;
            delete (first);


        }
    }

    t front() {
        if (isempty()) {
//            throw "it is empty \n";

        } else {
            return head->number;
        }
    }

    void display() {
        node *currentnode;
        if (head == NULL) {
            cout << "linked list is empty";

        } else {
            currentnode = head;
            while (currentnode != NULL) {
                cout << currentnode->number << endl;
                currentnode = currentnode->next;
            }
        }
    }


};

struct Pair {
    int id, tik;

    Pair() {}

    Pair(int i, int t) : id(i), tik(t) {}
};

void Time(int tickets[], int k, int s) {
    int time = 0;
    queue<Pair> obj;
    for (int i = 0; i < s; i++) {
        obj.pushback({i, tickets[i]}); //[0,1,2]
    }
//    for (int i = 0; i < obj.SIZE(); i++) {
//        cout << obj.front().tik;
//        obj.pushback(obj.front());
//        obj.pop();
//    }
//    cout<<'\n';
    Pair temp = {-1, -1};
    while (!(temp.id == k && temp.tik <= 0)) {
        temp = obj.front();
        obj.pop();
        temp.tik--;

        if (temp.tik > 0)
            obj.pushback(temp);
        time++;
//        for (int i = 0; i < obj.SIZE(); i++) {
//            cout << obj.front().tik;
//            obj.pushback(obj.front());
//            obj.pop();
//        }
//        cout<<'\n';
    }
    cout << "time is: " << time << endl;
}

void Example1() {
    int arr[] = {2, 3, 2};
    int size;
    size = sizeof(arr) / sizeof(arr[0]);;
    int k = 2;
    Time(arr, k, size);
}

void Example2() {
    int arr[] = {5, 1, 1, 1};
    int size;
    size = sizeof(arr) / sizeof(arr[0]);;
    int k = 0;
    Time(arr, k, size);
}

int main() {
    cout << "--------test one -------\n";
    Example1();
    cout << "--------test two -------\n";
    Example2();
    return 0;
}
