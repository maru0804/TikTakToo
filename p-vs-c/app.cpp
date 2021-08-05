#include<iostream>
#include "boad.h"

using namespace std;
char turn;

int main(){
    int a, win,cnt=0;
    char hand;
    cout << "先攻後攻の選択(先攻 > 1 : 後攻 > 2) > ";
    cin >> a;
    if(a == 1){
        turn = player;
    }else{
        turn = cpu;
    }
    Boad boad;
    boad.drow();
    while(true){
        if(turn == player){
            input(boad, turn);
            boad.drow();
            win = jadge(boad,turn);
            if(win == 1){
                cout << "you win this game!" << endl;
                break;
            }
            changep(turn);
            cnt ++;
        }else{
            hand = minmax(boad);
            boad.set(hand,turn);
            boad.drow();
            win = jadge(boad,turn);
            if(win == 1){
                cout << "you lose this game!" << endl;
                break;
            }
            changep(turn);
            cnt ++;
        }
        
        if(cnt == 9){
            cout << "DLOW ..." << endl;
            break;
        }
    }
    
    cout << "sccess" << endl;
    return 0;
}