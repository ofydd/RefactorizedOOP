#include "Comanda.h"
int main()
{


	try
	{
		Carte* c = new Carte(1, 1, 10, Status::Activ, "Baltagul", "Mihail Sadoveanu", "Facla", 131, 1973, genLiterar::Proza);
		Vinyl* v = new Vinyl(2, 1, 25, Status::Activ, "Mugur de fluier", "Phoenix", 7, 131, genMuzical::Rock);
		Produs* p1 = new Produs(101, 101, 10, Status::Activ);

		string filename = "testCarteBinar.bin";
		
		ofstream ofs;
		ofs.open(filename, ios::binary | ios::out);
		if (!ofs.is_open())
			cout << "N-a mers";
		else
			cout << "A mers";
		

		
		
		
		ifstream ifs;
		ifs.open(filename, ios::binary | ios::in);
		if (!ifs.is_open()) {
			cout << "N-am putut sa deschid";
		}
		else cout << "Am deschis";
		
		ofs << c;
		Carte* cBinar = new Carte();
		ifs >> cBinar;

		cout << cBinar;

		
		
	}
	catch (out_of_range& ex)
	{
		cout << ex.what() << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}


	return 0;
}