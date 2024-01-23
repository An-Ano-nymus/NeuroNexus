#include <iostream>
using namespace std;

class TicTacToe{
    
    char player1='O';
    char player2='X';
    char board[3][3]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
     };
    

    
    void player1_turn(){
        MARKER:
        int i, j;
        cout << "ENTER LOCATION TO ENTER O\n" << "RANGE FROM 0,0 to 2,2: ";
        cin >> i >> j;
        if(board[i][j]=='X' || board[i][j]=='O' || ( i>2 || j>2 || i<0 || j<0 )){
            cout<<"WRONG POSITION RE_ENTER\n";
            goto MARKER;
        }else{
            board[i][j] = player1;
        }
    
    }
    
    void player2_turn(){
        MARKER:
        int i, j;
        cout << "ENTER LOCATION TO ENTER X\n" << "RANGE FROM 0,0 to 2,2: ";
        cin >> i >> j;
        if(board[i][j]=='X' || board[i][j]=='O' || ( i>2 || j>2 || i<0 || j<0 )){
            cout<<"WRONG POSITION RE_ENTER\n";
            goto MARKER;
        }else{
            board[i][j] = player2;
        }
    }
    
    bool checkWinner(char player) {
        
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                cout << "Player " << player << " WINS!" << endl;
                return true;
            }
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                cout << "Player " << player << " WINS!" << endl;
                return true;
            }
        }
        
        
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            cout << "Player " << player << " WINS!" << endl;
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            cout << "Player " << player << " WINS!" << endl;
            return true;
        }

        return false;
    }
    
    bool isBoardFull() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void DISPLAY(){
        cout << "-------------" << endl;
        for (int i = 0; i < 3; i++){
            cout << "| ";
            for (int j = 0; j < 3; j++){
                cout << board[i][j] << " | ";
            }
            cout << endl << "-------------" << endl;
        }
    }
    public:
    void newgame(){
        while (true){
            DISPLAY();
            player1_turn();
            if (checkWinner(player1) || isBoardFull()) {
    
                break;
            }

            DISPLAY();
            player2_turn();
            if (checkWinner(player2) || isBoardFull()) {

                break;
            }
        }
        cout << "GAME OVER" << endl;
    }
};

int main(){
    TicTacToe A;
    A.newgame();
    return 0;
}