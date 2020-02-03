# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct Objet{
	char nom[30];
	int prix;
};
typedef struct Objet item;

void viewInventaire(item * inventaire){
	for (int i=0; i<5; i++){
		printf ("%s ", inventaire[i].nom);
		printf ("prix %d\n",inventaire[i].prix);	
	}
};

int main(){
	
	//création inventaire joueur
	int tab [5];
	item inventaireJoueur [5] = {{"chacal", 2}, {"gilbert de compagnie", 67}};
	
	viewInventaire(&inventaireJoueur[0]);
	
return 0;
}