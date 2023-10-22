


#include <string.h>  
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <functional>
#include <array>
#include <algorithm>
#include <fstream>
using namespace std;


int  i = 0,j = 0, l = 0;
char *token1 = NULL;
char *next_token1 = NULL;

struct Playar
{
public:
	string fn, ln, gp, lg, id;
	int pts, oreb, dreb, to, asts, stl, blk, min;

};

Playar D[4000];



double sh(Playar a, Playar b)
{
	int a1 = a.pts, a2 = a.oreb, a3 = a.dreb, a4 = a.to, a5 = a.asts, a6 = a.stl, a7 = a.blk;
	int b1 = b.pts, b2 = b.oreb, b3 = b.dreb, b4 = b.to, b5 = b.asts, b6 = b.stl, b7 = b.blk;
	return abs((a1*b1 + a2*b2 + a3*b3 + a4*b4 + a5*b5 + a6*b6 + a7*b7) / ((sqrt(pow(a1, 2) + pow(a2, 2) + pow(a3, 2) + pow(a4, 2) + pow(a5, 2) + pow(a6, 2) + pow(a7, 2)))*(sqrt(pow(b1, 2) + pow(b2, 2) + pow(b3, 2) + pow(b4, 2) + pow(b5, 2) + pow(b6, 2) + pow(b7, 2)))));
};



int main(void)
{
	ifstream file("t1.txt");
	
	for (int i = 0;i<3115;i++)
	{

		

		char string1[200];
		file.getline(string1, 199);
		string X[21];
		
		token1 = strtok_s(string1, ",", &next_token1);
		j=0;
		
		while ((token1 != NULL))
		{
		// Get next token:
			if (token1 != NULL)
			{
				X[j] = token1;
				token1 = strtok_s(NULL, ",", &next_token1);
			}
			j++;
		}
		
		
		D[i].id = X[0];
		D[i].fn = X[1];
		D[i].ln = X[2];
		D[i].lg = X[3];
		D[i].gp = X[4];
		D[i].min = atoi(X[5].c_str());
		D[i].pts = atoi(X[6].c_str());
		D[i].oreb = atoi(X[7].c_str());
		D[i].dreb = atoi(X[8].c_str());
		D[i].asts = atoi(X[10].c_str());
		D[i].stl = atoi(X[11].c_str());
		D[i].blk = atoi(X[12].c_str());
		D[i].to = atoi(X[13].c_str());
	}
	

	file.close();

	
	cout << "Please enter the First name of playar."<<endl;
	string Fn, Ln;
	cin >> Fn;
	cout << "Now, please enter the Last name of playar "<<endl;
	cin >> Ln;

	

	int R = 0;
	for (i = 0;i < 3115;i++) if (Fn == D[i].fn && Ln == D[i].ln) { R = i;break; }
	Playar U = D[R];



	double q[3567];

	for (i = 0;i < 3115;i++)
	{
		if (i == R) q[i] = 0;
		else q[i] = sh(U, D[i]);
	}

	double m1 = -1;
	int r1 = 0;
	double m2 = -1;
	int r2 = 0;
	double m3 = -1;
	int r3 = 0;
	double m4 = -1;
	int r4 = 0;
	double m5 = -1;
	int r5 = 0;

	for (i = 0;i < 3567;i++) if (q[i] > m1) { m1 = q[i]; r1 = i; }
	for (i = 0;i < 3567;i++) if (q[i] > m2 && q[i]<m1) { m2 = q[i]; r2 = i; }
	for (i = 0;i < 3567;i++) if (q[i] > m3 && q[i]<m2) { m3 = q[i]; r3 = i; }
	for (i = 0;i < 3567;i++) if (q[i] > m4 && q[i]<m3) { m4 = q[i]; r4 = i; }
	for (i = 0;i < 3567;i++) if (q[i] > m5 && q[i]<m4) { m5 = q[i]; r5 = i; }



	cout <<
		"These 5 playars are recommend for you:" << endl
		<<
		D[r1].fn << " " << D[r1].ln << " " << m1 << " shebahat" << endl
		<<
		D[r2].fn << " " << D[r2].ln << " " << m2 << " shebahat" << endl
		<<
		D[r3].fn << " " << D[r3].ln << " " << m3 << " shebahat" << endl
		<<
		D[r4].fn << " " << D[r4].ln << " " << m4 << " shebahat" << endl
		<<
		D[r5].fn << " " << D[r5].ln << " " << m5 << " shebahat" << endl
		;


	_getch();

}

