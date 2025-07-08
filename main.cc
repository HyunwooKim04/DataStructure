// main.cpp
#include "stack.h"
#include "circular_queue.h"

int main() {
    /* ---stack--- */
    
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

    /* ---circular queue--- */

    try {
        CircularQueue<int> q(5);

        q.Push(10);
        q.Push(20);
        q.Push(30);

        std::cout << "큐 내용: " << q << "\n";
        std::cout << "Front: " << q.Front() << "\n";

        q.Pop();
        std::cout << "Pop 후 큐 내용: " << q << "\n";

        q.Push(40);
        q.Push(50);
        q.Push(60);  // 이 시점에서 꽉 참

        std::cout << "최종 큐: " << q << "\n";
    } catch (const char* e) {
        std::cerr << "예외 발생: " << e << "\n";
    }
}
