//
//  main.cpp
//  p10-4
//
//  Created by Jakob Hammond on 11/2/23.
//

#include <iostream>
using namespace std;

bool isCardValid(int digits[], int size);
int main(void){
    int digits[8];
    int size = 8;
    int number;
    
    while(true){
        cout << "Enter 8-digit credit card # or Q to quit: ";
        
        //if(cin >> number){
        cin >> number;
        if (cin.fail()) break;
        
        for(int i = 0; i < size; i++){
            digits[size - i] = number % 10;
            number /= 10;
        }
        
        if(isCardValid(digits, size)) cout << "Card is valid." << endl;
        else cout << "Card is not valid." << endl;
    //}
      //  else break;
    }
    return 1;
}

bool isCardValid(int digits[], int size){
    int firstSum = 0;
    int secondSum = 0;
    for(int i = size; i > 1; i -= 2){
        firstSum += digits[i];
    }
    for(int i = size - 1; i >= 0; i -= 2){
        int temp = digits[i] * 2;
        secondSum += temp / 10;
        secondSum += temp % 10;
    }
    
    if(firstSum + secondSum == 50) return true;
    else return false;
}
