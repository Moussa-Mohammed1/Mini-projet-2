#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    // structure : contact

typedef struct contact{
    char nom[30];
    char prenom[30];
    char NumTele[20];
    char Email[30];
}contact;

contact carnet[100];
char recherche[20];
int CntCount = 0; // Nombres des Contacts enregistre dans le carnet
int i,j, t = 0;
int exist;
int choix;
 // fonction qui transforme le premier caractere en MAJUSCULE et supprimer les espaces avant le premier caractere
void Majuscule(char str[]) {
    i = 0, j = 0;
    while (str[i] == ' ') i++;
    while (str[i]) {
        str[j++] = str[i++];
    }
    str[j] = '\0';
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - ('a' - 'A');
    }
}
    // fonction des choix non personnaliser
int ChoiseMaker(){
    int Choise;
invalide:
    printf("Votre choix :");
    scanf("%d",&Choise);
    getchar();
    switch (Choise)
    {
    case 1:
        return Choise;
        break;
    case 2:
        return Choise;
        break;
    default:
        printf("Choix Invalide ! ");
        goto invalide;
    }
}

    // fontion d'ajoute du contact en entrant des donnees specifie
void AjouteContact(){

        /*l'utlisateur peut entrer un nom contient un espace (ex: adil reda), ca cause des problem de "reading".
        Alors, l'utilisation de fgets avec strcspn est efficace que scanf() et getchar() pour les strings, 
        pour bien manipuler les input et eviter ces problem. */
    if (CntCount < 100)
    {

        printf("1. Ajoute simple.\n2. Ajoute multiple.\n");
        choix = ChoiseMaker();
        if(choix == 1){
            printf("Nom :");
            fgets(carnet[CntCount].nom,sizeof(carnet[CntCount].nom), stdin);
            carnet[CntCount].nom[strcspn(carnet[CntCount].nom,"\n")]=0;
            Majuscule(carnet[CntCount].nom);                            // appeler la fonction Majuscule pour mettre le premier caracter;
            printf("Prenom :");
            fgets(carnet[CntCount].prenom,sizeof(carnet[CntCount].prenom), stdin);
            carnet[CntCount].prenom[strcspn(carnet[CntCount].prenom,"\n")]=0;
            Majuscule(carnet[CntCount].prenom);
            printf("Numero de telephone : ");
            fgets(carnet[CntCount].NumTele,sizeof(carnet[CntCount].NumTele), stdin);
            carnet[CntCount].NumTele[strcspn(carnet[CntCount].NumTele,"\n")]=0;
            printf("Email : ");
            scanf("%s",carnet[CntCount].Email);
            getchar();
            Majuscule(carnet[CntCount].Email);
            CntCount ++;
            choix == -1;
        }
        else {
            int Adds, cntAdds = 0;
            printf("--------------------------------------------------\n");
            printf("Combien de contacts vous souhaitez ajouter :");
            scanf("%d",&Adds);
            getchar();
            do
            {
                printf("Contact N%d :\n", cntAdds + 1);
                printf("Nom :");
                fgets(carnet[CntCount].nom,sizeof(carnet[CntCount].nom), stdin);
                carnet[CntCount].nom[strcspn(carnet[CntCount].nom,"\n")]=0;
                Majuscule(carnet[CntCount].nom);
                printf("Prenom :");
                fgets(carnet[CntCount].prenom,sizeof(carnet[CntCount].prenom), stdin);
                carnet[CntCount].prenom[strcspn(carnet[CntCount].prenom,"\n")]=0;
                Majuscule(carnet[CntCount].prenom);
                printf("Numero de telephone : ");
                fgets(carnet[CntCount].NumTele,sizeof(carnet[CntCount].NumTele), stdin);
                carnet[CntCount].NumTele[strcspn(carnet[CntCount].NumTele,"\n")]=0;
                printf("Email : ");
                scanf("%s",carnet[CntCount].Email);
                getchar();
                Majuscule(carnet[CntCount].Email);
                CntCount ++;
                cntAdds ++;
                choix == -1;
                printf("--------------------------------------------------\n");
            } while (cntAdds < Adds);
        }
    }
    else{
        printf("Votre carnet est plein !");
    }
}
    // fonction de modification des donnees d'un contact enregistre en fontion du nom du contact
void ModifierContact(){
    if (CntCount == 0){
        printf("\nAucun contact n'est disponible pour modification !\n\n");
    }
    else{
        exist = -1;
        printf("\nEntrer Le nom du contact que vous voulez modifier :");
        fgets(recherche, sizeof(recherche), stdin);
        recherche[strcspn(recherche,"\n")]=0;
        for ( i = 0; i < CntCount; i++){
            if (strcmp(carnet[i].nom,recherche) == 0){
                printf("ce contacts exist sur votre carnet !\n");
                printf("ces details :\nNom et Prenom : %s %s\nNumero de telephone : %s\nadresse e-mail : %s.\n", carnet[i].nom, carnet[i].prenom, carnet[i].NumTele, carnet[i].Email);
                printf("--------------------------------------------------\n");
                printf("Entrer le nouveau nom :");
                fgets(carnet[i].nom,sizeof(carnet[i].nom), stdin);
                carnet[i].nom[strcspn(carnet[i].nom,"\n")]=0;
                Majuscule(carnet[i].nom);
                printf("Entrer le nouveau prenom :");
                fgets(carnet[i].prenom,sizeof(carnet[i].prenom), stdin);
                carnet[i].prenom[strcspn(carnet[i].prenom,"\n")]=0;
                Majuscule(carnet[i].prenom);
                printf("Entrer le nouveau numero de telephone :");
                fgets(carnet[i].NumTele, sizeof(carnet[i].NumTele), stdin);
                carnet[i].NumTele[strcspn(carnet[i].NumTele,"\n")]=0;
                printf("Entrer le nouveau adresse e-mail :");
                scanf("%s",carnet[i].Email);
                getchar();
                Majuscule(carnet[i].Email);
                printf("\nModifier avec success, nouveau details:\nNom : %s \nPrenom : %s\nNumero de telephone : %s\nadresse e-mail : %s.\n", carnet[i].nom, carnet[i].prenom, carnet[i].NumTele, carnet[i].Email);
                printf("--------------------------------------------------\n");
                exist = 1;
                break;
            }
        }
        if (exist != 1){
            printf("\nContact %s non trouve\n",recherche);
        }
    }
}
    // fonction de suppression d'un contact en recherchant par nom
void SupprimerContact(){
    exist = 0;
    if (CntCount == 0){
        printf("\nAucun contact n'est disponible pour suppression.\n");
    }
    else{
        printf("\nEntrer le nom contact que vous voulez supprimer :");
        fgets(recherche, sizeof(recherche), stdin);
        recherche[strcspn(recherche,"\n")]=0;

        for ( i = 0; i < CntCount; i++){
            if (strcmp(carnet[i].nom,recherche)==0){
                // confirmation du suppression
                printf("Contact %s est trouve !\n",recherche);
                printf("Voulez-vous vraiment supprimer ce contact:\n1. oui.\n2.annuler\n");
                choix = ChoiseMaker();
                if(choix == 1){
                    for ( j = i; j < CntCount -1 ; j++){
                        strcpy(carnet[j].nom, carnet[j+1].nom);
                        strcpy(carnet[j].prenom, carnet[j+1].prenom);
                        strcpy(carnet[j].NumTele, carnet[j+1].NumTele);
                        strcpy(carnet[j].Email, carnet[j+1].Email);
                    }
                    CntCount --;   
                
                    printf("Contact %s supprime avec success .\n",recherche);
                    exist = 1;
                    choix = -1;
                    break;
                }else{
                    printf("Suppression de %s annule avec success !:\n", recherche);
                    choix = -1;
                    break;
                }
            }
        }
        if (exist != 1){
            printf("\nContact %s non trouve\n",recherche);
        }
    }
}
    // fontion d'affichage de tous les contact enregistre dans le carnet
void AfficheContacts(){
    if (CntCount == 0){
        printf("\nVotre carnet est totalement vide !\n");
    }
    else{
        printf("\nLa liste complete des contacts avec leurs details:\n");
        for ( i = 0; i < CntCount; i++)
        {
            printf("\nContact N%d :\nNom : %s \nPrenom : %s\nNumero de telephone : %s\nAdresse e-mail : %s.\n", i+1, carnet[i].nom, carnet[i].prenom, carnet[i].NumTele, carnet[i].Email);
            printf("--------------------------------------------------\n");
        }
    }
}
    // fonction de recherche d'un contacts par son nom
void RechercheContact(){
    exist = 0;
    if (CntCount == 0){
        printf("\nVotre carnet est vide !\n");
    }
    else{
        printf("\nEntrer le nom du contact a rechercher : ");
        fgets(recherche, sizeof(recherche), stdin);
        recherche[strcspn(recherche, "\n")] = 0;
        for ( i = 0; i < CntCount; i++){
            if (strcmp(carnet[i].nom, recherche) == 0)
            {
                printf("\nContact %s est trouve, ces detailes son :\nNom : %s\nPrenom :  %s\nNumero de telephone : %s\nadresse e-mail : %s.\n", recherche, carnet[i].nom, carnet[i].prenom, carnet[i].NumTele, carnet[i].Email);
                printf("--------------------------------------------------\n");
                exist = 1;
                break;
            }
        }
        if (exist != 1){
            printf("\nContact %s non trouve\n", recherche);
        }
    }
}
void triecontact(){
    /* pour bien trie le tableaux in faut transformer le premier caractere ou tout la chaine en "MAJUSCLE", pour eviter problem declassification*/
    printf("Voulez-vous trie le tableau en :\n");
    printf("--------------------------------------------------\n");
    printf("1. Ascendent.\n2. Descendent.\n");
    choix = ChoiseMaker();
    if (choix == 1){
        for (i = 0; i < CntCount - 1; i++) {
            for (j = 0; j < CntCount - i - 1; j++) {
                if (strcmp(carnet[j].nom, carnet[j + 1].nom) > 0) {
                    contact temp = carnet[j];
                    carnet[j] = carnet[j + 1];
                    carnet[j + 1] = temp;
                }
            }
        }
        AfficheContacts();
    }
    else{
        
        for (i = 0; i < CntCount - 1; i++) {
            for (j = 0; j < CntCount - i - 1; j++) {
                if (strcmp(carnet[j].nom, carnet[j + 1].nom) < 0){
                    contact temp = carnet[j];
                    carnet[j] = carnet[j + 1];
                    carnet[j + 1] = temp;
                }
            }
        }
        AfficheContacts();
    }
    
}
    // Menu principale du systeme de gestion de contacts
void MenuPrincipale(){

    do{
        printf("\n------Systeme de Gestion de Contacts YouCode------\n");
        printf("--------------------------------------------------\n");
        printf("\t1. Ajouter un Contact.\n");
        printf("\t2. Modifier un Contact.\n");
        printf("\t3. Supprimer un Contact.\n");
        printf("\t4. Afficher Tous les Contacts.\n");
        printf("\t5. Rechercher un Contact.\n");
        printf("\t6. Trier les contacts.\n");
        printf("\t7. Quitter.\n");
        printf("--------------------------------------------------\n");
        printf("Choisir une option :");
        scanf("%d",&choix);
        getchar();
        printf("--------------------------------------------------\n");
        switch (choix)
        {
        case 1:
            AjouteContact();
            break;
        case 2:
            ModifierContact();
            break;
        case 3:
            SupprimerContact();
            break;
        case 4:
            AfficheContacts();
            break;
        case 5:
            RechercheContact();
            break;
        case 6:
            triecontact();
            break;
        case 7:
            printf("program termine !\n");
            break;
        default:
            printf("\nchoix invalide, veuillez ressayez!\n");
        }
    } while (choix != 7);
}
int main(){

    strcpy(carnet[0].nom, "El Amrani");
    strcpy(carnet[0].prenom, "Youssef");
    strcpy(carnet[0].NumTele, "0612345678");
    strcpy(carnet[0].Email, "youssef.elamrani@gmail.com");
    CntCount ++;
    strcpy(carnet[1].nom, "Benjelloun");
    strcpy(carnet[1].prenom, "Sanaa");
    strcpy(carnet[1].NumTele, "0678123456");
    strcpy(carnet[1].Email, "sanaa.benjelloun@hotmail.com");
    CntCount ++;
    strcpy(carnet[2].nom, "El Fassi");
    strcpy(carnet[2].prenom, "Rachid");
    strcpy(carnet[2].NumTele, "0655987123");
    strcpy(carnet[2].Email, "rachid.elfassi@yahoo.com");
    CntCount ++;
    strcpy(carnet[3].nom, "Cherkaoui");
    strcpy(carnet[3].prenom, "Fatima");
    strcpy(carnet[3].NumTele, "0623456789");
    strcpy(carnet[3].Email, "fatima.cherkaoui@gmail.com");
    CntCount ++;
    strcpy(carnet[4].nom, "Lahlou");
    strcpy(carnet[4].prenom, "Mohamed");
    strcpy(carnet[4].NumTele, "0632145789");
    strcpy(carnet[4].Email, "mohamed.lahlou@hotmail.com");
    CntCount ++;
    strcpy(carnet[5].nom, "Haddad");
    strcpy(carnet[5].prenom, "Imane");
    strcpy(carnet[5].NumTele, "0645781234");
    strcpy(carnet[5].Email, "imane.haddad@gmail.com");
    CntCount ++;
    strcpy(carnet[6].nom, "El Idrissi");
    strcpy(carnet[6].prenom, "Karim");
    strcpy(carnet[6].NumTele, "0678123490");
    strcpy(carnet[6].Email, "karim.elidrissi@yahoo.com");
    CntCount ++;
    strcpy(carnet[7].nom, "Bouziane");
    strcpy(carnet[7].prenom, "Nour");
    strcpy(carnet[7].NumTele, "0612349876");
    strcpy(carnet[7].Email, "nour.bouziane@hotmail.com");
    CntCount ++;
    strcpy(carnet[8].nom, "Zahraoui");
    strcpy(carnet[8].prenom, "Yassine");
    strcpy(carnet[8].NumTele, "0654321987");
    strcpy(carnet[8].Email, "yassine.zahraoui@gmail.com");
    CntCount ++;
    strcpy(carnet[9].nom, "Mansouri");
    strcpy(carnet[9].prenom, "Salma");
    strcpy(carnet[9].NumTele, "0621987654");
    strcpy(carnet[9].Email, "salma.mansouri@hotmail.com");
    CntCount ++;
    MenuPrincipale();
    return 0;
}