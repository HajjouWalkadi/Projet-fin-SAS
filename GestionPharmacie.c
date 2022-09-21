#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// sructure


typedef struct Produit
{
    int code;
    char nom[50];
    int quantite;
    float prix;
    float prixTTC;

} Produit;

typedef struct statistique
{
    int code;
    char nom[50];
    int quantite;
    float prixTTC;
    int day ;
    int month;
    int year;

} Statistique;

Produit produit[100];
int np = 0;

Statistique statistique[100];
int sizeStatistique = 0;

void ajouterproduit()
{
    printf("\nentrer le code du produit :");
    scanf("%d", &produit[np].code);
    printf("entrer le nom du produit :");
    scanf("%s", &produit[np].nom);
    printf("entrer la quantite du produit :");
    scanf("%d", &produit[np].quantite);
    printf("entrer le prix du produit :");
    scanf("%f", &produit[np].prix);
    produit[np].prixTTC = produit[np].prix + (produit[np].prix * 0.15);
    printf("le prixTTC du produit : %.2f", produit[np].prixTTC);

    np++;
}
void ajouterPlusieursProduit()
{
    int i, nbr;
    printf("entrer le nombre de produit :");
    scanf("%d", &nbr);
    for (i = 0; i < nbr; i++)
    {
        ajouterproduit();
    }
}

void afficherVendu()
{
    int i;
    printf("\tCODE\tNOM\tQUANTITE\tPRIX\tPRIXTTC\n");
    for (i = 0; i < np; i++)
    {
        printf("\t%d", statistique[i].code);
        printf("\t%s", statistique[i].nom);
        printf("\t%d", statistique[i].quantite);
        printf("\t%.2f\n", statistique[i].prixTTC);
        printf("\t%d-%d-%d\n", statistique[i].day,statistique[i].month,statistique[i].year);
    }

}

void afficher()
{
    int i;
    printf("\tCODE\tNOM\tQUANTITE\tPRIX\tPRIXTTC\n");
    for (i = 0; i < np; i++)
    {
        printf("\t%d", produit[i].code);
        printf("\t%s", produit[i].nom);
        printf("\t%d", produit[i].quantite);
        printf("\t\t%.2f", produit[i].prix);
        printf("\t%.2f\n", produit[i].prixTTC);
    }

}

void alphabetcroissant()
{
    int i, j;

    for (i = 0; i < np; i++)
    {
        for (j = i + 1; j < np; j++)
        {
            if (strcmp(produit[i].nom, produit[j].nom) > 0)
            {
                Produit zone;
                zone = produit[i];
                produit[i] = produit[j];
                produit[j] = zone;
            }
        }
    }
    afficher();
}

void prixdecroissant()
{
    int i, j;

    for (i = 0; i < np; i++)
    {
        for (j = i + 1; j < np; j++)
        {
            if (produit[i].prix < produit[j].prix)
            {
                Produit zone;
                zone = produit[i];
                produit[i] = produit[j];
                produit[j] = zone;
            }
        }
    }
    afficher();
}

// acheter un produit
void acheterProduit()
{
    time_t t = time(NULL);
    struct tm* tm = localtime(&t); // structure time_t affiche temps actuelle
    // initialiser
    int i, code, quantite, indice = -1;
    afficher();
    printf("Entrer le code  :");
    scanf("%d", &code);

    for (i = 0; i < np; i++)
    {
        if (produit[i].code == code)
        {
            indice = i;
            break;
        }
    }

    if (indice != -1)
    {
    GL:
        printf("Entrer le quantite  :");
        scanf("%d", &quantite);
        if (quantite < 0)
        {
            printf("Impossible d'entrer un nombre negatif\n");
            goto GL;
        }
        else if (quantite <= produit[indice].quantite)
        {
            produit[indice].quantite = produit[indice].quantite - quantite; // indice= prdt acheté

            statistique[sizeStatistique].code = produit[indice].code;
            strcpy(statistique[sizeStatistique].nom, produit[indice].nom);
            statistique[sizeStatistique].quantite = quantite;
            statistique[sizeStatistique].prixTTC = produit[indice].prixTTC * quantite;
            statistique[sizeStatistique].day=tm->tm_mday;
            statistique[sizeStatistique].month=tm->tm_mon + 1;
            statistique[sizeStatistique].year=tm->tm_year + 1900;

            sizeStatistique++;
        }
        else
        {
            printf("cette quantite n'existe pas'");
        }
    }
    else
    {
        printf("introuvable");
    }
    for(i = 0 ; i < sizeStatistique ; i ++){
        printf("%d    %f     %d",statistique[i].code, statistique[i].prixTTC,statistique[i].quantite);
    }
}

void rechercheCode()
{
    int c, i, indice = 0;
    printf("recherche un produit \n");
    printf("donner le code de produit que vous recherchez ;");
    scanf("%d", &c);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == c)
        {
            indice = 1;
            printf("code    nom      prix      quantite \n");
            printf("%d      %s      %.2fdh        %d     \n", produit[i].code, produit[i].nom, produit[i].prix, produit[i].quantite);
            break;
        }
    }
    if (indice == 0)
    {
        printf("introuvable");
    }
}

void rechercheQuantite()
{
    int q, i, indice = -1;
    printf("recherche un produit ");
    printf("donner la quantite de produit que vous rechercher ;");
    scanf("%d", &q);
    for (i = 0; i < np; i++)
    {
        if (produit[i].quantite == q)
        {
            indice = i;
            printf("code    nom      prix      quantite \n");
            printf("%d      %s      %.2fdh        %d     \n", produit[i].code, produit[i].nom, produit[i].prix, produit[i].quantite);
            break;
        }
    }
    if (indice == -1)
    {
        printf("introuvable");
    }
}
void etatStock()
{
    int i, m = 0;
    printf("\tCODE\tNOM\tQUANTITE\tPRIX\tPRIXTTC\n");
    for (i = 0; i < np; i++)
    {
        if (produit[i].quantite < 3)
        {
            printf("\t%d", produit[i].code);
            printf("\t%s", produit[i].nom);
            printf("\t%d", produit[i].quantite);
            printf("\t\t%.2f", produit[i].prix);
            printf("\t%.2f\n", produit[i].prixTTC);
            m=1;
        }
    }
    if(m==0){
        printf("\nAucun produit avec cette quntite\n");
    }
}

void alimenterStock()
{
    int i, code, quantite, indice = -1;
    printf("Veuillez entrer le code de produit :");
    scanf("%d", &code);
    for (i = 0; i < np; i++)
    {
        if (produit[i].code == code)
        {
        QUANTITE:
            indice = i;
            printf("Veuillez entrer la quantite de produit :");
            scanf("%d", &quantite);

            if (quantite > 0)
            {
                produit[i].quantite += quantite;
            }
            else
            {
                printf("Entrer une quantite valide\n");
                goto QUANTITE;
            }
            break;
        }
    }
    if (indice == -1)
    {
        printf("Impossible d'executer cette operation!!!");
    }
}

void supprimer()
{
    int i, c, position = -1;
    printf("supprimer un produit \n");
    printf("Donner le code de produit que vous souhaitez supprimer :");
    scanf("%d", &c);

    for (i = 0; i < np; i++)
    {
        if (c == produit[i].code)
        {
            position = i;
            break;
        }
    }
    if (position != -1)
    {
        for (i = position; i < np; i++)
        {
            produit[i] = produit[i + 1];
        }
        np--;
    }
    else
    {
        printf("ERREUR!!! PRODUIT INTROUVABLE !!!");
    }
}

void statistiqueVente(){
    int i, quantiteTotal = 0;
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    afficherVendu();
    float moyenne , prixTotal = 0 , max , min;
    max = statistique[0].prixTTC;
    min = statistique[0].prixTTC;

    for( i = 0 ; i < sizeStatistique ; i++){
        if(statistique[i].day == tm->tm_mday  && statistique[i].month == (tm->tm_mon + 1)  && statistique[i].year == (tm->tm_year + 1900))
        {
        
            prixTotal = prixTotal + statistique[i].prixTTC;
            quantiteTotal = quantiteTotal + statistique[i].quantite;
            if(max<statistique[i].prixTTC){
                max = statistique[i].prixTTC;
            }
            if(min>statistique[i].prixTTC){
                min = statistique[i].prixTTC;
            }
        }
    }

    // printf("%.2f\n", prixTotal);
    // printf("%.2f\n",prixTotal/(float)quantiteTotal);
    // printf("%.2f\n",max);
    // printf("%.2f\n",min);
    printf("total %.2fdhs\n", prixTotal);
    printf("moyenne %.2f\n", moyenne);
    printf("max %.2f\n", max);
    printf("min %.2f\n", min);
}

void menu()
{
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

int main()
{
    printf("____________________________**BIENVENUE DANS VOTRE SYSTEME DE GESTION DE VOTRE PHARMACIE**__________________________");
    printf("-------------------------------------------------------------------------------------------------------------------\n");
    printf("---------------------------------------------------MENU------------------------------------------------------------\n");
    int choix;
debut:
    menu();
    printf("\n-------------------------------------------------------------------------------------------------------------------\n");

    printf("Veuillez entrer votre choix: \n ");
    scanf("%d", &choix);

    switch (choix)
    {
    case 1:
        printf("Ajouter un nouveau produit: \n ");
        ajouterproduit();
        goto debut;
    case 2:
        printf("Ajouter plusieurs produits: \n");
        ajouterPlusieursProduit();
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
    case 12:
        printf("Afficher les statistiques de vente: \n");
        statistiqueVente();
        goto debut;
    }
}
