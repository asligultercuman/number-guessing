#include <iostream>
#include <time.h>
using namespace std;

int num = 0;

class Player{
    
    public:
    int chance;
    Player(int level){

        if (level == 1)
            chance = 10;
        else if(level == 2)
            chance = 7;
        else if(level == 3)
            chance = 5;
        else
            exit(-1);//düzelt
    }        
};

int control(int quess, Player *p1){

    if( quess < 1 || quess > 100 ){
        cout << "\nInvalid type. Quess a positive number (1-100)";
        return 0; 
    }

    if(quess == num) 
        cout << "\nYou win";
    else if(quess > num)
        cout << "\nIt is smaller than your guess";
    else if(quess < num)
        cout << "\nIt is greater than your guess"; 
    
    p1->chance--;
}

int main(){

    srand(time(NULL));
    num = (rand() % 100) + 1; // 1-100

    int level;
    cout << "Choose a difficulty level (1-3) ";
    cin >> level;

    Player p(level);

    while( p.chance != 0){

        int quess;
        cout << "\nQuess the number ";
        cin >> quess;

        control(quess, &p);
    }

    return 0;
}