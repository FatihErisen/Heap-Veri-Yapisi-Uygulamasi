#include <iostream>
#include <cstdio>

using namespace std;

const int MaxEleman = 15; // heap veri yap�s�n�n en fazla ka� eleman saklayabilece�i

class Heap {
private:
    int size; // heap veri yap�s�nda ka� eleman oldu�u
    int data[MaxEleman]; // heap veri yap�s�n�n elemanlar�n� tutan dizi

public:
    Heap() {
        size = 0;
    }

    // heap veri yap�s�n�n d�zenini restore eden fonksiyon
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < size && data[left] > data[largest])
            largest = left;
        if (right < size && data[right] > data[largest])
            largest = right;

        if (largest != i) {
            swap(data[i], data[largest]);
            heapify(largest);
        }
    }

    // heap veri yap�s�na yeni eleman ekleyen fonksiyon
    void Ekle(int value) {
        if (size == MaxEleman) {
            cout << "Hata: Heap dolu!" << endl;
            return;
        }

        data[size] = value;
        int i = size;
        size++;

        while (i > 0 && data[i] > data[(i - 1) / 2]) {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // heap veri yap�s�ndan en b�y�k eleman� silen fonksiyon
    int EnBuyuguSil() {
        if (size == 0) {
            cout << "Hata: Heap bos" << endl;
            return -1;
        }

        int EnBuyuk = data[0];
        data[0] = data[size - 1];
    size--;
    heapify(0);
    return EnBuyuk;
	}
	
	// heap veri yap�s�ndaki elemanlar� yazd�r.
	void Yazdir() {
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;

	}
	
	// heap veri yap�s�ndaki elemanlar� s�rala
	void Sirala() {
    int original_size = size;
    for (int i = 0; i < original_size; i++) {
        // heap veri yap�s�ndaki en b�y�k eleman� al ve size de�i�kenini bir azalt
        int max = data[0];
        data[0] = data[--size];
        heapify(0);

        cout << max << " ";
    }
    cout << endl;
	}
	
	// heap veri yap�s�ndaki bir eleman� silme
	void ElemanSil(int val) {
	    // veriyi arama
	    int i;
	    for (i = 0; i < size; i++) {
	        if (data[i] == val) {
	            break;
	        }
	    }
	
	    // veriyi silme
	    data[i] = data[--size];
	    heapify(i);
	}

};
int main() {
    Heap h; // heap veri yap�s�n� olu�turuyoruz
	printf("*********************************************************** \n");
	printf("* Heap Yapisi Eleman Ekleme, Silme ve Siralama Uygulamasi *\n");
	printf("*********************************************************** \n \n");
	int secim;
	while(1){
		printf("Lutfen Yapmak istediginiz islemi seciniz: \n \n");
		printf("1 - Heap veri yapisini olustur ve ilk elemanlari gir. \n");
		printf("2 - En buyuk elemani sil \n");
		printf("3 - Istenen elemani sil \n");
		printf("4 - Yeni eleman ekle \n");
		printf("5 - Elemanlari sirala \n");
		printf("6 - Exit \n"); 
		scanf("%d",&secim);
		switch(secim)
		{
			case 1: 
				    while (true) {
        				cout << "Heap'e eklenecek sayiyi giriniz. (Sonlandirmak icin: 0 giriniz): ";
        				int x;
        				cin >> x;
        				if (x == 0) break;
        				h.Ekle(x); // heap veri yap�s�na x de�erini ekliyoruz
    					}
						h.Yazdir();
						printf("\n");
						break;
			case 2: h.EnBuyuguSil();
					h.Yazdir();
					printf("\n");
					break;
			case 3: int y;
        			cout << "Heap'ten silinmesini istediginiz sayiyi giriniz: ";
					cin >> y;
					h.ElemanSil(y);
					h.Yazdir();
					printf("\n");
					break;
			case 4: int z;
        			cout << "Heap'e eklemek istediginiz sayiyi giriniz: ";
					cin >> z;
					h.Ekle(z);
					h.Yazdir();
					printf("\n");
					break;
			case 5: h.Sirala();
					break;
			case 6:  exit(0);
			default: printf("Hatali Secim Yaptiniz!!!");
		}
	}

    return 0;
	}
