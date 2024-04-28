#include <iostream>
#include <conio.h>
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

void oneplayermode();
int twoplayermode(int );
void info();

int main(){
	//INTERFACE
char start{};

system("CLS");

cout<<"WELCOME TO\n\n";
	cout<<" _    _          _   _  _____ __  __          _   _"<<endl;
	cout<<"| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |"<<endl;
	cout<<"| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |"<<endl;
	cout<<"|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |"<<endl;
	cout<<"| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |"<<endl;
	cout<<"|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|"<<endl<<endl<<endl<<endl;
	cout<<"               By:Mahdi Tamjidi & Amir Mohammad Khah"<<endl;
    cout<<"                                     GP:I don't know"<<endl<<endl<<endl;
	cout<<"Press and enter any key to start"<<endl;
    cin>>start;

system("CLS");
	
//MENU	
	
int a;
char rpt;
do {
    system("CLS"); 
    cout<<"Chose and enter the number of the option you want:\n\n"<<"1.One player mode\n\n2.Two player mode\n\n3.Info/help\n\n4.Exit"<<endl<<endl; cin>>a; 

	system("CLS");
		
	do{
		
	switch(a){
	
		case 1 : {
			oneplayermode(); 
			cout<<"Press t to go to top menu and press p to play again.\n"; cin>>rpt;
            if(rpt=='p')	
              a=1;
			break;
		}
		
		case 2 : {
			int p1=twoplayermode(1);
            int p2=twoplayermode(2);

            if(p1==0 && p2==0)
              cout<<"DRAW!!!You both guessed the word wrong.\n\n"<<endl;
            if(p1==1 && p2==1)
              cout<<"DRAW!!!You both got the word right.\n\n"<<endl;
            if(p1==1 && p2==0)
              cout<<"Congratulations Player 1, you won!!!\n\n"<<endl;
            if(p1==0 && p2==1)
              cout<<"Congratulations Player 2, you won!!!\n\n"<<endl;
			cout<<"Press t to go to top menu and press p to play again.\n"; cin>>rpt;
            if(rpt=='n')	
              a=2;
            system("CLS");
			break;
		}
		
		case 3 :{
			info();
		    cout<<"Press t to go to top menu.\n"; cin>>rpt;
			break;
		} 
		
		case 4 : {
			cout<<" _    _          _   _  _____ __  __          _   _"<<endl;
	        cout<<"| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |"<<endl;
	        cout<<"| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |"<<endl;
	        cout<<"|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |"<<endl;
	        cout<<"| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |"<<endl;
	        cout<<"|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|"<<endl<<endl<<endl<<endl;
			cout<<"            THANKS FOR PLAYING THIS GAME"<<endl;
			cout<<"               HOPE YOU ENJOYED IT "<<endl;
			break;
		}
		

	
		default : cout<<"error";
		}
	}while(rpt=='p');	
 	
}while(a!=4 && rpt=='t');	
	
	
 

getch() ;
return 0;
}

void oneplayermode(){
system("CLS"); 
	
cout<<"                       "	<<endl;
cout<<"                       "	<<endl;
cout<<"                       "	<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"                          "<<endl;
cout<<"                          "<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"            "<<endl;
cout<<"            "<<endl;
cout<<"            "<<endl;
cout<<"            "<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n\n\n";

	// VARIABLES 
int guesses{6}; 
char guess; 
bool correctguess = false;
char previousguesses[7]; 
previousguesses[0]='\0';
for(int i=1 ; i<6 ; i++) 
{
	previousguesses[i]='-';
}
previousguesses[6]='\0';
string word; 
string wordlist[50]; 

// RANDOM WORD
srand(time(NULL));
ifstream randomword; 
randomword.open("Words.txt"); 

for(int i=0; i<50; i++){
	
	randomword>>wordlist[i]; 
    //cout<<wordlist[i]<<endl; //TEST
}

int randomNUM = rand() % 50; 
word = wordlist[randomNUM];
//cout<<word<<endl; //TEST or CHEAT*************
randomword.close();

// HIDDEN WORD
string hiddenword(word.length(),'*'); 
//cout<<hiddenword<<endl; //TEST 



while(guesses>= 0){


//RESET BOOL
correctguess=false; 


// WORD INFO
cout<<"The word you have to guess is:"<<endl<<endl;
cout<<hiddenword<<endl;
cout<<endl<<"There are "<<hiddenword.length()<<" letters in the word"<<endl<<endl;
cout<<"You have "<<guesses<<" guesses left"<<endl;
if(previousguesses[0]=='\0'){
	cout<<endl;
}
else {
	cout<<"Wrong letters you've guessed: "<<previousguesses<<endl;
}
cout<<"\nGuess a letter: ";
cin>>guess;
system("CLS");




// GUESS CHECK
for(int i=0; i<hiddenword.length(); i++) 
{
	if(word[i]==guess) 
	{
		hiddenword[i]=guess;
		correctguess = true;
	}
}
if (word==hiddenword){
	cout<<" _    _          _   _  _____ __  __          _   _"<<endl;
	cout<<"| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |"<<endl;
	cout<<"| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |"<<endl;
	cout<<"|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |"<<endl;
	cout<<"| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |"<<endl;
	cout<<"|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|"<<endl;
	cout <<endl<<endl<<"Congratulations!You've got the word correct :"<<hiddenword<<endl<<endl<<endl<<endl;
	break;
}

if (correctguess==false ){
	if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess && previousguesses[4]!=guess && previousguesses[5]!=guess)
	guesses--;
	cout<<"Sorry,"<<guess<<" is not part of the word."<<endl<<endl;
}
else {
	   cout<<"Congrats, "<<guess<<" is one of the letters."<<endl; 
}

	switch (guesses){
		case 6:{
cout<<"                       "	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |              "<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";		
			break;
		}
		
		case 5:{
cout<<"           +----------+"	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |           "<<endl;
cout<<"           |           "<<endl;
cout<<"           |              "<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess) 
	 previousguesses[0]=guess;
}
		

			break;
		}
		
		case 4:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |             "<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess && previousguesses[1]!=guess)
	previousguesses[1]=guess;
}
	
		
			break;
		}
		
		case 3:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {o_o}"<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess)
	previousguesses[2]=guess;
}
	
		
			break;
		}
		
		case 2:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {o_o}"<<endl;
cout<<"           |     o__/   \\__o"<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
	
		if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess && previousguesses[4]!=guess)
previousguesses[3]=guess;
}
	
		
			break;
		}
		
		case 1:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {o_o}"<<endl;
cout<<"           |     o__/   \\__o"<<endl;
cout<<"           |        |   | "<<endl;
cout<<"           |         \\_/ "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess && previousguesses[4]!=guess && previousguesses[5]!=guess)
	previousguesses[4]=guess;
}
	
		
			break;
		}
		
		case 0:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {x_x}"<<endl;
cout<<"           |     o__/   \\__o"<<endl;
cout<<"           |        |   | "<<endl;
cout<<"           |         \\_/ "<<endl;
cout<<"           |         | |"<<endl;
cout<<"           |         | | "<<endl;
cout<<"           |         o o"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"       GAME OVER"<<endl;
cout<<"\nThe word you had to guess was:"<<word<<endl;
cout<<"\n";
		guesses=-1;
			break;
		
		}
		
		default : cout<<"barname error dare";
	}
	
}




}


int twoplayermode(int player){

// VARIABLES 
int guesses{6}; 
char guess; 
bool correctguess = false;
char previousguesses[7]; 
previousguesses[0]='\0';
for(int i=1 ; i<6 ; i++) 
{
	previousguesses[i]='-';
previousguesses[6]='\0';
string word; 

//WORD READ
cout<<"Player "<<player<<", enter a word for your opponent to guess :"<<endl; cin>>word;



// HIDDEN WORD
string hiddenword(word.length(),'*'); 
//cout<<hiddenword<<endl; //TEST 

system("CLS");
cout<<"                       "	<<endl;
cout<<"                       "	<<endl;
cout<<"                       "	<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"                          "<<endl;
cout<<"                          "<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"                         "<<endl;
cout<<"            "<<endl;
cout<<"            "<<endl;
cout<<"            "<<endl;
cout<<"            "<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n\n\n";
while(guesses>= 0){


//RESET BOOL
correctguess=false; 


// WORD INFO
cout<<"The word you have to guess is:"<<endl<<endl;
cout<<hiddenword<<endl;
cout<<endl<<"There are "<<hiddenword.length()<<" letters in the word"<<endl<<endl;
cout<<"You have "<<guesses<<" guesses left"<<endl;
if(previousguesses[0]=='\0'){
	cout<<endl;
}
else {
	cout<<"Wrong letters you've guessed: "<<previousguesses<<endl;
}
cout<<"\nGuess a letter: ";
cin>>guess;
system("CLS");


// GUESS CHECK
for(int i=0; i<hiddenword.length(); i++) 
{
	if(word[i]==guess) 
	{
		hiddenword[i]=guess;
		correctguess = true;
	}
}
if (word==hiddenword){
    cout<<" _    _          _   _  _____ __  __          _   _"<<endl;
	cout<<"| |  | |   /\\   | \\ | |/ ____|  \\/  |   /\\   | \\ | |"<<endl;
	cout<<"| |__| |  /  \\  |  \\| | |  __| \\  / |  /  \\  |  \\| |"<<endl;
	cout<<"|  __  | / /\\ \\ | . ` | | |_ | |\\/| | / /\\ \\ | . ` |"<<endl;
	cout<<"| |  | |/ ____ \\| |\\  | |__| | |  | |/ ____ \\| |\\  |"<<endl;
	cout<<"|_|  |_/_/    \\_\\_| \\_|\\_____|_|  |_/_/    \\_\\_| \\_|"<<endl<<endl;;
	cout <<"Congratulations!You've got the word correct: "<<hiddenword<<endl<<endl<<endl<<endl;
	break;
}
if (correctguess==false){
	if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess && previousguesses[4]!=guess && previousguesses[5]!=guess)
	guesses--;
	cout<<guess<<" is not part of the word"<<endl;
}
else {
	   cout<<"Congrats "<<guess<<" is one of the letters"<<endl; 
}

switch (guesses){
		case 6:{
cout<<"                       "	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |              "<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";		
			break;
		}
		
		case 5:{
cout<<"           +----------+"	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |           "	<<endl;
cout<<"           |           "<<endl;
cout<<"           |           "<<endl;
cout<<"           |              "<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess) 
	previousguesses[0]=guess;
}
		

			break;
		}
		
		case 4:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |             "<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess && previousguesses[1]!=guess)
	previousguesses[1]=guess;
}
	
		
			break;
		}
		
		case 3:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {o_o}"<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess)
	previousguesses[2]=guess;
}
	
		
			break;
		}
		
		case 2:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {o_o}"<<endl;
cout<<"           |     o__/   \\__o"<<endl;
cout<<"           |              "<<endl;
cout<<"           |             "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
	
		if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess && previousguesses[4]!=guess)
previousguesses[3]=guess;
}
	
		
			break;
		}
		
		case 1:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {o_o}"<<endl;
cout<<"           |     o__/   \\__o"<<endl;
cout<<"           |        |   | "<<endl;
cout<<"           |         \\_/ "<<endl;
cout<<"           |             "<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"\n";
if(correctguess==false){
		if(previousguesses[0]!=guess && previousguesses[1]!=guess && previousguesses[2]!=guess && previousguesses[3]!=guess && previousguesses[4]!=guess && previousguesses[5]!=guess)
	previousguesses[4]=guess;
}
	
		
			break;
		}
		
		case 0:{
cout<<"           +----------+"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"	<<endl;
cout<<"           |          |"<<endl;
cout<<"           |          |"<<endl;
cout<<"           |         MMM"<<endl;
cout<<"           |        {x_x}"<<endl;
cout<<"           |     o__/   \\__o"<<endl;
cout<<"           |        |   | "<<endl;
cout<<"           |         \\_/ "<<endl;
cout<<"           |         | |"<<endl;
cout<<"           |         | | "<<endl;
cout<<"           |         o o"<<endl;
cout<<"           |"<<endl;
cout<<"           |"<<endl;
cout<<"    [-------------]"<<endl;
cout<<"       GAME OVER"<<endl;
cout<<"\nThe word you had to guess was:"<<word<<endl;
cout<<"\n";
		guesses=-1;
			break;
		
		}
		
		default : cout<<"barname error dare";
	}
	
}

if (guesses==-1)
  return 0;
return 1;
	
	
	
}


void info(){
	
	cout<<"Hangman is a multiplayer guessing game in which you have "<<endl;
    cout<<"to guess the hidden word a letter at a time within 6"<<endl;
	cout<<"guesses. After each wrong guess a part of the hangman will"<<endl;
	cout<<"be drawn and you'll lose when the hangman is completed."<<endl<<endl;
	cout<<"Throughout the game you need to press ENTER every time "<<endl;
	cout<<"you want to enter a character."<<endl<<endl;
	cout<<"While guessing your word it's ok to enter multiple"<<endl;
	cout<<"letters at once ."<<endl<<endl;
	cout<<"After each round you'll be asked to play again and stay"<<endl;
	cout<<"in the same game mode or to go back to the top menu ."<<endl;
	cout<<"Respond with p for the first option and t for the second one."<<endl<<endl;
	cout<<"Throughout the game always respond with small characters."<<endl<<endl;
	cout<<"Hope you enjoy our game."<<endl<<endl<<endl<<endl;
 
	
	
	
	
}

