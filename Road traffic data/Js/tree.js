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
		console.log(this.val[0]+'\t'+this.val[1]+'\t'+this.val[2]+'\t'+this.val[3]+'\t'+this.val[4]+'\t'+this.val[5]+'\t'+this.val[6]+'\t'+this.val[7]+'\t'+this.val[8]+'\t'+this.val[9]+'\n');
        if(this.left != null)
            this.left.afficher();
        if(this.right != null)
            this.right.afficher();
	}
	search(age){
		if(this.val[3] == age)
			console.log(this.val[0]+'\t'+this.val[1]+'\t'+this.val[2]+'\t'+this.val[3]+'\t'+this.val[4]+'\t'+this.val[5]+'\t'+this.val[6]+'\t'+this.val[7]+'\t'+this.val[8]+'\t'+this.val[9]+'\n');
        if(this.left != null)
            this.left.search(age);
        if(this.right != null)
            this.right.search(age);
	}
	
	sort(){
        if(this.left != null)
            this.left.sort();
		console.log(this.val[0]+'\t'+this.val[1]+'\t'+this.val[2]+'\t'+this.val[3]+'\t'+this.val[4]+'\t'+this.val[5]+'\t'+this.val[6]+'\t'+this.val[7]+'\t'+this.val[8]+'\t'+this.val[9]+'\n');
        
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