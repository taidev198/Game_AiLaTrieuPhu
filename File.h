#ifndef FILE_H
#define FILE_H
#include <fstream>
#include<iostream>

using namespace std;
struct Info
{
	char Quest[100];
	char key;
	char A1[30];
	char A2[30];
	char A3[30];
	char A4[30];
	int ThuTu;
};
void gotoxy(int x, int y);
void MENU();//MENU CHOICE
void Play();
void PrintBlockHelp();
void Help(Info&,int);//TH HELP OF PROGRAMIGNG
void Print(Info& );
void PrintBlock();//PRINT BLOCK ANSWER
void PrintBigBlock();//PRINT BLOCK QUESTION
void ReadQuestAndAnswer(string);//playsound for string file name
void WriteFile();//write data file on the file
void Assignmet(int,Info&);//assignment value in the file to variable
void ReadFile();//read file and display on screen.
bool Check(int,Info);//check for key
void Choice(Info&);//THE CHOICE OF USER
#endif