#include<iostream>
using namespace std;
int board[100][100];
int row,col;
int count=0;
void initboard(int *q,int r,int c)
{
    for(int i=0;i<r;i++)
{
    for(int j=0;j<c;j++)
    {
      *(q+i*c+j)=0;
    }
}

}
void display(int *q,int r,int c)
{
    cout<<"---------------------------------"<<"\n";
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
             if(*(q+i*c+j)==1)
             {
                 cout<<"K"<<"\t";
             }

            else
            {
               cout<<"_"<<"\t";
            }

        }
        cout<<"\n";
    }
    cout<<"---------------------------------";
cout<<"\n\n";
}

void attack(int *p,int ri,int cj)
{
         if(*(p+ri*col+cj)==1)
    {

       if(ri-2>=0&&ri-2<row&&cj-1<col&&cj-1>=0)
               *(p+(ri-2)*col+(cj-1))=-1;
       if(ri-1>=0&&ri-1<row&&cj-2<col&&cj-2>=0)
             *(p+(ri-1)*col+(cj-2))=-1;
       if(ri-2>=0&&ri-2<row&&cj+1<col&&cj+1>=0)
             *(p+(ri-2)*col+(cj+1))=-1;
       if(ri-1>=0&&ri-1<row&&cj+2<col&&cj+2>=0)
             *(p+(ri-1)*col+(cj+2))=-1;
        if(ri+1>=0&&ri+1<row&&cj-2<col&&cj-2>=0)
             *(p+(ri+1)*col+(cj-2))=-1;
         if(ri+2>=0&&ri+2<row&&cj-1<col&&cj-1>=0)
            *(p+(ri+2)*col+(cj-1))=-1;
         if(ri+2>=0&&ri+2<row&&cj+1<col&&cj+1>=0)
            *(p+(ri+2)*col+(cj+1))=-1;
          if(ri+1>=0&&ri+1<row&&cj+2<col&&cj+2>=0)
            *(p+(ri+1)*col+(cj+2))=-1;



    }







}
bool canplace(int *p,int ri,int cj )
{

    if( *(p+ri*col+cj)==-1||*(p+ri*col+cj)==1)
       return false;
    else
        return true;

}
void place(int *p,int ri,int cj)
{

    *(p+ri*col+cj)=1;

}

void Kknights(int *p,int sti,int stj,int k)
{

    if(k==0)
    {
    ++count;
    display(p,row,col);
   // cout<<count<<"\n";
    return;


    }

    else
    {
        for(int i=sti;i<row;i++)
        {

            for(int j=stj;j<col;j++)
            {

                if(canplace(p,i,j)==true)
                {

                    int newb[row][col];



                    for(int i=0;i<row;i++)
                    {
                        for(int j=0;j<col;j++)
                        {
                            newb[i][j]=*(p+i*col+j);
                        }

                    }
                    place(newb[0],i,j);
                    attack(newb[0],i,j);
                    Kknights(newb[0],i,j,k-1);



                }


            }

           stj=0;

        }

    }


}

int main()
{
    int kn;
    cout<<"Enter the number of rows and columns"<<"\n";
    cin>>row>>col;
    cout<<"Enter the number of knights"<<"\n";
    cin>>kn;
    cout<<"No. of board configurations are:\n";

   initboard(board[0],row,col);
   Kknights(board[0],0,0,kn);
    cout<<count<<"\n";

   //display(board[0],row,col);

}
//61412928
