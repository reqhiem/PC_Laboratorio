#include <iostream>
using namespace std;

const int MAXL = 1e5;

int N, x;

//Class Deque
class Deque{
public:
    int *arr;
    int _size;
    int _left, _right;
public:
    Deque(){
        arr = new int[MAXL];
        _size = 0;
        _left = _right = MAXL/2;
    }
    ~Deque(){
        delete[] arr;
    }

    void push_front(int x){
        if (_size == 0){
            _right++;
        }
        arr[_left] = x;
        _left--;
        _size++;
    }
    void pop_front(){
        _left++;
        _size--;
    }

    void push_back(int x){
        if (_size == 0){
            _left--;
        }
        arr[_right] = x;
        _right++;
        _size++;
    }
    void pop_back(){
        _right--;
        _size--;
    }

    int front(){
        return arr[_left+1];
    }
    int back(){
        return arr[_right-1];
    }
    int size(){
        return _size;
    }
    int& operator[](int i){
        return arr[_left + 1 + i];
    }
};

class Teque{
public:
    Deque *left, *right;
    int _size;
public:
    Teque(){
        left = new Deque();
        right = new Deque();
    }
    ~Teque(){
        delete left;
        delete right;
    }
    void push_front(int x){
        left->push_front(x);
        if(left->size() > (right->size() + 1)){
            right->push_front(left->back());
            left->pop_back();
        }
    }
    void push_back(int x){
        right->push_back(x);
        if(right->size() > left->size()){
            left->push_back(right->front());
            right->pop_front();
        }
    }
    void push_middle(int x){
        right->push_front(x);
        if(right->size() > left->size()){
            left->push_back(right->front());
            right->pop_front();
        }
    }
    int& operator[](int i){
        if(i < left->size()){
            return (*left)[i];
        }else{
            return (*right)[i - left->size()];
        }
    }

    int size(){
        return left->size() + right->size();
    }
};

int main(int argc, char const *argv[]){
    cin >> N;
    string operation;
    Teque teque;

    while(N--){
        cin >> operation >> x;
        if (operation == "push_back"){
            teque.push_back(x);
        }else if (operation == "push_front"){
            teque.push_front(x);
        }else if (operation == "push_middle"){
            teque.push_middle(x);
        }else if (operation == "get"){
            cout << teque[x] << endl;
        }
    }

    return 0;
}