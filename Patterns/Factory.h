#if !defined(FACTORY_H_AP64_2023)
#define FACTORY_H_AP64_2023

namespace Patterns {
    template <typename T>
    class TypeContainer {
    public:
        typedef T Type;
    };

    template <typename T, typename B>
    class TypeSet {
    public:
        typedef T Type;
        typedef B Base;
    };

    class FactoryNone {};

    template <typename ...TYPES>
    class Factory : public Factory<FactoryNone, TypeSet<TYPES, TYPES>...> {
    public:
        template<typename BASE>
        BASE* Make() {
            return this->MakeType(TypeContainer<BASE>());
        }
    };

    template <typename I, typename P_TYPE, typename P_BASE_TYPE, typename ...TYPES>
    class Factory<I, TypeSet<P_TYPE, P_BASE_TYPE>, TYPES...> : public Factory<I, TYPES...> {
    public:
        virtual P_BASE_TYPE* MakeType(TypeContainer<P_BASE_TYPE>) {
            return new P_TYPE();
        }

        using Factory<I, TYPES...>::MakeType;
    };

    template <typename I, typename P_TYPE, typename P_BASE_TYPE>
    class Factory<I, TypeSet<P_TYPE, P_BASE_TYPE>> : public I {
    public:
        virtual P_BASE_TYPE* MakeType(TypeContainer<P_BASE_TYPE>) {
            return new P_TYPE();
        }
    };

    template <typename... TYPES>
    class CFactory;

    template <
        typename ...BASE_TYPES,
        typename ...TYPES
    >
    class CFactory<Factory<BASE_TYPES...>, TYPES...> : public Factory<Factory<BASE_TYPES...>, TypeSet<TYPES, BASE_TYPES>...> {};
}

#endif // FACTORY_H_AP64_2023
