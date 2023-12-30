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
class tree{
	constructor(elt = []){
		this.val = elt;
		this.left = null;
		this.right = null;
	}
	
	insert(val){
        if(this.val != null){
            if(val[3] <= this.val[3]){ 
                if(this.left == null){
                    this.left = new tree(val);
                }else
                    this.left.insert(val);
            }else if(val[3] > this.val[3]){ 
                if(this.right == null){
                    this.right = new tree(val);
				}else
                    this.right.insert(val);
			}
        }else
            this.val = val;		
	}
	
	save(){
		var lines = save_table();
		this.val = lines[0];
		var i = 1;
		while(i < 19){
			this.insert(lines[i]);
			i++;
		} 
	}
	
	afficher(){
		console.log(this.val[0]+'\t'+this.val[1]+'\t'+this.val[2]+'\t'+this.val[3]+'\t'+this.val[4]+'\t'+this.val[5]+'\t'+this.val[6]+'\t'+this.val[7]+'\t'+this.val[8]+'\t'+this.val[9]+'\t'+this.val[10]+'\n');
        if(this.left != null)
            this.left.afficher();
        if(this.right != null)
            this.right.afficher();
	}
	search(age){
		if(this.val[3] == age)
			console.log(this.val[0]+'\t'+this.val[1]+'\t'+this.val[2]+'\t'+this.val[3]+'\t'+this.val[4]+'\t'+this.val[5]+'\t'+this.val[6]+'\t'+this.val[7]+'\t'+this.val[8]+'\t'+this.val[9]+'\t'+this.val[10]+'\n');
        if(this.left != null)
            this.left.search(age);
        if(this.right != null)
            this.right.search(age);
	}
	
	sort(){
        if(this.left != null)
            this.left.sort();
		console.log(this.val[0]+'\t'+this.val[1]+'\t'+this.val[2]+'\t'+this.val[3]+'\t'+this.val[4]+'\t'+this.val[5]+'\t'+this.val[6]+'\t'+this.val[7]+'\t'+this.val[8]+'\t'+this.val[9]+'\t'+this.val[10]+'\n');
        
		if(this.right != null)
            this.right.sort();
	}
}

var x = 1
arbre = new tree();
while (x != 0){
    console.log("----------------------- MENU --------------------------");
    console.log("0 - Quitter");
    console.log("1 - Enregistrer les donnee");
    console.log("2 - Trier en fonction de l'age");
    console.log("3 - Rechercher les donnee en fonction de l'age\n");
    x = prompt("Faites un choix : ");
    x = parseInt(x);
    if (x == 1){
        arbre.save();
		arbre.afficher();
    }else if(x == 2){
        arbre.sort();
    }else if(x == 3){
        age = prompt("Entrer l'age a rechercher : ");
        age = parseInt(age);
        arbre.search(age);
	}else if(x == 0){
		
    }else
        console.log("Faire un choix entre 0 et 3");
}