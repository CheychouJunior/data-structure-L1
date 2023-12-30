//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
#include <iostream>
#include <fstream>
#include <cstdlib>

#define MAX 300
#define HASHTABLE_SIZE 10

using namespace std;

// La structure de donnée qui vas contenir horodateur
typedef struct {
    int jour;
    int mois;
    int ans;
    int heure;
    int minutes;
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
        hashtable[location] = (node*)malloc(sizeof(node*));

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
            node* ptr = head;
            while(ptr!=NULL){
                cout<<ptr->value.horodateur.jour<<"/"<<ptr->value.horodateur.mois<<"/"<<ptr->value.horodateur.ans<<"\t"<<ptr->value.horodateur.heure<<":"<<ptr->value.horodateur.minutes<<":"<<ptr->value.horodateur.sec<<"\t";
                cout<<ptr->value.sexe<<"\t"<<ptr->value.age<<"\t"<<ptr->value.Date_transport.jour<<"/"<<ptr->value.Date_transport.mois<<"/"<<ptr->value.Date_transport.ans<<"\t";
                cout<<ptr->value.period<<"\t"<<ptr->value.trajet<<"\t"<<ptr->value.cout_totale<<"\t"<<ptr->value.embouteillage<<"\t"<<ptr->value.duree_trajet<<"\t"<<ptr->value.etat_route<<"\n\n";
                ptr = ptr->next;
            }
        }
    }
}

node** get_hashtable(){
    node** hashtable = (node**)calloc(HASHTABLE_SIZE, sizeof(node*));
    return hashtable;
}

node **save(){
    node** table = get_hashtable();
    FILE *in = fopen("urban_data.txt","r");
    int i;
    data x;
    char ch;

    if(in == NULL){
        cout<<"Erreur lors de l'ouverturee du fichier\n";
        return NULL;
    }
    fscanf(in,"%d",&x.horodateur.jour);
    if(feof(in))
        cout<<"Desolé, le fichier est vide :(\n";
    while(x.horodateur.jour != EOF){
        i = 0;
        if(feof(in))
            break;
        fscanf(in,"%d%d%d%d%d",&x.horodateur.mois,&x.horodateur.ans,&x.horodateur.heure,&x.horodateur.minutes,&x.horodateur.sec);
        x.sexe = getc(in);//recupere l'espace qu'il ya entre le champs seconde et sexe
        x.sexe = getc(in);//ecrase la valueeur precedente(l'espace) avec celui du sexe
        fscanf(in,"%d%d%d%d%s",&x.age,&x.Date_transport.jour,&x.Date_transport.mois,&x.Date_transport.ans,x.period);
        ch = getc(in);
        ch = getc(in);
        while((ch = getc(in))!='"'){
            x.trajet[i++]=ch;
        }
        x.trajet[i]='\0';//indique la fin de la chaine de caractère
        fscanf(in,"%d%s%d%s",&x.cout_totale,x.embouteillage,&x.duree_trajet,x.etat_route);
        insert_into_table(table,x);
        fscanf(in,"%d",&x.horodateur.jour);
    }
    fclose(in);
    return table;
}
void search_hash(node** table, int age){
    int index = get_location(age);
    node* ptr = table[index];
    int i = 0;

    while(ptr!=NULL){
        if(ptr->value.age == age){
            cout<<ptr->value.horodateur.jour<<"/"<<ptr->value.horodateur.mois<<"/"<<ptr->value.horodateur.ans<<"\t"<<ptr->value.horodateur.heure<<":"<<ptr->value.horodateur.minutes<<":"<<ptr->value.horodateur.sec<<"\t";
            cout<<ptr->value.sexe<<"\t"<<ptr->value.age<<"\t"<<ptr->value.Date_transport.jour<<"/"<<ptr->value.Date_transport.mois<<"/"<<ptr->value.Date_transport.ans<<"\t";
            cout<<ptr->value.period<<"\t"<<ptr->value.trajet<<"\t"<<ptr->value.cout_totale<<"\t"<<ptr->value.embouteillage<<"\t"<<ptr->value.duree_trajet<<"\t"<<ptr->value.etat_route<<"\n\n";
            i++;
        }
        ptr = ptr->next;
    }
    if(i==0)
        cout<<"Aucun element trouver\n";
}

void sort_hash(node** table){
    int i;
    for(i=7; i< HASHTABLE_SIZE; i++){
        node* head = table[i];

        if(head != NULL){
            node* ptr = head;
            while(ptr!=NULL){
                cout<<ptr->value.horodateur.jour<<"/"<<ptr->value.horodateur.mois<<"/"<<ptr->value.horodateur.ans<<"\t"<<ptr->value.horodateur.heure<<":"<<ptr->value.horodateur.minutes<<":"<<ptr->value.horodateur.sec<<"\t";
                cout<<ptr->value.sexe<<"\t"<<ptr->value.age<<"\t"<<ptr->value.Date_transport.jour<<"/"<<ptr->value.Date_transport.mois<<"/"<<ptr->value.Date_transport.ans<<"\t";
                cout<<ptr->value.period<<"\t"<<ptr->value.trajet<<"\t"<<ptr->value.cout_totale<<"\t"<<ptr->value.embouteillage<<"\t"<<ptr->value.duree_trajet<<"\t"<<ptr->value.etat_route<<"\n\n";
                ptr = ptr->next;
            }
        }
    }
    for(i=0; i< 7; i++){
        node* head = table[i];

        if(head != NULL){
            node* ptr = head;
            while(ptr!=NULL){
                cout<<ptr->value.horodateur.jour<<"/"<<ptr->value.horodateur.mois<<"/"<<ptr->value.horodateur.ans<<"\t"<<ptr->value.horodateur.heure<<":"<<ptr->value.horodateur.minutes<<":"<<ptr->value.horodateur.sec<<"\t";
                cout<<ptr->value.sexe<<"\t"<<ptr->value.age<<"\t"<<ptr->value.Date_transport.jour<<"/"<<ptr->value.Date_transport.mois<<"/"<<ptr->value.Date_transport.ans<<"\t";
                cout<<ptr->value.period<<"\t"<<ptr->value.trajet<<"\t"<<ptr->value.cout_totale<<"\t"<<ptr->value.embouteillage<<"\t"<<ptr->value.duree_trajet<<"\t"<<ptr->value.etat_route<<"\n\n";
                ptr = ptr->next;
            }
        }
    }
}

int main(){
    node** table = get_hashtable();
    int choix,age;
    data *tab;

    do{
        cout<<"---------------------- MENU ------------------------\n";
        cout<<"0- Quiter\n";
        cout<<"1- Enregistrer et afficher le tableau\n";
        cout<<"2- Rechercher et afficher les elements du tableau\n";
        cout<<"3- Trier le tableau (en fonction de l'age)\n\n";
        cout<<"Faites un choix : ";
        cin>>choix;
        switch(choix){
            case 0: break;
            case 1: system("cls");
                    table = save();
                    afficher(table);
                    break;
            case 2: system("cls");
                    cout<<"Entrer l'age a rechercher : ";
                    cin>>age;
                    system("cls");
                    search_hash(table,age);
                    break;
            case 3: system("cls");
                    sort_hash(table);
                    break;
            default: cout<<"Faire un choix entre 0 et 3...\n";
        }
        system("PAUSE");
        system("cls");
    }while(choix!=0);
    return 0;
}
