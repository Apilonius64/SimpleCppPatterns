#if !defined(DEMO_H_AP64_2023)
#define DEMO_H_AP64_2023

/*                                                                         
___                
|   \ ___ _ __  ___ 
| |) / -_) '  \/ _ \
|___/\___|_|_|_\___/
                     
== Table of Contents ===================
- Anything
    - Something     : Anything
- AnythingA
    - SomethingA    : AnythingA
- AnythingB
    - SomethingB    : AnythingB
*/

#include <iostream>

namespace Demo {
    class Anything {
    public:
        virtual void Print() {
            std::cout << "Anything" << std::endl;
        }
    };

    class Something : public Anything {
    public:
        virtual void Print() {
            std::cout << "Something" << std::endl;
        }
    };

    class AnythingA {
    public:
        virtual void Print() {
            std::cout << "AnythingA" << std::endl;
        }
    };

    class SomethingA : public AnythingA {
    public:
        virtual void Print() {
            std::cout << "SomethingA" << std::endl;
        }
    };

    class AnythingB {
    public:
        virtual void Print() {
            std::cout << "AnythingB" << std::endl;
        }
    };

    class SomethingB : public AnythingB {
    public:
        virtual void Print() {
            std::cout << "SomethingB" << std::endl;
        }
    };
}

#endif // FACTORY_H_AP64_2023