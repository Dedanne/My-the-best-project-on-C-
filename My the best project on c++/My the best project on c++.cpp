#include <iostream>
#include <ctime>

using namespace std;

    

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

void FrameShow(MyGame* Game) {

}

void Show(MyGame* Game) {
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
int main()
{
    MyGame* Game = Create();
    Show(Game);
}


