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

}



void Logic(MyGame*Game) {
    if (_kbhit()) {
        switch (_getch()) {
           
            case SPACE:
                Checker = true;
                break;

            case UP:
                Game->snake->y--;
                
                break;

            case DOWN:
                Game->snake->y++;
                break;

            case RIGHT:
                Game->snake->x++;
                break;

            case LEFT:
                Game->snake->x--;
                break;
}
    }
    if (Game->snake->x == Game->fruit->x and Game->snake->y == Game->fruit->y) {
        Game->fruit->x = rand() % 39 + 1;
        Game->fruit->y = rand() % 19 + 1;
    }
    if (Game->snake->x == 0 or Game->snake->y == 0 or Game->snake->x == Game->field->x or Game->snake->y == Game->field->y)
        Checker = true;
    

}

int main()
{
        MyGame* Game = Create();
    while (!Checker) {
        Show(Game);
        Logic(Game);
    }
    
}


