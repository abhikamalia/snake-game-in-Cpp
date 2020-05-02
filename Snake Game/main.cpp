//A console snake game...
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <conio.h>
#include <windows.h>
//#include <graphics.h>
using namespace std;

int tail_x[100];
int tail_y[100];
int tail_length;
const int width = 20;
const int height =20;
bool gameOver;
int x , y , foodx , foody , score;
enum direction {STOP = 0 , UP , DOWN , LEFT , RIGHT};
direction dir;

//Boulders class
class Boulders{
    public:
        void Map1();
        void Map2();
        void Map3();
        void Logic1();
        void Logic2();
        void Logic3();
};
//snake class
class Snake : public Boulders{
    public:
        Snake();
        void Map();
        void Input();
        void Logic();
};

//snake class constructor...
Snake :: Snake(){
    srand(time(0));
    gameOver = false;
    x = width / 2;
    y = height / 2;
    foodx = (rand() % width) + 1;
    foody = (rand() % height) + 1;
    score = 0;

}

//Logic3 function for Boulders.....
void Boulders :: Logic3(){
     int previous_x = tail_x[0] , previous_y = tail_y[0];
    int previous_x2  , previous_y2;
    tail_x[0] = x ; tail_y[0] = y;
    for(int i = 1 ; i <  tail_length ; i++){

        previous_x2 = tail_x[i];
        previous_y2 = tail_y[i];
        tail_x[i] = previous_x;
        tail_y[i] = previous_y;
        previous_x = previous_x2;
        previous_y = previous_y2;
    }

    switch(dir){
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
    }
    if(x <= 0) x = width;
    else if(x >= width) x = 0;

    if(y <= 0) y = height;
    else if(y >= height) y = 0;

    for(int k = 0 ; k < tail_length ; k++){
        if(tail_x[k] == x && tail_y[k] == y){
        	cout << "The snake bit itself...." << endl;
        	cout << "......GAME OVER......" << endl;
            gameOver = true;
        }
    }

    if(x == foodx && y == foody){
        foodx = (rand() % width - 1) + 1;
        foody = (rand() % height - 1) + 1;
        score++;
        tail_length++;
    }
    if((y >= 6 && x == 6) && (y <= 12 && x == 6) || (y >= 6 && x == 12) && (y <= 12 && x == 12)){
        cout << "The Snake thrashed with the Bolders...." << endl;
        cout << "GAME OVER" << endl;
        gameOver = true;
    }
}


//Map3 function for Boulders....
void Boulders :: Map3(){
    system("cls");
    cout << "---- SNAKE GAME ----" << endl;
    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(j == 0){
                cout << "#";
            }

            if(i == y && j == x){
                cout << "O";
            }
            else if((foodx == j && foody == i) || ((foody <= 6 && foodx == 6) && (foody >= 12 && foodx == 6))|| ((foody <= 6 && foodx == 14) && (foody >= 12 && foodx == 14))){
                cout << "*";
            }
            else if(((i >= 6 && j == 6) && (i <= 12 && j == 6)) || ((i >= 6 && j == 12) && (i <= 12 && j == 12))){
                cout << "#";
            }
            else{
                bool okay = false;
                for(int k = 0 ; k < tail_length ; k++){
                    if(tail_x[k] == j && tail_y[k] == i){
                        cout << 'o';
                        okay = true;
                    }
                }
                if(!okay){
                    cout << " ";
                }
            }
            if(j == width - 1){
                cout << "#";
            }
        }cout << endl;
    }

    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;
    cout << "Score : " << score << endl;
}


//Logic2 function for Boulders
void Boulders :: Logic2(){
     int previous_x = tail_x[0] , previous_y = tail_y[0];
    int previous_x2  , previous_y2;
    tail_x[0] = x ; tail_y[0] = y;
    for(int i = 1 ; i <  tail_length ; i++){

        previous_x2 = tail_x[i];
        previous_y2 = tail_y[i];
        tail_x[i] = previous_x;
        tail_y[i] = previous_y;
        previous_x = previous_x2;
        previous_y = previous_y2;
    }

    switch(dir){
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
    }
    if(x <= 0) x = width;
    else if(x >= width) x = 0;

    if(y <= 0) y = height;
    else if(y >= height) y = 0;

    for(int k = 0 ; k < tail_length ; k++){
        if(tail_x[k] == x && tail_y[k] == y){
        	cout << "The snake bit itself...." << endl;
        	cout << "......GAME OVER......" << endl;
            gameOver = true;
        }
    }

    if(x == foodx && y == foody){
        foodx = (rand() % width - 1) + 1;
        foody = (rand() % height - 1) + 1;
        score++;
        tail_length++;
    }
    if((y == 4 && x >= 3) && (y == 4 && x <= 6) || (y == 4 && x >= 13) && (y == 4 && x <= 16) || (y == 15 && x >= 3) && (y == 15 && x <= 6) || (y == 15 && x >= 13) && (y == 15 && x <= 16)){
        cout << "The Snake thrashed with the Bolders...." << endl;
        cout << "GAME OVER" << endl;
        gameOver = true;
    }
}

//Map2 function for Boulders....
void Boulders :: Map2(){
    system("cls");
    cout << "---- SNAKE GAME ----" << endl;
    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(j == 0){
                cout << "#";
            }

            if(i == y && j == x){
                cout << "O";
            }
            else if((foodx == j && foody == i) || ((foody != 4 && foodx <= 3) && (foody != 4 && foodx >= 6)) || ((foody != 4 && foodx <= 13) && (foody != 4 && foodx >= 16)) || ((foody != 15 && foodx <= 3) && (foody != 15 && foodx >= 6)) || ((foody != 15 && foodx <= 13) && (foody != 15 && foodx >= 16))){
                cout << "*";
            }
            else if(((i == 4 && j >= 3) && (i == 4 && j <= 6)) || ((i == 4 && j >= 13) && (i == 4 && j <= 16)) || ((i == 15 && j >= 3) && (i == 15 && j <= 6)) || ((i == 15 && j >= 13) && (i == 15 && j <= 16)) ){
                cout << "#";
            }
            else{
                bool okay = false;
                for(int k = 0 ; k < tail_length ; k++){
                    if(tail_x[k] == j && tail_y[k] == i){
                        cout << 'o';
                        okay = true;
                    }
                }
                if(!okay){
                    cout << " ";
                }
            }
            if(j == width - 1){
                cout << "#";
            }
        }cout << endl;
    }

    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;
    cout << "Score : " << score << endl;
}

//Logic1 function for Boulders...
void Boulders :: Logic1(){
     int previous_x = tail_x[0] , previous_y = tail_y[0];
    int previous_x2  , previous_y2;
    tail_x[0] = x ; tail_y[0] = y;
    for(int i = 1 ; i <  tail_length ; i++){

        previous_x2 = tail_x[i];
        previous_y2 = tail_y[i];
        tail_x[i] = previous_x;
        tail_y[i] = previous_y;
        previous_x = previous_x2;
        previous_y = previous_y2;
    }

    switch(dir){
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
    }
    if(x <= 0) x = width;
    else if(x >= width) x = 0;

    if(y <= 0) y = height;
    else if(y >= height) y = 0;

    for(int k = 0 ; k < tail_length ; k++){
        if(tail_x[k] == x && tail_y[k] == y){
        	cout << "The snake bit itself...." << endl;
        	cout << "......GAME OVER......" << endl;
            gameOver = true;
        }
    }

    if(x == foodx && y == foody){
        foodx = (rand() % width - 1) + 1;
        foody = (rand() % height - 1) + 1;
        score++;
        tail_length++;
    }
    if(((y == 10 && x >= 3) && (y == 10 && x <= 6)) || ((y == 10 && x >= 13) && (y == 10 && x <= 16)) ){
        cout << "The Snake thrashed with the Bolders...." << endl;
        cout << "GAME OVER" << endl;
        gameOver = true;
    }
}
//Map1 function for Boulders...
void Boulders :: Map1(){
    system("cls");
    cout << "---- SNAKE GAME ----" << endl;
    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(j == 0){
                cout << "#";
            }

            if(i == y && j == x){
                cout << "O";
            }
            else if((foodx == j && foody == i) || ((foody != 10 && foodx <= 3) && (foody != 10 && foodx >= 6)) || ((foody != 10 && foodx <= 13) && (foody != 10 && foodx >= 16))){
                cout << "*";
            }
            else if(((i == 10 && j >= 3) && (i == 10 && j <= 6)) || ((i == 10 && j >= 13) && (i == 10 && j <= 16)) ){
                cout << "#";
            }
            else{
                bool okay = false;
                for(int k = 0 ; k < tail_length ; k++){
                    if(tail_x[k] == j && tail_y[k] == i){
                        cout << 'o';
                        okay = true;
                    }
                }
                if(!okay){
                    cout << " ";
                }
            }
            if(j == width - 1){
                cout << "#";
            }
        }cout << endl;
    }

    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;
    cout << "Score : " << score << endl;
}

//Input function to input keys from keyboard in snake class....
void Snake :: Input(){
    if(_kbhit()){
        switch(_getch()){
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x' :
            	cout << ".....GAME OVER....." << endl;
                gameOver = true;
                break;
        }
    }

}


//Default Map function ..if none of the map is choosen .....without Bolders...
void Snake :: Map(){
    system("cls");
    cout << "---- SNAKE GAME ----" << endl;
    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(j == 0){
                cout << "#";
            }
            if(i == y && j == x){
                cout << "O";
            }
            else if(foodx == j && foody == i){
                cout << "*";
            }
            else{
                bool okay = false;
                for(int k = 0 ; k < tail_length ; k++){
                    if(tail_x[k] == j && tail_y[k] == i){
                        cout << 'o';
                        okay = true;
                    }
                }
                if(!okay){
                    cout << " ";
                }
            }
            if(j == width - 1){
                cout << "#";
            }
        }cout << endl;
    }

    for(int i = 0 ; i <= width + 1 ; i++){
        cout << "#";
    }cout << endl;
    cout << "Score : " << score << endl;


}

//Default Logic function ....in snake class
void Snake :: Logic(){
    int previous_x = tail_x[0] , previous_y = tail_y[0];
    int previous_x2  , previous_y2;
    tail_x[0] = x ; tail_y[0] = y;
    for(int i = 1 ; i <  tail_length ; i++){

        previous_x2 = tail_x[i];
        previous_y2 = tail_y[i];
        tail_x[i] = previous_x;
        tail_y[i] = previous_y;
        previous_x = previous_x2;
        previous_y = previous_y2;
    }

    switch(dir){
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
    }
    if(x <= 0) x = width;
    else if(x >= width) x = 0;

    if(y <= 0) y = height;
    else if(y >= height) y = 0;

    for(int k = 0 ; k < tail_length ; k++){
        if(tail_x[k] == x && tail_y[k] == y){
        	cout << "The snake bit itself...." << endl;
        	cout << "......GAME OVER......" << endl;
            gameOver = true;
        }
    }

    if(x == foodx && y == foody){
        foodx = (rand() % width - 1) + 1;
        foody = (rand() % height - 1) + 1;
        score++;
        tail_length++;
    }
}
/*void Setup(){
    srand(time(0));
    gameOver = false;
    x = width / 2;
    y = height /2;
    foodx = (rand() % width ) + 1;
    foody = (rand() % height ) + 1;
    score = 0;
}*/


int main()
{
    //initwindow(800 , 800);
    //setbkcolor(3);
    //Setup();
    Snake s;
    //Bolders b;
    cout << "---- SNAKE GAME ----" << endl;
    int choose , choose_map;
    cout << "Without Bolders (0) or With Bolders (1)";
    cin >> choose;
    if(choose == 1){
        cout << "Choose Map" << endl;
        cout << "Map 1 (two bolders) (1)" << endl;
        cout << "Map 2 (four bolders (2))" << endl;
        cout << "Map 3 (two vertical bolders (3))" << endl;
        cin >> choose_map;
        switch(choose_map){
            case 1:
                while(!gameOver){//loop until gameOver is true...
                    s.Map1();
                    s.Input();
                    s.Logic1();
                    Sleep(10);
                }
                break;
            case 2:
                while(!gameOver){//loop until gameOver is true...
                    s.Map2();
                    s.Input();
                    s.Logic2();
                    Sleep(10);
                }
                break;
            case 3:
                while(!gameOver){//loop until gameOver is true...
                    s.Map3();
                    s.Input();
                    s.Logic3();
                    Sleep(10);
                }
                break;

        }
    }
    else{
        while(!gameOver){//loop until gameOver is true...
            s.Map();
            s.Input();
            s.Logic();
            Sleep(10);
    }
    }


    return 0;
}









/*#include <iostream>
#include <cstdlib>
#include<ctime>
#include<conio.h>
#include <windows.h>

using namespace std;
int tailx[100] , taily[100];//the arrays to keep track of the tail....it means the coordinates of o is stored in this arrays...
int tail_length = 0;
bool gameOver;//to check if the game is over or not.......
const int width = 20;//width of the game.....
const int height = 20;//height of the game .....
int  x , y , foodx , foody , score;//x and y are the coordinated of the snake...
//foodx and foody are the coordinates of the food.....
enum direction{STOP = 0 , UP , DOWN , LEFT , RIGHT};//enum is used to give direction to the snake....
direction dir;//enum variable...
int s = 30;
void Logic(){

    int prevx = tailx[0];
    int prevy = taily[0];
    int prevx2 , prevy2;
    tailx[0] = x;
    taily[0] = y;
    for(int i = 1 ; i < tail_length ; i++){
        prevx2 = tailx[i];
        prevy2 = taily[i];
        tailx[i] = prevx;
        taily[i] = prevy;
        prevx = prevx2;
        prevy = prevy2;
    }
    switch(dir){
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case STOP:
            break;
    }
    if(x > width || x < 0 || y > height || y < 0){
        gameOver = true;

    }
    if(x >= width){x = 0;}
    else if (x <= 0){x = width;}

    if(y >= height){y = 0;}
    else if (y <= 0){y = height;}

    for(int k = 0 ; k < tail_length ; k++){
        if(tailx[k] == x && taily[k] == y){
            gameOver = true;
        }
    }

    if(x == foodx && y == foody){//if the snake eats the food increase the score and place another food in a random place....
        score++;
        foodx = rand() % width;
        foody = rand() % height;
        tail_length++;

        if(tail_length >= 3 || tail_length >= 5 || tail_length >= 7 || tail_length >= 9 || tail_length >= 11 || tail_length >= 13){
            s = s - 5;
        }
    }
}

void Input(){
    if(_kbhit()){//if any character from the keyboard is pressed....then do this...
        switch(_getch()){
            case 'w':
                dir = UP;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 'x':
                gameOver = true;
                break;
        }
    }
}

void Map(){
    system("cls");
    for(int i = 0 ; i < width + 2 ; i++){

        cout << "#";
    }cout << endl;

    for(int i = 0 ; i < height ; i++){
        for(int j = 0 ; j < width ; j++){
            if(j == 0){//the first column to be a symbol #...
                cout << "#";
            }
            if(i == y && j == x){//if the coordinates of snake is matched ....it is printed there...
                cout << "O";
            }
            else if(i == foody && j == foodx){//when the coordinates of food is matched ....it is printed.....
                cout << "F";
            }
            else{
                bool print = false;
                for(int k = 0 ; k < tail_length ; k++){
                    if(tailx[k] == j && taily[k] == i){
                        cout << 'o';
                        print = true;
                    }
                }
                if(!print){
                    cout << " ";// or else just print the blank space....
                }

            }
            if(j == width-1){//this checks if the whole row is completed ....then print #
                cout << "#";
            }

        }cout << endl;
    }

    for(int i = 0 ; i < width + 2; i++){

        cout << "#";
    }cout << endl;
    cout << "Score : " << score;
}

void Setup(){
    srand(time(0));
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    foodx = rand() % width;
    foody = rand() % height;
    cout << foodx;
    score = 0;
}

int main()
{
    Setup();
    while(!gameOver){//if the game is on.....it means if gameover variable is not false...
        Map();
        Input();
        Logic();
        Sleep(s);//time delay...speed in short
    }
    return 0;
}*/
