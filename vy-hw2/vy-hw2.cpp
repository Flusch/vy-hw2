//
//Yavuz Selim GÜLER
//1306160016
//

#include <iostream>
using namespace std;

//ikili Agac

class agac
{
	int arr[100] = { 0 };
	int leafCounter = 0;
	int counter = 0;
	struct dugum
	{
		int deger;
		dugum* sol;
		dugum* sag;
	};

	dugum* kok;

	dugum* bosalt(dugum* t)
	{
		if (t == NULL)
			return NULL;
		{
			bosalt(t->sol);
			bosalt(t->sag);
			delete t;
		}
		return NULL;
	}

	dugum* ekle(int x, dugum* t)
	{
		if (t == NULL)
		{
			t = new dugum;
			t->deger = x;
			t->sol = t->sag = NULL;
		}
		else if (x < t->deger)
			t->sol = ekle(x, t->sol);
		else if (x > t->deger)
			t->sag = ekle(x, t->sag);
		return t;
	}

	void yaprakDugum(dugum* t)
	{

		if (!t) {
			cout << "Agacta goruntulenecek eleman yok" << endl;
			return;
		}
		if (!t->sol && !t->sag)
		{
			arr[leafCounter] = t->deger;
			leafCounter++;
			return;
		}
		if (t->sol)
			yaprakDugum(t->sol);
		if (t->sag)
			yaprakDugum(t->sag);
	}

public:
	agac()
	{
		kok = NULL;
	}

	~agac()
	{
		kok = bosalt(kok);
	}

	void ekle(int x)
	{
		kok = ekle(x, kok);
		counter++;
	}

	void yapraklar()
	{
		yaprakDugum(kok);
		if (kok != NULL) {
			cout << "Yaprak Dugumler:" << endl;
			for (int i = 0; i < leafCounter; i++) {
				cout << arr[i] << "     ";
			}
			cout << endl;
		}
	}
};

//ikili Agac sonu.

int main() {
	int selection, eklenecek;
	class agac tr;

	while (1)
	{
		cout << "*** *** *** *** *** ***\n";
		cout << " 1 --> Eleman Ekle \n";
		cout << " 2 --> Yaprak Dugumleri Goruntule \n";
		cout << " 3 --> Cikis \n";
		cout << "*** *** *** *** *** ***\n";

		cout << "Seciminizi girin: ";
		cin >> selection;

		switch (selection) {
		case 1:
			cout << "Eklemek istediginiz elemani giriniz:";
			cin >> eklenecek;
			tr.ekle(eklenecek);
			cout << endl;
			break;
		case 2:
			tr.yapraklar();
			cout << endl;
			break;
		case 3:
			exit(0);
		default:
			cout << "Yanlis Secim!!\n";
			continue;
		}
	}
	system("pause");
	return 0;
}