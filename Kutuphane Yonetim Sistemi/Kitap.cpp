#include <iostream>
#include <map>
#include <string>
#include "Kitap.h"

// Constructor
Kitap::Kitap(string _kitapAdi = "", string _yazarAdi = "", int _rafNo = 0) : kitapAdi(_kitapAdi), yazarAdi(_yazarAdi), rafNo(_rafNo) {}
// getKitapAdi
string Kitap::getKitapAdi() const { return kitapAdi; }
// getYazarAdi
string Kitap::getYazarAdi() const { return yazarAdi; }
// getRafNo
int Kitap::getRafNo() const { return rafNo; }