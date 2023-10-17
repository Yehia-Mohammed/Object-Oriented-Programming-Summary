#include <iostream>
#include <process.h>
using namespace std;
class Members { // Abstract Classes -> No actual instances (objects) of this class are created.
private:
    static unsigned int Counter;
protected: // to be acessible in derived classes
    unsigned int Age = 10;
    string Name;
    short int Section;
public:
    Members() : Name(""), Age(0), Section(0)
    {Counter++;}
    Members(string name, unsigned int age, short int section) : Name(name), Age(age), Section(Section)
    {Counter++;}
    void Get_Data()
    {
        cout << "Enter your Name : "; cin >> Name;
        cout << "Enter your age : "; cin >> Age;
        cout << "Select your Technology\n(1) for Problem Solving\n(2) for Web\n(3) for Flutter : "; cin >> Section;
    }
    void Show_Data()
    {
        cout << "Name : " << Name;
        cout << "\nAge : " << Age;
        cout << "\nTechnology : " << Section << '\n';
    }
};
class Coach : public Members { // pubicly derived 
private:
    unsigned int ID, Number_Of_Participants;
public:
    // The derived class can call the base class’s constructors using the member initializer list syntax, as shown in your code:
    Coach() : Members(), ID(0), Number_Of_Participants(0) // <- Member initializer list
    { }
    // This construction causes the Coach Empty constructor to call the Members Empty constructor in the base class.
    Coach(string name, unsigned int age, short int section, unsigned int id, unsigned int number_of_participants)
                                : Members(name, age, section), ID(id), Number_Of_Participants(number_of_participants)       
    { }
    // This construction causes the Coach parameterize constructor to call the Members parameterize constructor in the base class.
    // The derived class constructor will invoke the base class constructor with the same parameter before executing its own body.
    // if the derived class doesn't call any base class constructor in the member initializer list,
    // then the compiler will try to call the default constructor of the base class (the one that takes no parameters).
    // If the base class doesn't have a default constructor, then this will cause a compilation error.
    void Get_Data() // Overriding Member Function
    {
        Members::Get_Data(); // Scope Resolution with Overridden Function
        cout << "Enter your ID : "; cin >> ID;
        cout << "\nEnter your Number of participants : "; cin >> Number_Of_Participants;
    }
    void Show_Data() // Overriding Member Function
    {
        Members::Show_Data();  // Scope Resolution with Overridden Function
        cout << "your ID : " << ID;
        cout << "your Number of participants : " << Number_Of_Participants << '\n';
    }

};
class Participant : public Members {  // pubicly derived 
private:
    short Number;
public:
    Participant() : Members(), Number(0)
    { }
    Participant(string name, unsigned int age, short int section, unsigned short int number)
                                                    : Members(name, age, section), Number(number)
    { }
    void Get_Data() // Overriding Member Function
    {
        Members::Get_Data(); // Scope Resolution with Overridden Function
        cout << "Enter your number : "; cin >> Number;
    }
};
unsigned int Members::Counter = 0; // define and initialize a static variable (important)
int main()
{
    Participant Participants[5]; Coach Coaches[3];
    for (int i = 0; i < 3; i++)
    {
            Coaches[i].Get_Data();
    }
    for (int i = 0; i < 5; i++)
    {
        Participants[i].Get_Data();
    }
    for (int i = 0; i < 3; i++)
    {
            Coaches[i].Show_Data();
    }
    for (int i = 0; i < 5; i++)
    {
        Participants[i].Show_Data();
    }
}