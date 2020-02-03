# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct Objet{
	char nom[30];
	int prix;
};
typedef struct Objet item;

void viewInventaire(item * inventaire){
	for (int i=0; i<50; i++){	
		if(strcmp(inventaire[i].nom, "") >0){
			
			int nSlot=i+1;
			
			printf ("case %d : %s \n",nSlot, inventaire[i].nom);
		}
	}
};

void viewInventairePrix(item * inventaire){
	for (int i=0; i<50; i++){	
		if(strcmp(inventaire[i].nom, "") >0){
			
			int nSlot=i+1;
			
			printf ("case %d : %s | ",nSlot, inventaire[i].nom);
			printf ("prix %d\n",inventaire[i].prix);
		}
	}
};

void triInventaire(item * inventaire){
	int tamponPrix = 0;
	char tamponNom[30];
	
	for(int i=0; i<49; i++){
		for(int j=(i+1); j<50; j++){
			if(strcmp(inventaire[j].nom, "") >0){
				for(int k=0; k<30; k++){
					if(strncmp(inventaire[i].nom, inventaire[j].nom, k) > 0 ){
						strcpy(tamponNom, inventaire[i].nom);
						strcpy(inventaire[i].nom, inventaire[j].nom);
						strcpy(inventaire[j].nom, tamponNom);
						
						tamponPrix = inventaire[i].prix;
						inventaire[i].prix = inventaire[j].prix;
						inventaire[j].prix = tamponPrix;
						
						k=30;
					}
				}
			}
		}
		
	}
	
};

void triInventairePrix(item * inventaire){
	int tamponPrix = 0;
	char tamponNom[30];
	
	for(int i=0; i<49; i++){
		for(int j=(i+1); j<50; j++){
			if(strcmp(inventaire[j].nom, "") >0){
				if(inventaire[i].prix>inventaire[j].prix){
					strcpy(tamponNom, inventaire[i].nom);
					strcpy(inventaire[i].nom, inventaire[j].nom);
					strcpy(inventaire[j].nom, tamponNom);
					
					tamponPrix = inventaire[i].prix;
					inventaire[i].prix = inventaire[j].prix;
					inventaire[j].prix = tamponPrix;
				}
			}
		}
		
	}
	
};

void addItem(item * inventaire){
	char nom[30];
	int prix;
	scanf("%s", &nom);
	scanf("%d", &prix);
	
	for(int i=0; i<50; i++){
		if (strcmp(inventaire[i].nom, "") == 0){
			strcpy(inventaire[i].nom, nom);
			inventaire[i].prix=prix;
			i=50;
		}
	}
};

void buyItem(item * inventaire, item * objet){
	int nSlot;
	printf("\n choisissez un item dans le magasin via son numero de case \n");
	scanf("%d", &nSlot);
	nSlot -= 1;

	for(int i=0; i<50; i++){
		if (strcmp(inventaire[i].nom, "") == 0){
			strcpy(inventaire[i].nom, objet[nSlot].nom);
			inventaire[i].prix = objet[nSlot].prix;
			strcpy(objet[nSlot].nom, "");
			objet[nSlot].prix=0;
			i=50;
		}
	}
	
};

int main(){
	
	//création inventaire joueur
	int tab [5];
	item inventaireJoueur [50] = {{"chacal |", 2}, {"gilbert de compagnie |", 67}, {"atomisateur supreme du Mahl |",42}};
	//voir l'inventaire
	
	printf(" votre inventaire \n");
	
	triInventaire(&inventaireJoueur[0]);
	
	viewInventaire(&inventaireJoueur[0]);
	
	//inventaire marchand
	printf("\n magasin du suicide \n");
	
	item inventaireMarchand [50]={{"corde ", 12}, {"pillules ", 14}, {"plomb en promo ", 8}};
	
	triInventairePrix(&inventaireMarchand[0]);
	
	viewInventairePrix(&inventaireMarchand[0]);
	
	//ajouter item au magasin
	printf("ajoutez un item au magasin. C'est comme ca que ca marche le commerce\n");

	addItem(&inventaireMarchand[0]);
	
	triInventairePrix(&inventaireMarchand[0]);
	
	viewInventairePrix(&inventaireMarchand[0]);
	
	//acheter objet
	buyItem(&inventaireJoueur[0], &inventaireMarchand[0]);
	
	viewInventaire(&inventaireJoueur[0]);
return 0;
}