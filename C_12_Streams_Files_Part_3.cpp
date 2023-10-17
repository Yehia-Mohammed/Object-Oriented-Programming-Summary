#include<iostream> // The iostream class is derived from both istream and ostream by multiple inheritance.
#include<fstream> // For file I/O which is derived from iostream
#include<iomanip>
#include<string>
using namespace std;
/*----- Chapter 12 Streams and Files Part_3 -----*/
class Player {
protected: 
    long long ID; 
    char Name[50]; // Must Be Array of Characters -> Note(fstream with Objects.pdf)
public:
    friend istream& operator >> (istream&Input, Player&player);
    friend ostream& operator << (ostream&Output, Player&player);
    void DiskIn(int N);
    void DiskOut();
    static int DiskCount();
};
istream& operator >> (istream&Input, Player&player)
{
    cout << "Enter Player ID "; cin >> player.ID;
    cout << "Enter Player Name "; cin >> player.Name;
    return Input;
}
ostream& operator << (ostream&Output, Player&player)
{
    cout << "\nID : " << player.ID << "\nName : " << player.Name << '\n';
    return Output;
}
void Player::DiskIn(int N) // Read Player Number N From The File
{
    ifstream In;
    In.open("C:/Users/User/Desktop/PLAYERS.DAT", ios::binary);
    In.seekg(N * sizeof(Player));
    In.read((char*)this, sizeof(*this));
}
void Player::DiskOut() // Write Player To The End of The File
{
    ofstream Out;
    Out.open("C:/Users/User/Desktop/PLAYERS.DAT", ios::app | ios::binary);
    Out.write((char*)this, sizeof(*this));
}
int Player::DiskCount()
{
    ifstream In;
    In.open("C:/Users/User/Desktop/PLAYERS.DAT", ios::binary);
    In.seekg(0, ios::end);
    return In.tellg() / sizeof(Player);
}
int main()
{
    Player Vector; char ch;
    do
    {
        cout << "Enter Data For PLayer\n";
        cin >> Vector;
        Vector.DiskOut();
        cout << "Enter another Player (y/n)? "; cin >> ch;
    } while (ch == 'y');
    int N = Player::DiskCount();
    cout << "There is " << N << " Player\\s in The Game ";
    for (int i = 0; i < N; i++)
    {
        Vector.DiskIn(i);
        cout << Vector;
    }
    /*---------- #We_Look_Towards_Excellence🤍✨ ----------*/
}