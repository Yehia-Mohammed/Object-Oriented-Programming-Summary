#include <iostream>
using namespace std;
/*----- Chapter 6 Objects & Classes -----*/
class Player {
private:
    int ID; 
    string Name;
    static int Count;
public:
    class Input
    {
    public:
        string Origin;
        int Number;
        Input(string O, int id)
        {
            Origin = O;
            Number = id;
        }
    };
    Player() : ID(0), Name("No Name")
    {
        Count++;
    }
    Player(int id, string name) : ID(id), Name(name)
    {
        if (id < 0)
        {
            throw Input("Out of Range !!!", id);
        }
        
        Count++;
    }
    void Get_Number_Of_Players();
    void Print_All_Data() const;
};
void Player::Get_Number_Of_Players()
{
    cout << "Number Of Players : " << Count << '\n';
}
void Player::Print_All_Data() const
{
    cout << "ID : " << ID << "\nName : " << Name << "\nNumber Of Actor : " << Count << '\n';
}
int Player::Count = 0;
int main() 
{
    Player(-1 , "1021");
    // try
    // {
    //     Player(-1 , "1021");
    // }
    // catch(Player::Input X)
    // {
    //     cout << "\nInitialization error in " << X.Origin
    //     << ".\n   Inches value of " << X.Number
    //     << " is too large.";
    // }
    
    
}
