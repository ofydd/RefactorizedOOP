#pragma once
#include "Vinyl.h"

class Comanda
{
private:
	unsigned int idComanda;
	char* numeClient;
	char* prenumeClient;
	float valoareComanda; //TODO: De transformat in calculeazaValoareComanda();
	int numarProduse;
public:
	Produs** produse;

	friend ofstream& operator<<(ofstream& ofs, Comanda& c);
	friend ifstream& operator>>(ifstream& ifs, Comanda& c);
	void writeBinary(ofstream& ofs);
	void readBinary(ifstream& ifs);

	Comanda();

	Comanda(unsigned int idComanda, const char* numeClient, const char* prenumeClient, float valoareComanda, Produs** produse, int numarProduse);
	Comanda(const Comanda& comanda);
	Comanda& operator=(const Comanda& co);
	
	char* getNumeClient(); 
	unsigned int getIDComanda(); 
	char* getPrenumeClient();
	float getValoareComanda(); 
	int getNumarProduse();
	// setNumarProduse nu are sens, caci nu vreau ca utilizatorul sa poata sa modifice numarul de produse, caci va strica vectorul.

	void setIDComanda(unsigned int comanda);
	void setNumeClient(const char* numeClient);
	void setPrenumeClient(const char* prenumeClient);
	void setValoareComanda(float valoareComanda);

	void operator+=(Produs* produs);
	void operator-=(Produs* produs);
	Produs* operator[](int index);
	
	friend ostream& operator<<(ostream& os, const Comanda& c);
	friend istream& operator>>(istream& is, Comanda& c);

	~Comanda();
	

};
