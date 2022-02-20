#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
char arr[3][3];

void frame()            //FRAME OF THE GAME
{
    HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE);  //ONLY FOR TEXT COLOUR
    int x=0,y=0;
    for(int i=1;i<=12;i++)
    {
        
        for(int j=1;j<=14;j++)
        {
            if(j==1) cout<<"\t\t";        //JUST TO ALLIGN TEXT IN MIDDLE
            SetConsoleTextAttribute(col,7);  //COLOUR WHITE
            if(i%4==0 && j%5!=0)
            {
                if(i==12)
                cout<<" ";
                else
                cout<<"_";
            }
            else if(j%5==0)
            {
                cout<<"|";
            }
            else                         //PRINTING OF CHARACTER ARRAY'S CHARACTER
            {
                if(i==2 && (j==2 || j==7 || j==12))    
                {
                    if(arr[x][y]=='X')
                    {
                        SetConsoleTextAttribute(col,6);     //COLOUR YELLOW
                        cout<<arr[x][y++];
                    }
                    else if(arr[x][y]=='O')
                    {
                        SetConsoleTextAttribute(col,1);     //COLOUR BLUE
                        cout<<arr[x][y++];
                    }
                    else
                    {
                        SetConsoleTextAttribute(col,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        cout<<arr[x][y++];
                    }
                    
                }
                
                else if(i==6 && (j==2 || j==7 || j==12))
                {
                    if(arr[x][y]=='X')
                    {
                        SetConsoleTextAttribute(col,6);         //COLOUR YELLOW
                        cout<<arr[x][y++];
                    }
                    else if(arr[x][y]=='O')
                    {
                        SetConsoleTextAttribute(col,1);         //COLOUR BLUE
                        cout<<arr[x][y++];
                    }
                    else
                    {
                        SetConsoleTextAttribute(col,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        cout<<arr[x][y++];
                    }
                    
                }
                else if(i==10 && (j==2 || j==7 || j==12))
                {
                    if(arr[x][y]=='X')
                    {
                        SetConsoleTextAttribute(col,6);     //COLOUR YELLOW
                        cout<<arr[x][y++];
                    }
                    else if(arr[x][y]=='O')
                    {
                        SetConsoleTextAttribute(col,1);     //COLOUR BLUE
                        cout<<arr[x][y++];
                    }
                    else
                    {
                        SetConsoleTextAttribute(col,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                        cout<<arr[x][y++];
                    }
                }
                else
                cout<<" ";
            }

        }
        cout<<endl;

        y=0;
        if(i==2 || i==6 || i==10)
        x++;        
    }
    cout<<endl;
}

bool checkWinner(char c)        //LOGIC PART TO CHECK THE WINNING CONDITION
{
    if(arr[0][0]==c && arr[0][1]==c && arr[0][2]==c ) return true; //ROW 1
    if(arr[1][0]==c && arr[1][1]==c && arr[1][2]==c ) return true; //ROW 2
    if(arr[2][0]==c && arr[2][1]==c && arr[2][2]==c ) return true; //ROW 3

    if(arr[0][0]==c && arr[1][0]==c && arr[2][0]==c ) return true; //COLUMN 1
    if(arr[0][1]==c && arr[1][1]==c && arr[2][1]==c ) return true; //COLUMN 2
    if(arr[0][2]==c && arr[1][2]==c && arr[2][2]==c ) return true; //COLUMN 3

    if(arr[0][0]==c && arr[1][1]==c && arr[2][2]==c ) return true; //DIAGONAL 1
    if(arr[0][2]==c && arr[1][1]==c && arr[2][0]==c ) return true; //DIAGONAL 2


    return false;
}

bool insert(int pos, char c)
{
    char choice='0'+pos;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i][j]==choice)
            {
                arr[i][j]=c;
                return true;
            }            
        }
    }
    return false;
}

void game()
{
    HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE); //ONLY FOR TEXT COLOUR
    int pos, count=0;
    while (1)       //ALWAYS TRUE 
    {
        count++;
        frame();
        SetConsoleTextAttribute(col,5);     //COLOUR PURPLE
        cout<<"\tPlayer 1 Enter the position"<<endl;  //PLAYER 1 TURN
        cin>>pos;

        if(!insert(pos,'X')) return;
        

        if(checkWinner('X'))
        {
            frame();
            SetConsoleTextAttribute(col,4);     ////COLOUR RED
            cout<<"\n\tHurray!! Player 1 WINS the game\n\n";
            return;
        }

        frame();
        if(count==9) break;

        count++;

        
        SetConsoleTextAttribute(col,5);     //COLOUR PURPLE
        cout<<"\tPlayer 2 Enter the position"<<endl;  //PLAYER 2 TURN
        cin>>pos;
        if(!insert(pos,'O')) return;


        if(checkWinner('O'))
        {
            frame();
            SetConsoleTextAttribute(col,6);
            cout<<"\n\tHurray!! Player 2 WINS the game\n\n";
            return;
        }

        
    }
    SetConsoleTextAttribute(col,4);     //COLOUR RED
    cout<<"\n\n\tGame Tie\n\n";
    
}

int main()
{
    HANDLE col=GetStdHandle(STD_OUTPUT_HANDLE); //ONLY FOR TEXT COLOUR
    char text='1';
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        arr[i][j]=text++;
    }
    SetConsoleTextAttribute(col,4);     //COLOUR RED
    cout<<"\n\n\t********** WEL-COME TO TIC TAC TOE GAME **********\n\n";
    
    game();
    cout<<"\n\tGAME END\n\n";
    SetConsoleTextAttribute(col,7);     //COLOUR WHITE
    return 0;
}