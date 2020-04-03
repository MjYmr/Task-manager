/*
编写开始于：中国广东中山 2020/4/2 21:00
编写结束于：中国广东中山 2020/4/3 10:45
编写人：Ij 
*/ 
#include <cstdio>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h> 
#include <cstring>
using namespace std;
char name[100][100];
char thing[100][500];
char ps[100][500];
int n;
int mx, my;
int del[100];


void gotoxy(int y, int x) 
{
	COORD pos = {x,y};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}

void draw_frame()
{
	gotoxy(0,0);
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	cout<<"|名称            |说明                                              |备注              |"<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"|                |                                                  |                  |"<<endl;
	cout<<"----------------------------------------------------------------------------------------"<<endl;
}

void init(int k)
{
	ifstream in;
	in.open("fpc.txt");
	if(k == 1)
	{
		in >> n;
	}
	if(k == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			in >> name[i];
			in >> thing[i];
			in >> ps[i];	
		}
	}
	for(int i = 1; i <= 20; i++)
	{
		gotoxy(3 + i - 1,1);
		cout << name[i];
		gotoxy(3 + i - 1,18);
		cout << thing[i];
		gotoxy(3 + i - 1,69);
		cout << ps[i];
		gotoxy(mx,my);
	}
	in.close();
}

void click(int p)
{
	gotoxy(1,90);
	cout<<"操作成功！";
	gotoxy(mx,my); 
	switch(p)
	{
		case 14:{
			int px = mx - 2;
			int py = my;
			system("cls");
			if(py <= 16)
			{
				cout << "任务" << "名称 " << px << ": ";
				cin >> name[px];
			}
			if(py >= 18 && py <= 67)
			{
				cout << "说明 " << px <<": ";
				cin >> thing[px];
			}
			if(py >= 69)
			{
				cout << "备注 " << px <<": ";
				cin >> ps[px];
			}
			system("cls");
			draw_frame();
			init(0);
			break;
		}
		case 44:{
			if(my == 0)
				break;
			gotoxy(mx,my - 1);
			my--;
			break;
		}
		case 46:{
			gotoxy(mx + 1,my);
			mx++;
			break;
		}
		case 47:{
			gotoxy(mx,my + 1);
			my++;
			break;
		}
		case 59:{
			if(mx == 0)
				break;
			gotoxy(mx - 1,my);
			mx--;
			break;
		}
		case 4:{
			int px = mx - 2;
			del[px] = 1;
			break;
		}
	}
}

void end()
{
	ofstream out;
	out.open("fpc.txt");
	n = 0;
	for(int i = 1; i <= 100; i++)
	{
		if(strlen(name[i]) == 0)
			continue;
		if(del[i] == 1)
			continue;
		n++;
	}
	out<<n<<endl;
	for(int i = 1; i <= 100; i++)
	{
		if(strlen(name[i]) == 0)
			continue;
		if(del[i] == 1)
			continue;	
		out<<name[i]<<endl;
		out<<thing[i]<<endl;
		out<<ps[i]<<endl;
	}
	out.close();
}

int main()
{
	draw_frame();
	init(1); 
	while(true)
	{
		char ch;
		if(kbhit())
		{
			gotoxy(0,90);
			cout<<"光标位置："<<mx<<","<<my<<"       ";
			gotoxy(mx,my); 
			ch = getch();
			switch(ch)
			{
				case 14:click(14);break;//Ctrl+N
				case 44:click(44);break; 
				case 46:click(46);break;
				case 47:click(47);break;
				case 59:click(59);break;
				case 4:click(4);break;
				case 27:{
					end();
					exit(0);
					break;
				}
			}
		}
	}
//	while(1)
//	{
//		system("cls");
//		gotoxy(0,0);
//		char ch;
//		ch = getch();
//		printf("%d", ch);
//	}
	return 0;
}
