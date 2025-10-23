#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
//#include <string.h>
#include <cstring>

void print_table_ref(int (&arr)[25]){
    for(int i = 0; i < 25; i ++){
        if( i % 5 == 0){
            std::cout << "|";
        }

        if( arr[i] < 10){
            std::cout << "0" << arr[i] << "|";
        } else {
            std::cout << arr[i] <<"|";
        }

        if( i % 5 == 4){
            std::cout << std::endl;
        }
    }
}

void print_table_ptr(const int* arr){
    for(int i = 0; i < 25; i ++){
        if (i % 5 == 0){
            std::cout << "|";
        }
        
        if (*(arr + i) < 10) {
            std::cout << "0" << *(arr + i) <<"|";
        } else {
            std::cout << *(arr + i) << "|";
        }
         
        if(i % 5 == 4){
            std::cout << std::endl;
        }
    }
}

int main(int argc, char* argv[]){
    int arr1[25];
    int number;
    bool dup_flag = 0;
    memset(arr1, 0, 25);
    //srand(25);
    srand(static_cast<int>(time(NULL)));
    for (int i = 0; i < 25; i++){
        dup_flag = 0;
        number = rand() % 25 + 1;
        if (i != 0){
            for (int j = 0; j < i; j ++){
                if (number == arr1[j]){
                    dup_flag = 1;
                    //continue; 
                    break;
                }
            }
        }
        if (dup_flag == 1){
            i --;
            continue;
        }
        arr1[i] = number;
    }
    
    //print_table_ptr(arr1);
    //std::cout<<std::endl;
    print_table_ref(arr1);
    
    return 0;    
}