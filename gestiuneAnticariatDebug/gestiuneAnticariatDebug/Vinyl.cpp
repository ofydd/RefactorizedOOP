#include "Vinyl.h"

Vinyl::Vinyl() : Produs()
{
	this->numeAlbum = new char[10];
	strcpy_s(this->numeAlbum, 10, "undefined");
	this->artist = new char[10];
	strcpy_s(this->artist, 10, "undefined");
	this->numarPiese = 0;
	this->durata = 0;
	this->gen_muzical = genMuzical::MuzicalNedefinit;
}

Vinyl::Vinyl(unsigned int idProdus, unsigned int stoc, float pret, Status status,
		     const char* numeAlbum, const char* numeArtist, unsigned int nrPiese, 
	         float length, genMuzical gm) : Produs(idProdus, stoc, pret, status){
	if (strlen(numeAlbum) > 0)
	{
		if (this->numeAlbum != NULL)
			delete[] this->numeAlbum;
		this->numeAlbum = new char[strlen(numeAlbum) + 1];
		strcpy_s(this->numeAlbum, strlen(numeAlbum) + 1, numeAlbum);
	}
	else
	{
		if (this->numeAlbum != NULL)
			delete[] this->numeAlbum;
		this->numeAlbum = new char[10];
		strcpy_s(this->numeAlbum, 10, "undefined");
	}

	if (strlen(numeArtist) > 0)
	{
		if (this->artist != NULL)
			delete[] this->artist;
		this->artist = new char[strlen(numeArtist) + 1];
		strcpy_s(this->artist, strlen(numeArtist) + 1, numeArtist);
	}
	else
	{
		if (this->artist != NULL)
			delete[] this->artist;
		this->artist = new char[sizeof(numeArtist) + 1];
		strcpy_s(this->artist, sizeof(numeArtist) + 1, numeArtist);
	}
	if (nrPiese > 0)
		this->numarPiese = nrPiese;
	else
		this->numarPiese = 0;
	if (length > 0)
		this->durata = length;
	else
		this->durata = 0;
	this->gen_muzical = gm;
}

Vinyl::Vinyl(const Vinyl& vinyl){
	if (this->numeAlbum != NULL)
		delete[] this->numeAlbum;
	this->numeAlbum = new char[strlen(vinyl.numeAlbum) + 1];
	strcpy_s(this->numeAlbum, strlen(vinyl.numeAlbum) + 1, vinyl.numeAlbum);

	if (this->artist != NULL)
		delete[] this->artist;
	this->artist = new char[strlen(vinyl.artist) + 1];
	strcpy_s(this->artist, strlen(vinyl.artist) + 1, vinyl.artist);
	this->numarPiese = vinyl.numarPiese;
	this->durata = vinyl.durata;
	this->gen_muzical = vinyl.gen_muzical;
}

Vinyl& Vinyl::operator=(const Vinyl& v)
{
	if (&v != this)
	{
		if (this->numeAlbum != NULL)
			delete[] this->numeAlbum;
		this->numeAlbum = new char[strlen(v.numeAlbum) + 1];
		strcpy_s(this->numeAlbum, strlen(v.numeAlbum) + 1, v.numeAlbum);

		if (this->artist != NULL)
			delete[] this->artist;
		this->artist = new char[strlen(v.artist) + 1];
		strcpy_s(this->artist, strlen(v.artist) + 1, v.artist);

		this->numarPiese = v.numarPiese;
		this->durata = v.durata;
		this->gen_muzical = v.gen_muzical;
	}
	else
		throw exception("Autoasignare");
	return *this;

}
char* Vinyl::getNumeAlbum() { return this->numeAlbum; }
void Vinyl::setNumeAlbum(char* numeAlbum)
{
	if (strlen(numeAlbum) > 0)
	{
		if (this->numeAlbum != NULL)
			delete[] this->numeAlbum;
		this->numeAlbum = new char[strlen(numeAlbum) + 1];
		strcpy_s(this->numeAlbum, strlen(numeAlbum) + 1, numeAlbum);
	}
}

char* Vinyl::getNumeArtist() { return this->artist; }
void Vinyl::setNumeArtist(char* numeArtist)
{
	if (strlen(numeArtist) > 0)
	{
		if (this->artist != NULL)
			delete[] this->artist;
		this->artist = new char[strlen(numeArtist) + 1];
		strcpy_s(this->artist, strlen(numeArtist) + 1, numeArtist);
	}
}

unsigned int Vinyl::getNumarPiese() { return this->numarPiese; }
void Vinyl::setNumarPiese(int nr)
{
	if (nr > 0)
		this->numarPiese = nr;
}

float Vinyl::getDurata() { return this->durata; }
void Vinyl::setDurata(float durata)
{
	if (durata > 0)
		this->durata = durata;
}

genMuzical Vinyl::getGenMuzical() { return this->gen_muzical; }
void Vinyl::setGenMuzical(genMuzical gen) { this->gen_muzical = gen; }

void Vinyl::display(ostream& os) //virtual override
{
	Produs::display(os);
	os << "numele albumului: " << this->numeAlbum << endl;
	os << "numele artistului: " << this->artist << endl;
	os << "numar de piese: " << this->numarPiese << endl;
	os << "durata: " << this->durata << endl;
	os << "gen muzical: " << this->gen_muzical << endl;
}

ostream& operator<<(ostream& os, Vinyl* vinyl)
{
	vinyl->display(os);
	return os;
}


void Vinyl::read(istream& is) //virtual override
{
	Produs::read(is);
	cout << "Introduceti numele albumului: ";
	char* albumTemp = new char[100];
	is >> ws;
	is.getline(albumTemp, 100);
	if (strlen(albumTemp) > 0)
	{
		if (strlen(this->numeAlbum) > 0)
			delete[] this->numeAlbum;
		this->numeAlbum = new char[strlen(albumTemp) + 1];
		strcpy_s(this->numeAlbum, strlen(albumTemp) + 1, albumTemp);
	}

	cout << "Introduceti numele artistului: ";
	char* artistTemp = new char[100];
	is >> ws;
	is.getline(artistTemp, 100);
	if (strlen(artistTemp) > 0)
	{
		if (strlen(this->artist) > 0)
			delete[] this->artist;
		this->artist = new char[strlen(artistTemp) + 1];
		strcpy_s(this->artist, strlen(artistTemp) + 1, artistTemp);
	}
	cout << "Introduceti numarul de piese: ";
	is >> numarPiese;
	cout << "Introduceti durata: ";
	is >> durata;

	is >> gen_muzical;
}

istream& operator>>(istream& is, Vinyl* vinyl)
{
	vinyl->read(is);
	return is;
}
//
//void Vinyl::writeBinary(ofstream& ofs) //virtual override
//{
//	/*
//	char* numeAlbum;
//	char* artist;
//	unsigned int numarPiese;
//	float durata;
//	genMuzical gen_muzical;
//	*/
//	Produs::writeBinary(ofs);
//	int length = strlen(numeAlbum);
//	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
//	ofs.write(numeAlbum, length + 1);
//
//	length = strlen(artist);
//	ofs.write(reinterpret_cast<char*>(&length), sizeof(length));
//	ofs.write(artist, length + 1);
//
//	ofs.write(reinterpret_cast<char*>(&numarPiese), sizeof(numarPiese));
//	ofs.write(reinterpret_cast<char*>(&durata), sizeof(durata));
//	ofs.write(reinterpret_cast<char*>(&gen_muzical), sizeof(gen_muzical));
//}
//
//
//
//void Vinyl::readBinary(ifstream& ifs)  //virtual override
//{
//	Produs* p = Produs::readBinary(ifs);
//	int length = 0;
//
//	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
//	char* numeAlbumTemp = new char[length + 1];
//	ifs.read(numeAlbumTemp, length + 1);
//
//	ifs.read(reinterpret_cast<char*>(&length), sizeof(length));
//	char* artistTemp = new char[length + 1];
//	ifs.read(artistTemp, length + 1);
//
//	unsigned int numarPieseTemp = 0;
//	ifs.read(reinterpret_cast<char*>(&numarPieseTemp), sizeof(numarPieseTemp));
//	
//	float durataTemp = 0;
//	ifs.read(reinterpret_cast<char*>(&durataTemp), sizeof(durataTemp));
//
//	genMuzical gen_muzicalTemp;
//	ifs.read(reinterpret_cast<char*>(&gen_muzicalTemp), sizeof(gen_muzicalTemp));
//
//	Vinyl* v = new Vinyl(p->getIDProdus(), p->getStoc(), p->getPret(), p->getStatusProdus(),
//						numeAlbumTemp, artistTemp, numarPieseTemp, durataTemp, gen_muzicalTemp);
//	cout << "Citesc vinyl-ul din fisier: " << endl << v << endl;
//}
//
// ofstream& operator<<(ofstream& ofs, Vinyl* vinyl)
//{
//	vinyl->writeBinary(ofs);
//	return ofs;
//}
//ifstream& operator>>(ifstream& ifs, Vinyl* v)
//{
//	v->readBinary(ifs);
//	return ifs;
//}

Vinyl::~Vinyl()
{
	delete[] this->numeAlbum;
	delete[] this->artist;
	Produs::~Produs();
}
