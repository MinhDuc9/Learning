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

int Ai_sm(vector<int>player){
	int a = player.at(0);
	if (a == 2 || a == 3 || a == 6 || a == 9){
		return 7;
	}
	else if (a == 4 || a == 7 || a == 8){
		return 3;
	}
	else{
		return 9;
	}
}

int Ai_tm(vector<int>player){
	int a = player.at(0);
    int b = player.at(1);

	if (a == 2 || a == 3){
        if (b == 4){
            return 9;
        }
        else{
            return 4;
        }
	}

    else if (a == 6){
        if (b == 4){
            return 5;
        }
        else{
            return 4;
        }
    }

    else if (a == 9){
        if (b == 4){
            return 3;
        }
        else{
            return 4;
        }
    }


    else if (a == 4 || a == 7){
        if (b == 2){
            return 9;
        }
        else{
            return 2;
        }
    }

    else if (a == 8){
        if (b == 2){
            return 5;
        }
        else{
            return 2;
        }
    }

    else if (a == 5){
        //truong hop cheo - chien thang
        if (b == 7){
            return 3;
        }
        else if (b == 3){
            return 7;
        }
        
        // doc - tran hoa
        else if (b == 2){
            return 8;
        }
        else if (b == 8){
            return 2;
        }
        
        // ngang - tran hoa
        else if (b == 4){
            return 6;
        }
        else{
            return 4;
        }
    }
}

int Ai_fm(vector<int>player){
    int a = player.at(0);
    int b = player.at(1);
    int c = player.at(2);

    if (a == 2 || a == 3){
        if (c == 8){
            return 5;
        }
        else{
            return 8;
        }
    }

    if (a == 6){
        if (c == 3){
            return 9;
        }
        else{
            return 3;
        }
    }

    if (a == 9){
        if (c == 5){
            return 2;
        }
        else{
            return 5;
        }
    }

    if (a == 4 || a == 7){
        if (c == 5){
            return 6;
        }
        else{
            return 5;
        }
    }

    if (a == 8){
        if (c == 7){
            return 9;
        }
        else{
            return 7;
        }
    }

    // if (a == 5){
    //     if (b == 7){
    //         if (c == 2){
    //             return 6;
    //         }
    //         else{
    //             return 2;
    //         }
    //     }

    //     else if (b == 2){
    //         return 
    //     }
    // }
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

    system("cls");  

    char board_fake [9] ={'1','2','3','4','5','6','7','8','9'}; 

    printscreen(board_fake);
    cout << endl;

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
					char temp = 'X';
                    if (i == 0){
						AI_move.push_back(1);
						board_fake[0] = temp;
						cout << "May di: " << 1 << endl;
						printscreen(board_fake);
					}
					
					else if (i == 2){
						int a = Ai_sm(player);
						AI_move.push_back(a);
						board_fake[a-1] = temp;
						cout << "May di: " << a << endl;
						printscreen(board_fake); 
					}

					else if (i == 4){
                        int a = Ai_tm(player);
						cout << "May di: " << a << endl;
						AI_move.push_back(a);
						board_fake[a-1] = temp;
                        printscreen(board_fake);
                        if (check(AI_move) == 1){
                            cout << "May thang!" << endl;
                            return 0;
                        }
					}

                    else if (i == 6){
                        int a = Ai_fm(player);
                        cout << "May di: " << a << endl;
                        AI_move.push_back(a);
                        board_fake[a-1] = temp;
                        printscreen(board_fake);
                        if (check(AI_move) == 1){
                            cout << "May thang!" << endl;
                            return 0;
                        }
                    }
                }

                else{
                    cout << "Nguoi choi di: ";
                    int a; cin >> a;
					player.push_back(a);
                    char temp = 'O'; 
					board_fake[a-1] = temp;
					printscreen(board_fake);
                }

                cout << endl;
                if (i == 8){
                    cout << "Tran dau hoa!" << endl;
                }
            }
        }
    }

}
