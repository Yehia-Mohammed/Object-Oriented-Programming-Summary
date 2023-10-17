#include<iostream>
#include <typeinfo> // For dynamic_cast
using namespace std;
/*----- Chapter 11 Virtual Functions -----*/
class Actor { // Actor class is an abstract class. To call a class abstract, it is enough to have one (or more) pure virtual function in it.
/* No Actor objects can ever be created. This class exists only to be the base class for the Player and Monstor classes.*/
protected:
    string Name;
public:
    void Set_Name()
    {
        cout << "Enter the Name : "; cin >> Name;
    }
    void Get_Name()
    {
        cout << "The name is : " << Name << '\n';
    }
    virtual void Set_Data() = 0; // The = 0 syntax is simply how we tell the compiler that a virtual function will be pure.
    virtual bool Is_Won() = 0;
    virtual ~Actor() // Virtual Destructor
    {
        cout << "Actor Deleted\n";
    }
};
class Player : public Actor{
private:
/*. To avoid copying, overload the assignment operator and the copy constructor as private members.*/
    int killed_Monsters;
    static int Online_Players;
public:
    Player()
    {
        Online_Players++;
        cout << "Player Created\n";
    }
    ~Player()
    {
        Online_Players--;
        cout << "Player Deleted\n";
    }
    void Set_Data() // Override pure virtual function
    {
        Actor::Set_Name();
        cout << "Number of killed monsters : "; cin >> killed_Monsters;
    }
    bool Is_Won() // Override pure virtual function
    {
        return (killed_Monsters > 10);
    }
    static void Show_Online()
    {
        cout << "Online players : " << Online_Players << '\n';
    }
    Player&operator=(Player &Copy) // overloaded = operator
    {
        Name = Copy.Name;
        killed_Monsters = Copy.killed_Monsters;
        return *this; // this is a pointer to the object of which the function is a member.
        cout << " overloaded = operator \n";
    }
    Player (Player &Copy) // overloaded = operator
    {
        Name = Copy.Name;
        killed_Monsters = Copy.killed_Monsters;
        cout << "Copy Constructor \n";
    }
};
class Monstor : public Actor{
private:
    bool Player_Killed;
public:
    void Set_Data() // Override pure virtual function
    {
        Actor::Set_Name();
        cout << "Is Player Killed (0/1)? "; cin >> Player_Killed;
    }
    bool Is_Won() // Override pure virtual function
    {
        return Player_Killed;
    }
    ~Monstor()
    {
        cout << "Monstor Deleted\n";
    }
};
int Player::Online_Players = 0;
int main() {
    // Actor Object_1; // Erorr -> No Actor objects can ever be created. As Actor is Abstract Class(have one or more pure virtual function)
    Actor *Actor_Pointer[100]; char Choice; int N = 0;
    do
    {
        cout << "Enter Player or Mostor (p/m) : "; cin >> Choice;
        if (Choice == 'p')
        {
            Actor_Pointer[N] =  new Player;
        }
        else
        {
            Actor_Pointer[N] =  new Monstor;
        }
        Actor_Pointer[N++]->Set_Data();
        cout << "Enter anoter (y/n) ? "; cin >> Choice;
    } while (Choice == 'y');
    for (int i = 0; i < N; i++)
    {
        Actor_Pointer[i]->Get_Name();
        if (Actor_Pointer[i]->Is_Won())
        {
            cout << "\tThis Actor Won\n";
        }
        else
        {
            cout << "\t->\tThis Actor lose\n";
        }
    }
    Player::Show_Online();
    Actor *ptr = new Player;
    delete ptr; // With Virtual Base Class This will call Derived class destructor then base class destructor
    Player Object;
    Object.Set_Data();
    Player Copy = Object; // invoke overloaded =
    Copy.Get_Name();
    Player Object_1(Object); // invoke copy constructor The equivalent statement Player Object_1 = Object;
    /*---------- #We_Look_Towards_Excellence🤍✨ ----------*/
}