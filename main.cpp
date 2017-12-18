#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

#define REGSIZE 32
#define MEMSIZE 320

/*�ci�ga do instrukcji
Rtype R1 R2 R3
ADD - dodawanie
MUL - mno�enie
SUB - odejmowanie
ADD i MUL s� tylko specjalnymi przypadkami Rtype ale z dzieleniem raczej nie b�dziey mieli do czynienia

LW R4 100 R5

SW R6 100 R7

BEQ R8 R9 loop

Rliczba - jeden unsigned int oznaczaj�cy adres rejestru zapisany w wektorze registerTab
loop - mo�na pomin��
*/

using namespace std;

enum insType
{
	Rtype = 0, //instrukcje operacji mo�e by� uzywany jako zape�niacz
	ADD = 1, //dodanie
	MUL = 2, //mno�enie
	SUB = 3, //odejmowanie
	LW = 4, //zapisanie z reg -> mem
	SW = 5, //wczytanie z mem -> reg
	BEQ = 6, //skok warunkwy
	NOP = 7 //nic
};

//instrukcja sk�ada si� z nazwy (typu) oraz indeks�w rejestr�w. 
//niekt�re mog� by� nie wype�nione lub wype�nione losowo w zale�no�ci od typu instrukcji
struct instruction
{
	insType type;
	unsigned int reg1;
	unsigned int reg2;
	unsigned int reg3;
};

vector<bool> regLock; //czy dany rejestr jest zabolowany
vector<int> reg; //warto�ci wewn�trz rejestr�w
vector<int> mem; //warto�ci wewn�trz pami�ci
vector<instruction> ins; //lista instrukcji procesora

void ReadInstructions(fstream &f) //wczytanie instrukcji z pliku
{
	
}

int main(int argc, char** argv)
{
	for(int i = 0; i < REGSIZE; ++i) //inicjalizacja rejestr�w
	{
		reg.push_back(0);
		regLock.push_back(false);
	}
	for(int i = 0; i < MEMSIZE; ++i) //inicjalizacji pami�ci
	{
		mem.push_back(0);
	}
	
	//inicjalizacjia instrukcji
	fstream file;
	file.open("instruction.txt", fstream::in);
	ReadInstructions(file);
	
	
	return 0;
}
