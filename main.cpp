#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

bool check_row(vector<vector<int> > sudoku,int r,int c,int number)
{
    
    for(int i=0;i<sudoku.size();i++)
    {
        if(sudoku[r][i]==number)
        return true;
    }
    return false;
}
bool check_column(vector<vector<int> > sudoku,int r,int c,int number)
{
    
    for(int i=0;i<sudoku.size();i++)
    {
        if(sudoku[i][c]==number)
        return true;
    }
    return false;
}
bool check_box(vector<vector<int> > sudoku,int r,int c,int number)
{
    int i,j,n;   
    n=sqrt(sudoku.size());
    i=(r/n)*n;
    int counti=0;
    for(;counti<n;i++,counti++)
    {
        int countj=0;
        j=(c/n)*n;
        for(;countj<n;j++,countj++)
        if(sudoku[i][j]==number)
        return true;
    } 
    return false;
}

void display_sudoku(vector<vector<int> > sudoku)
{
    for(int i=0;i<sudoku.size();i++)
    {
        for(int j=0;j<sudoku.size();j++)
        cout<<sudoku[i][j]<<" ";
        cout<<endl<<endl;
    }
}
vector<vector<int> > initialize_sudoku(int size)
{
    vector<vector<int> > sudoku(size,vector<int> (size,0));
    for(int i=0;i<size;i++)
    {
        string temp;
        cin>>temp;
        for(int j=0;j<size;j++)
        {
            if(temp[j]!='.')
            sudoku[i][j]=temp[j]-'0';
        }
    }
    return sudoku;
}
vector<vector<vector<int> > > initialize_temp(int size,vector<vector<int> >sudoku,vector<vector<stack<int> > >  &rowcount,vector<vector<stack<int> > > &colcount,vector<vector<stack<int> > >  &boxcount)
{
    int n=sqrt(size);
    vector<vector<vector<int> > > temp(size,vector<vector<int> >(size,vector<int>(0)));
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
           if(sudoku[i][j]==0)
           {
            for(int k=1;k<10;k++)
            {
                if(!check_row(sudoku,i,j,k)&&!check_column(sudoku,i,j,k)&&!check_box(sudoku,i,j,k))
                {
                    temp[i][j].push_back(k);
                    rowcount[i][k].push(j);
                    colcount[j][k].push(i);
                    int y=((i/n)*n)+(j/n);
                    
                }
            }
           }
        }
    }
    return temp;
}

void del_row(int size,vector<vector<vector<int> > > &temp,int r,int number)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<temp[r][i].size();j++)
        {
            if(temp[r][i][j]==number)
            temp[r][i].erase(temp[r][i].begin()+j);
        }
    }
}
void del_column(int size,vector<vector<vector<int> > > &temp,int c,int number)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<temp[i][c].size();j++)
        {
            if(temp[i][c][j]==number)
            temp[i][c].erase(temp[i][c].begin()+j);
        }
    }
}
void del_box(int size,vector<vector<vector<int> > > &temp,int r,int c,int number)
{
    int i,j,n;
    n=sqrt(size);
    i=(r/n)*n;
    
    int counti=0;
    for(;counti<n;i++,counti++)
    {
        int countj=0;
        j=(c/n)*n;
        for(;countj<n;j++,countj++)
        {
            for(int k=0;k<temp[i][j].size();k++)
            if(temp[i][j][k]==number)
            temp[i][j].erase(temp[i][j].begin()+k);
            
        }
    } 
}

void solve(int size,vector<vector<int> > &sudoku,vector<vector<vector<int> > > &temp)
{ 
 for(int f=0;f<size;f++)
 {
    for(int i=0;i<size;i++)
    {   
        for(int j=0;j<size;j++)
        { 
           if(temp[i][j].size()==1)
           {
            int k=temp[i][j][0];
            sudoku[i][j]=k;
            temp[i][j].clear(); 
            del_row(size,temp,i,k);
            del_column(size,temp,j,k);
            del_box(size,temp,i,j,k);
           }
           cout<<endl;
           
        }
    }
 }
}

void solve2(int size,vector<vector<int> > &sudoku,vector<vector<vector<int> > > &temp,vector<vector<stack<int> > > &rowcount,vector<vector<stack<int> > > &colcount,vector<vector<stack<int> > >&boxcount)
{
   for(int i=0;i<size;i++)
   {
    for(int j=1;j<=size;j++)
    {
       
    }
   }
}

void display_temp(vector<vector<vector<int> > > temp)
{
    for(int i=0;i<temp.size();i++)
    {
        for(int j=0;j<temp[i].size();j++)
       { {
        cout<<i<<" "<<j<<"&&&  ";
        for(int k=0;k<temp[i][j].size();k++)
        cout<<temp[i][j][k]<<" ";}
        cout<<endl<<endl;}
         cout<<endl<<endl;
          cout<<endl<<endl;
           cout<<endl<<endl;
    }
}

void display_count(vector<vector<int> > temp)
{
    for(int i=0;i<temp.size();i++)
    {
        for(int j=1;j<temp[i].size();j++)
        cout<<temp[i][j]<<" ";
        cout<<endl;
    }
}
int main() 
{
    int size;
    cin>>size;
    vector<vector<stack<int> > > rowcount(size,vector<stack<int> >(size));
    vector<vector<stack<int> > > colcount(size,vector<stack<int> >(size));
    vector<vector<stack<int> > > boxcount(size,vector<stack<int> >(size));
    vector<vector<int> > sudoku(size,vector<int> (size));
    sudoku=initialize_sudoku(size);

    vector<vector<vector<int> > > temp=initialize_temp(size,sudoku,rowcount,colcount,boxcount);
    //solve(size,sudoku,temp);
   // display_sudoku(sudoku);
   // display_temp(temp);
    //display_count(boxcount);
	return 0;
}
