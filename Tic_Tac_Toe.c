#include <stdio.h>
#include <stdbool.h>
int xfunc();
int yfunc();
int checkwin();
int printboard();


int main()
{
    int xstate[9]={0};
    int ystate[9]={0};
    int k,turn=1;
    //int f=1;
    while(true)
    {
        printboard(xstate,ystate);
        if(turn==1)
        {
           xfunc(xstate,ystate);
           k=checkwin(xstate,ystate);
           if(k==0)
           {

              break;
           }
           turn=turn-1;
        }
        else
        {
           yfunc(xstate,ystate);
           k=checkwin(xstate,ystate);
           if(k==0)
           {

              break;
           }
           turn=turn+1;
        }
        //f++;
        //if(f==10)
          //  printf("Draw");
        //break;
    }
    if(k!=0)
    {
        printf("Draw");
    }
}
int xfunc(int xstate[9],int ystate[9])
{
    int pos;
    printf("\nX's turn:");
    printf("\nEnter the position(enter something between 0 to 10(Dont repeat the same position again))");
    scanf("%d",&pos);
    xstate[pos]=1;
}
int yfunc(int xstate[9],int ystate[9])
{
    int pos;
    printf("\nO's turn:");
    printf("\nEnter the position(enter something between 0 to 10(Dont repeat the same position again))");
    scanf("%d",&pos);
    ystate[pos]=1;
}
int checkwin(int xstate[9],int ystate[9])
{
    if((xstate[0]+xstate[1]+xstate[2]==3) || (xstate[3]+xstate[4]+xstate[5]==3) || (xstate[6]+xstate[7]+xstate[8]==3) || (xstate[0]+xstate[3]+xstate[6]==3) || (xstate[1]+xstate[4]+xstate[7]==3) || (xstate[2]+xstate[5]+xstate[8]==3) || (xstate[0]+xstate[4]+xstate[8]==3) || (xstate[2]+xstate[4]+xstate[6]==3))
    {
        printboard(xstate,ystate);
        printf("\nX won the match:");
        return 0;
    }
    else if((ystate[0]+ystate[1]+ystate[2]==3) || (ystate[3]+ystate[4]+ystate[5]==3) || (ystate[6]+ystate[7]+ystate[8]==3) || (ystate[0]+ystate[3]+ystate[6]==3) || (ystate[1]+ystate[4]+ystate[7]==3) || (ystate[2]+ystate[5]+ystate[8]==3) || (ystate[0]+ystate[4]+ystate[8]==3) || (ystate[2]+ystate[4]+ystate[6]==3))
    {
        printboard(xstate,ystate);
        printf("\nO won the match:");
        return 0;
    }
    else
        return 1;
}
int printboard(int xstate[9],int ystate[9])
{
    char zero,one,two,three,four,five,six,seven,eight;
    zero=two=three=four=five=six=seven=eight=' ';
    if(xstate[0]==1)
        zero='X';
    else if(ystate[0]==1)
        zero='O';
    if(xstate[1]==1)
        one='X';
    else if(ystate[1]==1)
        one='O';
    if(xstate[2]==1)
        two='X';
    else if(ystate[2]==1)
        two='O';
    if(xstate[3]==1)
        three='X';
    else if(ystate[3]==1)
        three='O';
    if(xstate[4]==1)
        four='X';
    else if(ystate[4]==1)
        four='O';
    if(xstate[5]==1)
        five='X';
    else if(ystate[5]==1)
        five='O';
    if(xstate[6]==1)
        six='X';
    else if(ystate[6]==1)
        six='O';
    if(xstate[7]==1)
        seven='X';
    else if(ystate[7]==1)
        seven='O';
    if(xstate[8]==1)
        eight='X';
    else if(ystate[8]==1)
        eight='O';
    printf("\n%c  | %c  | %c ",zero,one,two);
    printf("\n--------------");
    printf("\n%c  | %c  | %c ",three,four,five);
    printf("\n--------------");
    printf("\n%c  | %c  | %c ",six,seven,eight);

}

