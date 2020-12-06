#include <iostream>
#include <ctime>
#include <conio.h>

using namespace std;

#define SPACE 32
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77



struct Field {
    int x;
    int y;
    char show=' ';
};
struct Fruit {
    int x;
    int y;
    char show='$';
};

struct Snake {
    int x;
    int y;
    char show='0';
};

struct MyGame {
    Field* field;
    Fruit* fruit;
    Snake* snake;
};

bool Checker;
int Turn;
int Counter;

MyGame*Create() {
    srand(time(NULL));

    MyGame* Game = new MyGame;
    Game->field = new Field;
    Game->fruit = new Fruit;
    Game->snake = new Snake;

    Game->field->x = 40;
    Game->field->y = 20;

    Game->snake->x = Game->field->x / 2-1;
    Game->snake->y = Game->field->y / 2-1;

    Game->fruit->x = rand() % Game->field->x + 1;
    Game->fruit->y = rand() % Game->field->y + 1;

    return Game;
}

void Show(MyGame* Game) {
    system("cls");
    for (int i = 0; i <= Game->field->x; i++)
        cout << "#";
    cout << endl;
    for (int j = 0; j < Game->field->y; j++) {
        for (int i = 0; i < Game->field->x; i++) {
            if (i == 0 or i == Game->field->x - 1)
                cout << "#";
            if (i == Game->snake->x and j == Game->snake->y)
                cout << Game->snake->show;
            else if (i == Game->fruit->x and j == Game->fruit->y)
                cout << Game->fruit->show;
            else cout << " ";
        }
        cout << endl;
    }
    for (int i = 0; i <= Game->field->x; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << Counter;

}



int Logic(MyGame*Game) {
    if (_kbhit()) {
        switch (_getch()) {
           
            case SPACE:
                Checker = true;
                break;

            case UP: 
                 return Turn = 1;
              break;

            case DOWN:
                
                Turn = 2;
                break;

            case RIGHT:
                
                Turn = 3;
                break;

            case LEFT:
                
                Turn = 4;
                break;
}
    }
    if (Game->snake->x == Game->fruit->x and Game->snake->y == Game->fruit->y) {
        Counter += 10;
        Game->fruit->x = rand() % 38 + 1;
        Game->fruit->y = rand() % 18 + 1;
    }
    if (Game->snake->x == -1 or Game->snake->y == -1 or Game->snake->x == Game->field->x or Game->snake->y == Game->field->y)
        Checker = true;
    if (Game->snake->x == Game->fruit->x and Game->snake->y == Game->fruit->y)
        Counter += 10;
}

int main()
{

    MyGame* Game = Create();
    while (!Checker) {
        Show(Game);
        Logic(Game);
        if (Turn == 1) 
            Game->snake->y--;
            if (Turn == 2)
                Game->snake->y++;
            if (Turn == 3)
                Game->snake->x++;
            if (Turn == 4)
                Game->snake->x--;
            
        
    }
}
