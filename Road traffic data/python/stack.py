#NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
def save():
    fic = open("foodData.txt","r")
    liste = []
    
    for fic.readline in fic:
        line = fic.readline
        line = line.split("\"")
        line[3] = int(line[3])
        liste.append(line)
    fic.close()
    liste.reverse()
    return liste

def afficher(li):
    print("\tHorodateur\t\t  Sexe  Age\t Date\t\tPeriod\t\tRepas\t\t\t\tUnite\t\tLieu\tNombre")
    for x in li:
        print("{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\t{}\n".format(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9]))

def sort(li):
    i=0
    while(i<len(li)) :
        j = i+1
        while(j<len(li)):
            if(li[i][3]>li[j][3]):
                x = li[i]
                li[i] = li[j]
                li[j] = x
            j+=1
        i+=1
    print("La liste a ete trier...\n")

def search(li, num):
    print("\tHorodateur\t\t  Sexe  Age\t Date\t\tPeriod\t\tRepas\t\t\t\tUnite\t\tLieu\tNombre")
    for x in li:
        if(x[3]==num):
            print("{} {} {} {} {} {} {} {} {} {}\n".format(x[0],x[1],x[2],x[3],x[4],x[5],x[6],x[7],x[8],x[9]))
    
x = 1
while x != 0:
    li = save()
    print("----------------------- MENU --------------------------")
    print("0 - Quitter")
    print("1 - Enregistrer les donnee")
    print("2 - Trier en fonction de l'age")
    print("3 - Rechercher les donnee en fonction de l'age\n")
    x = input("Faites un choix : ")
    x = int(x)
    if (x == 1):
        afficher(li)
    elif x == 2:
        sort(li)
        afficher(li)
    elif x == 3:
        age = input("Entrer l'age a rechercher : ")
        age = int(age)
        search(li,age)
    else:
        print("Faire un choix entre 0 et 3")           