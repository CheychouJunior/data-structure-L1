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
    date Date;
    char period[10];
    char repas[MAX];
    char unite[30];
    char lieu[25];
    int nombre;
}data;

typedef struct list{
    data val;
    struct list* next;
}list;
/* LA FONCTION CREER QUI SERT A CREER LE PREMIER ELEMENT DE LA LISTE, ET PREND A PARAMETRE LA DONNEE DE PREMIER ELEMENT*/
list *creer(data x){
    list *li;
    li = (list*)malloc(sizeof(list));
    li->val = x;
    li->next = NULL;
    return li;
}
/*LA FONCTION AJOUTER SERT A AJOUTER DES ELEMENTS A UNE LISTE DEJA EXISTANT*/
list *push(list *li, data val){
    list *ptr = li, *element;

    element = (list*)malloc(sizeof(list));
    element->val = val;
    element->next = li;

    return element;
}
/*LA FONCTION SAVE LIS LES DONNEES A STRUCTURER DU FICHIER "urban_data.txt" ET LES MET DANS UNE LISTE*/
 list *save_stack(){
     FILE *in = fopen("foodData.txt","r");
     int i,count = 1;
     data x;
     list *tete;
     char ch;

     if(in == NULL){
        printf("Erreur lors de l'ouverture du fichier !!! :(\n");
        return NULL;
     }
     fscanf(in,"%d",&x.horodateur.jour);
     if(feof(in))
        printf("Desolé, le fichier est vide :(\n");
     while(x.horodateur.jour != EOF){
        i = 0;
        if(feof(in))
            break;
        fscanf(in,"%d%d%d%d%d",&x.horodateur.mois,&x.horodateur.ans,&x.horodateur.heure,&x.horodateur.min,&x.horodateur.sec);
        x.sexe = getc(in);//recupere l'espace qu'il ya entre le champs seconde et sexe
        x.sexe = getc(in);//ecrase la valeur precedente(l'espace) avec celui du sexe
        fscanf(in,"%d%d%d%d%s",&x.age,&x.Date.jour,&x.Date.mois,&x.Date.ans,x.period);
        ch = getc(in);
        ch = getc(in);
        while((ch = getc(in))!='"'){
            x.repas[i++]=ch;
        }
        x.repas[i]='\0';//indique la fin de la chaine de caractère
        ch = getc(in);
        ch = getc(in);
        i = 0;
        while((ch = getc(in))!='"'){
            x.unite[i++]=ch;
        }
        x.unite[i]='\0';//indique la fin de la chaine de caractère
        fscanf(in,"%s%d",x.lieu,&x.nombre);
        if(count == 1){
            tete = creer(x);
        }else{
            tete = push(tete,x);
        }
        count++;
        fscanf(in,"%d",&x.horodateur.jour);

     }

     fclose(in);
    return tete;
 }
 //LA FONCION afficher SERT A AFFICHER LES ELEMENTS DE LA LISTE PASSER EN PARAMETRE
 void print_stack(list* li){// Elle affiche en FIFO (First In First Out)
    list* ptr = li;
    while(ptr!=NULL){
        printf("%d/%d/%-5d%d:%d:%-5d",ptr->val.horodateur.jour,ptr->val.horodateur.mois,ptr->val.horodateur.ans,ptr->val.horodateur.heure,ptr->val.horodateur.min,ptr->val.horodateur.sec);
        printf("%-3c%-3d%d/%d/%-7d",ptr->val.sexe,ptr->val.age,ptr->val.Date.jour,ptr->val.Date.mois,ptr->val.Date.ans);
        printf("%-10s%-65s%-20s%-15s%-5d\n",ptr->val.period,ptr->val.repas,ptr->val.unite,ptr->val.lieu,ptr->val.nombre);
        ptr = ptr->next;
     }
 }
 //LA FONCTION search PERMET DE RECHERCHER ET A AFFICHER LES ELEMENTS D'UNE LISTE QUI ONT UN AGE SPECIFIQUE
 void search(list *li,int age){
    list *ptr = li;
    int i=0;
    while(ptr != NULL){
        if(ptr->val.age == age){
            printf("%d/%d/%-5d%d:%d:%-5d",ptr->val.horodateur.jour,ptr->val.horodateur.mois,ptr->val.horodateur.ans,ptr->val.horodateur.heure,ptr->val.horodateur.min,ptr->val.horodateur.sec);
            printf("%-3c%-3d%d/%d/%-7d",ptr->val.sexe,ptr->val.age,ptr->val.Date.jour,ptr->val.Date.mois,ptr->val.Date.ans);
            printf("%-10s%-70s%-20s%-20s%-5d\n",ptr->val.period,ptr->val.repas,ptr->val.unite,ptr->val.lieu,ptr->val.nombre);
            i++;
        }
        ptr = ptr->next;
    }
    if(i==0)
        printf("Aucun element trouver... :(\n");
 }
//LA FONCTION clear_list SERT A EFFACER LA LISTE PASSEE EN PARAMETRE
 void clear_stack(list* li){
    list *ptr = li;
    while(li != NULL){
        li = li->next;
        free(ptr);
        ptr = li;
    }
 }
//LA FONCTION sort PERMET DE TRIER LES ELEMENTS D'UNE LISTE EN FONCTION DE L'AGE
void sort(list *li){
    list *ptr = li, *ctr;
    data temp;
    // le tri insertion //
    while(ptr->next != NULL){
        ctr = ptr->next;
        while(ctr != NULL){
            if(ptr->val.age > ctr->val.age){
                temp = ptr->val;
                ptr->val = ctr->val;
                ctr->val = temp;
            }
            ctr = ctr->next;
        }
        ptr = ptr->next;
    }
}
int main(){
    int choix,age;
    list *li;

    li = save_stack();
    do{
        printf("---------------------- MENU ------------------------\n");
        printf("0- Quiter\n");
        printf("1- Afficher la liste\n");
        printf("2- Rechercher et afficher les elements de la liste\n");
        printf("3- Trier la liste(en fonction de l'age)\n\n");
        printf("Faites un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 0: break;
            case 1: system("cls");
                    print_stack(li);
                    break;
            case 2: system("cls");
                    printf("Entrer l'age a rechercher : ");
                    scanf("%d",&age);
                    system("cls");
                    search(li,age);
                    break;
            case 3: system("cls");
                    sort(li);
                    printf("Le tri a ete effectuer avec succes :)\n");
                    break;
            default: printf("Faire un choix entre 0 et 3...\n");
        }
        system("PAUSE");
        system("cls");
    }while(choix!=0);
    clear_stack(li);

    return 0;
}
