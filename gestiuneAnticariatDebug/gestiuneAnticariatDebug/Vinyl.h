#pragma once
#include "Carte.h"

class Vinyl : public Produs
{
private:
	char* numeAlbum;
	char* artist;
	unsigned int numarPiese;
	float durata;
	genMuzical gen_muzical;
public:
	Vinyl(); 

	Vinyl(unsigned int idProdus, unsigned int stoc, float pret, Status status,
		const char* numeAlbum, const char* numeArtist, unsigned int nrPiese, float length, genMuzical gm);

	Vinyl(const Vinyl& vinyl);
	Vinyl& operator=(const Vinyl& v);

	char* getNumeAlbum();
	void setNumeAlbum(char* numeAlbum);

	char* getNumeArtist();
	void setNumeArtist(char* numeArtist);

	unsigned int getNumarPiese();
	void setNumarPiese(int nr);


	float getDurata();
	void setDurata(float durata);

	genMuzical getGenMuzical();
	void setGenMuzical(genMuzical gen);

	virtual void display(ostream& os) override;
	friend ostream& operator<<(ostream& os, Vinyl* vinyl);

	virtual void read(istream& is) override;
	friend istream& operator>>(istream& is, Vinyl* vinyl);

	/*virtual void writeBinary(ofstream& ofs) override;
	friend ofstream& operator<<(ofstream& ofs, Vinyl* vinyl);
	
	void readBinary(ifstream& ifs);
	friend ifstream& operator>>(ifstream& ifs, Vinyl* v);*/

	~Vinyl();

};