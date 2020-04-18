#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>

int main(int argc, char *argv[])
{
        char normalize = 'e';
        char automaticCheck = 'k';
        int isDifferent = 0;
        int viimeinenMuutos = 1;
        int matriisinKoko = 2;
        int m = matriisinKoko;
        int n = matriisinKoko;
        int p = matriisinKoko;
        int q = matriisinKoko;
        int c = 0;
        int d = 0;
        int k = 0;
        int numberOfIterations = 1;
        //int digits = 2;
        int count = 0;
        double number;
        long double sum = 0;
        int firstRound = 1;
        //int isDone = 0;


        FILE *inputFile;
      	FILE *outputFile;

        printf("argumentti 0 %s\n",argv[0]);
        printf("argumentti 1 %s\n",argv[1]);

        if(argc>1)
        {
        //int arrayLenght = (int)( sizeof(&argv) / sizeof(&argv[0]));
        inputFile = fopen(argv[1], "r");
        printf("avataan tiedostoa %s\n",argv[1]);
        }
        else
        {
        // avaa tiedosto josta matriisi luetaan
        inputFile = fopen("matriisi.txt", "r"); // "r" avataan lukemista varten
        }


        // jos matriisi.txt löytyi
        if(inputFile!=NULL){
                printf("Normalisoidaanko (k = kylla / e = ei):");
                scanf(" %c",&normalize);
                printf("Matriisinkoko:");
                scanf(" %d",&matriisinKoko);
                 m = matriisinKoko;
                 n = matriisinKoko;
                 p = matriisinKoko;
                 q = matriisinKoko;
                 long double first[m][q], second[m][q], multiply[m][q], previous[m][q];

                // valitaan kertolaskujen määrä
                printf("Kirjoita haluamasi potenssi kokonaislukuna:");
                scanf(" %d",&numberOfIterations);

                printf("Automaattinen tarkistus (k = kylla / e = ei):");
                scanf(" %c",&automaticCheck);
                printf("\n");

                // avaa tiedosto tuloksen kirjaamista varten
                outputFile = fopen("tulos.txt", "w"); // "w" kirjoittamista varten
                // luetaan luvut matriisi.txt tiedostosta
                while(fscanf(inputFile,"%lf", &number) != EOF){
                        printf("%.*lf\t",8, (double)number);
                        first[c][d] = number;
                        second[c][d] = first[c][d];
                        d++;
                        if(d>=n){
                                c++;
                                d=0;
                                printf("\n");
                        }
                }
        printf("\n");

        fprintf(outputFile, "Laskettava matriisi:\n");

                for (c = 0; c < m; c++) {
                        for (d = 0; d < q; d++){
                                fprintf(outputFile,"%.*lf\t",8,(double)first[c][d]);
                        }
                fprintf(outputFile,"\n");
                }
        fprintf(outputFile,"\n");



while(count < numberOfIterations){

        if(normalize != 'e'){

                printf("\n");
                printf("Normalisoidaan...\n");
                printf("\n");

                // tarkista matriisin arvot
                long double rivisumma[matriisinKoko];
                for (c = 0; c < m; c++) {
                        long double riviTotal = 0;
                        for (d = 0; d < q; d++){
                                if(firstRound == 1){
                                riviTotal += first[c][d];
                                } else
                                {
                                riviTotal += second[c][d];
                                }
                        }
                        rivisumma[c] = riviTotal;
                }

                // normalisoidaan matriisi
                for (c = 0; c < m; c++) {
                        for (d = 0; d < q; d++){
                                if(firstRound == 1){
                                  if(rivisumma[c]==0)
                                  {
                                    second[c][d] = first[c][d];
                                  }
                                  else
                                  {
                                    second[c][d] = first[c][d]/rivisumma[c];
                                  }
                                first[c][d] = second[c][d];
                                previous[c][d] = second[c][d];
                                }
                                else
                                {
                                  if(rivisumma[c]==0)
                                  {
                                    //second[c][d] = second[c][d];
                                  }
                                  else
                                  {
                                    second[c][d] = second[c][d]/rivisumma[c];
                                  }
                                }
                        }
                }

        if(firstRound == 1)
        {
                printf("Lahtomatriisi normalisoituna\n");
                fprintf(outputFile, "Lahtomatriisi normalisoituna\n");

                        for (c = 0; c < m; c++) {
                                for (d = 0; d < q; d++){
                                        printf("%.*lf\t",8,(double)first[c][d]);
                                        fprintf(outputFile,"%.*lf\t",8,(double)first[c][d]);
                                }
                        printf("\n");
                        fprintf(outputFile,"\n");
                        }
                printf("\n");
                fprintf(outputFile,"\n");
        }
        firstRound=0;
        }

        for (c = 0; c < m; c++) {
                for (d = 0; d < q; d++) {
                        for (k = 0; k < p; k++) {
                                  sum = sum + first[c][k]*second[k][d];
                        }
                        multiply[c][d] = sum;
                        sum = 0;
                }
        }


        if(automaticCheck=='k' && count > 1)
        {
                isDifferent = 0;
                for (c = 0; c < m; c++) {
                        for (d = 0; d < q; d++){
                                if(previous[c][d]!=multiply[c][d])
                                {
                                isDifferent=1;
                                printf("muutos solussa (%d : %d) : ",c,d);
                                //printf("vrt %.64Lf : %.64Lf)\n",previous[c][d],multiply[c][d]);
                                long double diff = fabsl(previous[c][d]-multiply[c][d]);
                                printf("erotus %.*lf\n",64,(double)diff);
                                fprintf(outputFile, "erotus %.*lf\n",64,(double)diff);


                                }
                        }
                }
        if(isDifferent==0)
        {
                printf("\nTulos ei muutu! %d\n",count);
                fprintf(outputFile, "Tulos ei muutu! %d\n",count);
                //count=numberOfIterations;
        }
        else
        {
                printf("\nTulos muuttuu!\n");
                fprintf(outputFile, "Tulos muuttuu!\n");
                viimeinenMuutos = count;
        }
        }


        count++;
        printf("\nTulos: %d\n",count);
        fprintf(outputFile, "\nTulos: %d\n",count);

        for (c = 0; c < m; c++) {
                for (d = 0; d < q; d++){
                        printf("%.*lf\t",8,(double)multiply[c][d]);
                        //long double result = round(multiply[c][d], 6);
                        fprintf(outputFile,"%.*lf\t",8,(double)multiply[c][d]);
                        //first[c][d]=multiply[c][d];
                        second[c][d]=multiply[c][d];
                        previous[c][d]=second[c][d];
                }
        printf("\n");
        fprintf(outputFile,"\n");
        }
        printf("\n");
        fprintf(outputFile,"\n");


        // printf("\n");
        // printf("Normalisoidaan edellinen tulos...\n");
        // printf("\n");

        // tarkista matriisin arvot
        long double rivisummaPrev[matriisinKoko];
        int r = 0;
        for (c = 0; c < m; c++) {
                long double riviTotalPrev = 0;
                for (d = 0; d < q; d++){
                        riviTotalPrev += previous[c][d];
                }
                rivisummaPrev[r] = riviTotalPrev;
                r++;
        }

        // normalisoidaan matriisi
        int i = 0;
        for (c = 0; c < m; c++) {
                for (d = 0; d < q; d++){
                        previous[c][d] = previous[c][d]/rivisummaPrev[i];
                }
        i++;
        }
        }
        if(isDifferent==0){
                printf("Arvot eivät muutu potenssin %d\n", viimeinenMuutos);
                fprintf(outputFile,"Arvot eivät muutu potenssin %d\n", viimeinenMuutos);
        }

        // close file
        fclose(inputFile);
        fclose(outputFile);

        }
        else
        {
        printf("Matriisitiedostoa ei löydy. Luo teksti tiedosto nimeltä matriisi.txt ja yritä uudelleen.\n");
        }

        return 0;
}
