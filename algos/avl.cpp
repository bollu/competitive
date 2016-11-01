#include <iostream>

template<typename T>
class avl {
    T val;
    avl<T> *left, *right;
    public:

    avl(T val) : val(val) {
        left = right = nullptr;
    }
};


int main() {
    return 0;
}
