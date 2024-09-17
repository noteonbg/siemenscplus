#include <iostream>

//C++ 11 feature


#if 0
#include <iostream>

// throw_lambda_expression.cpp
int main() // C4297 expected
{
   []() noexcept { std::cout << "hi"; throw 5; };
}

#endif



#if 0
// captures_lambda_expression.cpp

#include <iostream>
using namespace std;

int main()
{
   int m = 0;
   int n = 0;
   [&,n] (int a) mutable { m = ++n + a; }(4);
   cout << m << endl << n << endl;
}

#endif

#if 1

//constexpr lambda expressions

    int main()
    {

    auto answer = [](int n)
    {
        return 32 + n;
    };

    constexpr int response = answer(10);
    std::cout << response << "\n ";
    
    auto Increment = [](int n)
    {
        return n + 1;
    };

    constexpr int(*inc)(int) = Increment;

    std::cout << inc(3);



    return 0;
    }


    


#endif



#if 0



constexpr int Increment(int n)
    {
        return [n] { return n + 1; }();
    }


    static int i=3;

int main()
{
    /*
    Lambda function signature : 
                                [capture list] (parameters) ->return type{
                                        // Function body
                                }
    */

   
   
   //Declaring a lambda function and calling it through a name
   

    #if 0
   int victim =2;
   int notvictim =44;
   
   auto func = [victim]() mutable noexcept {
        victim=44;
        i=44;
        std::cout << "Hello World!" <<victim<<  std::endl;
      

   };
  func();

  /*
  
  create a fp
  create a function and assing it to fp
  operate on fp.. leading to function call.
  what is stupid this.. I
  
  */








    #endif

   int y = 32;

   auto answer = [](int n)
    {
        return 32 + n;
    };

    constexpr int response = answer(10);

    /**/
   auto answer = []() constexpr
    {
        int x = 10;
        return x;
    };
    constexpr int response = answer(10);

    


   auto x1 = [](int i){ return i; }; // OK: return type is int
   auto x2 = []{ return {2,3}; };  // ERROR: return type is void, deducing
                                  // return type 
                                  //from braced-init-list isn't valid
  






   

    #if 0
    //Declare a lambda function and call it directly
  
    auto x=[](){
        std::cout << "Hello World!" << std::endl;
    };
    x();



  
    

    //Lambda function that takes parameters

    
    [](double a, double b){
       std::cout << "a + b : " << (a + b)  << std::endl;
    }(10.0,50.0);



    
   
    auto func1 = [](double a, double b){
       std::cout << "a + b : " << (a + b)  << std::endl;
    };

    func1(10,20);
    func1(5,7);
   


   //Lambda function that returns something
   
    auto result = [](double a, double b){
        return a + b;
    }(10,60);

    //std::cout << "result : " << result << std::endl;
    std::cout << "result : " << [](double a, double b){
        return a + b;
    }(10,60) << std::endl;
   


  
    auto func1 = [](double a, double b){
        return a + b;
    };

    auto result1 = func1(23,7);
    auto result2 = func1(9,45);

    std::cout << "result1 : " << result1 << std::endl;
    std::cout << "result2 : " << result2 << std::endl;
    std::cout  <<"direct call : " << func1(5,2) << std::endl;
    

    //Explicitly specify the return type
    
   
    auto func3 = [](double a, double b)-> int{
        return a + b;
    };

    auto func4 = [](double a, double b){
        return a + b;
    };

    int a{6.9};
    double b{3.5};

    auto result3 = func3(a,b);
    auto result4 = func4(a,b);

    std::cout << "result3 : " << result3 << std::endl;
    std::cout << "result4 : " << result4 << std::endl;
    std::cout << "sizeof(result3) : " << sizeof(result3) << std::endl; // 4
    std::cout << "sizeof(result4) : " << sizeof(result4) << std::endl; // 8
    std::cout << "Done!" << std::endl;

    #endif

    return 0;
}

#endif