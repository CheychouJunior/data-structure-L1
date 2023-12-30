//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
#include <stdio.h>
#include <stdlib.h>

#define MAX 300
#define HASHTABLE_SIZE 10

// La structure de donn�e qui vas contenir horodateur
typedef struct {
    int jour;
    int mois;
    int ans;
    int heure;
    int min;
    int sec;
}horodate;
// La structure de donn�e pour la date
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

typedef struct node{
    data value;
    struct node* next;
}node;

void insert_new_node(node** head, data new_value){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = new_value;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
    }else{
        node* current = *head;
        while(current->next!=NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}

int get_location(int new_value){
    return new_value%HASHTABLE_SIZE;
}

void insert_into_table(node** hashtable, data new_value){
    int location = get_location(new_value.age);

    if(hashtable[location]==NULL){
        hashtable[location] = malloc(sizeof(node*));

        node* head = NULL;
        insert_new_node(&head, new_value);

        hashtable[location] = head;
    }else{
        node* head = hashtable[location];
        insert_new_node(&head,new_value);

        hashtable[location] = head;
    }
}

void afficher(node** hashtable){
    int i;
    for(i=0; i< HASHTABLE_SIZE; i++){
        node* head = hashtable[i];

        if(head != NULL){
            node* current = head;
            while(current!=NULL){
                printf("%d/%d/%-5d%d:%d:%-5d",current->value.horodateur.jour,current->value.horodateur.mois,current->value.horodateur.ans,current->value.horodateur.heure,current->value.horodateur.min,current->value.horodateur.sec);
                printf("%-3c%-3d%d/%d/%-7d",current->value.sexe,current->value.age,current->value.Date_transport.jour,current->value.Date_transport.mois,current->value.Date_transport.ans);
                printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n\n",current->value.period,current->value.trajet,current->value.cout_totale,current->value.embouteillage,current->value.duree_trajet,current->value.etat_route);
                current = current->next;
            }
        }
    }
}

node** get_hashtable(){
    node** hashtable = calloc(HASHTABLE_SIZE, sizeof(node*));
    return hashtable;
}

node **save(){
    node** table = get_hashtable();
    FILE *in = fopen("urban_data.txt","r");
    int i,count = 1,found,index;
    data x;
    char ch;

    if(in == NULL){
        printf("Erreur lors de l'ouverture du fichier !!! :(\n");
        return;
    }
    fscanf(in,"%d",&x.horodateur.jour);
    if(feof(in))
        printf("Desol�, le fichier est vide :(\n");
    while(x.horodateur.jour != EOF){
        i = 0;
        if(feof(in))
            break;
        fscanf(in,"%d%d%d%d%d",&x.horodateur.mois,&x.horodateur.ans,&x.horodateur.heure,&x.horodateur.min,&x.horodateur.sec);
        x.sexe = getc(in);//recupere l'espace qu'il ya entre le champs seconde et sexe
        x.sexe = getc(in);//ecrase la valeur precedente(l'espace) avec celui du sexe
        fscanf(in,"%d%d%d%d%s",&x.age,&x.Date_transport.jour,&x.Date_transport.mois,&x.Date_transport.ans,x.period);
        ch = getc(in);
        ch = getc(in);
        while((ch = getc(in))!='"'){
            x.trajet[i++]=ch;
        }
        x.trajet[i]='\0';//indique la fin de la chaine de caract�re
        fscanf(in,"%d%s%d%s",&x.cout_totale,x.embouteillage,&x.duree_trajet,x.etat_route);
        insert_into_table(table,x);
        fscanf(in,"%d",&x.horodateur.jour);
    }
    fclose(in);
    return table;
}
void search(node** table, int age){
    int index = get_location(age);
    node* head = table[index];
    int i = 0;

    while(head!=NULL){
        if(head->value.age == age){
            printf("%d/%d/%-5d%d:%d:%-5d",head->value.horodateur.jour,head->value.horodateur.mois,head->value.horodateur.ans,head->value.horodateur.heure,head->value.horodateur.min,head->value.horodateur.sec);
            printf("%-3c%-3d%d/%d/%-7d",head->value.sexe,head->value.age,head->value.Date_transport.jour,head->value.Date_transport.mois,head->value.Date_transport.ans);
            printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n\n",head->value.period,head->value.trajet,head->value.cout_totale,head->value.embouteillage,head->value.duree_trajet,head->value.etat_route);
            i++;
        }
        head = head->next;
    }
    if(i==0)
        printf("Aucun element trouver\n");
}

void sort(node** table){
    int i;
    for(i=7; i< HASHTABLE_SIZE; i++){
        node* head = table[i];

        if(head != NULL){
            node* current = head;
            while(current!=NULL){
                printf("%d/%d/%-5d%d:%d:%-5d",current->value.horodateur.jour,current->value.horodateur.mois,current->value.horodateur.ans,current->value.horodateur.heure,current->value.horodateur.min,current->value.horodateur.sec);
                printf("%-3c%-3d%d/%d/%-7d",current->value.sexe,current->value.age,current->value.Date_transport.jour,current->value.Date_transport.mois,current->value.Date_transport.ans);
                printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n\n",current->value.period,current->value.trajet,current->value.cout_totale,current->value.embouteillage,current->value.duree_trajet,current->value.etat_route);
                current = current->next;
            }
        }
    }
    for(i=0; i< 7; i++){
        node* head = table[i];

        if(head != NULL){
            node* current = head;
            while(current!=NULL){
                printf("%d/%d/%-5d%d:%d:%-5d",current->value.horodateur.jour,current->value.horodateur.mois,current->value.horodateur.ans,current->value.horodateur.heure,current->value.horodateur.min,current->value.horodateur.sec);
                printf("%-3c%-3d%d/%d/%-7d",current->value.sexe,current->value.age,current->value.Date_transport.jour,current->value.Date_transport.mois,current->value.Date_transport.ans);
                printf("%-10s\"%-70s\"%-5d%-5s%-5d%-8s\n\n",current->value.period,current->value.trajet,current->value.cout_totale,current->value.embouteillage,current->value.duree_trajet,current->value.etat_route);
                current = current->next;
            }
        }
    }
}

int main(){
    node** table = get_hashtable();
    int choix,age;
    data *tab;

    do{
        printf("---------------------- MENU ------------------------\n");
        printf("0- Quiter\n");
        printf("1- Enregistrer et afficher le tableau\n");
        printf("2- Rechercher et afficher les elements du tableau\n");
        printf("3- Trier le tableau (en fonction de l'age)\n\n");
        printf("Faites un choix : ");
        scanf("%d",&choix);
        switch(choix){
            case 0: break;
            case 1: system("cls");
                    table = save();
                    afficher(table);
                    break;
            case 2: system("cls");
                    printf("Entrer l'age a rechercher : ");
                    scanf("%d",&age);
                    system("cls");
                    search(table,age);
                    break;
            case 3: system("cls");
                    sort(table);
                    printf("Le tri a ete effectuer avec succes :)\n");
                    break;
            default: printf("Faire un choix entre 0 et 3...\n");
        }
        system("PAUSE");
        system("cls");
    }while(choix!=0);
    return 0;
}
