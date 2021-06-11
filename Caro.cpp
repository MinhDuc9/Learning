#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <cstdlib>
using namespace std;

void printscreen(char board[]){
    for (int i=0; i<9; i+=3)
    {
        cout << board[i]<< " " << board[i+1] << " " << board[i+2] << endl;
    }
}

int row1[3] = {1,2,3};
int row2[3] = {4,5,6};
int row3[3] = {7,8,9};

int col1[3] = {1,4,7};
int col2[3] = {2,5,8};
int col3[3] = {3,6,9}; 

int cheo1[3]={1,5,9};
int cheo2[3]={3,5,7};

int check (vector<int>a){
    int tong1 = 0, tong2 = 0, tong3 = 0, tong4 = 0, tong5 = 0, tong6 = 0, tong7 = 0, tong8 = 0;
    for (int i=0; i<a.size(); i++){
        for (int j=0; j<3; j++){
            if (a.at(i) == row1[j]){
                tong1++;
            }
            if (tong1 == 3){
                return 1;
            }
        }

        for (int j=0; j<3; j++){
            if (a.at(i) == row2[j]){
                tong2++;
            }
            if (tong2 == 3){
                return 1;
            }
        }

        for (int j=0; j<3; j++){
            if (a.at(i) == row3[j]){
                tong3++;
            }
            if (tong3 == 3){
                return 1;
            }
        }

        for (int j=0; j<3; j++){
            if (a.at(i) == col1[j]){
                tong4++;
            }
            if (tong4 == 3){
                return 1;
            }
        }

        for (int j=0; j<3; j++){
            if (a.at(i) == col2[j]){
                tong5++;
            }
            if (tong5 == 3){
                return 1;
            }
        }

        for (int j=0; j<3; j++){
            if (a.at(i) == col3[j]){
                tong6++;
            }
            if (tong6 == 3){
                return 1;
            }
        }
        
        for (int j=0; j<3; j++){
            if (a.at(i) == cheo1[j]){
                tong7++;
            }
            if (tong7 == 3){
                return 1;
            }
        }

        for (int j=0; j<3; j++){
            if (a.at(i) == cheo2[j]){
                tong8++;
            }
            if (tong8 == 3){
                return 1;
            }
        }
    }
    return 0;
}

int AI_Wining(vector<int>AI, vector<int>player){
    int random_first_move[4] = {1,3,7,9};
    srand ( time(NULL) );

    int RandIndex = rand() % 4; 
    int first_move = random_first_move[RandIndex];
    int move;
    if (AI.empty()){
        move = first_move;
    }
    else{
        move = 0;
    }
    return move;
}

int main(){
    cout << "Chao mung cac ban den voi tro choi caro!" << endl;
    cout << "Made by: Duc va Thong \n" << endl;
    cout << "Chon o so tu 1->9 trong bang de choi! \n" << endl;

    cout << "Chon che do choi (1 - Single play || 2 - Multiplay) \n" << endl;

    int option; cin >> option;
    int ordinal;

    if (option == 1){
        cout << "Di sau an phim 1 (di truoc an phim 2): " << endl;
        cin >> ordinal;
    }

    system("clear");  

    char board_fake [9] ={'1','2','3','4','5','6','7','8','9'}; 

    printscreen(board_fake);

    if (option == 2){
        vector<int>player1;
        vector<int>player2;
        for (int i=0; i<9; i++){
            if (i%2 == 0){
                cout << "Nguoi choi X di: " << endl;
                int a; cin >> a;
                player1.push_back(a);
                char temp = 'X';
                board_fake[a-1] = temp;
                if (check(player1) == 1){
                    board_fake[a-1] = temp;
                    cout << endl;
                    printscreen(board_fake);
                    cout << "Nguoi choi X thang!" << endl;
                    return 0;

                    if (i == 9){
                        cout << "Mot tran hoa!" << endl;
                        return 0;
                    }
                }
                printscreen(board_fake);
                cout << endl;
            }
            else{
                cout << "Nguoi choi O di: " << endl;
                int a; cin >> a;
                player2.push_back(a);
                char temp = 'O';
                board_fake[a-1] = temp;
                if (check(player2) == 1){
                    board_fake[a-1] = temp;
                    cout << endl;
                    printscreen(board_fake);
                    cout << "Nguoi choi O thang!" << endl;
                    return 0;
                }
                printscreen(board_fake);
                cout << endl;
            }
        }
    }
    else{
        if (ordinal == 1){
            vector<int>AI_move;
            vector<int>player;
            for (int i=0; i<9; i++){
                if (i % 2 == 0){
                    cout << "May di: " << endl;
                    int a = AI_Wining(AI_move, player);
                    char temp = 'X';
                    board_fake[a-1] = temp;
                    printscreen(board_fake);
                    AI_move.push_back(a);
                    cout << endl;
                }
                else{
                    cout << "Nguoi choi di: " << endl;
                    int a; cin >> a;
                    char temp = 'O'; 
                }
            }
        }
    }

}
