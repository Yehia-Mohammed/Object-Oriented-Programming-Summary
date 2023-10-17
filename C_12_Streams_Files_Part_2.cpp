#include<iostream> // The iostream class is derived from both istream and ostream by multiple inheritance.
#include<fstream> // For file I/O which is derived from iostream
#include<iomanip>
#include<string>
using namespace std;
/*----- Chapter 12 Streams and Files Part_2 -----*/
class Player {
protected:
    long long ID; 
    char Name[50]; // Must Be Array of Characters -> Note(fstream with Objects.pdf)
public:
    void Set_Data() // Member Function (Setter)
    {
        cout << "Enter Player ID "; cin >> ID;
        cout << "Enter Player Name "; cin >> Name;
    }
    void Print_All_Data() 
    {
        cout << "ID : " << ID << "\nName : " << Name << '\n' ;
    }
};
int main()
{
    /*---write to disk using formatted I/O---*/
    int Year = 2024; string Name = "Future_Developers_Team"; int Members = 20; char ch;
    ofstream Write_File("C:/Users/User/Desktop/Team_Data.txt");
    Write_File << Year << Name << ' ' << Members; //  The Write_File object acts much as cout
    cout << "File written formatted I/O\n";
    Write_File.close();
   /*---Read from disk using formatted I/O---*/
    int Var1, Var2; string STR;
    ifstream Read_File("C:/Users/User/Desktop/Team_Data.txt");
    Read_File >> Var1 >> STR >> Var2;
    cout << Var1 << ' ' << STR << ' ' << Var2 << '\n';
    Read_File.close();
    cout << "File read formatted I/O\n";
    /*---write to disk using Binary I/O---*/
    const int Max = 100;
    int Buffer[Max];
    for (int i = 1; i < 100; i++)
    {
        Buffer[i] = i;
    }
    ofstream Binary_File_I("C:/Users/User/Desktop/Binary.txt", ios::binary);
    Binary_File_I.write(reinterpret_cast<char*>(Buffer), Max * sizeof(int)); // Write an array of intgers to the file -> Note(reinterpret_cast IO.pdf)
    Binary_File_I.close(); // Must close it
    // The first stream must be closed before the second is opened. We use the close() member function for this.
    for (int i = 1; i < 100; i++) // Erase buffer
    {
        Buffer[i] = 0;
    }
    ifstream Binary_File_O("C:/Users/User/Desktop/Binary.txt", ios::binary);
    Binary_File_O.read(reinterpret_cast<char*>(Buffer), Max * sizeof(int)); // Read an int from the file
    for (int i = 1; i < 100; i++)
    {
        if (Buffer[i] != i)
        {
            cout << "Incorrect Data\n";
            cout << Buffer[i] << '\n';
        }
    }
    Binary_File_O.close();
    /*---Object I/O with One Object---*/
    Player Vector, Copy;
    Vector.Set_Data();
    ofstream output_Object("C:/Users/User/Desktop/Object_Data.DAT", ios::binary);
    output_Object.write(reinterpret_cast<char*>(&Vector), sizeof(Vector)); // Write an Object to the file
    output_Object.close();
    ifstream input_Object("C:/Users/User/Desktop/Object_Data.DAT", ios::binary);
    input_Object.read(reinterpret_cast<char*>(&Copy), sizeof(Copy)); // Read an Object From the file
    Copy.Print_All_Data();
    input_Object.close();
    /*----Object I/O with Multiple Objects---*/
    fstream Binary_Object_IO; // Create a file that can be used for both input and output
    Binary_Object_IO.open("C:/Users/User/Desktop/GROUPDATA.DAT", ios::app | ios::in | ios::out | ios::binary);
    do
    {
        cout << "Enter Player Data\n";
        Vector.Set_Data();
        Binary_Object_IO.write(reinterpret_cast<char*>(&Vector), sizeof(Vector));
        cout << "Enter anoter Player (y/n)? ";
        cin >> ch;
    } while (ch == 'y');
    Binary_Object_IO.seekg(0); // Reset to start of file It ensures we’ll start reading at the beginning of the file
    Binary_Object_IO.read(reinterpret_cast<char*>(&Vector), sizeof(Vector));
    while (!Binary_Object_IO.eof())
    {
        cout << "Player:\n";
        Vector.Print_All_Data();
        Binary_Object_IO.read(reinterpret_cast<char*>(&Vector), sizeof(Vector));
    }
    Binary_Object_IO.close();
    /*---To find a particular Player object in the GROUPDATA.DAT file, and to display the data for that particular Player. ---*/
    Binary_Object_IO.open("C:/Users/User/Desktop/GROUPDATA.DAT", ios::in | ios::binary);
    /*The first thing is figure out how many persons are in the file. It does this by positioning the get pointer at the end of the file with the statement*/
    Binary_Object_IO.seekg(0, ios::end); // Go to 0 bytes from end
    int EndPosition = Binary_Object_IO.tellg(); // Find where we are -> his is the length of the file in bytes.
    int N = EndPosition / sizeof(Vector); // Number of Objects in the File
    cout << "There are " << N << " Players in the File\n";
    cout << "Enter Player Number "; cin >> N;
    int Position = (N - 1) * sizeof(Vector); // Object N is Started from Position bytes from start
    Binary_Object_IO.seekg(Position);
    Binary_Object_IO.read(reinterpret_cast<char*>(&Vector), sizeof(Vector));
    Vector.Print_All_Data();
    Binary_Object_IO.close();
}
/*-Notes of This Source Code reinterpret_cast I/O.pdf && reinterpret_cast I/O.pdf-*/
/*-continued in Part 3->🤍-*/