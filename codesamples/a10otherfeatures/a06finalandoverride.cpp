#if 1

struct Base {
    virtual void foo()=0;
    
};

struct A : private Base {
    void foo() override final {}// Base::foo is overridden, and A::foo is final
    // Error: bar cannot be final as it is non-virtual
    void bar()  {}
};

struct B final : A {
    // Error: foo cannot be overridden as it is final in A
    //void foo() override {}
};

// Error: B is final
//struct C : B {};

int main() {
    // Compile-time errors will occur due to the use of final
    A obj;
    obj.foo();
    return 0;
}


#endif