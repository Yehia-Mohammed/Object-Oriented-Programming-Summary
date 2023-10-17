#include <iostream>
using namespace std;
struct Student
{
    int Age;// 4 Bytes
    long long ID;// 8 Bytes
};
struct Uni
{
    Student S;// Structures Within Structures
    string Faculty;
    int Hot_Line;
};
enum Days_Of_Week { Sat = 1, Sun, Mon, Tue, Wed, Thu, Fri };
int main() {
    /*--------------Structures--------------*/
    Student S_1;
    cout << sizeof(S_1) << '\n';// This will print 16 Because of Structure padding
    S_1.Age = 19;
    S_1.ID = 1;
    Uni Sohag_Uni;
    Sohag_Uni.Faculty = " FCAI";
    Sohag_Uni.Hot_Line = 2018;
    Sohag_Uni.S = S_1;// Structure Variables in Assignment Statements
    Sohag_Uni.S.Age = 20; // Accessing Nested Structure Members 
    /*--------------Enumerations--------------*/
    Days_Of_Week Day_1, Day_2;
    Day_1 = Tue;
    Day_2 = Sat;
    if (Day_1 < Day_2)// Enumerations are treated internally as integers.
    {
        cout << "Day_1 comes Before Day_2\n";
    }
    else
    {
        cout << "Day_2 comes Before Day_1\n";
    }
}