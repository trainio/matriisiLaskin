#include <stdio.h>

long double round(long double var, int digits);
long double potenssi(long double var, int pow);

int main()
{
        char normalize = 'e';
        int matriisinKoko = 2;
        int m = matriisinKoko;
        int n = matriisinKoko;
        int p = matriisinKoko;
        int q = matriisinKoko;
        int c = 0;
        int d = 0;
        int k = 0;
        int numberOfIterations = 1;
        int digits = 2;
        int count = 0;
        double number;
        long double sum = 0;
        long double first[10][10], second[10][10], multiply[10][10];

        FILE *inputFile;
	FILE *outputFile;
	// avaa tiedosto josta matriisi luetaan
	inputFile = fopen("matriisi.txt", "r"); // "r" lukemista

        printf("Normalisoidaanko (k = kyllä / e = ei):");
        scanf("%c",&normalize);
        printf("Matriisinkoko:");
        scanf("%d",&matriisinKoko);
         m = matriisinKoko;
         n = matriisinKoko;
         p = matriisinKoko;
         q = matriisinKoko;

        // jos matriisi.txt löytyi
        if(inputFile!=NULL){
                // valitaan kertolaskujen määrä
                printf("Kirjoita haluamasi potenssi kokonaislukuna:");
                scanf("%d",&numberOfIterations);

                // avaa tiedosto tulksen kirjaamista varten
                outputFile = fopen("tulos.txt", "w"); // "w" kirjoittamista varten
                // luetaan luvut matriisi.txt tiedostosta
                while(fscanf(inputFile,"%lf", &number) != EOF){
                        printf("%lf\t", number);
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

while(count < numberOfIterations){

        if(normalize == 'k'){
                printf("\n");
                printf("Normalisoidaan...\n");

                // tarkista matriisin arvot
                long double rivisumma[matriisinKoko];
                int r = 0;
                for (c = 0; c < m; c++) {

                        long double riviTotal = 0;
                        for (d = 0; d < q; d++){

                                riviTotal += first[c][d];
                        }
                        rivisumma[r] = riviTotal;
                        r++;
                }
                // normalisoidaan matriisi
                int i = 0;
                for (c = 0; c < m; c++) {
                        for (d = 0; d < q; d++){
                                second[c][d] = first[c][d]/rivisumma[i];
                                first[c][d] = second[c][d];
                        }
                i++;
                }
        }


        count++;

        for (c = 0; c < m; c++) {
                for (d = 0; d < q; d++) {
                        for (k = 0; k < p; k++) {
                                  sum = sum + first[c][k]*second[k][d];
                        }
                        multiply[c][d] = sum;
                        sum = 0;
                }
        }


        printf("Tulos: %d\n",count);
        fprintf(outputFile, "Tulos: %d\n",count);

                for (c = 0; c < m; c++) {
                        for (d = 0; d < q; d++){
                                printf("%Lf\t", multiply[c][d]);
                                //long double result = round(multiply[c][d], 6);
                                fprintf(outputFile,"%Lf\t",multiply[c][d]);
                                first[c][d]=multiply[c][d];
                                second[c][d]=multiply[c][d];

                        }
                printf("\n");
                fprintf(outputFile,"\n");
                }
        printf("\n");
        fprintf(outputFile,"\n");
}
  // close file
  fclose(inputFile);
  fclose(outputFile);

} else {
printf("Matriisitiedostoa ei löydy. Luo teksti tiedosto nimeltä matriisi.txt");
}

  return 0;
}


long double round(long double var, int digits)
{
        int mult = potenssi(10,digits);
        long double value = (int)(var * mult + .5);
        return (double)value / mult;
}

long double potenssi(long double var, int pow)
{
        int i;
        long double result;
        for (i = 0; i < pow; i++) {
                var*=var;
                result=var;
        }
    return result;
}
