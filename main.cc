// main.cpp
#include "stack.h"

int main() {
    try {
        Stack<int> s(5);

        s.Push(10);
        s.Push(20);
        s.Push(30);

        std::cout << "스택 내용: " << s << "\n";
        std::cout << "Top: " << s.Top() << "\n";

        s.Pop();
        std::cout << "Pop 후 스택 내용: " << s << "\n";
    }
    catch (const char* e) {
        std::cerr << "예외 발생: " << e << "\n";
    }

    return 0;
}
