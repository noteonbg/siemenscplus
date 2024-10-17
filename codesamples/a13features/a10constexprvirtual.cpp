#if 0

#include <cassert>

struct Box {
    double width{0.0};
    double height{0.0};
    double length{0.0};
};

struct Product {
    constexpr virtual ~Product() = default;
    constexpr virtual Box getBox() const noexcept = 0;
};

struct Notebook : public Product {
    constexpr ~Notebook() noexcept {};
    constexpr Box getBox() const noexcept override {
        return {.width = 30.0, .height = 2.0, .length = 30.0};
    }
};

struct Flower : public Product {
    constexpr Box getBox() const noexcept override {
        return {.width = 10.0, .height = 20.0, .length = 10.0};
    }
};

constexpr bool canFit(const Product &prod, const Box &minBox) {
    const auto box = prod.getBox();
    return box.width < minBox.width && box.height < minBox.height && box.length < minBox.length;
}

int main() {
    constexpr Notebook nb;
    constexpr Box minBox{100.0, 100.0, 100.0};
    static_assert(canFit(nb, minBox), "Notebook cannot fit into the minimum box size!");
    // Compile-time check: If this assertion fails, it means the notebook doesn't fit.
    // Otherwise, it's guaranteed to fit.
}


/*

We define a Product base class with a constexpr virtual function getBox() 
that returns the box size for each product.
The Notebook and Flower classes override getBox() with
 their specific dimensions.
The canFit function checks if a product fits into 
a given minimum box size.
At compile time, we ensure that the notebook fits into the
 specified minimum box size using static_assert.


*/

#endif


#if 0

struct Base {
    constexpr virtual int get() { return 1; }
    virtual ~Base() = default;
};

struct Child : Base {
    constexpr int get() override { return 2; }
};

constexpr int foo(bool b) {
    Base* ptr = b ? new Base() : new Child();
    auto res = ptr->get(); // This call is now possible in C++20
    delete ptr;
    return res;
}

constexpr auto BaseVal = foo(true);
constexpr auto ChildVal = foo(false);



#endif