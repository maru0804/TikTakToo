#include<iostream>

using namespace std;
char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
char player='X';
void Draw()
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
void Input()
{
    int a;
    cout << "press the number of the field:";
    cin >> a;
    if(a == 1){
        if(matrix[0][0] == '1'){
            matrix[0][0] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==2){
        if(matrix[0][1] == '2'){
            matrix[0][1] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==3){
        if(matrix[0][2] == '3'){
            matrix[0][2] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==4){
        if(matrix[1][0] == '4'){
            matrix[1][0] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==5){
        if(matrix[1][1] == '5'){
            matrix[1][1] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==6){
        if(matrix[1][2] == '6'){
            matrix[1][2] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==7){
        if(matrix[2][0] == '7'){
            matrix[2][0] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==8){
        if(matrix[2][1] == '8'){
            matrix[2][1] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else if(a ==9){
        if(matrix[2][2] == '9'){
            matrix[2][2] = player;
        }else{
            cout << "already field. try agein." << endl;
            Input();
        }
    }else{
        cout << "already field. try agein." << endl;
        Input();
    }
}
void TogglePlayer(){
    if(player == 'X'){
        player = 'O';
    }else{
        player = 'X';
    }
}
char Win(){
    for(int i = 0;i < 3;i++){
            if(matrix[i][0] == 'X' && matrix[i][1]== 'X' && matrix[i][2] == 'X'){
                return 'X';
            }
            if(matrix[i][0] == 'O' && matrix[i][1]== 'O' && matrix[i][2] == 'O'){
                return 'O';
            }
            if(matrix[0][i] == 'X' && matrix[1][i]== 'X' && matrix[2][i] == 'X'){
                return 'X';
            }
            if(matrix[0][i] == 'O' && matrix[1][i]== 'O' && matrix[2][i] == 'O'){
                return 'O';
        }
    }
    if(matrix[0][0] == 'X' && matrix[1][1]== 'X' && matrix[2][2] == 'X'){
                return 'X';
            }
    if(matrix[0][0] == 'O' && matrix[1][1]== 'O' && matrix[2][2] == 'O'){
                return 'O';
            }
    if(matrix[2][0] == 'X' && matrix[1][1]== 'X' && matrix[0][2] == 'X'){
                return 'X';
            }
    if(matrix[2][0] == 'O' && matrix[1][1]== 'O' && matrix[0][2] == 'O'){
                return 'O';
            }
    return '/';
}
int main()
{  
    int cnt = 0;
    Draw();
    while(1){
        Input();
        Draw();
        if(Win() == 'X'){
            cout << "X win !!!" << endl;
            break;
        }else if(Win() == 'O'){
            cout << "O win !!!" << endl;
            break;
        }
        TogglePlayer();
        cnt ++;
        if(cnt == 9){
            cout << "DLOW ..." << endl;
            break;
        }
    }
    return 0;
}