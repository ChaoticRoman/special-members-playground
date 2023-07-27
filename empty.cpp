#include <memory>
#include <iostream>

struct A{
    A() {
        std::cout << "Default constructed.\n";
    }

    A(const A&) {
        std::cout << "Copy constructed.\n";
    }

    A& operator=(const A& other) {
        std::cout << "Copy assigned.\n";
        return *this;
    }

    A(A&&) {
        std::cout << "Move constructed.\n";
    }

    A& operator=(A&& other) {
        std::cout << "Move assigned.\n";
        return *this;
    }


    ~A() {
        std::cout << "Destructed.\n";
    }
};

int main() {
    A a;
    //auto p = std::unique_ptr<A>(&a);
    auto p = std::make_unique<A>(a);
    return 0;
}
