#include<iostream>
#include<vector>
#include "boad.h"

using namespace std;

Boad::Boad()
{
    matrix[0][0]='1';
    matrix[0][1]='2';
    matrix[0][2]='3';
    matrix[1][0]='4';
    matrix[1][1]='5';
    matrix[1][2]='6';
    matrix[2][0]='7';
    matrix[2][1]='8';
    matrix[2][2]='9';
}
char Boad::geter(int i,int j){
    return matrix[i][j];
}
void Boad::drow()
{
    system("clear");
    cout << "Game ver 1.0" << endl;
    for(int i = 0;i < 3; i++){
        for(int j = 0;j < 3; j++){
        cout << matrix[i][j] << " ";
    }
    cout << endl;
    }
}
void Boad::set(char hand, char turn)
{
    if(hand == '1'){matrix[0][0] = turn;}
    else if(hand == '2'){matrix[0][1] = turn;}
    else if(hand == '3'){matrix[0][2] = turn;}
    else if(hand == '4'){matrix[1][0] = turn;}
    else if(hand == '5'){matrix[1][1] = turn;}
    else if(hand == '6'){matrix[1][2] = turn;}
    else if(hand == '7'){matrix[2][0] = turn;}
    else if(hand == '8'){matrix[2][1] = turn;}
    else if(hand == '9'){matrix[2][2] = turn;}
}

char minmax(Boad& boad){
    
    vector<char> hands;
    int val,val_max = -1,depth=1;
    char hand;
    
    // 入力可能な場所の配列handsを作成
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(boad.geter(i,j)!='O' && boad.geter(i,j)!='X'){
                hands.push_back(boad.geter(i,j));
            }
        }
    }
    // 全ての可能な手に対してmin,maxを試行する
    for(int i=0;i<hands.size();i++){
        Boad sboad;
        sboad = boad;
        sboad.set(hands[i],'X');

        val = min(sboad,depth);
        if(val>val_max){
            val = val_max;
            hand = hands[i];
        }
    }
    return hand;
}
int max(Boad& sboad, int depth){
    if(score(sboad,depth) == 0){
        depth ++;
    }else{
        return score(sboad,depth);
    }
    vector<char> hands;
     // 入力可能な場所の配列handsを作成
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sboad.geter(i,j)!='O' && sboad.geter(i,j)!='X'){
                hands.push_back(sboad.geter(i,j));
            }
        }
    }
    // 全ての可能な手に対してmaxを探索
    int val,val_max = -1;
    for(int i=0;i<hands.size();i++){
        Boad ssboad;
        ssboad = sboad;
        ssboad.set(hands[i],'X');

        val = min(ssboad,depth);
        if(val>val_max){
            val = val_max;
        }
    }
    return val_max;
}
int min(Boad& sboad, int depth){
    if(score(sboad,depth) == 0){
        depth ++;
    }else{
        return score(sboad,depth);
    }
    vector<char> hands;
     // 入力可能な場所の配列handsを作成
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sboad.geter(i,j)!='O' && sboad.geter(i,j)!='X'){
                hands.push_back(sboad.geter(i,j));
            }
        }
    }
    // 全ての可能な手に対してminを探索
    int val,val_min = 10;
    for(int i=0;i<hands.size();i++){
        Boad ssboad;
        ssboad = sboad;
        ssboad.set(hands[i],'O');

        val = min(ssboad,depth);
        if(val<val_min){
            val = val_min;
        }
    }
    return val_min;
}
int score(Boad& boad, int depth){
    if(jadge(boad,'O') == 1){
        return depth - 10;
    }else if(jadge(boad,'X') == 1){
        return 10 - depth;
    }else{
        return 0;
    }
}
void changep(char& turn){
    if(turn == player){
        turn = cpu;
    }else{
        turn = player;
    }
}
int jadge(Boad& boad, char turn){
    for(int i=0;i<3;i++){
        if(boad.geter(i,0) == turn && boad.geter(i,1)==turn && boad.geter(i,2)==turn){
            return 1;
        }
        if(boad.geter(0,i) == turn && boad.geter(1,i)==turn && boad.geter(2,i)==turn){
            return 1;
        }
    }
    if(boad.geter(0,0) == turn && boad.geter(1,1)== turn && boad.geter(2,2) == turn){
        return 1;
    }
    if(boad.geter(2,0) == turn && boad.geter(1,1)== turn && boad.geter(0,2) == turn){
        return 1;
    }
    return 0;
}
void input(Boad& boad, char turn){
    int a;
    cout << "press the number of the field:";
    cin >> a;
    if(a == 1){
        if(boad.geter(0,0) == '1'){
            boad.set('1',turn);
            char b = boad.geter(0,0);
            cout << b << endl;
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==2){
        if(boad.geter(0,1) == '2'){
            boad.set('2',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
            }
    }else if(a ==3){
        if(boad.geter(0,2) == '3'){
            boad.set('3',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==4){
        if(boad.geter(1,0) == '4'){
            boad.set('4',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==5){
        if(boad.geter(1,1) == '5'){
            boad.set('5',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==6){
        if(boad.geter(1,2) == '6'){
            boad.set('6',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==7){
        if(boad.geter(2,0) == '7'){
            boad.set('7',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==8){
        if(boad.geter(2,1) == '8'){
            boad.set('8',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else if(a ==9){
        if(boad.geter(2,2) == '9'){
            boad.set('9',turn);
        }else{
            cout << "already field. try agein." << endl;
            input(boad,turn);
        }
    }else{
        cout << "already field. try agein." << endl;
        input(boad,turn);
    }    
}