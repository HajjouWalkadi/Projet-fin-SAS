#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdbool.h>

//sructure
typedef struct Produit{
    int code;
    char nom[50];
    int quantite;
    float prix;
    float prixTTC;

}Produit;

Produit produit[100];
int np=0;
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
    for(i=0;i<np;i++){
        printf("nom de produit %s",produit[i].nom);
        printf("code de produit %d",produit[i].code);
        printf("quantite de produit %d",produit[i].quantite);
        printf("prix de produit %f",produit[i].prix);
        printf("prixttc de produit %f\n",produit[i].prixTTC);
        
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
void acheterProduit(){
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
   	printf("Entrer le quantite  :");
    	scanf("%d",&quantite); 
    	
    	if(quantite <= produit[indice].quantite){
    		
    		produit[indice].quantite = produit[indice].quantite - quantite;
		}else{
			printf("cette quantite n'existe pas'");
		}
   }	
   else{
   	printf("introuvable");
   }
   	//_______________________Rechercher par code________________________ //	
    }
//void rechercherCode(){
//	int i,nbr;
//	bool isExist = false;
//   printf("Entrer le code  :");
//   scanf("%d",&nbr); 
//   
//   for(i=0; i < np; i++){
//   		if(produit[i].code==nbr){
//   			isExist = true;
//   			
//		   }
//   }
//   
//   if(isExist)
//   printf("ce produit existe");
//   else
//   printf("introuvable");
//}
//
//void rechercherQuantite(){
//	int i,q;
//	bool isExist = false;
//   printf("Entrer la quantité  :");
//   scanf("%d",&q); 
//   
//   for(i=0; i < np; i++){
//   		if(produit[i].quantite==q){
//   			isExist = true;
//   			
//		   }
//   }
//   
//   if(isExist)
//   printf("cette quantite existe");
//   else
//   printf("Out of stock");
//}
//
void rechercheCode(){
  	    int c,i;
        printf("-----------------------------------------\n");
        printf(" -> 1 : chercher avec le code de produit :\n");
        printf("-----------------------------------------");
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
        printf("-----------------------------------------\n");
        printf(" -> 2 : chercher avec le nom de produit  :\n");
        printf("-----------------------------------------");
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
	printf("entre le code de produit :");
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
                      printf("donner le code de produit que vous voulez  supprimer ;");
                      scanf ("%d",&c);

                      for(i=0;i<np;i++){
                       if(c ==produit[i].code ){
                           printf("%d",i);
                         position = i;
                       for (i=position;i<np;i++){
                           produit[i]=produit[i+1];
                           np--;
                          break;
                      }
                     }
                   }
          }


void menu(){
    printf("\n\t\t\t1==> Ajouter un nouveau produit:                      \n");
	printf("--------------------------------------------------------------\n");

    printf("2\t\t\t==> Ajouter plusieurs produits:                        \n");
    printf("3\t\t\t==> Afficher un produit:                               \n");
    printf("4\t\t\t==> Tri par alphabet:                                  \n");
    printf("5\t\t\t==> Tri par prix:                                      \n");
    printf("6\t\t\t==> Rechercher par code:                               \n");
    printf("7\t\t\t==> Rechercher par quantité:                           \n");
    printf("8\t\t\t==> Acheter un produit:                                \n");
    printf("9\t\t\t==> Voir etat du stock:                                \n");
    printf("10\t\t\t==> Alimenter le stock:                               \n");
    printf("11\t\t\t==> supprimer:                                        \n");
}

int main(){
    int choix;
    debut:
    menu();
    printf("entrer votre choix");
    scanf("%d", &choix);
    switch(choix){
        case 1: 
        printf("ajouter un nouveau produit");
        ajouterproduit();
        goto debut;
        case 2: 
        printf("ajouter plusieurs produits");
        ajouterPlusieurProduit();
        goto debut;
        case 3: 
        printf("afficher produit");
        afficher();
        goto debut;
        case 4: 
        printf("tri par alphabet");
        alphabetcroissant();
        goto debut;
        case 5: 
        printf("tri par prix");
        prixdecroissant();
        goto debut;
        case 6: 
        printf("rechercher par code");
        rechercheCode();
        goto debut;
        case 7: 
        printf("rechercher par quantite");
        rechercheQuantite();
        goto debut;
        case 8: 
        printf("acheter");
        acheterProduit();
        goto debut;
        case 9: 
        printf("Etat du stock\n");
        etatStock();
        goto debut;
        case 10: 
        printf("Alimenter le stock\n");
        alimenterStock();
        goto debut;
        case 11: 
        printf("Supprimer\n");
        supprimer();
        goto debut;
    }
    

}