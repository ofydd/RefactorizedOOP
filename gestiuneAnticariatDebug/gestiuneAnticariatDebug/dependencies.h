#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


enum Status {
	Activ,
	Inactiv
};
ostream& operator<<(ostream& os, const Status& status);
istream& operator>>(istream& is, Status& status);

enum Categorie	//TODO: Implementare in cadrul clasei de baza.
{
	Carti,
	Vinyluri,
	Nedefinit //pentru cazul default din switch(categorie) si pentru constructorul fara parametri
};
ostream& operator<<(ostream& os, const Categorie& categorie);
istream& operator>>(istream& is, Categorie& categorie);

enum genLiterar
{
	Filosofie,
	IstoriaReligiilor,
	Istorie,
	Proza,
	Poezie,
	Psihologie,
	LiterarNedefinit
};
ostream& operator<<(ostream& os, const genLiterar& gen);
istream& operator>>(istream& is, genLiterar& gen);

enum genMuzical
{
	Rock,
	Metal,
	Clasica,
	Pop,
	Populara,
	MuzicalNedefinit
};
ostream& operator<<(ostream& os, const genMuzical& gen);
istream& operator>>(istream& is, genMuzical& gen);