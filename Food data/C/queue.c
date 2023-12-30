//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
#include <stdio.h>
#include <stdlib.h>
#define MAX 300 // la taille maximum du tableau qui vas contenir les données sur le trajet
// La structure de donnée qui vas contenir horodateur
typedef struct {
    int jour;
    int mois;
    int ans;
    int heure;
    int min;
    int sec;
}horodate;
// La structure de donnée pour la date
typedef struct {
    int jour;
    int mois;
    int ans;
}date;

typedef struct{
    horodate horodateur;
    char sexe;
    int age;
    date Date_transport;
    char period[10];
    char trajet[MAX];
    int cout_totale;
    char embouteillage[5];
    int duree_trajet;
    char etat_route[10];
}data;

data *save(int *n){
    static data *tab;
    FILE *in = fopen("urban_data.txt","r");
    int i=0,j=0;
    char ch;

    if(in == NULL){
        printf("Erreur lors de l'ouverturee du fichier\n");
        return NULL;
    }
    (*n) = 1;
    tab = (data*)malloc((*n)*sizeof(data));
    fscanf(in,"%d",&tab[i].horodateur.jour);
     if(feof(in))
        printf("Desole, le fichier est vide :(\n");
     while(tab[i].horodateur.jour != EOF){
        j=0;
        if(feof(in))
            break;
        fscanf(in,"%d%d%d%d%d",&tab[i].horodateur.mois,&tab[i].horodateur.ans,&tab[i].horodateur.heure,&tab[i].horodateur.min,&tab[i].horodateur.sec);
        tab[i].sexe = getc(in);//recupere l'espace qu'il ya entre le champs seconde et sexe
        tab[i].sexe = getc(in);//ecrase la valeur precedente(l'espace) avec celui du sexe
        fscanf(in,"%d%d%d%d%s",&tab[i].age,&tab[i].Date_transport.jour,&tab[i].Date_transport.mois,&tab[i].Date_transport.ans,tab[i].period);
        ch = getc(in);
        ch = getc(in);
        while((ch = getc(in))!='"'){
            tab[i].trajet[j++]=ch;
        }
        tab[i].trajet[j]='\0';//indique la fin de la chaine de caractère
        fscanf(in,"%d%s%d%s",&tab[i].cout_totale,tab[i].embouteillage,&tab[i].duree_trajet,tab[i].etat_route);
        i++;
        (*n)++;
        tab = (data*)realloc(tab,(*n)*sizeof(data));
        fscanf(in,"%d",&tab[i].horodateur.jour);
     }
     (*n)--;
     fclose(in);
     return tab;
}

void afficher(data *tab, int n){
    int i;
    for (i=0; i<n; i++){
        printf("%d/%d/%-5d%d:%d:%-5d",tab[i].horodateur.jour,tab[i].horodateur.mois,tab[i].horodateur.ans,tab[i].horodateur.heure,tab[i].horodateur.min,tab[i].horodateur.sec);
        printf("%-3c%-3d%d/%d/%-7d",tab[i].sexe,tab[i].age,tab[i].Date_transport.jour,tab[i].Date_transport.mois,tab[i].Date_transport.ans);
        printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n",tab[i].period,tab[i].trajet,tab[i].cout_totale,tab[i].embouteillage,tab[i].duree_trajet,tab[i].etat_route);
    }
}

void search(data *tab, int n, int age){
    int i,j=0;

    for (i=0; i<n; i++){
        if(age==tab[i].age){
            j++;
            printf("%d/%d/%-5d%d:%d:%-5d",tab[i].horodateur.jour,tab[i].horodateur.mois,tab[i].horodateur.ans,tab[i].horodateur.heure,tab[i].horodateur.min,tab[i].horodateur.sec);
            printf("%-3c%-3d%d/%d/%-7d",tab[i].sexe,tab[i].age,tab[i].Date_transport.jour,tab[i].Date_transport.mois,tab[i].Date_transport.ans);
            printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n",tab[i].period,tab[i].trajet,tab[i].cout_totale,tab[i].embouteillage,tab[i].duree_trajet,tab[i].etat_route);
        }
    }
    if(j==0)
        printf("Aucun element ne contient cette age !!!\n");
}
void sort(data *tab, int n){
    data temp;
    int i, j;

    for(i=0; i<n-1; i++){
        for(j=i+1; j<n; j++){
            if(tab[i].age > tab[j].age){
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
        }
    }
}

int main(){
    int choix,age,n;
    data *tab;

    tab = save(&n);
    do{
        printf("---------------------- MENU ------------------------\n");
        printf("0- Quiter\n");
        printf("1- Afficher le tableau\n");
        printf("2- Rechercher et afficher les elements du tableau\n");
        printf("3- Trier le tableau (en fonction de l'age)\n\n");
        printf("Faites un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 0: break;
            case 1: system("cls");
                    afficher(tab,n);
                    break;
            case 2: system("cls");
                    printf("Entrer l'age a rechercher : ");
                    scanf("%d",&age);
                    system("cls");
                    search(tab,n,age);
                    break;
            case 3: system("cls");
                    sort(tab,n);
                    printf("Le tri a ete effectuer avec succes :)\n");
                    break;
            default: printf("Faire un choix entre 0 et 3...\n");
        }
        system("PAUSE");
        system("cls");
    }while(choix!=0);

    free(tab);

    return 0;
}
