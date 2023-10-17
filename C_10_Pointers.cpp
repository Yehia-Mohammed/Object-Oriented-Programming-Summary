#include <iostream>
using namespace std;
/*----- Chapter 10 Pointers -----*/
int Global_Var1 = 1, Global_Var2 = 5;
class Programmer {
private:
    string Name, Programming_Language;
    unsigned long long ID;
public:
    void Set_Data()
    {
        cout << "\n\nEnter your name : "; cin >> Name;
        cout << "Enter your ID : "; cin >> ID;
        cout << "Enter your programming language : "; cin >> Programming_Language;
    }
    void Print_Data()
    {
        cout << "\nyour name : "; cout << Name;
        cout << "\nyour ID : "; cout << ID;
        cout << "\nyour programming language : "; cout << Programming_Language;
    }
    string Get_Name()
    {
        return Name;
    }
};
void Print_Array()
{
    string Array[3] = {"Future", "Developers", "Team"};
    // The name of the array is the address of the first element in it
    string *ptr = Array; // pointer to string, this pointer will  point to the first element in Array
    for (int i = 0; i < 3; i++)
    {
        cout << *(Array + i) << ' '; /* *(Array++) -> this sytax is wrong, you can’t increment a constant (address)*/
    }
    cout << '\n';
    /*While you can't increment an address, you can increment a pointer that holds an address.*/
    for (int i = 0; i < 3; i++)
    {
        cout << *(ptr++) << ' ';
    }
}
void Pass_Arguments_By_Pointer(double *Pointer)
{ // The function Pass_Arguments_By_Pointer() is declared as taking an argument that is a pointer to double.
    *Pointer *= 1000;
} // Since Pointer contains the address of Var, anything done to *Pointer is actually done to Var.
void Pass_Array(float *array, int size)
{ // it’s more common to use pointer notation instead of array notation when arrays are passed to functions
    cout << "The Array before sorting\n";
    for (int i = 0; i < size; i++)
    {
        cout << *array++ << ' ';
    }
} // float* is equivalent here to float[], although the pointer syntax is more commonly used.
void Bubble_Sort(float *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                swap(*(array + j), *(array + j + 1));
            }
        }
    }
}
void Sorting_Pointers(Programmer **array, int size)
{/*The array is of type pointers to Programmer, or  Programmer*, so its address is type Programmer**.
    The address of a pointer is a pointer to a pointer*/
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((*(array + j))->Get_Name() > (*(array + j + 1))->Get_Name())
            {
                swap(*(array + j), *(array + j + 1));
            }
        }
    }
}
int main()
{
    int *PTR; // The asterisk used in a declaration means pointer to.
    int Var1 = 21, Var2 = 10, Var3 = 32;
    int *ptr1 = &Var1, *ptr2 = &Var2, *ptr3 = &Var3; // Must give pointers a valid address before use it
    cout << "Address of Varible 1 : " << ptr1       // 0x5ffe74
            << "\nAddress of Varible 2 : " << ptr2  // 0x5ffe70
            << "\nAddress of Varible 3 : " << ptr3; // 0x5ffe6c
           /*The addresses appear in descending order because local variables are stored on the Stack, which grows downward in memory.*/ 
    int *G_ptr1 = &Global_Var1, *G_ptr2 = &Global_Var2;
    cout << "\nAddress of Global Varible 1 : " << G_ptr1                              // 0x7ff67a913000
          << "\nAddress of Global Varible 2 : " << G_ptr2 << '\t' << G_ptr2 - G_ptr1; // 0x7ff67a913004
        /*if we had used global variables, they would have ascending addresses, since global variables are stored on the Heap, which grows upward.*/
        /*the substraction of ptr1 - ptr2 or ptr2 - ptr3 or G_ptr2 - G_ptr1 = 4 Bytes That’s because integers occupy 4 bytes of memory.*/
    cout << "\nThe value stored at the address that's stored in G_ptr1 : " <<  *G_ptr1 // dereference operator or indirection operator
        << "\nThe value stored at the address that's stored in ptr1 : " <<  *ptr1; // -> It means the value of the variable pointed to by ptr1
    Var1 = 99; *ptr2 = 15;/*indirection: value of variable pointed to by ptr2*/ Var3 *= 5;
    cout << '\n' << *ptr1 << ' '  << Var2 << ' '  << *ptr3 << '\n'; cout << '\n';
    // Using the dereference operator to access the value stored in an address is called indirect addressing, or sometimes dereferencing the pointer.
    Print_Array(); cout << '\n';/*-- Line 4 --*/
    double Var = 5; // The type of Var must be the same to the type that the pointer pointed to in the prototype of the function or use pointer to void.
    Pass_Arguments_By_Pointer(&Var); // the address of the variable as the argument /*-- Line 16 --*/
    cout << '\n' << Var << '\n';
    /*Passing a pointer as an argument to a function is in some ways similar to passing a reference.
    They both permit the variable in the calling program to be modified by the function. 
    However, the mechanism is different. A reference is an alias for the original variable, while a pointer is the address of the variable.*/
    float Arr[4] = {2050.9, 2030.5, 2024.1, 3.14};
    Pass_Array(Arr, 4);
    cout << '\n';
    Bubble_Sort(Arr, 4);
    cout << "\nThe Array after sorting\n";
    for (int i = 0; i < 4; i++)
    {
        cout << *(Arr + i) << ' ';
    }
    Programmer *Pointer; // Pointer to user defiened data (Programmer)
    Pointer = new Programmer; // new Programmer returns a pointer to a memory area large enough for a Programmer object
    Pointer->Set_Data(); // also (*Pointer).Set_Data(); This syntax is right But cumbersome to write.
    Pointer->Print_Data(); cout << '\n';
    Programmer &A = *(new Programmer);
     // The reference A is an alias for the new object, and can be used to access or modify its data members and methods. 
     // *(new Programmer) This is the object pointed to by the pointer
    A.Set_Data();
    A.Print_Data();
    Programmer *Array[3]; // array of pointers to Programmers
    /*This arrangement allows easy access to a group of objects, and is more flexible than placing the objects themselves in an array*/
    for (int i = 0; i < 3; i++)
    {
        Array[i] = new Programmer;
        (*(Array + i))->Set_Data(); // <- This is pointer notation. It is the same as array notation Array[i]->Set_Data();
        (*(Array + i))->Print_Data();
    }
    Sorting_Pointers(Array, 3);
    for (int i = 0; i < 3; i++)
    {
        (**(Array + i)).Print_Data(); // The object that the pointer in the array of pointers pointed to.
    }
    /*---------- #We_Look_Towards_Excellence🤍✨ ----------*/
}