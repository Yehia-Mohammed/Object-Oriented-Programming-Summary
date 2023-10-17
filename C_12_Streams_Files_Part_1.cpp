#include<iostream> // The iostream class is derived from both istream and ostream by multiple inheritance.
#include<fstream> // for file I/O
#include<iomanip>
#include<string>
using namespace std;
/*----- Chapter 12 Streams and Files Part_1 -----*/
int main()
{
    char Character;
    /*By default, the skipws flag is set for standard input streams,
    which means that any whitespace before the next input is ignored.
    you can use the noskipws function to disable the skipping of whitespace.-*/
    cout << "Enter Space\n";
    cin >> noskipws >> Character; // Press Space
    cout << Character << '4' << '\n';
    cout << internal << setw(12) << showpos << 19 << '\n';  // showpos Display + before positive integers
    cout  << right << setw(10) << setfill('*') << 73 << '\n'; // setw is a manipulator sets the width of the output field for the next output operation.
    // the total width of the output is setw argument characters. Other character will be white space by default if you didn't use setfill.
    cout << dec << 0x2a << '\t' << hex  << showbase << 42 << '\n'; // Convert form hexadecimal to decimal and vice versa
    cout << oct << showbase << 2024 << '\t' << dec << 03750 << '\n'; // Convert form octal to decimal and vice versa
    /*showbase -> Use base indicator on output (0 for octal, 0x for hex), if you will write the number in the code you must write 0 for octal, 0x for hex*/
    bool Boolean = false;
    cout << boolalpha << Boolean << '\n'; // Convert bool form 0, 1 to “true” or “false” strings.
    cout << 10.00 << '\n'; // 10
    cout << showpoint << setprecision(8) << 100.00 << '\n'; // 10.00000 // Set precision (number of digits displayed)
    cout << setprecision(2) << scientific << 1000000.0 /* = 1e6*/ << '\t' << fixed << 1e6 << '\n';
    // scientific -> Use exponential format on floating-point output [1.00e+06]
    // fixed Use fixed format on floating-point output [1000000.00]
    /*you can set the formatting flags using the setf() and unsetf() ios member functions by cout and cin objects of the standard input/output streams
    OR setiosflags(), resetiosflags()*/
    cout.setf(ios::dec);
    cout << 03750 << '\n';
    // you can use to set the formatting flags and perform other tasks using ios member functions.
    cout.width(6);
    cout.fill('0');
    cout.precision(3);
    cout << noshowpos << 1973 << '\n';
    cout << cout.width() << ' ' << cout.fill() << ' ' << cout.precision() << ' ' << '\n';
    cout.setf(ios::right, ios::adjustfield); // clears all the flags dealing with text justification and then sets the right flag for right-justified output.
    cout << setw(12) << 10 << '\n';
    string S;
    char C;
    C = cin.get();
    cout << C;
    char A[40];
    char B[40];
    cout << "Enter Characters till Q || 20 Characters\n";
    cin.get(A, 20, 'Q'); // Very important -> Note(TABLE 12.6), Note(The difference between get and getline Functions.pdf)
    cin.ignore(20, '\n'); // to skip over any remaining characters in the stream.
    cout << "Enter Characters till q || 20 Characters\n";
    cin.getline(B, 20, 'q');
    for (int i = 0; i < 20; i++)
    {
        cout << A[i];
    }
    cout << '\n';
    for (int i = 0; i < 20; i++)
    {
        cout << B[i];
    }
    cout << "\nEnter Characters till * Character\n";
    getline(cin, S, '*');
    /*There is getline version in string libaray. The syntax is getline(stream, S, delimit), where stream is the input stream, S is the name of the string object,
    and delimit is the delimiting character that stops the reading (default is \n). The function can include the delimiting character in the string.
    This Function version doesn't provide the option to specify a maximum number of characters*/
}
/*-Notes of This Source Code TABLE 12.6 Note.pdf && The difference between get and getline Functions.pdf-*/
/*-continued in Part 2->🤍-*/