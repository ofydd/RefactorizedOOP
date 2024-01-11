#pragma once
#include "dependencies.h"

class Produs
{
public:
	virtual void writeBinary(ofstream& ofs);
	virtual void readBinary(ifstream& ifs);
protected:
	unsigned int idProdus;
	unsigned int stoc;
	float pret;
	Status statusProdus;

public:
	Produs();
	Produs(unsigned int idProdus, unsigned int stoc, float pret, Status status);
	Produs(const Produs& p);
	~Produs();
	
	Produs& operator=(const Produs& p);

	unsigned int getIDProdus(); 
	unsigned int getStoc();
	float getPret();
	Status getStatusProdus();

	void setIDProdus(unsigned int id);
	void setStoc(unsigned int stoc);
	void setPret(float pret);
	void setStatusProdus(Status s);
	
	virtual void display(ostream& os);
	friend ostream& operator<<(ostream& os, Produs* produs);
	
	virtual void read(istream& is);
	friend istream& operator>>(istream& is, Produs* produs);
	
	
	friend ofstream& operator<<(ofstream& ofs, Produs* p);

	
	friend ifstream& operator>>(ifstream& ifs, Produs* p);
};
