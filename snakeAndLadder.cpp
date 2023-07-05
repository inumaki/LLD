#include<bits/stdc++.h>
using namespace std;
class Player;
class Game;
class Dice
{
	int diceCount=0;
	public:
	Dice(int diceCount)
	{
	this->diceCount = diceCount;
	srand(time(0));
	}
	int rollDice()
	{ 
	int dice = this->diceCount;
	int num=0;
	while(dice--){
	num+= (rand()%7)+1;
	}
	return num;
	}
};
class Player
{
    public:
int position;
int id;
Dice *dice;
Player(int id,Dice *dice)
{
	this->position =0;
	this->id = id; 
	this->dice = dice;
}
int roll()
{
    return this->dice->rollDice();
}		
}; 
class Board
{
 public:
 	int rows ;
	int columns;
	int snake;
	int ladder;
 	vector<vector<int>>board;
 	void prepareBoard(int rows,int columns,int snake,int ladder)
 	{
 		this->rows = rows;
 		this->columns = columns;
 		board.resize(rows,vector<int>(columns,0));
 		this->snake = snake;
 		this->ladder = ladder;
 		this->addSnakes();
 		this->addLadders();
 		srand(time(0));
	}
	void addSnakes()
	{
		int end= rand()%(this->rows*this->columns);
		int start =  rand()%(this->rows*this->columns); // start>>end
			//to implement;
	}
	void addLadders()
	{
		int start= rand()%(this->rows*this->columns)+1;
		int end =  rand()%(this->rows*this->columns)+1+start;	//end>>start
		//to implement;
		board[start/this->rows][start%this->columns] = end; 	
	}
	void updatePlayerPosition(Player *player,int position)
	{
	    position+= player->position;
	    if(position>= this->rows*this->columns)
	    {
		player->position = this->rows*this->columns;
		return ;
		}
		
	    int newPosition = this->board[position/(this->rows)][position%(this->columns)];
	    player->position = newPosition? newPosition : position;
	}
};
class Game
{
Board *board;
public:	
    queue<Player*>playerQueue;
	Game(int rows,int column,int snake,int ladder)
	{
		this->board = new Board();
		this->board->prepareBoard(rows,column,snake,ladder);
	}
	void addPlayer(Player* player)
	{
	    this->playerQueue.push(player);
	}
	void movePlayer(Player *player)
	{
		int number = player->roll();
		this->board->updatePlayerPosition(player,number);
	}
	string startGame()
	{
		while(1)
		{
	auto playerToPlay = this->playerQueue.front();
	this->playerQueue.pop();
	this->movePlayer(playerToPlay);
	
	cout<<"Player with id = "<<playerToPlay->id<<"  has been moved to "<<playerToPlay->position<<"\n";
	if(playerToPlay->position>= this->board->rows*this->board->columns)
	{
	return  "PLayer with id "+ to_string(playerToPlay->id) +" has won the game";
	}
	
	this->playerQueue.push(playerToPlay);
}
}
	
};

int main()
{
Game game(10,10,10,4);
cout<<"Enter number of players "<<"\n";
int n;
cin>>n;
Dice dice(1);
while(n--)
game.addPlayer(new Player(n,&dice));

cout<<game.startGame()<<"\n";

}

