//NOM: CHEYCHOU MOUAFO JUNIOR   mat: 21T2374
function save_tab(){
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

class node{
	constructor(elt){
		this.val = elt;
		this.next = null;
	}
}

class linked_list{
	constructor(){
		this.head = null;
		this.size = 0;
	}
	save(){
		var data = save_tab();
		var i = 0;
		while(i<19){
			var noeud = new node(data[i]);
			if(this.head == null){
				this.head = noeud;
				this.size++;
			}else{
				noeud.next = this.head;
				this.head = noeud;
				this.size++;
			}
			i++;
		}
	}
	
	afficher(){
		var pt = this.head;
		while(pt){
			console.log(pt.val[0]+'\t'+pt.val[1]+'\t'+pt.val[2]+'\t'+pt.val[3]+'\t'+pt.val[4]+'\t'+pt.val[5]+'\t'+pt.val[6]+'\t'+pt.val[7]+'\t'+pt.val[8]+'\t'+pt.val[9]+'\n');
			pt = pt.next;
		}
	}
	
	sort(){
		var j, i = 0;
		var ctr, pt = this.head;
		while(pt){
			ctr = pt.next;
			while(ctr){
				if(ctr.val[3] < pt.val[3]){
					var temp = ctr.val;
					ctr.val = pt.val;
					pt.val = temp;
				}
				ctr = ctr.next;
			}
			pt = pt.next;
		}
	}
	
	search(age){
		var i = 0;
		var pt = this.head;
		while(pt){
			if(age == pt.val[3]){
				i++;
				console.log(pt.val[0]+'\t'+pt.val[1]+'\t'+pt.val[2]+'\t'+pt.val[3]+'\t'+pt.val[4]+'\t'+pt.val[5]+'\t'+pt.val[6]+'\t'+pt.val[7]+'\t'+pt.val[8]+'\t'+pt.val[9]+'\n');
			}
			pt = pt.next;
		}
		if(i == 0)
			console.log('Aucun element trouver');
	}
}

var x = 1
stack = new linked_list();
while (x != 0){
    console.log("----------------------- MENU --------------------------");
    console.log("0 - Quitter");
    console.log("1 - Enregistrer les donnee");
    console.log("2 - Trier en fonction de l'age");
    console.log("3 - Rechercher les donnee en fonction de l'age\n");
    x = prompt("Faites un choix : ");
    x = parseInt(x);
    if (x == 1){
        stack.save();
		stack.afficher();
    }else if(x == 2){
        stack.sort();
		stack.afficher();
    }else if(x == 3){
        age = prompt("Entrer l'age a rechercher : ");
        age = parseInt(age);
        stack.search(age);
	}else if(x == 0){
		
    }else
        console.log("Faire un choix entre 0 et 3");
}
