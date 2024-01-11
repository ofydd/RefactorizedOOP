#include "Produs.h"
#include "dependencies.h"

Produs::Produs() {
	this->idProdus = 0; // TODO: de randomizat cu random();
	this->stoc = 0;
	this->pret = 0;
	this->statusProdus = Status::Inactiv;
}

Produs::Produs(unsigned int idProdus, unsigned int stoc, float pret, Status status)
{
	if (idProdus > 0)
		this->idProdus = idProdus;
	else
		this->idProdus = 0;
	if (stoc > 0)
		this->stoc = stoc;
	else
		this->stoc = 0;
	if (pret > 0)
		this->pret = pret;
	else
		this->pret = 0;

	this->statusProdus = status;
}

Produs::Produs(const Produs& p)
{
	this->idProdus = p.idProdus;
	this->stoc = p.stoc;
	this->pret = p.pret;
	this->statusProdus = p.statusProdus;
}

Produs& Produs::operator=(const Produs& p) {
	if (&p != this)
	{
		this->idProdus = p.idProdus; //TODO: de gandit daca merita sa schimb id-ul produsului aici, desi nu cred. 
		this->stoc = p.stoc;
		this->pret = p.pret;
		this->statusProdus = p.statusProdus;
	}
	else
		throw exception("Autoasignare");
	return *this;
}

unsigned int Produs::getIDProdus() { return this->idProdus; }
void Produs::setIDProdus(unsigned int id)
{
	if (id != 0) { this->idProdus = id; }	
}

unsigned int Produs::getStoc() { return this->stoc; }
void Produs::setStoc(unsigned int stoc)
{
	if (stoc > 0)
		this->stoc = stoc;
}

float Produs::getPret() { return this->pret; }
void Produs::setPret(float pret)
{
	if (pret > 0)
		this->pret = pret;
}

Status Produs::getStatusProdus() { return this->statusProdus; }
void Produs::setStatusProdus(Status s)
{
	this->statusProdus = s; //TODO: daca exista validari, ar trebui sa le fac.
}

void Produs::display(ostream& os) //virtual
{
	os << "idProdus: " << this->idProdus << endl;
	os << "stoc: " << this->stoc << endl;
	os << "pret: " << this->pret << endl;
	os << "status: " << this->statusProdus << endl;
}

ostream& operator<<(ostream& os, Produs* produs)
{
	produs->display(os);
	return os;
}

void Produs::read(istream& is) //virtual
{
	cout << "Introduceti id-ul produsului: ";
	is >> this->idProdus;
	cout << "Introduceti pretul: ";
	is >> this->pret;
	cout << "Introduceti cantitatea in stoc: ";
	is >> this->stoc;
	is >> this->statusProdus;
}

istream& operator>>(istream& is, Produs* produs)
{
	produs->read(is);
	return is;
}


void Produs::writeBinary(ofstream& ofs) //virtual
{
	ofs.write((char*)&idProdus, sizeof(idProdus));
	ofs.write((char*)&stoc, sizeof(stoc));
	ofs.write((char*)&pret, sizeof(pret));
	ofs.write((char*)&statusProdus, sizeof(statusProdus));
}

void Produs::readBinary(ifstream& ifs)
{
	ifs.read((char*)&idProdus, sizeof(idProdus));
	ifs.read((char*)&stoc, sizeof(stoc));
	ifs.read((char*)&pret, sizeof(pret));
	ifs.read((char*)&statusProdus, sizeof(statusProdus));
}


ofstream& operator<<(ofstream& ofs, Produs* p)
{
	p->writeBinary(ofs);
	return ofs;
}

ifstream& operator>>(ifstream& ifs, Produs* p)
{
	p->readBinary(ifs);
	return ifs;
}

Produs::~Produs() {}