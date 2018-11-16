#include <stdio.h>
#include <stdlib.h>

struct client{
    char numClient[50];
    char nom[100];
};

struct materiel{
    char numMat[25];
    char nom[50];
    char disign[100];
    int pu;
    double StockActuel;
    double StockInit;
};


struct achat{
    char numClient[50];
    char numMat[100];
    int qte;
    char dateAchat[50];// atao struct ny date
};
void creation_Fmateriel();
int ajout_mat();
int recherch_mat(char);

int main()
{
    char nb[20];
    creation_Fmateriel();
    //ajout_mat();
    printf("Entrer :");scanf("%s",nb);
    recherch_mat(*nb);
    return 0;
}


void creation_Fmateriel(){
    FILE *file = fopen("Materiel.txt","a");
    fclose(file);
}
/*
void creation_Fclient(){
    FILE *file = fopen("client.txt","w");
    fclose(file);
}
*/

int recherch_mat(char numMatrl){
    struct materiel rech;
    FILE *file = NULL;
    file = fopen("Materiel.txt","r");

    do{
        fscanf(file,"%s\t%s\t\t%s\n",rech.numMat,rech.nom,rech.disign);
        fflush(stdin);

        if(*rech.numMat == numMatrl){
            printf("\nNumero: %s\nNom: %s\nPrix unitaire: %s\n",rech.numMat,rech.nom,rech.disign);
            return 1;
        }
    }while(!feof(file));

    printf("Le numero n'exite pas\n");
    fclose(file);
    return 0;
}


int ajout_mat(){
    struct materiel mat;
    char chaine;
    FILE *file = NULL;

    printf("Entrer le numero du materiel: ");scanf("%s",mat.numMat);
    printf("Entrer le nom du materiel: ");scanf("%s",mat.nom);
    printf("Le taux de la materiel: ");scanf("%d",&mat.pu);

    file = fopen("Materiel.txt","r");
        chaine = fgetc(file);
        fflush(stdin);

            if(chaine == 'N')
                {
                    fclose(file);
                    file = fopen("Materiel.txt","a");
                    fprintf(file,"%s\t%s\t\t%d\n",mat.numMat,mat.nom,mat.pu);
                    fclose(file);
                    return -1;
                }else
                    {
                        fclose(file);
                        file = fopen("Materiel.txt","a");
                        fprintf(file,"Numero\tNOM\t\tTaux\n");
                        fprintf(file,"%s\t%s\t\t%d\n",mat.numMat,mat.nom,mat.pu);
                        fclose(file);
                        return -2;
                    }

    fclose(file);

    return 1;
}

