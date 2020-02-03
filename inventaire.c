# include <stdio.h>
# include <string.h>
# include <stdlib.h>

struct Objet{
	char nom[30];
	int prix;
};
typedef struct Objet item;

int main(){
	
	
	
	//création inventaire joueur
	int tab [5];
	item inventaireJoueur [5] = {{"chacal", 2}, {"gilbert de compagnie", 67}};
		
	for (int i=0; i<5; i++){
		printf ("%s ", inventaireJoueur[i].nom);
		printf ("prix %d\n",inventaireJoueur[i].prix);
		
	}
	
	
	
	
}