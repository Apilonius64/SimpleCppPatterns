# SimpleCppPatterns
A small, lightweight cpp libary (still in process) which implements easy-to-use classes for the most common design patterns.

## How to use
### Abstract factory
```cpp
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
```
You can find everything at on place at the [demo files](demo.cpp).

## What is already implemented?
- Abstract Factory

## What may be implemented in the future?
Hopefully, a lot of common patterns (The development is just beginning). Issues and Pull requests are welcome!

## I want to learn more about Design Patterns
You may take a look at the wikipedia article: https://en.wikipedia.org/wiki/Design_Patterns

## License
