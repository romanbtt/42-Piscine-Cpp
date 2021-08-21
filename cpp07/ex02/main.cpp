#include <iostream>
#include <Array.hpp>

#define MAX_VAL 10

class MyFavortiteNumber
{
    private:
        int _n;

    public:

        MyFavortiteNumber( void ) : _n(12) {}
        MyFavortiteNumber( int input ) : _n( input ) {}
        MyFavortiteNumber &  operator= (MyFavortiteNumber const & rhs) { _n = rhs._n; return *this; }
        MyFavortiteNumber    operator+ (MyFavortiteNumber const & rhs) { return _n + rhs._n; }
        MyFavortiteNumber    operator- (MyFavortiteNumber const & rhs) { return _n - rhs._n; }
        MyFavortiteNumber    operator* (MyFavortiteNumber const & rhs) { return _n * rhs._n; }
        MyFavortiteNumber    operator/ (MyFavortiteNumber const & rhs) { return _n / rhs._n; }
        int      getN( void ) { return _n; }
};

std::ostream & operator<<(std::ostream & o, MyFavortiteNumber & rhs) { o << rhs.getN(); return o; }

int main(int, char**)
{    
    {
        Array<MyFavortiteNumber> favortiteNumber(3);
        std::cout << favortiteNumber[0] << std::endl;
        favortiteNumber[0] = favortiteNumber[1] + favortiteNumber[2];
        std::cout << favortiteNumber[0] << "\n" << std::endl;
    }
    {
        Array<int> test1(5);
        Array<const int> test2(5);
        test1[0] = 42;
        std::cout << "*" << test1[0] << std::endl;
        test1[0] = test2[0];
        std::cout << "*" << test1[0] << "\n" << std::endl;
        //test2[0] = 42;
    }

    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
        std::cout << numbers[i] << std::endl;
        std::cout << mirror[i] << "\n" << std::endl;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "***" << std::endl;
        std::cout << tmp[5] << std::endl;
        std::cout << test[5] << "\n***" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
        std::cout << numbers[i] << "\n" << std::endl;
    }
    delete [] mirror;
    return 0;
}