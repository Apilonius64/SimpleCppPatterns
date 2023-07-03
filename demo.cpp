/*                                                                         
___                
|   \ ___ _ __  ___ 
| |) / -_) '  \/ _ \
|___/\___|_|_|_\___/
                     
*/


#include "Patterns/Factory.h"
#include "demo.h"

using namespace Patterns;
using namespace Demo;

int main(int argc, char const *argv[])
{
    Factory<Anything, AnythingA, AnythingB> fac;
    CFactory<
        Factory<Anything,   AnythingA,  AnythingB>,
                Something,  SomethingA, SomethingB
    > cFac;
    Factory<Anything, AnythingA, AnythingB>* cFacPtr = &cFac;

    cFacPtr->Make<Anything>()->Print();
    cFacPtr->Make<AnythingA>()->Print();
    cFacPtr->Make<AnythingB>()->Print();

    return 0;
}
