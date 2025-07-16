#include <stdio.h>
#include <string.h>
//funkcija glavnog terminala gdje se bira radnja
int Pocetna(int *pokaziupit){
    int upit;
printf("\n\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
printf("\nPostovani, dobrodosli u PBZ racunalo Vaseg racuna za potrosenu elektricnu energiju ! [HEP ELEKTRIKA]\n");
printf("___________________________________________________\n");
printf("         /   /                 _______   ______       \n");
printf("        /   /      |     |    |         |      | \n");
printf("       /   /       |     |    |         |      ) \n");
printf("       --  --      |_____|    |_______  |_____/            \n");
printf("        /   /      |     |    |         |       \n");
printf("       /   /       |     |    |         |      \n");
printf("      /   /        |     |    |_______  |             \n");
printf("____________________________________________________\n");
printf("\n\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/");
do{
printf("\nOdaberite jednu od opcija: \n1. [Racunanje troskova] \n2. [Detalji o racunu] \n3. [Izlaz]\nOdabir:  ");
scanf("%d", &upit);
*pokaziupit=upit; //pretvara vrijednosti u int main, x u upit
if (upit!=1 && upit!=2 && upit!=3) {
printf("Pogreska u odabiru, odaberite jednu od opcija utipkavanjem broja.\n");
}
}while (upit!=1 && upit!=2 && upit!=3);
}
/////////////////////
//funkcija koja ispisuje tj. potvrduje upisani odabir
void ProvjeraOdabira(int *odabir){
printf("\n\nOdabrano je opcija %d\n\n", *odabir);

}
/////////////////////
//funkcija kojom se izvrsava pojedina operacija n-odabir,
//*pracun-pokazuje na varijablu uk=0 kako bi se sačuvao račun nakon svakog novog ponavljanja glavnog terminala Pocetna, poljez-prazno polje za broj sati
void Operacije(int n, float *pracun, int poljez){
    char uredaj[20+1];
    float racun=*pracun;
    int *pointclan=poljez; //inicijalizacija pokazivača koji pokazuje na prvi član polja z
    int i;
    char odg;

//odabir kojim se izvodi račun
if (n==1){
    while(strcmp(uredaj,"STOP")!=0){ //petlja koja se obavlja sve dok korisnik ne upise STOP
          printf("\nUpisite koji uredaj ste koristili po sat vremena u proteklih 30 dana \n(OPCIJE: [Bojler] [Tv] [ZoomKonzultacije] [Rasvjeta] [Klima] [Kalkulator] [STOP]): ");
          scanf("%s", &uredaj);

            if (strcmp(uredaj, "STOP") == 0) { //provjera odabira, za svaki uređaj se povećava račun za struju te se u polju na koje pokazuje pointclan zapisuje broj ponavljanja
                break;
            } else if (strcmp(uredaj, "Tv") == 0) {
                racun += 0.46*0.041468;
                *(pointclan+0)=*(pointclan+0)+1;
            } else if (strcmp(uredaj, "ZoomKonzultacije") == 0) {
                racun += 0.33*0.041468;
                *(pointclan+1)=*(pointclan+1)+1;
            } else if (strcmp(uredaj, "Rasvjeta") == 0) {
                racun += 0.7*0.041468;
                *(pointclan+2)=*(pointclan+2)+1;
            } else if (strcmp(uredaj, "Klima") == 0) {
                racun += 0.03*0.041468;
                *(pointclan+3)=*(pointclan+3)+1;
            } else if (strcmp(uredaj, "Bojler") == 0) {
                racun += 0.28*0.041468;
                *(pointclan+4)=*(pointclan+4)+1;
            } else if (strcmp(uredaj, "Kalkulator") == 0) {
                racun += 0.00025*0.041468;
                *(pointclan+5)=*(pointclan+5)+1;
            } else {
                printf("Netocan upis, ponovite: ");
            }
        }
    printf("Racun za struju toga mjeseca je %.6f eura. (Ukljucuje se naknada usluge je %.6f+0.3 eura)", racun+0.3, racun);
    *pracun=racun; //pokazivač kojime prebacujemo vrijednost računa u iduću funkciju
    IzradaRacuna(pracun); //Čim je račun obavljen pokreće se funkcija upisivanja računa i podataka u tekstualni dokument
    }

//odabir kojim se ispisuju specifikacije i personalizirana računica pomoću računa
if (n==2){
    printf("\n\n\n\n\n\n\n\n\n\n Sukladno tarifnoj stavci za opskrbu kupaca kategorije kucanstvo u sustavu javne usluge,\n u primjeni od 01.04.2023. godine: ");
    printf("\nVasa trajna tarifa je 'Crveni model' te je cijena (EUR/kWh) ukljucujuci PDV = 0.041468");
    printf("\nSlijedi potrosnja vasih uredaja po svakih 24 sata: ");
    printf("\n8K UHD 100Hz TV___________11,04 kWh(0,46 kWh po satu");
    printf("\nZoom konzultacije_________8 kWh (0,33 kWh po satu)");
    printf("\nRasvjeta__________________17 kWh (0,7 kWh po satu)");
    printf("\nKlima_____________________0,8 kWh(0,03 po satu)");
    printf("\nBojler____________________6,69 kWh (0,28 kWh po satu)");
    printf("\nKalkulator________________0,006 kWh(0,00025 kWh po satu");
if(racun==0){ //personalizirana računica se ne ispisuje ako korisnik još nije odradio računski dio
    printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
    printf("\n Nemate jos uracunat racun za ovaj mjesec, izracunajte troskove pa pokusajte ponovno zatraziti detalje o racunu.");
}
else{
    do{printf("\nZelite li proracun vasih koristenih uredaja? [y/n]:");
    scanf(" %c", &odg);
    if(odg=='y'){
            printf("\n\n\n\n\n\n\n}/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");
    for(i=0;i<6;i++){  //petlja ispisuje sve članove polja z pomoću pomicanja pokazivača koji predstavljaju broj upisanih sati korištenja
            if(*(pointclan+i)>0){
                if (i==0)printf("\nTv potrosnja: %d h (%d * 0,019075 = %f)", *(pointclan+i), *(pointclan+i), *(pointclan+i)*0.019075);
                else if(i==1)printf("\n Zoom potrosnja: %d h (%d * 0,013684 = %f)", *(pointclan+i), *(pointclan+i), *(pointclan+i)*0.013684);
                else if(i==2)printf("\nRasvjeta %d h (%d * 0,0290276 = %f)", *(pointclan+i), *(pointclan+i), *(pointclan+i)*0.0290276);
                else if(i==3)printf("\nKlima %d h (%d * 0,001244 = %f)", *(pointclan+i), *(pointclan+i), *(pointclan+i)*0.001244);
                else if(i==4)printf("\nBojler %d h (%d * 0,01161 = %f)", *(pointclan+i), *(pointclan+i), *(pointclan+i)*0.01161);
                else if(i==5)printf("\nKalkulator %d h (%d * 0,000010367 = %f)", *(pointclan+i), *(pointclan+i), *(pointclan+i)*0.000010367);
            }
    }
    printf("\n/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\");}
    else if(odg=='n')
        break;
    else printf("\nNijedan odabir nije unesen, ponovite unos.");}while(odg!='y' && odg!='n'); //do-while petlja kojom se ponavlja pitanje y/n sve dok korisnik ne upiše jedno od ta dva slova
}}

//odabir kojim se ispisuje da je ugašen program te se cijeli program tim odabirom završava
if (n==3){
printf("\nUspjesno je ugasen program!");
}
}
/////////////////////
//funkcija izrade računa koristeći pokazivač koji pokazuje na račun izračunat u funkciji Operacije
void IzradaRacuna(float *rachoon){
    int prava=0;
    srand((unsigned)time(NULL));
    prava=rand()%500+500;
    struct Osoba{
    char ime[20+1];
    char prezime[20+1];
    char adresa[30+1];
        int brojulice;
}podaci;
    do{
    printf("\nUnesite ime:");
    scanf("%s", podaci.ime);
    printf("\nUnesite prezime:");
    scanf("%s", podaci.prezime);
    printf("\nUnesite adresu (Umjesto razmaka koristite '_'):");
    scanf("%s", podaci.adresa);
    printf("\nUnesite ulicni broj:");
    scanf("%d", &podaci.brojulice);
    if(strlen(podaci.ime)>21 || strlen(podaci.ime)<=0 || strlen(podaci.prezime)>21 || strlen(podaci.prezime)<=0 || strlen(podaci.adresa)>31 || strlen(podaci.adresa)<=0)//provjera duljine svakog podatka
        printf("Greska u unosu podataka, Ponovite unos\n");
    }while(strlen(podaci.ime)>21 || strlen(podaci.ime)<=0 || strlen(podaci.prezime)>21 || strlen(podaci.prezime)<=0 || strlen(podaci.adresa)>31 || strlen(podaci.adresa)<=0);
FILE *Upis=fopen("Racuni.txt","w"); //otvaranje i učitavanje podataka iz strukture o korisniku u tekstualni dokument Racuni.txt
if (Upis==NULL){
    printf("Greska u ispisu racuna");
}
else{
fprintf(Upis,"______________________________________\n");
fprintf(Upis,"__HEP-TOPLINARSTVO____________________\n");
fprintf(Upis,"PLATITELJ:________________Valuta plaćanja:EUR_____Iznos:%.6f eura\n", *rachoon+0.3);
fprintf(Upis,"%s|___________________________________________\n", podaci.ime);
fprintf(Upis,"%s|___________________________________________\n", podaci.prezime);
fprintf(Upis,"%s %d   |_____________________________________\n", podaci.adresa, podaci.brojulice);
fprintf(Upis,"_______________________________________________\n");
fprintf(Upis,"_______________________________________________\n");
fprintf(Upis,"PRIMATELJ:             |_______________________\n");
fprintf(Upis,"HEP-TOPLINARSTVO d.o.o.|_______________________\n");
fprintf(Upis,"MIŠEVEČKA 15A          |_______________________\n");
fprintf(Upis,"10000 ZAGREB           |_______________________\n");
fprintf(Upis,"_______________________|_______________________\n");
fclose(Upis);
printf("\n Racun je uspjesno isprintan, provjerite vasu podatkovnu mapu.");
}}
//////////////////
int main(){
    int x=0; //njime čuvamo odabran upit od 1 do 3
    float uk=0; //njime čuvamo vrijednost računa koju prenosimo u druge funkcije
int *pupit=&x;
float *racun=&uk;
int z[6]={0};
do{
Pocetna(pupit);
ProvjeraOdabira(pupit);
Operacije(x, racun, z);
}while(x!=3);
return 0;}
