#include <fstream>
#include<iostream>
//#include<graphics.h>
#include"File.h"
#include<conio.h>
#include<string>
#include<ctime>
#include<Windows.h>
#include<mmsystem.h>

using namespace std;
int money = 0;
int CheckHelp;
// Hàm thay đổi kích cỡ của khung cmd.
//void resizeConsole(int width, int height)
//{
//	HWND console = GetConsoleWindow();
//	RECT r;
//	GetWindowRect(console, &r);
//	MoveWindow(console, r.left, r.top, width, height, TRUE);
//}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void MENU()
{
//	resizeConsole(1000, 500);//rộng 800px,dài 500px

	system("color 1C");
	//PlaySound(TEXT("MUSIC/MUSIC BACKGROUND.wav"), NULL, SND_ALIAS_START);
	system("cls");//clean sreen
	gotoxy(20, 10);
	cout << "===============================MENU======================================";
	gotoxy(50, 12);
	cout << "F1::PLAY";
	gotoxy(50, 14);
	cout << "F2::HUONG DAN";
	gotoxy(50, 16);
	cout << "F3::ABOUT ME";
	gotoxy(50, 18);
	cout << "F4::EXIT";
	_getch();
	if(GetAsyncKeyState(VK_F2))//huong dan
	{
		system("cls");
		gotoxy(10, 10);
		string s = "DUNG CAC PHIM 1,2,3,4 DE LUA CHON .DUNG CAC PHIM A.B.C.D DE LUA CHON DAP AN";
		cout << s;
		PlaySound(TEXT("PRESENT/HUONG DAN.wav"), NULL, SND_ALIAS_START);
		gotoxy(10, 10);
		for (int i = 0; i < s.length(); i++)
		{
			Sleep(100);
			textcolor(7);
			cout << s[i];
		}
		Sleep(5000);
			MENU();
	}
	//else if (choice == 'a'||choice == 'A')
	else if(GetAsyncKeyState(VK_F1))
	{
		system("cls");
		Play();
	}
	else if (GetAsyncKeyState(VK_F3))
	{
		system("cls");
		gotoxy(1, 10);
		textcolor(14);
		cout << "NAME:NGUYEN THANH TAI" << endl << "ADDR:TIEN THANG - ME LINH -HA NOI"<<endl<<"SCHOOL:KMA"<<endl<<"PHONE:01627249988"<<endl<<"EMAIL:TRAIGIUXOM9X@GMAIL.COM";
		PlaySound(TEXT("PRESENT/ABOUT.wav"), NULL, SND_ALIAS_START);
		Sleep(5000);
			MENU();
	}
	else if (GetAsyncKeyState(VK_F6))
	{
		system("cls");
		PlaySound(TEXT("PRESENT/ABOUT.wav"), NULL, SND_ALIAS_START);
	}
	else if (GetAsyncKeyState(VK_F4))
	{
		exit(0);
	}
}

void Play()
{
	Info data;
	int i = 0;
	PrintBlockHelp();
	gotoxy(1, 13);
	cout << "SO TIEN HIEN TAI LA:" << money << "  VND";
	PlaySound(TEXT("MUSIC/PRESENT.wav"), NULL, SND_LOOP);
	while (i < 15)
	{
		system("cls");
		PrintBlockHelp();
		gotoxy(1,13);
		cout << "SO TIEN HIEN TAI LA:" << money<<"  VND";
		srand(time(NULL));
		int a = rand() % 12;
		Assignmet(a,data);
		i++;
		Sleep(5000);
	}

}

void PrintBlockHelp()
{
	fstream fileIn("BLOCK.txt", ios::in);
	char ch;
	while (!fileIn.eof())
	{
		fileIn.get(ch);
		cout << ch;
	}
	fileIn.close();
}

void Help(Info& data,int value)
{

	if (value==5)
	{

	}
	else if (value==6)
	{
		if (data.key == 1)
		{
			gotoxy(2, 30);
			cout << "SYSTEM DELETE TWO WRONG ANSWER !!:" <<" B,D " ;
		}

		else if(data.key == 2)
			cout << "SYSTEM DELETE TWO WRONG ANSWER !!:" << " A,C ";
		else if (data.key == 3)
			cout << "SYSTEM DELETE TWO WRONG ANSWER !!:" << " A,D ";
		else if (data.key == 4)
			cout << "SYSTEM DELETE TWO WRONG ANSWER !!:" << " A,C ";
	}
}

void Print(Info &data)
{
	string n = data.Quest;
	int size = n.length();
	int i = 1;
	gotoxy((85 - size) / 2 - 8, 2);
	cout << "CAU :"<<i++;
	gotoxy((85-size)/2, 2);
	cout << data.Quest;
	Sleep(5000);
	gotoxy(3, 7);
	cout << "A:" << data.A1;
	gotoxy(27, 7);
	cout << "B:" << data.A2;
	gotoxy(3, 10);
	cout << "C:" << data.A3;
	gotoxy(27, 10);
	cout << "D:" << data.A4;
	switch (data.ThuTu)
	{
	case 0:PlaySound(TEXT("cau0.wav"), NULL, SND_ASYNC);
		break;
	case 1:PlaySound(TEXT("cau1.wav"), NULL, SND_LOOP);
		break;
	case 2:PlaySound(TEXT("cau2.wav"), NULL, SND_LOOP);
		break;
	case 3:PlaySound(TEXT("cau3.wav"), NULL, SND_LOOP);
		break;
	case 4:PlaySound(TEXT("cau4.wav"), NULL, SND_LOOP);
		break;
	case 5:PlaySound(TEXT("cau5.wav"), NULL, SND_LOOP);
		break;
	case 6:PlaySound(TEXT("cau6.wav"), NULL, SND_LOOP);
		break;
	case 7:PlaySound(TEXT("cau7.wav"), NULL, SND_LOOP);
		break;
	case 8:PlaySound(TEXT("cau8.wav"), NULL, SND_LOOP);
		break;
	case 9:PlaySound(TEXT("cau9.wav"), NULL, SND_LOOP);
		break;
	case 10:PlaySound(TEXT("cau10.wav"), NULL, SND_LOOP);
		break;
	case 11:PlaySound(TEXT("cau11.wav"), NULL, SND_LOOP);
		break;
	default:
		break;
	}
	PlaySound(TEXT("MUSIC/WAITANSWER.wav"), NULL, SND_ASYNC);//vua chay nhac vua chay lenh
	Choice(data);
}

void PrintBlock()
{
	fstream fileIn("KHUNG.txt", ios::in);
	char ch;
	textcolor(10);
	while (!fileIn.eof())
	{
		fileIn.get(ch);
		cout << ch;
	}
	fileIn.close();
	textcolor(7);
}

void PrintBigBlock()
{
	fstream fileIn("KHUNGQ.txt", ios::in);
	char ch;
	textcolor(10);
	while (!fileIn.eof())
	{
		fileIn.get(ch);
		cout << ch;
	}
	fileIn.close();
	textcolor(7);
}

void ReadQuestAndAnswer(string filename)
{
	PlaySound(TEXT("filename"), NULL, SND_LOOP);
}
void WriteFile()
{
		int again;
		fstream data("data1.dat",ios::out|ios::binary);//write data in the  binary file
		Info Data;
		if(!data)
		{
			cout<<"File cannot opened!!";
			exit(0);
		}
		do
		{
		cout<<"Thu Tu:";
		cin>>Data.ThuTu;
		cin.ignore();
		cout<<endl<<"Cau Hoi:";
		cin.getline(Data.Quest,100);
		data.clear();
		cout<<endl<<"Answer:";
		cin.getline(Data.A1,30);
		cout<<endl<<"Answer:";
		cin.getline(Data.A2,30);
		cout<<endl<<"Answer:";
		cin.getline(Data.A3,30);
		cout<<endl<<"Answer:";
		cin.getline(Data.A4,30);
		//cin.ignore();
		cout<<endl<<"Key:";
		cin>>Data.key;
		data.write(reinterpret_cast<char*>(&Data),sizeof(Data));
		cout<<endl<<"again? enter #1:";
		cin>>again;
		}while(again!=1);

		data.close();
}
void Assignmet(int value,Info &data)
{
	fstream data1("data1.dat", ios::in | ios::binary);//read data in the  binary file
	data1.seekg(value * sizeof(Info), ios::beg);
	data1.read(reinterpret_cast<char*>(&data), sizeof(data));
	Print(data);
}
void ReadFile()
{
	Info Data;
	fstream data1("data1.dat", ios::in | ios::binary);//read data in the  binary file
	srand(time(NULL));
	int a = rand() % 12;
	data1.seekg(a * sizeof(Info), ios::beg);
	data1.read(reinterpret_cast<char*>(&Data), sizeof(Data));
	cout << "Thu Tu:";
	cout << Data.ThuTu;
	cout << endl << "Cau Hoi:";
	cout << Data.Quest;
	cout << endl << "Answer:";
	cout << Data.A1;
	cout << endl << "Answer:";
	cout << Data.A2;
	cout << endl << "Answer:";
	cout << Data.A3;
	cout << endl << "Answer:";
	cout << Data.A4;
	cout << endl << "Key:";
	cout << Data.key;
	data1.close();
}

bool Check(int choice, Info data)
{
	return (choice == data.key);
}

void Choice(Info &data)
{
	int choice;
	gotoxy(1, 17);
	cout << "CAU TRA LOI CUA BAN?:";cin >> choice;
	gotoxy(1, 18);
	cout << "KEY:" << data.key;
	
		if (data.key!=choice)
		{
			Beep(500, 100);
			Beep(500, 100);
			MessageBoxA(NULL, "INCORRECT!", "NOTIFICATION", MB_OKCANCEL);
			system("cls");
			gotoxy(15, 10);
			cout << " CHUC MUNG BAN!";
			gotoxy(15, 12);
			PlaySound(TEXT("MUSIC/CORRECT.wav"), NULL, SND_RING);
			cout << " SO TIEN CUA BAN LA:" << money << "   VND";
			Sleep(5000);
			exit(0);
		}
		if(Check( choice, data))
		{
			PlaySound(TEXT("MUSIC/CORRECT.wav"), NULL, SND_LOOP);
			MessageBoxA(NULL, "CORRECT", "NOTIFICATION", MB_OKCANCEL);
			money += 100;
			gotoxy(2, 16);
			cout << "CHUC MUNG BAN DUOC CONG THEM 100K!!";
		}
	//}
}
