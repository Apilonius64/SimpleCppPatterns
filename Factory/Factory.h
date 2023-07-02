#if !defined(FACTORY_H_AP64_2023)
#define FACTORY_H_AP64_2023

#include <iostream>
#include <tuple>

// #define FACTORY_BIND_DTYPE(_T, _B) _B* makeT() {return new _T();}

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

template <typename T>
class TypeContainer {
public:
    typedef T Type;
};

template <typename T, typename B>
class FactoryMethodMaker {
public:
    virtual B* MakeType(TypeContainer<B>) {
        return new T();
    }
};

template <typename T, typename B, typename CB>
class FactoryMethodMakerF : public CB {
public:
    virtual B* MakeType(TypeContainer<B>) {
        return new T();
    }

    using CB::MakeType;
};


template <typename P_TYPE, typename ...TYPES>
class FactoryF : public FactoryMethodMakerF<P_TYPE, P_TYPE, FactoryF<TYPES...>> {};

template <typename P_TYPE>
class FactoryF<P_TYPE> : public FactoryMethodMaker<P_TYPE, P_TYPE> {};

template <typename ...TYPES>
class Factory : public FactoryF<TYPES...> {
public:
    template<typename BASE>
    BASE* Make() {
        return this->MakeType(TypeContainer<BASE>());
    }
};

template <typename ...T>
class ChildFactoryF {};

template <typename ...T>
class ChildFactory {};

template <
    typename ...BASE_TYPES,
    typename ...TYPES
>
class ChildFactory<Factory<BASE_TYPES...>, TYPES...> : public ChildFactoryF<Factory<BASE_TYPES...>, Factory<BASE_TYPES...>, TYPES...> {};

template <
    typename COMPLETE_FACTORY,
    typename P_BASE_TYPE,
    typename P_TYPE,
    typename ...BASE_TYPES,
    typename ...TYPES
>
class ChildFactoryF<COMPLETE_FACTORY, Factory<P_BASE_TYPE, BASE_TYPES...>, P_TYPE, TYPES...> : public FactoryMethodMakerF<P_TYPE, P_BASE_TYPE, ChildFactoryF<COMPLETE_FACTORY, Factory<BASE_TYPES...>, TYPES...>> {};

template <
    typename COMPLETE_FACTORY,
    typename P_BASE_TYPE,
    typename P_TYPE
>
class ChildFactoryF<COMPLETE_FACTORY, Factory<P_BASE_TYPE>, P_TYPE> : public FactoryMethodMakerF<P_TYPE, P_BASE_TYPE, COMPLETE_FACTORY> {};

#endif // FACTORY_H_AP64_2023
