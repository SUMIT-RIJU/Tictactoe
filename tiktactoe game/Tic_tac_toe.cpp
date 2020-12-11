#include<iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn='X';
int row,column;
bool draw= false;



 void display_board() 
 { system("cls"); 
 cout<<"                              Hello everyone welcome . R u ready to play tiktactoe!!!\n";
 cout<<"player1 [X]\nplayer 2 [O]\n";
 cout<<"          |          |          \n";
 cout<<"    "<<board[0][0]<<"     |    " <<board[0][1]<<"     |  "<<board[0][2]<<"      \n";
 cout<<"__________|__________|__________\n";
 cout<<"          |          |          \n";
cout<<"    "<<board[1][0]<<"     |    " <<board[1][1]<<"     |  "<<board[1][2]<<"      \n";
 cout<<"__________|__________|__________\n";
 cout<<"          |          |          \n";
 cout<<"    "<<board[2][0]<<"     |    " <<board[2][1]<<"     |  "<<board[2][2]<<"      \n";
 cout<<"          |          |          \n";
 	
 	
 	
 }
 
 
player_turn()
{ int choice;
  if(turn=='X')
	cout<<" player 1[x] turn:";
  else if(turn=='O')
	cout<<" player 2[O] turn:";
 cin>>choice;
 switch(choice)
 { case 1: row=0;column=0;break; 
   case 2: row=0;column=1;break; 
   case 3: row=0;column=2;break; 
   case 4: row=1;column=0;break; 
   case 5: row=1;column=1;break; 
   case 6: row=1;column=2;break; 
   case 7: row=2;column=0;break; 
   case 8: row=2;column=1;break; 
   case 9: row=2;column=2;break;   
   default: cout<<"invalid choice\n";
            break;    
        
 }
 if(turn=='X' && board[row][column]!='X' && board[row][column]!='O')
 {board[row][column]='X';
  turn='O';
 }
 else if(turn=='O' && board[row][column]!='X' && board[row][column]!='O')
 {board[row][column]='O';
  turn='X';
 }
 else
 {cout<<"box is already filled please make another choice\n";
  player_turn();
 }
  display_board();
	
}
bool gameover()
{//win
 for(int i=0;i<3;i++)
 {if(board[i][0]==board[i][1] && board[i][0]==board[i][2] || board[0][i]==board[1][i] &&  board[0][i]==board[2][i])
   return false;
    
 
 if(board[0][0] == board[1][1] && board[0][0]==board[2][2] || board[0][2] == board[1][1] && board[0][2]==board[2][0])
 return false;
 }
 //in the running position where any position is left to fill
 for(int i=0;i<3;i++)
 {for(int j=0;j<3;j++)
   {if(board[i][j]!='X' && board[i][j]!='O')
     return true;
   }
 }

 draw =true;
 return false;
 
}
 
main()
{

 while(gameover())
 {
 display_board();
 player_turn();
 gameover();
 
}

if (turn=='X' && draw == false)
 cout<<"player 2[O] wins!! congratulations\n\n";
 else if (turn=='O'&& draw == false)
 cout<<"player 1[X] wins!! congratulations\n\n";
 else
  cout<<"well played both of you the game is draw!!!!! \n";
}
