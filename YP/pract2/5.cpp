/*Программа для моделирования колоды карт
 * Язык программирования: С++
 * Автор: Ольшевская О.И., гр. 18ПИ1 
 * */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Card {
	int rank; //ранг
	int suit; //масть
	Card() {};
	Card (int r, int s): rank(r), suit(s) {};
	friend ostream& operator << (ostream& outputStream, Card c) {
		string s[] = {"heart","diamond","club","spade"}; // массив с мастями
		string r[] = {"six","seven","eight","nine","ten","Jack","Queen","King","Ace"}; //массив с рангом
		return outputStream << r[c.rank] + " " + s[c.suit];
	}

};

bool SameColor (Card a, Card b)
{
	if ((a.suit == b.suit) || (a.suit == 0 && b.suit == 1) || (a.suit == 2 && b.suit == 3) || (b.suit == 1 && a.suit == 0) || (b.suit == 3 && a.suit == 2))
		return true;
	else return false;
}
bool SameRank (Card a, Card b)
{
	if (a.rank == b.rank)
		return true;
	else return false;
}

bool IsQueen(Card a)
{
	return (a.rank== 6 && a.suit == 3);
}

bool IsAce(Card a)
{
	return (a.rank == 8);
}

int main(int argc, char **argv)
{
	vector <Card> deck;
	//заполнение колоды
	for (int j=0; j<4; j++) {
		for (int i=0; i<9; i++) {
			deck.push_back(Card(i, j));
		}
	}
	for (int i=0; i<36; i++)
		cout << deck[i] << endl;
	cout << "---------------------\n" ;
	//перемешивание колоды
	random_shuffle(deck.begin(),deck.end());
	for (int i=0; i<36; i++)
		cout << i+1 << " " << deck[i] << endl;
	//поиск карт, одинаковых по цвету
	for (auto it = ++deck.begin(); it < deck.end(); it++) {
		it = adjacent_find (--it, deck.end(), SameColor);
		if (it != deck.end())
			cout << "Карты одного цвета: " <<*(it) <<" и " <<*(it++)<<'\n';
	}
	
	//поиск карт, одинаковых по номиналу
	for (auto it = ++deck.begin(); it < deck.end(); it++) {
		it = adjacent_find (--it, deck.end(), SameRank);
		if (it != deck.end())
			cout << "Карты одного ранга: " << *(it) <<" и " <<*(it++)<<'\n';
	}
	//поиск позиции пиковой дамы
	auto it = find_if (deck.begin(), deck.end(), IsQueen);
	cout << "Пиковая дама " << distance(deck.begin(), it) + 1 << "-я в колоде" <<endl;
	//поиск позиции тузов
	cout << "Тузы в колоде на ";
	it = deck.begin()-1;
	for (int i = 0; i < 4; i++) {
		it = find_if(it+1, deck.end(), IsAce);
		cout<< distance(deck.begin(), it) + 1 << " ";
	}
	cout << "позициях" << endl;
	return 0;
}
