#include<stdio.h>
#include<string.h>
#include<time.h>
#include <unistd.h>
#include<stdbool.h>

//sructure
typedef struct Produit{
    int code;
    char nom[50];
    int quantite;
    float prix;
    float prixTTC;

}Produit;

typedef struct stockagePrix{
    int code;
    char nom[50];
    int quantite;
    float prixTTC;
    char date[50];

}Stockage;

Produit produit[100] = {
	{4, "GHAGF", 19.30, 20.20},
	{56, "SFFD", 19.30, 20.20},
	{23, "LKSF", 19.30, 20.20},
	{1, "IOHQSU", 19.30, 20.20},
};
int np=4;
Stockage stockage[100];
int sizeStockage=0;
void ajouterproduit(){
    printf("\nentrer le code du produit :");
    scanf("%d",&produit[np].code);
    printf("entrer le nom du produit :");
    scanf("%s",&produit[np].nom);
    printf("entrer la quantite du produit :");
    scanf("%d",&produit[np].quantite);
    printf("entrer le prix du produit :");
    scanf("%f",&produit[np].prix);
    produit[np].prixTTC = produit[np].prix + (produit[np].prix * 0.15);
    printf("le prixTTC du produit : %.2f", produit[np].prixTTC);
    
    np++;
}
void ajouterPlusieurProduit(){
    int i ,nbr;
    printf("entrer le nombre de produit :");
    scanf("%d",&nbr);
    for(i=0;i<nbr;i++){
        ajouterproduit();
    }
}
void afficher(){
     int i; 
     printf("\tCODE\tNOM\tQUANTITE\tPRIX\tPRIXTTC\n");
    for(i=0;i<np;i++){
    	printf("\t%d",produit[i].code);    	
        printf("\t%s",produit[i].nom);
        printf("\t%d",produit[i].quantite);
        printf("\t\t%.2f",produit[i].prix);
        printf("\t%.2f\n",produit[i].prixTTC);
        
    }
}
void alphabetcroissant(){
    int i,j;

    for(i=0;i<np;i++){
         for(j=i+1;j<np;j++){
            if(strcmp(produit[i].nom,produit[j].nom)>0){
                Produit zone;
                zone=produit[i];
                produit[i]=produit[j];
                produit[j]=zone;
            }
         }
    }
    afficher();
}
void prixdecroissant(){
    int i,j;

    for(i=0;i<np;i++){
         for(j=i+1;j<np;j++){
            if(produit[i].prix<produit[j].prix){
                Produit zone;
                zone=produit[i];
                produit[i]=produit[j];
                produit[j]=zone;
            }   
         }
   }
   afficher();
}

// acheter un produit
void acheterProduit(){
	time_t now;//structure time_t affiche temps actuelle 
    time(&now);//initialiser
    int i,code,quantite,indice = -1;
    afficher();
    printf("Entrer le code  :");
    scanf("%d",&code); 
   
    for(i=0; i < np; i++){
   		if(produit[i].code==code){
   			indice = i;
   			break;
		   }
    }
   
   if(indice != -1){
   	GL:
   	printf("Entrer le quantite  :");
    	scanf("%d",&quantite); 
    	if(quantite<0){ 
			printf("Impossible d'entrer un nombre negatif\n");
			goto GL;
		}else if(quantite <= produit[indice].quantite){
    		produit[indice].quantite = produit[indice].quantite - quantite; //indice= prdt acheté
    		
    		
    		stockage[sizeStockage].code = produit[indice].code;
    		strcpy(stockage[sizeStockage].nom , produit[indice].nom);
    		stockage[sizeStockage].quantite = quantite;
    		stockage[sizeStockage].prixTTC = produit[indice].prixTTC * quantite;
    		strcpy(stockage[sizeStockage].date , ctime(&now));
    		sizeStockage++;
		}else{
			printf("cette quantite n'existe pas'");
		}
   }	
   else{
   	printf("introuvable");
   }

    }

void rechercheCode(){
  	    int c,i;
//        printf("-----------------------------------------\n");
//        printf(" -> 1 : chercher avec le code de produit :\n");
//        printf("-----------------------------------------");
             printf("recherche un produit ");
                      printf("donner le code de produit que vous rechercher ;");
                      scanf ("%d",&c);
                      for(i=0;i<np;i++){
                       if(produit[i].code == c){
                    printf("code    nom      prix      quantite \n");
                    printf("%d      %s      %.2fdh        %d     \n",produit[i].code , produit[i].nom , produit[i].prix , produit[i].quantite);
                    break ;             } 
                    }
    }
  
void rechercheQuantite(){
  	    int q,i;
//        printf("-----------------------------------------\n");
//        printf(" -> 2 : chercher avec le nom de produit  :\n");
//        printf("-----------------------------------------");
             printf("recherche un produit ");
                      printf("donner la quantite de produit que vous rechercher ;");
                      scanf ("%d",&q);
                      for(i=0;i<np;i++){
                       if(produit[i].quantite == q){
                    printf("code    nom      prix      quantite \n");
                    printf("%d      %s      %.2fdh        %d     \n",produit[i].quantite , produit[i].nom , produit[i].prix , produit[i].quantite);
                    break ;             } 
                    }
    }
    void etatStock(){
   	int i;
   	for(i=0;i<np;i++){
   	if(produit[i].quantite<=3){
   		printf("nom: %s",produit[i].nom);
   		printf("code: %d",produit[i].code);
   		printf("prix: %f",produit[i].prix);
	         }
              }
              }
              
    void alimenterStock(){
	int i,code,quantite;
	printf("Veuillez entrer le code de produit :");
	scanf("%d",&code);
	printf("entre la quantite de produit :");
	scanf("%d",&quantite);
	for(i=0;i<np;i++){
		if(produit[i].code==code){
			produit[i].quantite += quantite;
	}
	break;
    }
    }  
             

void supprimer(){
	int i ,c,position;
         printf("supprimer un produit \n");
                      printf("Donner le code de produit que vous voulez  supprimer :");
                      scanf ("%d",&c);

                      for(i=0;i<np;i++){
                       if(c ==produit[i].code ){
                           printf("%d",i);
                         position = i;
                         break;
                     }
                   }
                   for (i=position;i<np;i++){
                           produit[i]=produit[i+1];
                      }
                      np--;
          }
          
// void statistiqueVente(){
// 	int 
// }         


void menu(){
	sleep(1);
	printf("\n\t[1]==>\t\t Ajouter un nouveau produit:                      \n");
    printf("\t[2]==>\t\t Ajouter plusieurs produits:                        \n");
    printf("\t[3]==>\t\t Afficher un produit:                               \n");
    printf("\t[4]==>\t\t Tri par alphabet:                                  \n");
    printf("\t[5]==>\t\t Tri par prix:                                      \n");
    printf("\t[6]==>\t\t Rechercher par code:                               \n");
    printf("\t[7]==>\t\t Rechercher par quantite:                           \n");
    printf("\t[8]==>\t\t Acheter un produit:                                \n");
    printf("\t[9]==>\t\t Voir etat du stock:                                \n");
    printf("\t[10]==>\t\t Alimenter le stock:                               \n");
    printf("\t[11]==>\t\t Supprimer:                                        \n");
    printf("\t[12]==>\t\t Statistique de vente:                             \n");

    
}

int main(){
	printf("____________________________**BIENVENUE DANS VOTRE SYSTEME DE GESTION DE VOTRE PHARMACIE**__________________________");
	printf("-------------------------------------------------------------------------------------------------------------------\n");
    int choix;
    debut:
    menu();
    printf("Veuillez entrer votre choix: \n ");
    scanf("%d", &choix);
	
    switch(choix){
        case 1: 
        printf("Ajouter un nouveau produit: \n ");
        ajouterproduit();
        goto debut;
        case 2: 
        printf("Ajouter plusieurs produits: \n");
        ajouterPlusieurProduit();
        goto debut;
        case 3: 
        printf("Afficher produit: \n");
        afficher();
        goto debut;
        case 4: 
        printf("Tri par alphabet: \n");
        alphabetcroissant();
        goto debut;
        case 5: 
        printf("Tri par prix: \n");
        prixdecroissant();
        goto debut;
        case 6: 
        printf("Veuillez entrer le code de produit que vous cherchez: \n");
        rechercheCode();
        goto debut;
        case 7: 
        printf("Veuillez entrer la quantite du produit que vous cherchez: \n");
        rechercheQuantite();
        goto debut;
        case 8: 
        printf("Acheter un produit: \n");
        acheterProduit();
        goto debut;
        case 9: 
        printf("Etat du stock: affichage des produits dont la quantite est inferieure a 3: \n");
        etatStock();
        goto debut;
        case 10: 
        printf("Veuillez alimenter le stock: \n");
        alimenterStock();
        goto debut;
        case 11: 
        printf("Supprimer ce produit: \n");
        supprimer();
        goto debut;
//        case 12: 
//        printf("Afficher les statistiques de vente: \n");
//        statistiqueVente();
//        goto debut;
    }
    
    

}









