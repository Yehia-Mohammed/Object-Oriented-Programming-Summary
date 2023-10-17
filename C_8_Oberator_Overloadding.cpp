#include <iostream>
#include <process.h> // For Exit()
using namespace std;
/*----- Chapter 8 Operator Overloading -----*/
class Overloading
{
private:
    static const int Size = 100;
    int Array[Size], X, Y;
public:
    Overloading() : X(0), Y(0)
    { }
    Overloading(int x, int y) : X(x), Y(y)
    { }
    Overloading operator++() // Prefix (Unary Operator)
    {
        return Overloading(++X, ++Y); // Nameless Temporary Object
        // OR
        // ++X; ++Y;
        // return *this;
    }
    Overloading operator++(int) // Postfix (Unary Operator)
    // (int) isn’t really an argument, and it doesn’t mean integer. It’s simply a signal to the compiler to create the postfix version of the operator.
    {
        return Overloading(X++, Y++); // Nameless Temporary Object
        // OR
        // Overloading Temp = *this;
        // X++; Y++;
        // return Temp;
    }
    Overloading operator-() // (Unary Operator)
    {
        X *= -1;
        Y *= -1;
        return *this;
        // OR
        // return Overloading(-X, -Y); // Nameless Temporary Object
    }
    // If the return type of the Unary Operator is Void and you used it assignment expressions like {Object_3 = Object_1++};
    // The compiler will complain  Because the assignment statement it is being asked type of void in the operator++().
    Overloading operator+(Overloading T) // Arithmetic Operators (Binary Operators)
    {
        Overloading Temp;
        Temp.X = T.X + X;
        Temp.Y = T.Y + Y;
        return Temp;
    }
    Overloading operator+=(Overloading O) // Arithmetic Assignment Operator (Binary Operator)
    {
        X += O.X;
        Y += O.Y;
        return *this;
    }
    bool operator>(Overloading O) // logical Oberator (Binary Operator)
    {
        return (Y > O.Y && X > O.X);
    }
    int & operator[](int n) // Subscript Operator ([]), (return by reference)
    {
        if (n < 0 || n >= Size)
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return Array[n];
    }
    void Print()
    {
        cout << "X = " << X << '\t' << "y =" << Y << '\n';
    }
};
int main()
{
    Overloading Object_1, Object_2(31, 216), Object_3;
    for (int i = 0; i < 100; i++)
    {
        Object_1[i] = i * 10; // left side of equal sign
    }
    for (int i = 0; i < 100; i++)
    {
        int temp = Object_1[i]; // right side of equal sign
        cout << "Element Number (" << i  << ") = " << temp << '\n';
    }
    Object_1++;
    Object_1.Print();   
    Object_3 = Object_1++ + Object_2;
    Object_3.Print();
    cout << ((Object_1 > Object_3) ? "True\n" : "False\n");
    return 0;
}
