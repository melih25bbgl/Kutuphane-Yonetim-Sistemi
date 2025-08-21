#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Kitap {
public:
	//Constructor
	Kitap(string _kitapAdi, string _yazarAdi, int _rafNo);
	string getKitapAdi()const;
	string getYazarAdi()const;
	int getRafNo()const;
private:
	string kitapAdi;
	string yazarAdi;
	int rafNo;
};