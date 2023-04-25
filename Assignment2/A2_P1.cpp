#include <iostream>

using namespace std;

template<class T>
class Stack {
private:
    // initialize the Node class
    struct Node {
        T data;
        Node *prev;

        explicit Node(T value) : data(value) {
            prev = nullptr;
        }

        Node() {
            prev = nullptr;
        }
    };

    Node *topPtr;
    int count;
    //function if you want to start any Stack
    void init() {
        topPtr = new Node;
        count = 0;
    }

public:
    Stack() {
        init();
    }
    //copy constructor lValue
    Stack(const Stack &other) {
        init();
        topPtr->data = other.topPtr->data;
        ++count;
        Node *newPtr = topPtr;
        for (Node *trvPtr = other.topPtr->prev;
             trvPtr != nullptr; trvPtr = trvPtr->prev) {
            T value = trvPtr->data;
            Node *newNode = new Node(value);
            newPtr->prev = newNode;
            ++count;
        }
    }

    //copy constructor rValue
    Stack(Stack &&rhs)
            : count{rhs.count}, topPtr{rhs.topPtr} {
        rhs.count = 0;
        rhs.topPtr = nullptr;
    }

    //Assigment operator lValue
    Stack &operator=(const Stack &other) {
        Stack copy = other;
        std::swap(*this, copy);
        return *this;
    }

    //Assigment operator rValue
    Stack &operator=(Stack &&other) {
        std::swap(count, other.count);
        std::swap(topPtr, other.topPtr);
        return *this;
    }

    int size() const {
        return count;
    }

    void push(T value) {
        Node *newNode = new Node(value);
        if (count == 0) {
            topPtr = newNode;
        } else {
            newNode->prev = topPtr;
            topPtr = newNode;
        }
        ++count;
    }

    T top() {
        if (isEmpty())
            throw ("StackException: stack empty on getTop");
        return topPtr->data;
    }

    bool isEmpty() const {
        return (count == 0);
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "List is empty.\n";
            return;
        }
        Node *d = topPtr;
        topPtr = topPtr->prev;
        delete d;
        --count;
    }

    void clear() {
        if (isEmpty()) {
            return;
        }
        while (!isEmpty())
            pop();
    }

    ~Stack() {
        clear();
    }
};

string unixStyleFileSystem(string A)
{
    // stack to store the file's names reversed.
    Stack<string> st;

    string dir;
    for (int i = 0; i < A.length(); i++) {

        dir.clear();

        // skip all the multiple '/' Eg. "/////"
        while (A[i] == '/')
            i++;

        // stores directory's name("a", "b" etc.)
        // or commands("."/"..") into dir
        while (i < A.length() && A[i] != '/') {
            dir.push_back(A[i]);
            i++;
        }

        // if dir has ".." just pop the topmost
        if (dir.compare("..") == 0) {
            if (!st.isEmpty())
                st.pop();
        }

        // if dir has "." then simply continue
        else if (dir.compare(".") == 0)
            continue;

        // push the last element if there is.
        else if (dir.length() != 0)
            st.push(dir);
    }

    //reverse to the original order.
    Stack<string> st1;
    while (!st.isEmpty()) {
        st1.push(st.top());
        st.pop();
    }

    // contains resultant simplifies string.
    string res;
    res.append("/");


    // the st1 will contain the actual res.
    while (!st1.isEmpty()) {
        string temp = st1.top();

        // if it's the last element no need to append "/".
        if (st1.size() != 1)
            res.append(temp + "/");
        else
            res.append(temp);

        st1.pop();
    }

    return res;
}

void Example1(){
    string str="/a/./b/../../c/";
    cout<<str<<'\n';
    string res = unixStyleFileSystem(str);
    cout << res<<'\n';
}

void Example2(){
    string str="/home/";
    cout<<str<<'\n';
    string res = unixStyleFileSystem(str);
    cout << res<<'\n';
}

void Example3(){
    string str="/../";
    cout<<str<<'\n';
    string res = unixStyleFileSystem(str);
    cout << res<<'\n';
}

void Example4(){
    string str="/home//foo/";
    cout<<str<<'\n';
    string res = unixStyleFileSystem(str);
    cout << res<<'\n';
}

int main() {
    cout<<"---------Example 1:--------------\n";
    Example1();
    cout<<"---------Example 2:--------------\n";
    Example2();
    cout<<"---------Example 3:--------------\n";
    Example3();
    cout<<"---------Example 4:--------------\n";
    Example4();
    return 0;
}



