//NOT: toupper('1') mümkün, sonucu '1'                     HAK(BASAMAK-1) OLMADI
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int num, basamak=0, option;

int tahmin ( ) {
    char option;
    printf ("Iki basamakli bir sayi tuttum. Icindeki bir rakami tahmin etmek icin \"1\"e, tum sayi icin \"A\"ya basin: ");
    scanf(" %c", &option);

    return option;
}

int main(){
    short int basamakcpy;

    srand(time(NULL));
    num = rand()%101; //0-100 olsun diye //%90 + 10; //sadece 2 basamaklı
    int numcpy=num;
    printf("\n%d\n", num);//
    while(numcpy>0){
        numcpy/=10;
        basamak++;
    }
    numcpy=num;

    short int ctrl=0, bil;
    while (ctrl == 0){

        char choice =tahmin();

        switch(toupper(choice)){
        case 'A': 
            printf("Tum sayi: ");
            scanf("%hi", &bil);
            if(bil == num) 
            ctrl=1;
            else 
                ctrl=2;
            break;
        
        case'1': 
            printf("Sayi: ");
            scanf("%hi", &bil);
            basamakcpy=basamak;
            for(basamakcpy; basamakcpy>0; basamakcpy--){
                if(bil == numcpy%10) ctrl=1;
                numcpy/=10;
            }

            //basamakcpy--;
            if(basamakcpy>0)
                printf("\tKalan hak: %hi\n", basamakcpy);
            else{
                ctrl=2;
                break;
            }
            break;

        default:
            printf("Ya A ya 1 olmali\n");
        }
    }
    //kazanma
    if (ctrl==1 && basamakcpy>0)
        printf("Tebrikler! Sayi: %d",num);
    else if(ctrl=2)
        printf("Kaybettin. Sayi: %d",num);
}