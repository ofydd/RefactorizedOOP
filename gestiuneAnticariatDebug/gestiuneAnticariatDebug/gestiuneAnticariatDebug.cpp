#include "Comanda.h"
int main()
{


	try
	{
		Carte* c = new Carte(1, 1, 10, Status::Activ, "Baltagul", "Mihail Sadoveanu", "Facla", 131, 1973, genLiterar::Proza);
		Vinyl* v = new Vinyl(2, 1, 25, Status::Activ, "Mugur de fluier", "Phoenix", 7, 131, genMuzical::Rock);
		Produs* p1 = new Produs(101, 101, 10, Status::Activ);
	
		Comanda co;
		co.setIDComanda(1234);
		co.setNumeClient("Oprea");
		co.setPrenumeClient("Ovidiu");
		co.setValoareComanda(100);

		co += c;
		co += v;

		//cout << co;

		string filename = "testComandaBinar1.bin";
		ofstream ofs;
		ofs.open(filename, ios::out | ios::binary);
		if (!ofs.is_open()) {
			cerr << "Could not open file!";
		}
		else
		{
			co.writeBinary(ofs);
			ofs.close();
		}

		ifstream ifs;
		ifs.open(filename, ios::in | ios::binary);
		if(!ifs.is_open())
		{
			cerr << "Could not open file";
		}
		else
		{
			co.readBinary(ifs);
			ifs.close();
		}
		
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