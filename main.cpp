#include <iostream>

using namespace std;

struct Ogrenci
{
string isim,harfnotu;
int ogrencino,*testnotlari; //Bize verilen struct yapımız.
double ortalama;
};

void verial(Ogrenci *Ogrenciler, int i, int *notlar, int testSayisi); //fonksiyon tanımlamaları
double notHesapla(Ogrenci *Ogrenciler, int i, int testSayisi);
void goster(Ogrenci *Ogrenciler, int i);
void sil(Ogrenci *Ogrenciler);

int main()
{
    int ogrenciSayi;
    int testSayisi; //tanımlamalar


    cout << "Ogrenci sayisini giriniz: ";    //Ogrenci sayisi ve test sayisini aldığımız kısım
    cin >> ogrenciSayi;
    cout << "Test sayisini giriniz: ";
    cin >> testSayisi;

    Ogrenci *Ogrenciler = new Ogrenci[ogrenciSayi]; //struct yapısından öğrenci sayısı uzunluğunda dinamik array oluşturduk.

    int *notlar = new int[testSayisi];  //test notları için dinamik bir dizi daha

    for(int i=0; i<ogrenciSayi; i++){

       verial(Ogrenciler,i,notlar,testSayisi);   //öğrenci bilgileri ve test notlarını alıyoruz

       Ogrenciler[i].testnotlari=&notlar[0];  //öğrenci struct'ındaki testnotları pointerına, notlar dizisinin adresini veriyoruz.

       Ogrenciler[i].ortalama = notHesapla(Ogrenciler,i,testSayisi);  //notHesapla fonksiyonunu çağırıp öğrencinin not ortalamasını aldıktan sonra structımızın ortalama elemanına atıyoruz.

       goster(Ogrenciler,i);  //Göster fonksiyonu çağrıldıktan sonra ortalamaya göre harf notu hesabı yapılıp ortalama ve harf notu konsola yazdırılır.
    }
    sil(Ogrenciler); //sil fonksiyonu çağırılıyor.

    return EXIT_SUCCESS;
}


void verial(Ogrenci *Ogrenciler,int i, int *notlar, int testsayisi){


        cout<< endl<<endl;   //öğrenci adı ve numarasını alıyoruz.
        cout <<i+1<<". Ogrencinin adini giriniz: ";
        cin>>Ogrenciler[i].isim;
        cout <<i+1<<". Ogrencinin numarasini giriniz: ";
        cin>>Ogrenciler[i].ogrencino;

        int sayac=0;           //test sayisi uzunluğunda bir döngü oluşturularak test notları alınır.
                               //Sayacı 0 yapmamızın nedeni ise öğrenci no artarken test sayısını bağımsızlaştırmak yani öğrenci no 2 olduğunda test sayısı yine 1'den başlayacak
        while(sayac<testsayisi){
        cout<<i+1<<". Ogrencinin "<<sayac+1<<". test notunu giriniz: ";
        cin>>notlar[sayac];
        sayac++;
        }
}
//test notlarının içinden notları çekip ortalamasını alıyoruz ve ortalamayı döndürüyoruz
double notHesapla(Ogrenci *Ogrenciler, int i,int testsayisi){

    float toplam=0,ortalama=0;
    for(int n=0; n<testsayisi; n++){
        toplam += *(Ogrenciler[i].testnotlari+n);
    }

    ortalama = toplam/testsayisi;

    return (ortalama);
}
//goster fonk. ise returnlediğimiz ortalamanın harf notu karşılığını bulduruyoruz ve Bastırıyoruz
void goster(Ogrenci *Ogrenciler, int i){

    if(Ogrenciler[i].ortalama>=85){
        Ogrenciler[i].harfnotu="A";
       }
       else if(Ogrenciler[i].ortalama>=75 && Ogrenciler[i].ortalama<=84){
        Ogrenciler[i].harfnotu="B";
       }
       else if(Ogrenciler[i].ortalama>=65 && Ogrenciler[i].ortalama<=74){ //Decision mekanizması
        Ogrenciler[i].harfnotu="C";
       }
       else if(Ogrenciler[i].ortalama>=50 && Ogrenciler[i].ortalama<=64){
        Ogrenciler[i].harfnotu="D";
       }
       else{
        Ogrenciler[i].harfnotu="F";
       }

   cout<<"Ortalama: "<< (Ogrenciler[i].ortalama);   //Bastırma işlemi
   cout<<" Harf Notu: "<< (Ogrenciler[i].harfnotu); //Bastırma işlemi
}
//Tüm işlemler bittikten sonra diziyi “delete” komutu ile geri veriyoruz.
void sil(Ogrenci *Ogrenciler){

   delete[] Ogrenciler;
}
