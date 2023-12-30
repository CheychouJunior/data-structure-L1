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

typedef struct tree{
    data val;
    struct tree* left;
    struct tree* right;
}tree;

/*LA FONCTION AJOUTER SERT A AJOUTER DES ELEMENTS A UNE LISTE DEJA EXISTANT*/
void ajouter(tree *tr, tree *element){
    tree *ptr = tr;

    if(element->val.age < ptr->val.age){
        if(ptr->left == NULL){
            ptr->left = element;
            return;
        }else
            ajouter(ptr->left, element);
    }else{
        if(ptr->right == NULL){
            ptr->right = element;
            return;
        }else
            ajouter(ptr->right, element);
    }
}
/*LA FONCTION SAVE LIS LES DONNEES A STRUCTURER DU FICHIER "urban_data.txt" ET LES MET DANS UNE LISTE*/
data *savetab(int *n){
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

tree *save_tree(data *tab, int n){
    int i;
    tree *racine, *elt;

    for(i=0;i<n;i++){
        if(i==0){
            racine->val = tab[i];
            racine->left = NULL;
            racine->right = NULL;
        }else{
            elt = (tree*)malloc(sizeof(tree));
            elt->val = tab[i];
            elt->right = NULL;
            elt->left = NULL;
            ajouter(racine,elt);
        }
    }
    return racine;
}

void afficher(tree *racine){
    tree *ptr = racine;

    if(ptr == NULL)
        return;
    else{
        printf("%d/%d/%-5d%d:%d:%-5d",ptr->val.horodateur.jour,ptr->val.horodateur.mois,ptr->val.horodateur.ans,ptr->val.horodateur.heure,ptr->val.horodateur.min,ptr->val.horodateur.sec);
        printf("%-3c%-3d%d/%d/%-7d",ptr->val.sexe,ptr->val.age,ptr->val.Date_transport.jour,ptr->val.Date_transport.mois,ptr->val.Date_transport.ans);
        printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n",ptr->val.period,ptr->val.trajet,ptr->val.cout_totale,ptr->val.embouteillage,ptr->val.duree_trajet,ptr->val.etat_route);
        afficher(ptr->left);
        afficher(ptr->right);
    }
}

void search(tree *racine, int age){
    tree *ptr = racine;

    if(ptr == NULL)
        return;
    else{
        if(ptr->val.age == age){
            printf("%d/%d/%-5d%d:%d:%-5d",ptr->val.horodateur.jour,ptr->val.horodateur.mois,ptr->val.horodateur.ans,ptr->val.horodateur.heure,ptr->val.horodateur.min,ptr->val.horodateur.sec);
            printf("%-3c%-3d%d/%d/%-7d",ptr->val.sexe,ptr->val.age,ptr->val.Date_transport.jour,ptr->val.Date_transport.mois,ptr->val.Date_transport.ans);
            printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n",ptr->val.period,ptr->val.trajet,ptr->val.cout_totale,ptr->val.embouteillage,ptr->val.duree_trajet,ptr->val.etat_route);
        }
        search(ptr->left,age);
        search(ptr->right,age);
    }
}

void sort_tree(tree *racine){//Il suffit de faire un parcour infix de l'arbre
    tree *ptr = racine;

    if(ptr == NULL)
        return;
    else{
        sort_tree(ptr->left);
        printf("%d/%d/%-5d%d:%d:%-5d",ptr->val.horodateur.jour,ptr->val.horodateur.mois,ptr->val.horodateur.ans,ptr->val.horodateur.heure,ptr->val.horodateur.min,ptr->val.horodateur.sec);
        printf("%-3c%-3d%d/%d/%-7d",ptr->val.sexe,ptr->val.age,ptr->val.Date_transport.jour,ptr->val.Date_transport.mois,ptr->val.Date_transport.ans);
        printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n",ptr->val.period,ptr->val.trajet,ptr->val.cout_totale,ptr->val.embouteillage,ptr->val.duree_trajet,ptr->val.etat_route);
        sort_tree(ptr->right);
    }
}

int main(){
    tree *arbre;
    int n,choix,age;

    data *tab = savetab(&n);
    arbre = save_tree(tab,n);
    do{
        printf("---------------------- MENU ------------------------\n");
        printf("0- Quiter\n");
        printf("1- Afficher le l'arbre\n");
        printf("2- Rechercher et afficher les elements de l'arbre\n");
        printf("3- Trier l'arbre (en fonction de l'age)\n\n");
        printf("Faites un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 0: break;
            case 1: system("cls");
                    afficher(arbre);
                    break;
            case 2: system("cls");
                    printf("Entrer l'age a rechercher : ");
                    scanf("%d",&age);
                    system("cls");
                    search(arbre,age);
                    break;
            case 3: system("cls");
                    sort_tree(arbre);
                    break;
            default: printf("Faire un choix entre 0 et 3...\n");
        }
        system("PAUSE");
        system("cls");
    }while(choix!=0);

    free(tab);

    return 0;
}
