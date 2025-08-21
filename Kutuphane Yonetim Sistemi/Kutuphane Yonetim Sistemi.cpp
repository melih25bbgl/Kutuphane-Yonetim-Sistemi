// Kutuphane Yonetim Sistemi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>
#include <cctype> 
#include "Kitap.h"
using namespace std;

bool KontrolString(const string& str) {
    for (char ch : str) {  // butun karakterlerin kontrolu icin dongu tanimlamasi
        if (!isdigit(ch))  // integer olmama durumu 
            return false;  // false
    }
    return !str.empty();  // string bos degilse true
}
void KitapEkle(map<int,Kitap>& mKutuphane) {
    string kitapAd, yazarAd;
    int kitapID,rafNum;
    try{
        cout << "Kitap ID : ";
        cin >> kitapID;
        if (cin.fail()) {
            cin.clear();  // hata bayragini sifirla
            cin.ignore(1000, '\n');  // tampondaki geçersiz girdiyi temizle
            throw 100;  // kitapID string olamaz hata firlat
        }
        cin.ignore();
        cout << "Kitap Adi : ";
        getline(cin, kitapAd);
        if (KontrolString(kitapAd)) {
            throw 101; // Kitap adý sayý olamaz
        }
        cout << "Yazar Adi : ";
        getline(cin, yazarAd);
        if (KontrolString(yazarAd)) {
            throw 102; // Yazar adý sayý olamaz
        }
        cout << "Raf Numarasi : ";
        cin >> rafNum;
        if (cin.fail()) {
            cin.clear();  // hata bayragini sifirla
            cin.ignore(1000, '\n');  // tampondaki geçersiz girdiyi temizle
            throw 103;  // rafNum string olamaz hata firlat
        }
        cout << "Kitap Ekleniyor ..." << endl;
        mKutuphane.insert({ kitapID,Kitap(kitapAd,yazarAd,rafNum) });
    }
    catch (int hataKodu) {
        cout << "Bir exception olustu , hata kodu : " << hataKodu << endl;
        if (hataKodu == 100)
            cout << "Kitap ID string deger olamaz !" << endl;
        else if(hataKodu == 101)
            cout << "Kitap Adi integer deger olamaz !" << endl;
        else if (hataKodu == 102)
            cout << "Yazar Adi integer deger olamaz !" << endl;
        else if (hataKodu == 103)
            cout << "Raf Numarasi string deger olamaz !" << endl;
    }
}
void KitapAra(map<int, Kitap>& mKutuphane) {
    int kitapIDN;
    cout << "Aranacak Kitap ID : ";
    cin >> kitapIDN;
    auto it = mKutuphane.find(kitapIDN);
    if (it != mKutuphane.end()) {
        cout << "Kitap bulundu bilgileri asagidaki gibidir : " << endl;
        const Kitap& kitap = it->second;  // pair (ID,Kitap) Kitap nesnesine eris
        cout << "Kitap Adi : " << kitap.getKitapAdi() << " | Yazari : " << kitap.getYazarAdi() << " | Raf Numarasi : " << kitap.getRafNo() << endl;;
    }
    else {
        cout << "\n" << kitapIDN << " ID li kitap bulunamadi." << endl;
    }
}
void KitapSil(map<int, Kitap>& mKutuphane) {
    int kitapIDN;
    cout << "Silinecek Kitap ID : ";
    cin >> kitapIDN;
    if (mKutuphane.erase(kitapIDN)) {
        cout << "Kitap Silindi !" << endl;
    }
    else
        cout << "Kitap Bulunamadi !" << endl;
}
void kitapListele(map<int, Kitap>& mKutuphane) {
    if (mKutuphane.empty()) {
        cout << "Kutuphanede Kayitli Kitap Bulunmuyor !" << endl;
        return;
    }
    cout << "* * * * Kutuphanedeki Kitaplar * * * *" << endl;
    for (const auto& kitapPair : mKutuphane) {
        cout << "Kitap ID : " << kitapPair.first
            << " | Kitap Adi : " << kitapPair.second.getKitapAdi()
            << " | Yazari : " << kitapPair.second.getYazarAdi()
            << " | Raf Numarasi : " << kitapPair.second.getRafNo() << endl;
    }
}
int main()
{
    map<int, Kitap> mKutuphane;  // map tanimi
    int input;
    do {
        cout << "- - - - Kutuphane Yonetim Sistemi - - - -" << endl;
        cout << "1. Kitap Ekleme" << endl;
        cout << "2. Kitap Bilgileri Goruntule" << endl;
        cout << "3. Kitap Silme" << endl;
        cout << "4. Tum Kitaplari Listele" << endl;
        cout << "5. Cikis" << endl;
        cout << "Seciminizi Yapin : ";
        cin >> input;
        switch (input) {
        case 1:
            KitapEkle(mKutuphane);
            break;
        case 2:
            KitapAra(mKutuphane);
            break;
        case 3:
            KitapSil(mKutuphane);
            break;
        case 4:
            kitapListele(mKutuphane);
            break;
        case 5:
            cout << "Cikis Yapiliyor ..." << endl;
            break;
        default:
            cout << "! Yanlis Deger Girdiniz !" << endl;
        }
    } while (input != 5);
    return 0;
}