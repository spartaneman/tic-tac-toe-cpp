#include <iostream>
#include <iomanip>

const char PLAYER1 = 'X';
const char PLAYER2 = 'O';
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
bool gameOver(char **, int size);
bool checkRows(char **, int);
bool checkColumns(char **, int);
bool checkDiagonals(char **, int);


int main(){
    //TODO create a variable that keeps track at how many pieces/moves have been made


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
    board[0][3] = PLAYER1;
    board[1][2] = PLAYER1;
    board[2][1] = PLAYER2;
    board[3][0] = PLAYER1;
    displayBoard(board, size);
    cout << checkDiagonals(board, size);

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
//this will check each row 
//we will need three different functions
    //one to check each row, 
    //one to check each column,
    //one to check the diagonals
bool checkRows(char **board, int size){
    
    //Iterate through all rows checking the columns against one another. 
    for(int i = 0; i < size; i++){
        //get the value of the first item in the row
        char first = board[i][0];

        //set the row to equal true, if at any point the check fails
        //then set the row to false and break from 
        bool row = true;
        for(int j = 0; j < size; j++){
            //first make sure to skip the first column
            if(j == 0){
                continue;
            }
            if(first != board[i][j]){
                row = false;
                if(row == false){
                    //since it failed brake from the loop
                    break;
                }
            }

        }//end of loop
        
        //if it gets to this point row should be true
        //double check row still is true, return true
        if(row){
            return true;
        }
    }//end of loop
    
    //if we reached this point, then we never got a true row and therefore return false
    return false;
}

//check whether any column matches 
bool checkColumns(char **board, int size){
    
    for(int col = 0; col < size; col++){

        bool column = true;
        //Will iterate through all rows checking that the character in the row matches 
        //the character in the following row but same column
        for(int row = 0; row < size-1; row++){
            //since I can get the character before getting the row, I will 
            //check each letter to the following one, 
            //if false then break
            char letter = board[row][col];
            if(letter != board[row + 1][col]){
                column = false;
                if(!column){
                    break;
                }
            }

        }//end of loop

        //check if column holds true
        if(column){
            return true;
        }
    }//end of loop
    
    //if it reaches this point then no column held true
    return false;
}

/**Function will check if the diagonals hold true*/
bool checkDiagonals(char **board, int size){
    //Only one for loop will be necessary for each direction
    //initiate the first character to check
    int endStart = size-1;
    char backSlash= board[0][0];
    char forwardSlash = board[0][endStart];

    //check the backSlash direction 
    bool bs = true;
    for(int row = 0; row < size; row++){
        if(row == 0){
            continue;
        }
        if(backSlash != board[row][row]){
            bs = false;
        }
    }

    //check the forwardSlash direction
    bool fs = true;
    for(int row = 0; row < size; row++)
    {
        if(row == 0){
            continue;
        }
        if(forwardSlash != board[row][endStart-row]){
            fs= false;
        }
    }

    //if either remains true, then return true
    //otherwise return false;
    if(bs == true || fs == true){
        return true;
    }
    else{
        return false;
    }
}