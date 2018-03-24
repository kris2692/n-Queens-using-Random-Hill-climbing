#include <iostream>
#include <stdlib.h> 
using namespace std;
struct queen
{
public:
int n; //number of queens
int least_conflict_row, least_conflict_col; //rows, cols having least number of conflicts between queens
bool check_solution; //to check if goal state has been reached
int temp_conflicts; //calculating conflicts between queens
int current_conflict, least_conflict; //to store least conflict and current conflict
int current_row; //to store elements in current row
int *state; //storing address of queens
}k;

//to claculate heuristics for a state
int cal_heuristics(int temp_array[])
{
        int conflict=0;
		int i=0;
        while(i<k.n)
        {
				int j=i+1;
                while(j<k.n)
                {
                        if((temp_array[i]-temp_array[j])==0||(abs(i-j)==abs(temp_array[i]-temp_array[j])))
                                conflict++;
								j++;
                }
				i++;
        }
        return conflict;
}

//to display the board along with quuen location.
void displaystate()
{
		int i=0;
        while(i<k.n)
        {
				int j=0;
                while(j<k.n)
                {
                        cout<<" ";
                        if(j!=k.state[i])
                                cout<<"*";
                        else
                                cout<<"Q";
						j++;
                }
                cout<<"\n";
				i++;
        }
}

//function to randomly generate a state for hill climbing if current one gets stuck 
void randomstart()
{
        int i =0;
		do{
                k.state[i]=(rand()%k.n);
				i++;
		  }while(i<k.n);
}

//actual hill climbing algorithm
void randoom_hill_climbing()
{
        int restarts=0; //counter to count restart points
        int steps=0; //counter to count hill climbing starts from random points
        int current_conflict=0;
        do //if goal state is not yet reached
        {
                randomstart();
                current_conflict=cal_heuristics(k.state);
                if(current_conflict==0) //checking if goal state is reached
                        k.check_solution=true;
                do
                {
                        steps++; //incrementing  step count if goal is not reached
                        k.least_conflict=current_conflict;
						int i=0;
                        while(i<k.n)
                        {		
								int j=0;
                                k.current_row=k.state[i];//storing location of queen in current row
                                while(j<k.n)
                                {
                                        if(k.state[i]!=j) //checking if current conflicts is least than lower conflict encountered till now
                                        {
                                                k.state[i]=j;
                                                k.temp_conflicts=cal_heuristics(k.state);
												if(k.temp_conflicts<k.least_conflict) //if minimum conflict position is found out
                                                {
                                                        k.least_conflict=k.temp_conflicts;
                                                        k.least_conflict_row=j;
                                                        k.least_conflict_col=i;
                                                }
                                                k.state[i]=k.current_row; //getting queen's position
                                        }
										j++;
                                }
								i++;
                        }
						//best candidate is obtained
                        if(k.least_conflict==current_conflict)
                        {
                                restarts++; 
                                break;
                        }
                        else //update the least conflict values
                        {
                                k.state[k.least_conflict_col]=k.least_conflict_row;
                                current_conflict=k.least_conflict;
                        }
                        if(k.least_conflict==0) //if goal is reached
                        {
                                k.check_solution=true;
                                cout<<"Number of restarts: "<<restarts<<"\n";
                                cout<<"Count of state changes: "<<steps<<endl;
                                cout<<"Goal state: "<<endl;
                                displaystate();                 
                                break;
                        }
                }while(current_conflict>0);
        }while(k.check_solution==false);
}

//main function to take inputs from user and calls the hill climb function
int main()
{
 cout<<"Enter number of queens\n";
cin>>k.n;
k.state=new int[k.n]; //to create array of size n
k.check_solution=false;
randoom_hill_climbing();
delete[] k.state;
return 0;
}

