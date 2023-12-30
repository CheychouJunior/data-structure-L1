//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
function save_table(){
	var line = ["23/03/2022","16:26:22","M",21,"23/03/2022","12h-14h","Riz sauce d'arachide","Plateau","Maison",8];
	var lines = [];
	lines[0] = line;
	line = ["23/03/2022","16:27:24","F",18,"23/03/2022","14h-16h","Corn flakes","Bol","Maison",1];
	lines[lines.length] = line;
	line = ["23/03/2022","16:27:47","M",18,"12/01/2004","14h-16h","Riz suave arachide avec la viande","Plat","Maison",3];
	lines[lines.length] = line;
	line = ["23/03/2022","16:29:33","F",18,"23/03/2022","12h-14h","Purée d'avocat-pain","Plat","Maison",3];
	lines[lines.length] = line;
	line = ["23/03/2022","16:31:02","M",17,"23/03/2022","14h-16h","Rice and tomato stew","Plat","Maison",6];
	lines[lines.length] = line;
	line = ["23/03/2022","16:32:32","M",19,"23/03/2022","14h-16h","Riz sauce blanche","Plat","Maison",6];
	lines[lines.length] = line;
	line = ["23/03/2022","16:32:53","M",18,"23/03/2022","14h-16h","Riz blanc accompagné du haricot","Plat","Maison",7];
	lines[lines.length] = line;
	line = ["23/03/2022","16:33:37","M",22,"23/03/2022","12h-14h","Foufou ans Eru","Plat","Maison",3];
	lines[lines.length] = line;
	line = ["23/03/2022","16:33:52","M",22,"23/03/2022","12h-14h","Beignets haricots Bouilli","plat","Maison",2];
	lines[lines.length] = line;
	line = ["23/03/2022","16:34:02","M",19,"23/03/2022","12h-14h","Plantain frit et 2 oeufs","Assiette creuse","Maison",6];
	lines[lines.length] = line;
	line = ["23/03/2022","16:37:53","F",20,"23/03/2022","16h-18h","Les crêpes au lait","Bol","Maison",6];
	lines[lines.length] = line;
	line = ["23/03/2022","16:40:05","M",21,"14/04/2000","16h-18h","okok baton de manioc","Assiette creuse","Maison",5];
	lines[lines.length] = line;
	line = ["23/03/2022","16:41:40","M",18,"23/03/2022","10h-12h","Pain et une tasse de café au lait","Tasse de café","Maison",1];
	lines[lines.length] = line;
	line = ["23/03/2022","16:42:03","M",20,"22/03/2022","12h-14h","Le riz avec la sauce tomate","Plat","Maison",1];
	lines[lines.length] = line;
	line = ["23/03/2022","16:43:35","F",20,"23/03/2022","20h-22h","Sauce d'arrahide avec le manioc","Plat","Maison",6];
	lines[lines.length] = line;
	line = ["23/03/2022","16:43:40","F",17,"23/03/2022","16h-18h","Riz sauce d'arachide sans viande","Plat","Maison",5];
	lines[lines.length] = line;
	line = ["23/03/2022","16:43:53","F",20,"23/03/2022","14h-16h","Okok sucré ,manioc","Assiette creuse","Maison",6];
	lines[lines.length] = line;
	line = ["23/03/2022","16:45:54","M",36,"23/03/2022","12h-14h","Bouillon viande, plaintain mur","Assiette creuse","Restaurant",0];
	lines[lines.length] = line;
	line = ["23/03/2022","16:46:26","M",18,"23/03/2022","6h-10h","pain omelette","Plat","Route",0];
	lines[lines.length] = line;	
	
	return lines;
}

class hash_table{
    constructor(){
        this.table = [[],[],[],[],[],[],[],[],[],[]]
		this.nbr_elt = [0,0,0,0,0,0,0,0,0,0,];
    }    
    save(){
		var lines = save_table();

		var i = 0;
		while(i < 19){
			this.insert(lines[i]);
			i++;
		} 
	}
        
    insert(val){
        var index = this.hash_function(val[3]);
        if(this.nbr_elt[index] == 0){
            this.table[index][0] = val;
			this.nbr_elt[index]++;
        }else {
            this.table[index][this.nbr_elt[index]] = val;
			this.nbr_elt[index]++;
		}
	}
        
    hash_function(val){
        return val % 10;
    }
	
    afficher(){
        var j,i = 0;
        while(i < 10){
            j = 0;
            while(j < this.table[i].length){
                console.log(this.table[i][j][0]+'\t'+this.table[i][j][1]+'\t'+this.table[i][j][2]+'\t'+this.table[i][j][3]+'\t'+this.table[i][j][4]+'\t'+this.table[i][j][5]+'\t'+this.table[i][j][6]+'\t'+this.table[i][j][7]+'\t'+this.table[i][j][8]+'\t'+this.table[i][j][9]+'\n');
                j++;
			}
            i++;
		}
	}
            
    search(age){
        var index = this.hash_function(age); 
        var j = 0, i = 0;
        if (this.nbr_elt[index] == 0)
            console.log('Aucun element trouver');
        while(i < this.table[index].length){
			if(age == this.table[index][i][3]){
				j++
				console.log(this.table[index][i][0]+'\t'+this.table[index][i][1]+'\t'+this.table[index][i][2]+'\t'+this.table[index][i][3]+'\t'+this.table[index][i][4]+'\t'+this.table[index][i][5]+'\t'+this.table[index][i][6]+'\t'+this.table[index][i][7]+'\t'+this.table[index][i][8]+'\t'+this.table[index][i][9]+'\n');
            }
			i++;
		}
		if(j == 0)
			console.log('Aucun element trouver');
	}
            
    sort(){
        var j,i = 7;
        while(i < 10){
            j = 0;
            while(j < this.nbr_elt[i]){
                console.log(this.table[i][j][0]+'\t'+this.table[i][j][1]+'\t'+this.table[i][j][2]+'\t'+this.table[i][j][3]+'\t'+this.table[i][j][4]+'\t'+this.table[i][j][5]+'\t'+this.table[i][j][6]+'\t'+this.table[i][j][7]+'\t'+this.table[i][j][8]+'\t'+this.table[i][j][9]+'\n');
                j++;
			}
            i++;
		}
        i = 0;
        while(i < 7){
            j = 0;
            while(j < this.nbr_elt[i]){
                console.log(this.table[i][j][0]+'\t'+this.table[i][j][1]+'\t'+this.table[i][j][2]+'\t'+this.table[i][j][3]+'\t'+this.table[i][j][4]+'\t'+this.table[i][j][5]+'\t'+this.table[i][j][6]+'\t'+this.table[i][j][7]+'\t'+this.table[i][j][8]+'\t'+this.table[i][j][9]+'\n');
                j++;
			}
            i++;
		}
	}
}
            
var x = 1
hashe = new hash_table();
while (x != 0){
    console.log("----------------------- MENU --------------------------");
    console.log("0 - Quitter");
    console.log("1 - Enregistrer les donnee");
    console.log("2 - Trier en fonction de l'age");
    console.log("3 - Rechercher les donnee en fonction de l'age\n");
    x = prompt("Faites un choix : ");
    x = parseInt(x);
    if (x == 1){
        hashe.save();
		hashe.afficher();
    }else if(x == 2){
        hashe.sort();
    }else if(x == 3){
        age = prompt("Entrer l'age a rechercher : ");
        age = parseInt(age);
        hashe.search(age);
	}else if(x == 0){
		
    }else
        console.log("Faire un choix entre 0 et 3");
}