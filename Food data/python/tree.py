#NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
class tree :
    def __init__(self,elt = []):
        self.val = elt
        self.left = None
        self.right = None
        self.root = None
        
    def insert(self, val):
        if self.val is not None:
            if val[3] <= self.val[3] : 
                if self.left is None:
                    self.left = tree(val)
                else:
                    self.left.insert(val)
            elif val[3] > self.val[3] : 
                if self.right is None:
                    self.right = tree(val)
                else:
                    self.right.insert(val)
        else:
            self.val = val
            
    def save(self):
        fic = open("urban_data.txt","r")
        
        line = fic.readline()
        line = line.split("\"")
        line[3] = int(line[3])
        self.val = line
        
        for fic.readline in fic:
            line = fic.readline
            line = line.split("\"")
            line[3] = int(line[3])
            self.insert(line)
        fic.close()
            
    def afficher(self):
        print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.val[0],self.val[1],self.val[2],self.val[3],self.val[4],self.val[5],self.val[6],self.val[7],self.val[8],self.val[9],self.val[10]))
        if self.left is not None:
            self.left.afficher()
        if self.right is not None:
            self.right.afficher()
            
    def search(self,age):
        if self.val[3] == age :
            print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.val[0],self.val[1],self.val[2],self.val[3],self.val[4],self.val[5],self.val[6],self.val[7],self.val[8],self.val[9],self.val[10]))
        if self.left is not None:
            self.left.search(age)
        if self.right is not None:
            self.right.search(age)
            
    def sort(self):
        if self.left is not None:
            self.left.sort()
        print("{} {} {} {} {} {} {} {} {} {} {}\n".format(self.val[0],self.val[1],self.val[2],self.val[3],self.val[4],self.val[5],self.val[6],self.val[7],self.val[8],self.val[9],self.val[10]))
        if self.right is not None:
            self.right.sort()

x = 1
while x != 0:
    arbre = tree()
    arbre.save()
    print("----------------------- MENU --------------------------")
    print("0 - Quitter")
    print("1 - Enregistrer les donnee")
    print("2 - Trier en fonction de l'age")
    print("3 - Rechercher les donnee en fonction de l'age\n")
    x = input("Faites un choix : ")
    x = int(x)
    if (x == 1):
        arbre.afficher()
    elif x == 2:
        arbre.sort()
    elif x == 3:
        age = input("Entrer l'age a rechercher : ")
        age = int(age)
        arbre.search(age)
    elif x == 0:
        pass
    else:
        print("Faire un choix entre 0 et 3")        