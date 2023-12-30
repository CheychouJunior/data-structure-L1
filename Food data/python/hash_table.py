#NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
class hash_table:
    def __init__(self):
        self.table = [[],[],[],[],[],[],[],[],[],[]]
        
    def save(self):
        fic = open("urban_data.txt","r")
        
        for fic.readline in fic:
            line = fic.readline
            line = line.split("\"")
            line[3] = int(line[3])
            self.insert(line)
        fic.close()
        
    def insert(self,val):
        index = self.hash_function(val[3])
        if self.table[index] is None:
            self.table[index][0] = val
        else: 
            self.table[index].append(val)
        
    def hash_function(self,val):
        return val % 10
    
    def afficher(self):
        i=0
        while i < 10:
            j = 0
            while j < len(self.table[i]) : 
                print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.table[i][j][0],self.table[i][j][1],self.table[i][j][2],self.table[i][j][3],self.table[i][j][4],self.table[i][j][5],self.table[i][j][6],self.table[i][j][7],self.table[i][j][8],self.table[i][j][9],self.table[i][j][10]))
                j+=1
            i+=1
            
    def search(self,age):
        index = self.hash_function(age)
        i = 0
        if len(self.table[index]) == 0:
            print("Aucun element trouver")
        while i < len(self.table[index]):
            if age == self.table[index][i][3]:
                print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.table[index][i][0],self.table[index][i][1],self.table[index][i][2],self.table[index][i][3],self.table[index][i][4],self.table[index][i][5],self.table[index][i][6],self.table[index][i][7],self.table[index][i][8],self.table[index][i][9],self.table[index][i][10]))
            i+=1
            
    def sort(self):
        i = 7
        while i < 10:
            j = 0
            while j < len(self.table[i]):
                print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.table[i][j][0],self.table[i][j][1],self.table[i][j][2],self.table[i][j][3],self.table[i][j][4],self.table[i][j][5],self.table[i][j][6],self.table[i][j][7],self.table[i][j][8],self.table[i][j][9],self.table[i][j][10]))
                j+=1
            i+=1
        i = 0
        while i < 7:
            j = 0
            while j < len(self.table[i]):
                print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.table[i][j][0],self.table[i][j][1],self.table[i][j][2],self.table[i][j][3],self.table[i][j][4],self.table[i][j][5],self.table[i][j][6],self.table[i][j][7],self.table[i][j][8],self.table[i][j][9],self.table[i][j][10]))
                j+=1
            i+=1
            
x = 1
while x != 0:
    hashe = hash_table()
    hashe.save()
    print("----------------------- MENU --------------------------")
    print("0 - Quitter")
    print("1 - Enregistrer les donnee")
    print("2 - Trier en fonction de l'age")
    print("3 - Rechercher les donnee en fonction de l'age\n")
    x = input("Faites un choix : ")
    x = int(x)
    if (x == 1):
        hashe.afficher()
    elif x == 2:
        hashe.sort()
    elif x == 3:
        age = input("Entrer l'age a rechercher : ")
        age = int(age)
        hashe.search(age)
    elif x == 0:
        pass
    else:
        print("Faire un choix entre 0 et 3")        
