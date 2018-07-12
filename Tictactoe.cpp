#include<iostream>
#include<stdlib.h>
using namespace std;
int board[10],turn;
//Initiallizing the board
int r1,r2,r3,c1,c2,c3,c4,d1,d2;

void initboard()
{

    for(int i=1;i<10;i++)
    {

        board[i]=2;
    }
}

//Display the board
void display()
{

    for(int i=1;i<10;i++)
    {

        if(i%3==0)
        {
           if (board[i]==2)
           {
               cout<<"__";
               cout<<i<<"|";


           }
           else if(board[i]==3)
           {
                cout<<"__";
               cout<<"X"<<"|";

           }

           else if(board[i]==5)
           {
                cout<<"__";
               cout<<"O"<<"|";


           }
           else
           {
               cout<<" ";

           }
           cout<<"\n";

        }

        else
        {
          if (board[i]==2)
           {
               cout<<"__";
               cout<<i<<"|";


           }
           else if(board[i]==3)
           {
               cout<<"__";
               cout<<"X"<<"|";

           }

           else if(board[i]==5)
           {
               cout<<"__";
               cout<<"O"<<"|";


           }
           else
           {
               cout<<" ";

           }


        }
    }
}




int findr(int i)
{
   if(board[i]==2)
   {
       return(i);
   }
   else if (board[i+1]==2)
   {
       return(i+1);
   }
   else if(board[i+2]==2)
   {
       return(i+2);

   }

   else
   {
       return(0);
   }

}

int findc(int i)
{
   if(board[i]==2)
   {
       return(i);
   }
   else if (board[i+3]==2)
   {
       return(i+3);
   }
   else if(board[i+6]==2)
   {
       return(i+6);

   }

   else
   {
       return(0);
   }

}
int findd(int i)
{
if(i==1)
{
 if(board[i]==2)
   {
       return(i);
   }
   else if (board[i+4]==2)
   {
       return(i+4);
   }
   else if(board[i+8]==2)
   {
       return(i+8);

   }

   else
   {
       return(0);
   }
}

else
{
  if(board[i]==2)
   {
       return(i);
   }
   else if (board[i+2]==2)
   {
       return(i+2);
   }
   else if(board[i+4]==2)
   {
       return(i+4);

   }

   else
   {
       return(0);
   }
}


}
int posswin(int p)
{
    int b;

    r1=board[1]*board[2]*board[3];
    r2=board[4]*board[5]*board[6];
    r3=board[7]*board[8]*board[9];
    c1=board[1]*board[4]*board[7];
    c2=board[2]*board[5]*board[8];
    c3=board[3]*board[6]*board[9];
    d1=board[1]*board[5]*board[9];
    d2=board[3]*board[5]*board[7];
    if(p==1)
    {
        if(r1==18)
        {
            b=findr(1);
            return(b);


        }

        else if( r2==18)
        {
            b=findr(4);
            return b;
        }

        else if(r3==18)
        {
            b=findr(7);
            return b;
        }

         else if(c1==18)
        {
            b=findc(1);
            return b;
        }

         else if(c2==18)
        {
            b=findc(2);
            return b;
        }

        else if(c3==18)
        {
            b=findc(3);
            return b;
        }

        else if(d1==18)
        {
            b=findd(1);
            return b;
        }

        else if(d2==18)
        {
            b=findd(3);
            return b;
        }

        else
        {
            return(0);
        }






    }





    else
    {
        if(r1==50)
        {
            b=findr(1);
            return(b);


        }

        else if( r2==50)
        {
            b=findr(4);
            return b;
        }

        else if(r3==50)
        {
            b=findr(7);
            return b;
        }

         else if(c1==50)
        {
            b=findc(1);
            return b;
        }

         else if(c2==50)
        {
            b=findc(2);
            return b;
        }

        else if(c3==50)
        {
            b=findc(3);
            return b;
        }

        else if(d1==50)
        {
            b=findd(1);
            return b;
        }

        else if(d2==50)
        {
            b=findd(3);
            return b;
        }

        else
        {
            return(0);
        }



}


}









int make1()
{
    if(turn%2!=0&&board[turn]==2)
   {
       return(turn);
   }
   else
   {
       return(0);
   }

}


int make2()
{

   if(turn%2==0&&board[turn]==2)
   {
       return(turn);
   }
   else
   {
       return(0);
   }

}
void go(int n)
{

    board[n]=5;

}


void go1(int n)
{

    board[n]=3;

}

int checkwin(int p)
{
    r1=board[1]*board[2]*board[3];
    r2=board[4]*board[5]*board[6];
    r3=board[7]*board[8]*board[9];
    c1=board[1]*board[4]*board[7];
    c2=board[2]*board[5]*board[8];
    c3=board[3]*board[6]*board[9];
    d1=board[1]*board[5]*board[9];
    d2=board[3]*board[5]*board[7];
    if(p==1)
    {
        if(r1==27)
        {
            cout<<"P1 won";
            return(1);


        }

        else if( r2==27)
        {
            cout<<"P1 won";
            return(1);

        }

        else if(r3==27)
        {
           cout<<"P1 won";
            return(1);

        }

         else if(c1==27)
        {
            cout<<"P1 won";
            return(1);

        }

         else if(c2==27)
        {
            cout<<"P1 won";
            return(1);

        }

        else if(c3==27)
        {
            cout<<"P1 won";
            return(1);

        }

        else if(d1==27)
        {
            cout<<"P1 won";
            return(1);

        }

        else if(d2==27)
        {
           cout<<"P1 won";
            return(1);

        }

        else
        {
            return(0);
        }






    }





    else
    {
        if(r1==125)
        {
            cout<<"P2 won";
            return(1);


        }

        else if( r2==125)
        {
           cout<<"P2 won";
            return(1);

        }

        else if(r3==125)
        {
            cout<<"P2 won";
            return(1);

        }

         else if(c1==125)
        {
            cout<<"P2 won";
            return(1);

        }

         else if(c2==125)
        {
            cout<<"P2 won";
            return(1);

        }

        else if(c3==125)
        {
            cout<<"P2 won";
            return(1);

        }

        else if(d1==125)
        {
            cout<<"P2 won";
            return(1);

        }

        else if(d2==125)
        {
            cout<<"P2 won";
            return(1);

        }

        else
        {
            return(0);
        }



}




}





void playerfirst()
{
    turn=1;
    int p=1;
    int c=0;
    int ch;

    while(1)
    {

        display();

        if(turn==1||turn==3||turn==5||turn==7||turn==9)
        {

            cout<<"enter your blockno";
            cin>>ch;
            if(board[ch]==2)
            {
             board[ch]=3;
            }
            else
                {
                    cout<<"na";
                }

            turn++;



        }


        if(turn==2)
        {
            if(board[5]==2)
            {
                board[5]=5;

            }

            else
            {
                //go(make2());

                go(3);
            }




            turn++;



        }
        if(turn==4)
        {

         if(board[2]==3&&board[4]==3)
                go(1);
         else if(board[2]==3&&board[6]==3)
                go(3);
         else if(board[6]==3&&board[8]==3)
                go(9);
         else if(board[4]==3&&board[8]==3)
                go(7);


         else if(board[5]==3&&board[7]==3)
                go(9);
        /*
        else if(board[5]==3&&board[3]==3)
                go(1);
        else if(board[5]==3&&board[1]==3)
                go(3);
        */
         else
         {
             if(posswin(c)!=0)
            {

                go(posswin(c));

            }
            else
            {
                if(posswin(p)!=0)
                {

                    go(posswin(p));

                }

                else
                {
                    if(make2()!=0)
                {
                 go(make2());
                }
                else
                {
                    for(int i=1;i<10;i++)
                    {

                        if(board[i]==2)
                        {
                            go(i);
                            break;
                        }
                    }
                }


                }
            }

         }
         turn++;
        }


        if(turn==6 || turn==8)
        {
           if(posswin(c)!=0)
            {

                go(posswin(c));

            }
            else
            {
                if(posswin(p)!=0)
                {

                    go(posswin(p));

                }

                else
                {
                    if(make2()!=0)
                {
                 go(make2());
                }
                else
                {
                    for(int i=1;i<10;i++)
                    {

                        if(board[i]==2)
                        {
                            go(i);
                            break;
                        }
                    }
                }


                }
            }

            turn++;
        }


        if(turn==10||checkwin(p)==1||checkwin(c)==1)
        {
            cout<<"\n"<<"Game Over"<<"\n";
           display();
            break;

        }




        }
    }


void compfirst()
{

     turn=1;
    int p=0;
    int c=1;
    int ch;

    while(1)
    {


        if(turn==3||turn==5||turn==7||turn==9)
        {
           if(posswin(c)!=0)
            {

                go1(posswin(c));

            }
            else
            {
                if(posswin(p)!=0)
                {

                    go1(posswin(p));

                }

                else
                {
                    if(make1()!=0)
                {
                 go1(make1());
                }
                else
                {
                    for(int i=1;i<10;i++)
                    {

                        if(board[i]==2)
                        {
                            go1(i);
                            break;
                        }
                    }
                }


                }
            }

            turn++;
            display();

        }


        if(turn==1)
        {
            if(board[5]==2)
            {
                board[5]=3;

            }

            else
            {
                int t;
                for(int i=0;i<8;i++)
                {
                    t=(rand()%10)+1;
                    if( board[t]==2)
                    {
                        break;
                    }
                   go(t);

                }




            }
            turn++;

            display();


        }


        if(turn==2||turn==4 || turn==6 || turn==8)
        {


          cout<<"enter your blockno";
            cin>>ch;
            if(board[ch]==2)
            {
             board[ch]=5;
            }
            else
                {
                    cout<<"na";
                }

            turn++;
        }


        if(turn==10||checkwin(p)==1||checkwin(c)==1)
        {
             cout<<"\n"<<"Game Over"<<"\n";
           display();
            break;

        }




        }
}




int main()
{
    int ch;

     while(1){
            initboard();
            playerfirst();
    cout<<"Press 3 to exit and press 1 to continue";
      cin>>ch;
      if(ch==3)
      {
          break;
      }
      else
      {
          initboard();
          playerfirst();
      }
    }


    return 0;
}

