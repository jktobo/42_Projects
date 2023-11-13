#include "Functions.hpp"

Base * generate() {
    srand(static_cast<unsigned>(time(nullptr)));
    int r = rand() % 3;
    if (r == 0)
        return (new A);
    else if (r == 1)
        return (new B);
    else if (r == 2)
        return (new C);
    else
        return (nullptr);
}

void identify(Base* p) {
    std::cout << "Pointer" << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "It's A class!" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "It's B class!" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "It's C class!" << std::endl;
    else
        std::cout << "Uncorrect" << std::endl;
}

// void identify(Base& p) {
//     std::cout << "Ref" << std::endl;
//     identify(&p);
// }

void identify(Base& p) {
    std::cout << "Ref" << std::endl;
    try {
        A a = dynamic_cast<A&>(p);
        std::cout << "It's A class!" << std::endl;
    } catch (std::exception & ex) {

    }
    try {
        B b = dynamic_cast<B&>(p);
        std::cout << "It's B class!" << std::endl;
    } catch (std::exception & ex) {

    }
    try {
        C c = dynamic_cast<C&>(p);
        std::cout << "It's C class!" << std::endl;
    } catch (std::exception & ex) {

    }
}