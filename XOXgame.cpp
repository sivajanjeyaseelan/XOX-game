#include<iostream>
#include<string>
#include <vector>

using namespace std;



class Player{
    private:
        
        string name;
        string symbol;

    public:

        Player(string playerName, string playerSymbol){
           
           
            name=playerName;
            symbol=playerSymbol;

        }
        
        string getname(){

            return name;

        }
            
        string getSymbol(){

            return symbol;

        }


};


class gameLogic{

    private:
        
        int firstPlayer=0;
        int i=0;
        int j=0;
        int checkWinner=0;
        vector <string> box;
        Player* p1;          
        Player* p2;           

    public:
    
        gameLogic(Player* player1, Player* player2) {
            box = {"0", "1", "2", "3", "4", "5", "6", "7", "8"};
            firstPlayer = 0;
            p1 = player1;  
            p2 = player2;  

        }
    

        void displayBoardstatus(){
           
           cout << endl;
           
            for(int i=0; i<9; i++){

                    if(i==3 || i==6){
                          
                          cout << endl;

                    }
                    
                    cout << box[i] << "  ";
                    
            
            }

            cout << endl;

        }


        void switchPlayer(){

            switch (firstPlayer)
            {
                case 0:

                    cout << ""<< p1->getname() << " enter ur "<< p1->getSymbol()<< " in correct box\t";
                    cin >> i;
                   

                    while(checktheValidbox(i)==1){

                            cout << ""<< p1->getname() << " enter ur "<< p1->getSymbol()<< " in correct box\t";
                            cin >> i;



                    }

                    if(checktheValidbox(i)==0){

                            box[i]=p1->getSymbol();
                            firstPlayer=(firstPlayer+1)%2;


                    }


                    break;
                
                case 1:
                    cout << ""<< p2->getname() << " enter ur "<< p2->getSymbol() << " in correct box\t";

                  cin >> j;

                    
                    while(checktheValidbox(j)==1){

                            cout << ""<< p2->getname() << " enter ur "<< p2->getSymbol()<< " in correct box\t";
                            cin >> j;


                    }

                    if(checktheValidbox(j)==0){

                            box[j]=p2->getSymbol();
                            firstPlayer=(firstPlayer+1)%2;


                    }


                    break;

            }

            




        }
                  

        int checktheValidbox(int a){

            if(box[a]=="X" || box[a]=="O"){

                cout << "This is a invalid move\n";

                return 1;

            }


            return 0;




        }

        void chooseWinner(){

            if((box[0]=="X"&&box[3]=="X"&&box[6]=="X") ||
               (box[1]=="X"&&box[4]=="X"&&box[7]=="X") || 
               (box[2]=="X"&&box[5]=="X"&&box[8]=="X") ||
               (box[2]=="X"&&box[4]=="X"&&box[6]=="X") ||
               (box[0]=="X"&&box[4]=="X"&&box[8]=="X") || 
               (box[0]=="X"&&box[1]=="X"&&box[2]=="X") ||
               (box[3]=="X"&&box[4]=="X"&&box[5]=="X") ||
               (box[6]=="X"&&box[7]=="X"&&box[8]=="X")){

                    cout << "player 1 wins the game";
                    checkWinner=1;

            } else if((box[0]=="O"&&box[3]=="O"&&box[6]=="O") ||
             (box[1]=="O"&&box[4]=="O"&&box[7]=="O") || 
             (box[2]=="O"&&box[5]=="O"&&box[8]=="O") || 
             (box[2]=="O"&&box[4]=="O"&&box[6]=="O") || 
             (box[0]=="O"&&box[4]=="O"&&box[8]=="O") || 
             (box[0]=="O"&&box[1]=="O"&&box[2]=="O") || 
             (box[3]=="O"&&box[4]=="O"&&box[5]=="O") || 
             (box[6]=="O"&&box[7]=="O"&&box[8]=="O")){

                    cout << "Player 2 wins the game";
                    checkWinner=1;


            } else if(isBoardfull()) {

                    cout << "Match get drawed";

            }


        }

        bool isBoardfull(){

            for(int j=0; j<9; j++){

                    if(box[j]!=p1->getSymbol()  && box[j]!=p2->getSymbol()){

                            return false;

                    }

            }


            return true;

        }

        bool gameover(){

            if(isBoardfull() || checkWinner==1){

                return true;


            }


            return false;

        }




};





int main(){

 


    Player p1("sivajan","X");
    Player p2("VK","O");


    
    gameLogic game(&p1,&p2);

    while(!game.gameover()){

        game.displayBoardstatus();
        game.switchPlayer();
        game.chooseWinner();

    }

    return 0;   

}


 /* for (int i = 0; i < 21; i++) {
        // Print the top border line (only on the first row)
        if (i == 0) {
            for (int j = 0; j < 69; j++) {
                cout << "-";
            }
            cout << endl; // Move to the next line after the border
        }

        // Print the vertical bars with space in between for the body of the box
        cout << "|";
        for (int j = 0; j < 67; j++) {
            cout << " "; // Add spaces in between the vertical bars
        }
        cout << "|" << endl;

        // Print the bottom border line (only on the last row)
        if (i == 20) {
            for (int k = 0; k < 69; k++) {
                cout << "-";
            }
            cout << endl; // Move to the next line after the border
        }
    }*/
