#include <raylib.h>
#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <exception>

#define PERFECT_SQUARE 25
#define NUMBER static_cast<int>(std::sqrt(PERFECT_SQUARE))
#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800

// program display a screen with 25 tiles with number 0 to 25 
// scatter over all tiles 

/*@brief: make an array which have 25 
 *@param: int& arr to return to that arr
 *@ret  : int& arr
 *@
 */
int* createArray(){
    bool dup_flag = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    int* temp = new int[PERFECT_SQUARE];
    srand(static_cast<unsigned int>(time(NULL)));
    //srand(25);
    for (i = 0; i < PERFECT_SQUARE;){
        dup_flag = 0;
        x = rand() % 25 + 1;
        if (i != 0){
            for (j = 0; j < i; j++){
                if(temp[j] == x){
                    dup_flag = 1;
                    break;
                }
            }
        }
        if (dup_flag != 1){
            temp[i++] = x;   
        }
    }
    return temp;  
};  

void display_table_1(int* arr){
    int i = 0;
    int j = 0;
    for (i = 0; i < PERFECT_SQUARE; i ++) {
        if (i % NUMBER == 0) std::cout << "|";
        if (arr[i] < 10) std::cout<< "0"<< arr[i]<<"|";
        else{
            std::cout<< arr[i]<<"|";
        }
        if (i % NUMBER == (NUMBER - 1 )) std::cout << std::endl;
    }   
};

void DrawMap25tiles(){
    Rectangle RectangleArray[PERFECT_SQUARE];
    int* temp = new int[PERFECT_SQUARE];
    temp = createArray();
    for(int x = 150; x <=650; x+=100){
        //int y = x;
        DrawLine(x, 150, x, 650, WHITE);// column
        DrawLine(150, x, 650, x, WHITE);// row
    }
    DrawRectangle(150, 150, 500, 500, RED);    
    for(int i = 0; i < PERFECT_SQUARE; i ++){
        
    }
};

void drawMonitor(){
    
    InitWindow(800, 800, "Game with 25 tiles");
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        DrawMap25tiles();
        EndDrawing();
    }
    CloseWindow();
};



int main(){
    int* arr1;
    //memset(arr1, 0, PERFECT_SQUARE*sizeof(int));// crash because of memset, go with pointer

    try{
        arr1 = createArray();
    } catch(...){
        std::cout<< "something wrong 1"<<std::endl;
    }
    try{
        display_table_1(arr1);
    } catch(...){
        std::cout<< "something wrong 2"<<std::endl;
    }
    drawMonitor();
    //drawMap25tiles();
    delete[]arr1;
    return 0;
}
