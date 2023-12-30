//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
function save_table(){
	var line = ["23/03/2022","16:28:24","F",18,"23/03/2022","Ras","Ras",0,"Non","0","Ras"];
	var lines = [];
	lines[0] = line;
	line = ["23/03/2022","16:28:54","M",18,"23/03/2022","10H-12H","Éleveur - Ngousso ( 200frs)",200,"Non",15,"Mauvaise"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:29:53","M",21,"23/03/2022","12H-16H","Ekoumdoum (Collège Pérou)-Awae Escalier (collège Dipito) marche pieds",0,"Non",30,"Passable"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:31:14","M",18,"12/01/2004","10H-12H","Carrefour TKC a Dovv mokolo 300 suivi de Dovv mokolo Afri Land acacia 400 puis Afri land acacia Maison Blanche à pied",600,"Non",30,"Passable"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:32:23","F",18,"23/03/2022","Ras","Ras",0,"Non",0,"Ras"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:33:05","M",18,"07/09/2003","18H-20H","De château ngoakele à terminus Mimboman 300fr et de terminus au dernier poto minboman 100fr",400,"Oui",60,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:36:00","M",19,"23/03/2022","06H-10H","mobile omnisport - hôpital général Ngousso montant: 150f emprunté un taxi",150,"Oui",13,"Passable"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:36:16","M",17,"23/03/2022","12H-16H","Première entré après le Carrefour Ebanda tout droit--- Entrée Simbock----moto",100,"Non",8,"Passable"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:37:16","M",18,"23/03/2022","10H-12H","Etoudi-poste centrale, 300fcfa, taxi",1200,"Oui",10,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:37:34","M",18,"23/03/2022","RAS","RAS",0,"Non",0,"RAS"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:39:23","M",23,"23/03/2022","16H-18H","Cité U je proposes au taxi 500f pour arriver a odza avant terminus plus précisément",500,"Oui",60,"Passable"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:40:37","M",17,"23/03/2022","06H-10H","Garage camion(cité verte), marché 8eme, moto taxi,300 - marché 8eme, polyclinique (Tsinga), à pied, 0",300,"Non",30,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:43:52","M",17,"23/03/2022","16H-18H","Polyclinique (Tsinga), marché 8eme, à pied,0",0,"Non",15,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:45:40","M",20,"22/03/2022","12H-16H","Départ de l'école de poste pour la cite 100f sur une moto",100,"Non",2,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:46:40","F",23,"23/03/2022","9h-16h30H","Carrefour régi - hôpital général",250,"Non",10,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:48:07","M",19,"23/03/2022","06H-10H","École de police-mokolo 150 moto",300,"Non",10,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:48:28","F",20,"23/03/2022","12H-16H","Jai prise le taxi de hôtel du plateau d'essos à château de ngoa kele 300 et au retour de château de ngoakele à hôtel du plateau d'essos 300",600,"Oui",45,"Bonne"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:49:14","F",20,"23/03/2022","10H-12H","Scalom-marché alcacia Tarif 100f Moto Marché alcacia-scalom Tarif 100f Moto",200,"Non",6,"Passable"];
	lines[lines.length] = line;
	line = ["23/03/2022","16:49:37","F",20,"22/03/2022","18H-20H","Château - hôtel du plateau 250 taxi Hôtels du plateau - mobile emana 300 taxi Mobile emana - monté mairie d'obala 500 car Monté mairie d'obala - boulangerie elig-bassala 100 moto",1150,"Oui",170,"Passable"];
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
                console.log(this.table[i][j][0]+'\t'+this.table[i][j][1]+'\t'+this.table[i][j][2]+'\t'+this.table[i][j][3]+'\t'+this.table[i][j][4]+'\t'+this.table[i][j][5]+'\t'+this.table[i][j][6]+'\t'+this.table[i][j][7]+'\t'+this.table[i][j][8]+'\t'+this.table[i][j][9]+'\t'+this.table[i][j][10]);
                j++;
			}
            i++;
		}
	}
            
    search(age){
        var index = this.hash_function(age); 
        var j = 0,i = 0;
        if (this.nbr_elt[index] == 0)
            console.log('Aucun element trouver');
        while(i < this.table[index].length){
			if(age == this.table[index][i][3]){
				j++;
				console.log(this.table[index][i][0]+'\t'+this.table[index][i][1]+'\t'+this.table[index][i][2]+'\t'+this.table[index][i][3]+'\t'+this.table[index][i][4]+'\t'+this.table[index][i][5]+'\t'+this.table[index][i][6]+'\t'+this.table[index][i][7]+'\t'+this.table[index][i][8]+'\t'+this.table[index][i][9]+'\t'+this.table[index][i][10]);
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
                console.log(this.table[i][j][0]+'\t'+this.table[i][j][1]+'\t'+this.table[i][j][2]+'\t'+this.table[i][j][3]+'\t'+this.table[i][j][4]+'\t'+this.table[i][j][5]+'\t'+this.table[i][j][6]+'\t'+this.table[i][j][7]+'\t'+this.table[i][j][8]+'\t'+this.table[i][j][9]+'\t'+this.table[i][j][10]);
                j++;
			}
            i++;
		}
        i = 0;
        while(i < 7){
            j = 0;
            while(j < this.nbr_elt[i]){
                console.log(this.table[i][j][0]+'\t'+this.table[i][j][1]+'\t'+this.table[i][j][2]+'\t'+this.table[i][j][3]+'\t'+this.table[i][j][4]+'\t'+this.table[i][j][5]+'\t'+this.table[i][j][6]+'\t'+this.table[i][j][7]+'\t'+this.table[i][j][8]+'\t'+this.table[i][j][9]+'\t'+this.table[i][j][10]);
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