#include <stdio.h>
#include <stdlib.h>

int main() {
    
    while(1){
        
        int row, col, i ,j, low, high;
        double **matrix, sum=0;
        printf("\nUnesite dimenziju kvadratne matrice:  ");
        scanf("%d", &row);
        if (row<=0){
            printf("Uneli ste nevalidnu dimenziju matrice. \n");
            break;
        }
        printf("\n");
        col=row;
        
        printf("Unesite opseg za generisanje rand brojeva. Prvo donju granicu, zatim gornju.\n");
        scanf("%d %d", &low, &high);
        
        matrix = malloc(row*sizeof(double*));
        if (matrix==NULL) {
            printf("\nAlokacija memorije nije uspela.\n");
            break;
        }
        
        for (i=0; i<row; i++){
            *(matrix+i)= malloc((col+1)*sizeof(double));
            if (*(matrix+i)==NULL) {
                printf("\nAlokacija memorije nije uspela.\n");
                break;
            }
            double sumrow=0;
            for (j=0; j<col; j++){
                matrix[i][j]=(double)rand()/RAND_MAX*(high-low)+low;
                sumrow+=matrix[i][j];
                if (i==j) sum+=matrix[i][j];
            }
            matrix[i][col]=sumrow/row;
            printf("Srednja vrednost vrste broj %d je %.3f \n", i+1, matrix[i][col]);
        }
        
        sum=sum/row;
        printf("\nSrednja vrednost elemenata glavne dijagonale je %.3f\n", sum);
        int count=0;
        
        printf("\nPre izbacivanja vrsta matrica izgleda ovako:");
        for (i=0; i<row; i++){
            printf("\n");
            for (j=0; j<col; j++)
                printf("%.3f\t", matrix[i][j]);
        }
        printf("\n");
        
        for (i=0; i<row; i++){
            if (matrix[i][col]<sum){
                free(matrix[i]);
                count++;
                continue;
            }
            matrix[i-count]=matrix[i];
        }
        row-=count;
        realloc(matrix, row*sizeof(double*));
        
        if (row==0)
            printf("Sve vrste su izbacene. \n");
        else {
            printf("\nPosle izbacivanja vrsta matrica izgleda ovako:");
            for (i=0; i<row; i++){
                printf("\n");
                for (j=0; j<col; j++)
                    printf("%.3f\t", matrix[i][j]);
            }
            printf("\n");
        
            for (i=0; i<row; free(matrix[i++]));
            free(matrix);
        }
             
    }
    return 0;
}
