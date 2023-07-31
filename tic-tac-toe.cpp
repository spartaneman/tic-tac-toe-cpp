#include <iostream>
#include <iomanip>

using namespace std;

/*Author: Emanuel Ruiz
 *Start Date: 7/27/23
 *Version 1.0
 *
 *Description: 
 *Simple tic tac toe game that will take the input of two players. 
 *The players will be asked to decide the size of the map which will then be displayed to them
 */

/**Psuedo code
 * Create game function that will loop as long as the users wishes to play the game. 
 *      ask user for size of map. 
 *      create map.
 * Create function that displays map
 * Create function that updates player move.
 *      checks whether move is valid 
 * Create function that checks whether a player has won, 
 *      checks whether there aren't any more possible spaces available
*/

void game();
char **getBoard(int size); 
void displayBoard(char **, int size);
int main(){
    // int game = 1;
    // cout <<setw(30)<< "Welcome to Tic  "<<endl;
    // cout << "A two player game of tic tac toe where each player takes a turn"<<endl;
    // do{
    //     cout<<"Would You like to play a game of tic tac toe"<<endl;
    //     cout<<"enter any character to continue or 0 (zero) to quit"<<endl;
    //     cin >> game;
        
    // }while(game != 0 );
    game();

    return 0;
}

/**The tic tac toe gave loop*/
void game(){
    int size;
    cout << "Enter the size of the board"<<endl;
    cin >> size;
    char **board = getBoard(size);
    
    displayBoard(board, size);

}

/**Displays the tic tac toe*/
void displayBoard(char **arr, int size){
    for(int i =0; i < size; i++){
    
        for(int j = 0; j < size; j++){
            if(j != 0 && j != size){
                cout<<setw(2)<<"|";
            }
            if(arr[i][j] == 'X' || arr[i][j] == 'O'){
                cout<<setw(2)<<arr[i][j];
            }
            else{
                cout<<setw(2)<< " ";
            }
        }//end of for
        cout<<endl;
        for(int k = 0; k < 2*size; k++){
            if( i != size-1){
                cout<<setw(2)<<"-";
            }
            
        }
        cout<<endl;
    }//end of for
}

/*Function will return a char pointer to a 2d array dynamically allocated in the heap*/
char ** getBoard(int size){


    char **board = new char*[size];
    
    //must dynamically create a 1d array for each item pointer in the 2d Array
    for(int i= 0; i < size; i++){
        board[i] = new char[size];
    }


    return board;
}

