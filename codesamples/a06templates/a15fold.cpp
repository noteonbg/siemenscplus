#if 0


template <typename... Items>
void printItems(Items... items) {
   ((std::cout << items << "\n"), ...); // unary right fold
}

int main() {
   std::cout << "printItems(1, 2.2, \"hello\"):\n";
   printItems(1, 2.2, "hello");
}


#endif

#if 0

#include <iostream>


template <typename... Items>
auto unaryLeftAdd(Items... items) {
   return (... + items); // unary left fold
}

template <typename... Items>
auto unaryRightAdd(Items... items) {
   return (items + ...); // unary right fold
}

template <typename... Items>
auto unaryLeftSubtract(Items... items) {
   return (... - items); // unary left fold
}

template <typename... Items>
auto unaryRightSubtract(Items... items) {
   return (items - ...); // unary right fold
}

int main() {
     	 std::cout << unaryLeftAdd(1, 2, 3, 4)  << "\n ";
         std::cout << unaryRightAdd(1, 2, 3, 4) << "\n";
         std::cout << unaryLeftSubtract(1, 2, 3, 4)  << "\n";
         std::cout << unaryRightSubtract(1, 2, 3, 4)  << "\n";
}

#endif


#if 0


#include <iostream>

template <typename... Items>
auto binaryLeftAdd(Items... items) {
   return (0 + ... + items); // binary left fold
}

template <typename... Items>
auto binaryRightAdd(Items... items) {
   return (items + ... + 0); // binary right fold
}

template <typename... Items>
auto binaryLeftSubtract(Items... items) {
   return (0 - ... - items); // binary left fold
}

template <typename... Items>
auto binaryRightSubtract(Items... items) {
   return (items - ... - 0); // binary right fold
}

int main() {
   std::cout << "Binary left and right fold with addition:\n " <<
   binaryLeftSubtract(1, 2, 3, 4) << "\n " <<
   binaryRightSubtract(1, 2, 3, 4);
   return 0;



   
}




#endif

