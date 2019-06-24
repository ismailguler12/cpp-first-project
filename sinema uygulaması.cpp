#include<iostream>
#include<stdlib.h>

using namespace std;

class Sinema{
	private:
		int toplamKoltuk, bosKoltuk, bakiye, salonNo, topSalon, fiyat, indirimliFiyat, normalBilet, indirimliBilet;
	
	public: Sinema(){
		bakiye = 0;
		topSalon = 0;
	}
	
	public: void SalonOlustur( ){
		cout<<"salon numarasini giriniz";
		cin>>salonNo;
		cout<<"salon koltuk sayisini girin";
		cin>>toplamKoltuk;
		cout<<"bilet fiyati ve indirimli bilet fiyat bilgisi girin";
		cin>>fiyat;
		cin>>indirimliFiyat;
		  
		bosKoltuk = toplamKoltuk;
			
	}
	
	public: void BiletSat(){
		
		cout<<"kac tane normal bilet satacaksiniz\n";
		cin>>normalBilet;
		cout<<"kac tane indirimli bilet satacaksiniz\n";
	
		cin>>indirimliBilet;
		
		if(bosKoltuk - (normalBilet + indirimliBilet ) < 0 ){
			cout<<"yeteri kadar bilet yok\n\n";
		}
		else{
		
			
			bakiye += fiyat*normalBilet;
			bakiye += indirimliFiyat*indirimliBilet;
		
			bosKoltuk -= (indirimliBilet + normalBilet);
	}	
		
	}
	
	public: void SalonGoruntule(){
		cout<<"salon no:"<<salonNo<<"\n";
		cout<<"bos koltuk sayisi "<<bosKoltuk<<"\n";
		
	}
	
	public: void BiletIptal(){
		int iptal1, iptal2;
		cout<<"kac tane normal bilet iptal edeceksiniz";
		cin>>iptal1;
		cout<<"kac tane indirimli bilet iptal edeceksiniz";
		cin>>iptal2;
		
		
		if(bosKoltuk + (iptal1 + iptal2 ) > toplamKoltuk ){
			cout<<"hata!!! bu kadar bilet iptal edemezsiniz bu kadar koltuk yok\n";
		}
		
		else{
		
			bakiye -= iptal1*fiyat;
			bakiye -= iptal2*indirimliFiyat;
		
			bosKoltuk += (iptal1 + iptal2);
		}
	}
	public: void BakiyeOgren(){
		cout<<"kasadaki para miktari: "<<bakiye<<"\n";
	}
	public: void Cikis(){
		cout<<"program bitti";
		exit(0);
	}
	
	
	
};

int main()
{
	
	Sinema s;
	int secim, sayac=0;
	
	
	while(1){
		etiket:
		cout<<"\n\n\n*************";
		cout<<"islem seciniz\n";
		cout<<"1-Salon olustur\n";
		cout<<"2-Bilet sat\n";
		cout<<"3-Solon Goruntule\n";
		cout<<"4-Bilet iptal\n";
		cout<<"5-Bakiye ogren\n";
		cout<<"6-Cikis\n";
		cout<<"**************\n\n\n";
		
		cin>>secim;
		sayac++;
		if(sayac == 1 && secim != 1 ){
			cout<<"lutfen once salon olusturun";
			sayac = 0;
			goto etiket;
		}
		
		if(secim == 1 ){
			s.SalonOlustur();
		}
		if(secim == 2){
			s.BiletSat();
		}
		
		if(secim == 3){
			s.SalonGoruntule();
		}
		if(secim == 4){
			s.BiletIptal();
		}
		
		if(secim == 5){
			s.BakiyeOgren();
		}
		
		if(secim == 6){
			s.Cikis();
		}
		
	}
	
	
}
