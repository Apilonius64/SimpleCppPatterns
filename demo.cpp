/*                                                                         
___                
|   \ ___ _ __  ___ 
| |) / -_) '  \/ _ \
|___/\___|_|_|_\___/
                     
== Table of Contents ============================================
- Demo: Factory
*/


#include "Patterns/Factory.h"
#include "demo.h"

using namespace Patterns;
using namespace Demo;

int main(int argc, char const *argv[])
{
    /*
    == Demo: Factory ============================================
    */
    
    // Create factory
    CFactory<
        Factory<Anything,   AnythingA,  AnythingB>,
                Something,  SomethingA, SomethingB
    > cFac;

    // Create a factory pointer (for the client)
    Factory<Anything, AnythingA, AnythingB>* cFacPtr = &cFac;

    // Use the factory pointer
    Anything*  myA  = cFacPtr->Make<Anything>();
    AnythingA* myAa = cFacPtr->Make<AnythingA>();
    AnythingB* myAb = cFacPtr->Make<AnythingB>();

    myA->Print();
    myAa->Print();
    myAb->Print();

    // Cleanup
    delete myA;
    delete myAa;
    delete myAb;

    return 0;
}
