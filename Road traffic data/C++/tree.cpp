//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
#include <iostream>
#include <fstream>

using namespace std;

#define MAX 300 // la taille maximum du tableau qui vas contenir les données sur le trajet
// La structure de donnée qui vas contenir horodateur
typedef struct {
    int jour;
    int mois;
    int ans;
    int heure;
    int minute;
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
    date Date;
    char period[10];
    char repas[MAX];
    char unite[30];
    char lieu[25];
    int nombre;
}data;

typedef struct tree{
    data val;
    struct tree* left;
    struct tree* right;
}tree;

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

data *savetab(int *n){
    static data *tab;
    FILE *in = fopen("foodData.txt","r");
    int i=0,j=0,k=0;
    char ch;

    if(in == NULL){
        cout<<"Erreur lors de l'ouverturee du fichier\n";
        return NULL;
    }
    (*n) = 1;
    tab = (data*)malloc((*n)*sizeof(data));
    fscanf(in,"%d",&tab[i].horodateur.jour);
     if(feof(in))
        cout<<"Desole, le fichier est vide :(\n";
     while(tab[i].horodateur.jour != EOF){
        j = k = 0;
        if(feof(in))
            break;
        fscanf(in,"%d%d%d%d%d",&tab[i].horodateur.mois,&tab[i].horodateur.ans,&tab[i].horodateur.heure,&tab[i].horodateur.minute,&tab[i].horodateur.sec);
        tab[i].sexe = getc(in);//recupere l'espace qu'il ya entre le champs seconde et sexe
        tab[i].sexe = getc(in);//ecrase la valeur precedente(l'espace) avec celui du sexe
        fscanf(in,"%d%d%d%d%s",&tab[i].age,&tab[i].Date.jour,&tab[i].Date.mois,&tab[i].Date.ans,tab[i].period);
        ch = getc(in);
        ch = getc(in);
        while((ch = getc(in))!='"'){
            tab[i].repas[j++]=ch;
        }
        tab[i].repas[j]='\0';//indique la fin de la chaine de caractère
        ch = getc(in);
        ch = getc(in);
        while((ch = getc(in))!='"'){
            tab[i].unite[k++]=ch;
        }
        tab[i].unite[k]='\0';//indique la fin de la chaine de caractère
        fscanf(in,"%s%d",tab[i].lieu,&tab[i].nombre);
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

    racine = (tree*)malloc(sizeof(tree));
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
        cout<<ptr->val.horodateur.jour<<"/"<<ptr->val.horodateur.mois<<"/"<<ptr->val.horodateur.ans<<"\t"<<ptr->val.horodateur.heure<<":"<<ptr->val.horodateur.minute<<":"<<ptr->val.horodateur.sec<<"\t";
        cout<<ptr->val.sexe<<"\t"<<ptr->val.age<<"\t"<<ptr->val.Date.jour<<"/"<<ptr->val.Date.mois<<"/"<<ptr->val.Date.ans<<"\t";
        cout<<ptr->val.period<<"\t"<<ptr->val.repas<<"\t"<<ptr->val.unite<<"\t"<<ptr->val.lieu<<"\t"<<ptr->val.nombre<<endl<<endl;
        afficher(ptr->left);
        afficher(ptr->right);
    }
}

void search_arbre(tree *racine, int age){
    tree *ptr = racine;

    if(ptr == NULL)
        return;
    else{
        if(ptr->val.age == age){
        cout<<ptr->val.horodateur.jour<<"/"<<ptr->val.horodateur.mois<<"/"<<ptr->val.horodateur.ans<<"\t"<<ptr->val.horodateur.heure<<":"<<ptr->val.horodateur.minute<<":"<<ptr->val.horodateur.sec<<"\t";
        cout<<ptr->val.sexe<<"\t"<<ptr->val.age<<"\t"<<ptr->val.Date.jour<<"/"<<ptr->val.Date.mois<<"/"<<ptr->val.Date.ans<<"\t";
        cout<<ptr->val.period<<"\t"<<ptr->val.repas<<"\t"<<ptr->val.unite<<"\t"<<ptr->val.lieu<<"\t"<<ptr->val.nombre<<endl<<endl;        }
        search_arbre(ptr->left,age);
        search_arbre(ptr->right,age);
    }
}

void sort_tree(tree *racine){//Il suffit de faire un parcour infix de l'arbre
    tree *ptr = racine;

    if(ptr == NULL)
        return;
    else{
        sort_tree(ptr->left);
        cout<<ptr->val.horodateur.jour<<"/"<<ptr->val.horodateur.mois<<"/"<<ptr->val.horodateur.ans<<"\t"<<ptr->val.horodateur.heure<<":"<<ptr->val.horodateur.minute<<":"<<ptr->val.horodateur.sec<<"\t";
        cout<<ptr->val.sexe<<"\t"<<ptr->val.age<<"\t"<<ptr->val.Date.jour<<"/"<<ptr->val.Date.mois<<"/"<<ptr->val.Date.ans<<"\t";
        cout<<ptr->val.period<<"\t"<<ptr->val.repas<<"\t"<<ptr->val.unite<<"\t"<<ptr->val.lieu<<"\t"<<ptr->val.nombre<<endl<<endl;
        sort_tree(ptr->right);
    }
}

int main(){
    tree *arbre;
    int n,choix,age;

    data *tab = savetab(&n);
    arbre = save_tree(tab,n);
    do{
        cout<<"---------------------- MENU ------------------------\n";
        cout<<"0- Quiter\n";
        cout<<"1- Afficher le l'arbre\n";
        cout<<"2- Rechercher et afficher les elements de l'arbre\n";
        cout<<"3- Trier l'arbre (en fonction de l'age)\n\n";
        cout<<"Faites un choix : ";
        scanf("%d",&choix);
        switch(choix){
            case 0: break;
            case 1: system("cls");
                    afficher(arbre);
                    break;
            case 2: system("cls");
                    cout<<"Entrer l'age a rechercher : ";
                    scanf("%d",&age);
                    system("cls");
                    search_arbre(arbre,age);
                    break;
            case 3: system("cls");
                    sort_tree(arbre);
                    break;
            default: cout<<"Faire un choix entre 0 et 3...\n";
        }
        system("PAUSE");
        system("cls");
    }while(choix!=0);

    free(tab);

    return 0;
}
