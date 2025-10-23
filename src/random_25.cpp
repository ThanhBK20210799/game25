#include <iostream>
#include <time.h>
#include <stdlib.h>

int main(){
    int i = 0;
    int j = 0;
    int x = 0;
    bool flip_bit = 0;
    int arr[25];
    srand(time(NULL));
    for (int i = 0; i < 25; i++){
        flip_bit = 0; 
        if (i % 5 == 0) std::cout<<"|";
        x = rand() % 25 + 1;
        if (i != 0){
            for (int j = 0; j < (i - 1); j++){
                if (x == arr[j]){
                    flip_bit = 1;
                    continue;
                }

            }
        }
        if(flip_bit == 1){
            continue;
        }
        arr[i] = x;
        if (x < 10){
            //std::cout<<"|"<< "0"<<x<<"|";
            std::cout<< "0"<<x<<"|";
        } else {
            //std::cout<<"|"<< x <<"|";
            std::cout<< x <<"|";
        }
        if (i % 5 == 4) std::cout<< std::endl;
    }
    getchar();
    return 0;
}
    
