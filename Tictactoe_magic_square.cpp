#include<iostream>
#include<stdlib.h>
using namespace std;
int board[10],turn;
//Initiallizing the board
int r1,r2,r3,c1,c2,c3,c4,d1,d2;
int visp[10],visc[10],p[10],c[10];
int t=0,pl=0;



void initboard()
{
    for(int i=1;i<10;i++)
    {
        visp[i]=0;
        visc[i]=0;
        p[i]=0;
        c[i]=0;

    }
board[1]=8;
board[2]=3;
board[3]=4;
board[4]=1;
board[5]=5;
board[6]=9;
board[7]=6;
board[8]=7;
board[9]=2;

}

//Display the board
void display()
{

for(int i=1;i<10;i++)
{

    if(i%3==0)
    {
        if(visp[i]!=0)
        {
          cout <<"__";
          cout<<"X"<<"|";
        }
        else if(visc[i]!=0)
        {
            cout <<"__";
          cout<<"O"<<"|";
        }
        else
        {
            cout<<"__";
            cout<<i<<"|";
        }
        cout<<"\n";

    }

    else
    {
         if(visp[i]!=0)
        {
          cout <<"__";
          cout<<"X"<<"|";
        }
        else if(visc[i]!=0)
        {
            cout <<"__";
          cout<<"O"<<"|";
        }
        else
        {
            cout<<"__";
            cout<<i<<"|";
        }
    }

}


}






int posswin(int d)
{
    int a,b,c1=-1,f=0;
   if(d==1)
   {



       for(int i=1;i<10;i++)
       {

           a=p[i];
        for(int j=1;j<10;j++)
        {
           b=p[j];



            if(15-(a+b)<=9&&15-(a+b)>0&&a!=b&&a!=0&&b!=0)
          {


              c1=15-(a+b);

               for(int i=1;i<10;i++)
           {
               if(board[i]==c1)
               {
                   c1=i;
                   break;
               }

           }
           if(visp[c1]!=1&&visc[c1]!=1)
           {
               f=1;
               break;

           }
          }

          }

         if(f==1)
         {
            break;

         }



       }


       if(f==1)
       {

          return(c1);

       }
       else{
        return(0);
       }

   }

   else
   {


      for(int i=1;i<10;i++)
       {

           a=c[i];

        for(int j=1;j<10;j++)
        {
           b=c[j];


          if(15-(a+b)<=9&&15-(a+b)>0&&a!=b&&a!=0&&b!=0)
          {


              c1=15-(a+b);
               for(int i=1;i<10;i++)
           {
               if(board[i]==c1)
               {
                   c1=i;
                   break;
               }

           }
           if(visp[c1]!=1&&visc[c1]!=1)
           {
               f=1;
               break;

           }


          }

         }
         if(f==1)
         {
             break;
         }


       }

       if(f==1)
       {

        return(c1);


       }
       else{
        return(0);
       }

   }



}








int make2()
{
    if(turn%2==0&&visp[turn]!=1)
   {
       return(turn);
   }
   else
   {
       return(0);
   }

}

int checkwin(int p2)
{
    int a,b,f1=0,f2=0,f=0,c1,d;

if(p2==1)
{
    for(int i=1;i<10;i++)
    {
        a=p[i];
        for(int j=1;j<10;j++)
        {
            b=p[j];
            for(int k=1;k<10;k++)
            {

                c1=p[k];
                if(a!=0&&b!=0&&c1!=0&&a!=b&&b!=c1&&a!=c1)
                {
                    if(a+b+c1==15)
                    {

                        f=1;
                        break;
                    }
                }


            }

            if(f==1)
            {
                f2=1;
                break;
            }
        }

        if(f2==1)
        {
            f1=1;
            break;

        }

    }
    if(f1==1)
    {
        cout<<"You won"<<"\n";
        return(1);

    }
    else
    {

        return(0);
    }
}

else
{
    for(int i=1;i<10;i++)
    {
        a=c[i];
        for(int j=1;j<10;j++)
        {
            b=c[j];
            for(int k=1;k<10;k++)
            {

                c1=c[k];
                if(a!=0&&b!=0&&c1!=0&&a!=b&&b!=c1&&a!=c1)
                {
                    if(a+b+c1==15)
                    {

                        f=1;
                        break;
                    }
                }


            }

            if(f==1)
            {
                f2=1;
                break;
            }
        }

        if(f2==1)
        {
            f1=1;
            break;

        }

    }
    if(f1==1)
    {
        cout<<"Comp Win"<<"\n";
        return(1);

    }
    else
    {

        return(0);
    }
}


}



void go(int ch)
{
    if(visp[ch]!=1&&visc[ch]!=1)
    {
    c[ch]=board[ch];
    visc[ch]=1;

    }




}










void playerfirst()
{
    turn=1;
    int pt=1;
    int co=0;
    int ch;

    while(1)
    {

        display();


        if(turn==1||turn==3||turn==5||turn==7||turn==9)
        {

            cout<<"enter your blockno";
            cin>>ch;
            if(visp[ch]!=1&&visc[ch]!=1)
            {
                p[ch]=board[ch];
                visp[ch]=1;
            }



            else
                {
                    cout<<"na";
                }

            turn++;
        }






        if(turn==2)
        {
            if(visc[5]!=1&&visp[5]!=1)
            {
                go(5);
            }

            else
            {
                //go(make2());
                int t;
                t=3;
                if(visp[t]!=1&&visc[t]!=1)
                {
                   go(t);
                }


            }




            turn++;



        }
        if(turn==4)
        {
         if(visp[2]==1&&visp[4]==1)
                go(1);
         else if(visp[2]==1&&visp[6]==1)
                go(3);
         else if(visp[6]==1&&visp[8]==1)
                go(9);
         else if(visp[4]==1&&visp[8]==1)
                go(7);
        else if(visp[5]==1&&visp[7]==1)
                go(9);

        else
        {
            if(posswin(co)>0)
            {

                go(posswin(co));

            }
            else
            {
                if(posswin(pt)>0)
                {

                    go(posswin(pt));

                }

                else
                {
                    int ct=0;
                    if(make2()>0)
                {
                 go(make2());
                }
                    else
                    {

                        for(int i=1;i<10;i++)
                        {
                            if(visp[i]==0)
                            {
                                ct=i;
                                break;

                            }
                        }

                        go(ct);

                    }



                }
            }
        }
        turn++;

        }




        if(turn==6 || turn==8)
        {
           if(posswin(co)>0)
            {

                go(posswin(co));

            }
            else
            {
                if(posswin(pt)>0)
                {

                    go(posswin(pt));

                }

                else
                {
                    int ct=0;
                    if(make2()>0)
                {
                 go(make2());
                }
                    else
                    {

                        for(int i=1;i<10;i++)
                        {
                            if(visp[i]==0)
                            {
                                ct=i;
                                break;

                            }
                        }

                        go(ct);

                    }



                }
            }

            turn++;
        }


        if(turn==10||checkwin(pt)==1||checkwin(co)==1)
        {
            cout<<"\n"<<"Game Over"<<"\n";
           display();
            break;

        }




        }
    }
/*

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

*/


int main()
{
    int ch=1;
  do
    {
        initboard();
    playerfirst();
    cout<<"Press 3 to exit";
    cout<<"\nPress 1 to continue";
    cin>>ch;


    }while(ch!=3);








    return 0;
}

