//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
function save(){
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
function afficher(lines){
	var i = 0;
	while(i < 19){
		console.log(lines[i][0]+'\t'+lines[i][1]+'\t'+lines[i][2]+'\t'+lines[i][3]+'\t'+lines[i][4]+'\t'+lines[i][5]+'\t'+lines[i][6]+'\t'+lines[i][7]+'\t'+lines[i][8]+'\t'+lines[i][9]+'\t'+lines[i][10]+'\n');
		i++;
	}
}

function search(lines,age){
	var i = 0;
	while(i < 19){
		if(age == lines[i][3]){
			console.log(lines[i][0]+'\t'+lines[i][1]+'\t'+lines[i][2]+'\t'+lines[i][3]+'\t'+lines[i][4]+'\t'+lines[i][5]+'\t'+lines[i][6]+'\t'+lines[i][7]+'\t'+lines[i][8]+'\t'+lines[i][9]+'\t'+lines[i][10]+'\n');
		}
		i++;
	}
}

function sort(lines){
	var i = 0;
	var j 
	while(i < 19){
		j = i+1;
		while(j < 19){
			if(lines[j][3] < lines[i][3]){
				var temp = lines[j];
				lines[j] = lines[i];
				lines[i] = temp;
			} 
			j++;
		}
		i++;
	}
}

var x = 1
while (x != 0){
    var li = save();
    console.log("----------------------- MENU --------------------------");
    console.log("0 - Quitter");
    console.log("1 - Enregistrer les donnee");
    console.log("2 - Trier en fonction de l'age");
    console.log("3 - Rechercher les donnee en fonction de l'age\n");
    x = prompt("Faites un choix : ");
    x = parseInt(x);
    if (x == 1){
        afficher(li);
    }else if(x == 2){
        sort(li);
        afficher(li);
    }else if(x == 3){
        age = prompt("Entrer l'age a rechercher : ");
        age = parseInt(age);
        search(li,age);
	}else if(x == 0){
		
    }else
        console.log("Faire un choix entre 0 et 3");
}