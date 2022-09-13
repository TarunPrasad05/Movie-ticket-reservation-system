#include <bits/stdc++.h>
#include <string>
#include <queue>
using namespace std;

class theatre
{
	string name;
	string movie[5];
	int seat_avl, fdista;
	char seat[13][20], seat_num[4];
	
	public :

	void values(string x, string m[]);
	string rname();
	int available(string mm);
	void booking(string movie);
	void disp(int x);
	int seat_book();
	void ticket_disp(char a[260][4], int price, int c, string pay, int x);
    void fdist(int m);
    int r_fdista(){
        return fdista;
    };

};

void theatre :: values(string x, string m[])
{
	name = x;
	for(int i = 0; i < 5; ++i)
		movie[i] = m[i];
	for(int i = 0; i < 13; i++)
		for(int j = 0; j < 20; j++)
			seat[i][j] = 'L';
	seat_avl = 260;
	
}

string theatre :: rname(){
    return name;
}

int theatre :: available(string m)
{
	for (int i = 0; i < 5; ++i)
		if (movie[i] == m)
			return i;
	return -1;
}

int price(char a)
{
	int sum;
	a = toupper(a);
	switch(a)
	{
		case 'A':
		case 'B':
		case 'C':   
            sum = 50;
			break;
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':   
            sum = 150;
			break;
		case 'K':
		case 'L':
		case 'M':   
            sum = 200;
			break;
		default :  
            sum = 0;
	}
	return sum;
}

void theatre :: booking(string m)
{
	int x = available(m), n, i, j, status, total = 0, c = 0;
	char tot_seat[260][4]; 
	string pay;
	cout << "\nEnter number of tickets to book: ";
	cin >> n;
	if(n < 1 || n > seat_avl)
		cout << "\nENTER A VALID NUMBER OF SEATS TO BOOK\n";
	else
	{
		//a=0;
		seat_avl -= n;
		for(i = 0; i < n; i++)
		{
			disp(x);
			cout << "\n SSelect seat"<<i+1<<"(eg:A1): ";
			cin >> seat_num;
			status = seat_book();
			if(status)
			{
				cout << "\n ENTER A VALID/NOT RESERVED SEAT NUMBER";
				i--;
			}
			else
			{
				total += price(seat_num[0]);
				strcpy(tot_seat[c++], seat_num);
			}
			if(i == n - 1)
				disp(x);
		}
		cout << "\n TThe total cost of " << n << " tickets is Rs " << total;
		while(1)
		{
			cout << " \n Are you paying through (cash/card)? :  ";
			cin >> pay;
			if(pay == "cash" || pay == "card")
				break;
			cout << "Invalid input enter again!";
		}
		ticket_disp(tot_seat, total, c, pay, x);
		cout << "\n Thank you for booking";
	}

}

void theatre :: ticket_disp(char a[260][4], int price, int c, string pay, int x)
{
	int i;
	cout << "\n\t\t\t=========TICKET==========\n";
	cout << "\t\t\tMovie            : " << movie[x];
	cout << "\n\t\t\tTheatre          : " << name;
	cout << "\n\t\t\tNumber of tickets: " << c;
	cout << "\n\t\t\tSeats            : ";
	for(i = 0; i < c; i++)
		if(i == c - 1)
			cout << a[i];
		else
			cout << a[i] << ',';
	cout << "\n\t\t\tCost             : " << price ;
	cout << "\n\t\t\tPayment done through " << pay << endl;
} 

void theatre ::  disp(int x)
{
	int i, j;
	cout << "\n\n" << name;
	cout << "\n\n\t\t\t\t  SCREEN\n\t\t\t         THIS WAY\n";
	cout << "     Movie: " << movie[x];
	for(i = 0; i < 13; i++)
	{
		cout << endl;
		switch(i)
		{
			case 0 :cout << "\033[1;36m";
				    cout << "     A ";
					cout << "\033[0m";
				    break;
			case 1 :cout << "\033[1;36m";
				    cout << "     B ";
					cout << "\033[0m";
				    break;
			case 2 :cout << "\033[1;36m";
				    cout << "     C ";
					cout << "\033[0m";
				    break;
			case 3 :cout << "\033[1;31m";
				    cout << "     D ";
					cout << "\033[0m";
				    break;
			case 4 :cout << "\033[1;31m";
				    cout << "     E ";
					cout << "\033[0m";
				    break;
			case 5 :cout << "\033[1;31m";
				    cout << "     F ";
					cout << "\033[0m";
				    break;
			case 6 :cout << "\033[1;31m";
				    cout << "     G ";
					cout << "\033[0m";
				    break;
			case 7 :cout << "\033[1;31m";
				    cout << "     H ";
					cout << "\033[0m";
				    break;
			case 8 :cout << "\033[1;31m";
				    cout << "     I ";
					cout << "\033[0m";
				    break;
			case 9 :cout << "\033[1;31m";
				    cout << "     J ";
					cout << "\033[0m";
				    break;
			case 10:cout << "\033[1;33m";
				    cout << "     K ";
					cout << "\033[0m";
				    break;
			case 11:cout << "\033[1;33m";
				    cout << "     L ";
					cout << "\033[0m";
				    break;
			case 12:cout << "\033[1;33m";
				    cout << "     M ";
				    cout << "\033[0m";
				    break;
		}
		for(j = 0; j < 5; j++)
			if(seat[i][j] == 'L')
			{
				cout << "\033[3;32m";
				cout << "  L";
				cout << "\033[0m";
			}
			else if(seat[i][j] == 'R')
			{
				cout << "\033[3;31m";
				cout << "  R";
				cout << "\033[0m";
			}
		cout << "    ";
		for(j = 5; j < 15; j++)
			if(j >= 9)
			{
				if(seat[i][j] == 'L')
				{
					cout << "\033[3;32m";
					cout << "  L";
					cout << "\033[0m";
				}
				else if(seat[i][j] == 'R')
				{
					cout << "\033[3;31m";
					cout << "  R";
					cout << "\033[0m";
				}
			}
			else
			{
				if(seat[i][j] == 'L')
				{
					cout << "\033[3;32m";
					cout << "  L";
					cout << "\033[0m";
				}
				else if(seat[i][j] == 'R')
				{
					cout << "\033[3;31m";
					cout << "  R";
					cout << "\033[0m";
				}
			}
		cout << "     ";
		for(j = 15; j < 20; j++)
			if(seat[i][j] == 'L')
			{
				cout << "\033[3;32m";
				cout << "  L";
				cout << "\033[0m";
			}
			else if(seat[i][j] == 'R')
			{
				cout << "\033[3;31m";
				cout << "  R";
				cout << "\033[0m";
			}
		if(i == 12)
		{
			cout << endl;
			cout << "         ";
			for(j = 0; j < 5; j++)
				cout << j + 1 << "  ";
			cout << "    ";
			for(j = 5; j < 15; j++)
				if(j < 9)
					cout << j + 1 << "  ";
				else
					cout << j + 1 << ' ';
			cout << "     ";
			for(j = 15; j < 20; j++)
				cout << j + 1 << ' ';
		}
	}
	cout << "\033[1;36m";
	cout << endl << endl;
	cout << "     #";
	cout << "(Rs50)each \t";
	cout << "\033[0m";
	cout << "\033[1;31m";
	cout << "#";
	cout << "(Rs150)each \t";
	cout << "\033[0m";
	cout << "\033[1;33m";
	cout << "#";
	cout << "(Rs200)each";
	cout << "\033[0;";
}

int theatre :: seat_book()
{
	int i, j, status = 0;
	seat_num[0] = toupper(seat_num[0]);
	i = (int)seat_num[0];
	i -= 65;
	if(i < 0 || i > 13)
		status = 1;
	else
	{
		switch(seat_num[1])
		{
			case '1':   switch(seat_num[2])
                        {
                            case '0':   j = 9;
                                        break;
                            case '1':   j = 10;
                                        break;
                            case '2':   j = 11;
                                        break;
                            case '3':   j = 12;
                                        break;
                            case '4':   j = 13;
                                        break;
                            case '5':   j = 14;
                                        break;
                            case '6':   j = 15;
                                        break;
                            case '7':   j = 16;
                                        break;
                            case '8':   j = 17;
                                        break;
                            case '9':   j = 18;
                                        break;
                            case '\0':  j = 0;
                                        break;
                            default  :  status = 1;
                        }
                        break;

			case '2':   switch(seat_num[2])
				        {
					        case '0' :  j = 19;
						                break;
					        case '\0':  j = 1;
						                break;
			        		default  : status = 1;
				        }
				        break;

			case '3':   j = 2;
				        break;

			case '4':   j = 3;
				        break;
			case '5':   j = 4;
				        break;
			case '6':   j = 5;
				        break;
			case '7':   j = 6;
				        break;
			case '8':   j = 7;
				        break;
			case '9':   j = 8;
				        break;

			default :   status = 1;
		}
	}
	if(seat[i][j] == 'L' && status == 0)
	{
		seat[i][j] = 'R';
		return 0;
	}
	else
		return 1;

}

void theatre :: fdist(int m)
{
    fdista = m;
}

int miniDist(int distance[], bool Tset[]) 
{
    int minimum = INT_MAX, ind;
              
    for(int k = 0; k < 5; k++) 
    {
        if(Tset[k] == false && distance[k] <= minimum)      
        {
            minimum = distance[k];
            ind = k;
        }
    }
    return ind;
}

int * DijkstraAlgo(int graph[5][5], int src) 
{
    static int distance[5];                           
    bool Tset[5];
    
    for(int k = 0; k < 5; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;                  
    
    for(int k = 0; k < 5; k++)                           
    {
        int m = miniDist(distance, Tset); 
        Tset[m] = true;
        for(int k = 0; k < 5; k++)                  
        {
            if(!Tset[k] && graph[m][k] && distance[m] != INT_MAX && distance[m] + graph[m][k] < distance[k])
                distance[k] = distance[m] + graph[m][k];
        }
    }

    return distance;
}

int main()
{
	
	theatre a[5];
	string movie1[5] = {"KGF 2","Vikram","Major","Don","Black Adam"};
	a[0].values("INOX",movie1);
	string movie2[5] = {"KGF 2","Vikram","Legend","Don","Black Adam"};
	a[1].values("SPI",movie2);
	string movie3[5] = {"KGF 2","Vikram","Major","Don","Black Adam"};
	a[2].values("IMAX",movie3);
	string movie4[5] = {"KGF 2","Vikram","Major","Legend","Black Adam"};
	a[3].values("Sathyam",movie4);
	string movie5[5]  = {"KGF 2","Legend","Major","Don","Black Adam"};
	a[4].values("Mayajal",movie5);
	
    int graph[5][5] = {
        {0, 4, 3, 2, 69},
        {4, 0, 1, 6, 69},
        {3, 1, 0, 69, 7},
        {2, 6, 69, 0, 3},
        {69, 69, 7, 3, 0}};
	
	string movie[6] = {"KGF 2","Vikram","Major","Don","Black Adam","Legend"};
	string area[5] = {"OMR","Adyar","Mylapore","Guindy","Anna Nagar"};
	int x, y, z;
	char b;
	do
	{
	while(1)
	{
    cout << "\033[1;36m";	
	cout << "\nChoose the movie: ";
    cout << "\033[0m";
	for (int i = 0; i < 6; ++i)
		cout << "\n" << i + 1 << " " << movie[i];
    cout << "\033[1;36m";	
	cout << "\n\nEnter your choice: ";
    cout << "\033[0m";
	cin >> x;
	if(x >= 1 && x <= 6)
	{
		x = x - 1;
		break;
	}	
	cout << "\nInvalid input Try again";
	}
	
	while(1)
	{
    cout << "\033[1;36m";	
	cout << "\nChoose your area: ";
    cout << "\033[0m";
	for (int i = 0; i < 5; ++i)
		cout << "\n" << i + 1 << " " << area[i];
    cout << "\033[1;36m";	
	cout << "\n\nEnter your choice: ";
    cout << "\033[0m";
	cin >> y;
	if(y >= 1 && y <= 5)
	{
		y = y - 1;
		break;
	}	
	cout << "\nInvalid input Try again";
	}
	
	int *p;
    p = DijkstraAlgo(graph, y);

    for(int i = 0; i < 5; ++i)
        a[i].fdist(*(p + i));
	
	int td[5];
	for(int i = 0; i < 5; ++i)
	{
		td[i] = *(p + i);
	}
	int st[5];
    cout << "\033[1;36m";	
	cout << "\nThe distance of theatre from " << area[y] << " are: ";
    cout << "\033[0m";
    int flag = 0;
	for(int i = 0; i < 5; ++i) 
		if (!(a[i].available(movie[x]) == -1))
		{
            if (td[i] == 0)
            {
                cout << "\n" << i + 1 << " " << a[i].rname() << " - " << " theatre in the same area!";
			    st[i] = 1; 
                flag = 1;
            }
            else
            {
                cout << "\n" <<i + 1 << " " << a[i].rname() << " - " << td[i] << " kilometre";
			    st[i] = 1;
                flag = 1;
            }
			
		}	
		else
		{
			cout << "\n" << i + 1 << " " << a[i].rname() << " - " << "not screening the movie";
			st[i] = 0;
		}
	if( flag == 0){
        cout << "\n\nmovie currently not screening\n";
    }
    else{
        while(1)
        {
        cout << "\033[1;36m";	
        cout << "\n\nSelect the theatre: ";
        cout << "\033[0m";
        cin >> z;	
        if (z <= 0)
            cout << "Invalid input try again!";
        else if (st[z - 1] == 0)
            cout << "Theatre not screening the movie! Try a different theatre!";
        else 
        {
            z = z - 1;
            break;
        }
        }
        
        a[z].booking(movie[x]);
    }
    system("clear");
    cout << "\033[1;36m";	
	cout << "\n\nDo you wish to continue?(y/n) : ";
    cout << "\033[0m";
	cin >> b;
	} while (b == 'y');
	
	return 0;
}
