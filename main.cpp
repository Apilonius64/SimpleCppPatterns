#include "Factory/Factory.h"

int main(int argc, char const *argv[])
{
    Factory<Anything, AnythingA, AnythingB> fac;
    ChildFactory<
        Factory<Anything,   AnythingA,  AnythingB>,
                Something,  SomethingA, SomethingB
    > cFac;
    Factory<Anything, AnythingA, AnythingB>* cFacPtr = &cFac;

    cFacPtr->MakeType(TypeContainer<Anything>())->Print();
    cFacPtr->MakeType(TypeContainer<AnythingA>())->Print();
    cFacPtr->MakeType(TypeContainer<AnythingB>())->Print();

    cFacPtr->Make<Anything>()->Print();
    cFacPtr->Make<AnythingA>()->Print();
    cFacPtr->Make<AnythingB>()->Print();

    return 0;
}
