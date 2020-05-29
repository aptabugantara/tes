#include <stdio.h>
using namespace std;
int calon1(), calon2(), menuCalon(), pilihanMenu(), generateNim(),nimMenu(),cariMenu(),listMenu(),verifikasiNim(),hasilPemilu(),sudahVote[100],hasilVote[100];

int generateNim(int dataNim[100]){ // generate nim angkatan 18, hanya 100 karena jika terlalu besar program menjadi not responding
	int i,si,sk;
	si = 180030000;
	sk = 180010000;
	for(i = 1;i <= 100;i++){
		if(i<=50){
			si += 1;
			dataNim[i] = si;
		}else if(i>=51){
			sk += 1;
			dataNim[i] = sk;
		}
	}
	return 0;
}

int calon1(){
	int keluar;
	printf("===========================================\n");
	printf("Calon No. 1\n");
	printf("Calon Ketua: I Putu Aris Sanjaya \n");
	printf("Calon Wakil Ketua: Muhammad Aditiya Firmansyah \n\n");
	printf("+ Visi & Misi\n");
	printf("~ Terwujudnya HIMAS Jimbaran yang aktif, kreatif dan konstruktif dengan\nberlandasan kekeluargaan serta bertanggung jawab terhadap kesejahteraan\ndan aspirasi mahasiswa/i STMIK STIKOM Bali Kampus Jimbaran.\n\n");
	printf("~ Build Character.\n");
	printf("~ Raise Awareness.\n");
	printf("~ Nureture Leadership.\n");
	printf(" ~ Base on family.\n");
	printf("===========================================\n");
	do{
		printf("untuk kembali input (0): ");
		scanf("%d",&keluar);
	}while(keluar != 0 || keluar < 0 && keluar > 0); // jika bukan nol maka repeat
	printf("===========================================\n");
	if(keluar == 0){
		menuCalon();
	}
	return 0;
}

int calon2(){
	int keluar;
	printf("===========================================\n");
	printf("Calon No. 2\n");
	printf("Calon Ketua: Gusti Made Sarma Sanjaya \n");
	printf("Calon Wakil Ketua: Dika Yuda Bagaskara \n\n");
	printf("+ Visi & Misi\n");
	printf("~ Meningkatkan kreatifitas mahasiswa agar lebih aktif, produktif dan\ninovatif serta menciptakan suasana kampus yang cinta keberagamaan dan\ncinta lingkungan.\n\n");
	printf("===========================================\n");
	do{
		printf("untuk kembali input (0): ");
		scanf("%d",&keluar);
	}while(keluar != 0 || keluar < 0 || keluar > 0); // jika bukan nol maka repeat
	printf("===========================================\n");
	if(keluar == 0){
		menuCalon();
	}
	return 0;
}

int menuCalon(){
	int cmenu;
	printf("===========================================\n");
	printf("List Calon Kandidat: \n");
	printf("1. Aris-Aditiya\n");
	printf("2. Sarma-Dika\n");
	printf("3. exit \n");
	printf("===========================================\n");
	
	do{
		printf("Pilih Menu: ");
		scanf("%d",&cmenu);
	}while(cmenu < 1 || cmenu > 3);
	
	if(cmenu == 1){
		calon1();
	}else if(cmenu == 2){
		calon2();
	}else if(cmenu == 3){
		pilihanMenu();
	}
	return 0;
}

int listMenu(){
	int i,lNim[100],keluar,sk;
	generateNim(lNim);
	
	printf("===========================================\n\n");
	printf("|-----------------------------------------|\n");
	printf("| Sistem Informasi  | Sistem Komputer     |\n");
	printf("|-----------------------------------------|\n");
	for(i=1;i<=50;i++){
		sk=50+i;
		printf("| %d         | %d           |\n",lNim[i],lNim[sk]);
	}
	printf("===========================================\n");
	do{
		printf("untuk kembali input (0): ");
		scanf("%d",&keluar);
	}while(keluar != 0 || keluar < 0 || keluar > 0);
	
	if(keluar == 0){
		nimMenu();
	}
}

int cariMenu(){
	int nim,i,temp,lNim[100];
	generateNim(lNim);
	printf("===========================================\n");
	do{
		printf("Nim (untuk exit input 0): ");
		scanf("%d",&nim);
		printf("===========================================\n");
		if(nim == 0){
			nimMenu();
		}else{
			for(i = 1;i<=100;i++){
				if(nim == lNim[i]){
					temp = lNim[i];
					break;
				}else{
					temp  = 0;
				}
			}
			
			if(temp != 0){
				printf("ditemukan %d \n",temp);
			}else{
				printf("tidak ditemukan.\n");
			}
		}
		printf("===========================================\n");
	}while(nim );
}

int nimMenu(){
	int nmenu;
	printf("===========================================\n");
	printf("1. List Nim\n");
	printf("2. Cari Nim\n");
	printf("3. Exit\n");
	printf("===========================================\n");
	
	do{
		printf("Pilih menu: ");
		scanf("%d",&nmenu);
	}while(nmenu < 1 || nmenu > 3);
	
	switch(nmenu){
		case 1:
			listMenu();
			break;
		case 2:
			cariMenu();
			break;
		case 3:
			pilihanMenu();
			break;
		default:
			break;
	}
	
}

int checkNim(int nim){
	int i,hasil;
	for(i=1;i<=100;i++){
		if(nim == sudahVote[i]){
			hasil = 1; // sudah vote
			break;
		}else if((nim >= 180030001 && nim <= 180030050) || (nim >= 180010001 && nim <= 180010050)){
			hasil = 2; // belum vote
		}else{
			hasil = 3; // nim tidak ditemukan
		}
	}
	return hasil;
}

int noArrLast(){
	int i,noArr;
	for(i=1;i<=100;i++){
		if(sudahVote[i] >= 1){
			
		}else{
			noArr = i;
			break;
		}
	}
	return noArr;
}

int vote(int nim){
	int voting,noArr,keluar;
	printf("===========================================\n");
	printf("List Calon Kandidat: \n");
	printf("1. Aris-Aditiya\n");
	printf("2. Sarma-Dika\n");
	printf("3. exit \n");
	printf("===========================================\n");
	do{
		printf("Pilih No: ");
		scanf("%d",&voting);
	}while(voting < 1 || voting > 3);
	
	if(voting == 1 || voting == 2){
		noArr = noArrLast();
		sudahVote[noArr] = nim;
		hasilVote[noArr] = voting;
		printf("Terima Kasih sudah menggunakan hak pilih anda, untuk kembali input (0): ");
		scanf("%d",&keluar);
		if(keluar == 0){
			pilihanMenu();
		}
	}else if(voting == 3){
		pilihanMenu();
	}
}

int verifikasiNim(){
	int nim,hasil;
	printf("===========================================\n");
	do{
		printf("Masukan Nim: ");
		scanf("%d",&nim);
		hasil = checkNim(nim);
		
		if(hasil == 1){
			printf("Nim ini sudah memilih.\n");
		}else if(hasil == 3){
			printf("Nim ini tidak ditemukan.\n");
		}
	}while(hasil == 1 || hasil == 3);
	vote(nim);
}

int hasilPemilu(){
	int i,no1,no2,keluar;
	no1 = 0;
	no2 = 0;
	i=1;
	while(i<=100){
		if(hasilVote[i] == 1){
			no1 += 1;
		}else if(hasilVote[i] == 2){
			no2 += 1;
		}
		i++;
	}
	
	printf("===========================================\n");
	printf("Hasil Pemilu: \n");
	printf("|-----------------------------------------|\n");
	printf("| ~ Aris-Aditiya: %d \n| ~ Sarma-Dika: %d \n",no1,no2);
	printf("|-----------------------------------------|\n");
	do{
		printf("untuk kembali input (0): ");
		scanf("%d",&keluar);
	}while(keluar != 0 || keluar < 0 || keluar > 0);
	
	if(keluar == 0){
		pilihanMenu();
	}
}

int pilihanMenu(){
	int pmenu;
	printf("============== Pemilu Himas ==============\n");
	printf("1. Calon Kandidat\n");
	printf("2. Vote Calon\n");
	printf("3. Nim\n");
	printf("4. Hasil Pemilu\n ");
	printf("===========================================\n");
	printf("Pilih Menu; ");
	scanf("%d",&pmenu);
	
	if(pmenu == 1){
		menuCalon();
	}else if(pmenu == 2){
		verifikasiNim();
	}else if(pmenu == 3){
		nimMenu();
	}else if(pmenu == 4){
		hasilPemilu();
	}
	return 0;
}

main(){
	int menu;
	pilihanMenu();
}
