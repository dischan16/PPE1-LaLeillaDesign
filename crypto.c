/*
 * crypto.c
 *
 *  Created on: 8 Jun 2021
 *      Author: disch
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

// fonction pour conversion en binaire

void conversion(char mdp[1000]) {
	int i, j, c;

	for (i = 0; mdp[i] != '\0'; i++) {
		c = mdp[i];
		for (j = 7; j + 1 > 0; j--) {
			if (c >= (1 << j)) {
				c = c - (1 << j);
				printf("1");
			} else
				printf("0");
		}
		printf(" ");
	}
}

//fonction d'encryption
int encrypt(char text[555]) {
// Initialisation des variables

	int i, key;
	char ch;

//Pour les alphabets miniscules

	printf("Inserrer la cle entre 1 et 9 inclusif: ");
	scanf("%d", &key);

	for (i = 0; text[i] != '\0'; ++i) {
		ch = text[i];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch + key;

			if (ch > 'z') {
				ch = ch - 'z' + 'a' - 1;
			}

			text[i] = ch;

		}

		//Alphabet Majuscule

		else if (ch >= 'A' && ch <= 'Z') {
			ch = ch + key;

			if (ch > 'Z') {
				ch = ch - 'Z' + 'A' - 1;
			}

			text[i] = ch;
		}
	}
	return key, text;
}

//function de decryptage

void decrypt(char text[555]) {

	//Alphabet miniscule

	int x, key;
	char ch;

	printf("Choissisez enter 1 et 9 inclusif: ");
	scanf("%d", &key);

	for (x = 0; text[x] != '\0'; ++x) {
		ch = text[x];

		if (ch >= 'a' && ch <= 'z') {
			ch = ch - key;

			if (ch < 'a') {
				ch = ch + 'z' - 'a' + 1;
			}

			text[x] = ch;
		} else if (ch >= 'A' && ch <= 'Z') {
			ch = ch - key;

			if (ch < 'A') {
				ch = ch + 'Z' - 'A' + 1;
			}

			text[x] = ch;
		}

	}
}
int main() {
	char text[500];
	FILE *fichier;

	//Ouvrir le ficher
	fichier = fopen("TP_XOR.txt", "w");

	printf("Inserrer une phrase : ");
	gets(text);

	fprintf(fichier, "Sentence: %s \n", text);

	int i, length, hash;
	char mdp[555];

	printf("Inserrer un mots de passe : ");
	scanf("%s", mdp);

	printf("L'equivalence du mots de passe en binaire : ");
	conversion(mdp);
	printf("\n");

	//Le hash de mots par mots

	length = strlen(mdp);

	for (i = 0; i < length; i++)

	{

		hash = hash ^ mdp[i];

	}

	//XOR letter et decalage

	int k, key, xor;

	k = hash ^ key;

	//XOR cesar et k

	int atoi(const char *str);
	xor = atoi(text) ^ k;

	//Le menu

	char choice[200];
	printf("Choissisez  encrypter or decrypter : ");
	scanf("%s", choice);

	if ((strcmp(choice, "encrypter") == 0)
			|| (strcmp(choice, "Encrypter") == 0)) {
		encrypt(text);
		printf("Cesar encrypter  :%s", text);
		fprintf(fichier, "Cesar encrypted  : %s \n", text);
		printf("\n");
		printf("Encryptage XOR : ");
		printf(xor);
		printf("XOR lettre et decalage (K): %d", k);
		printf("\n");
		printf("Le Hash  : %s", hash);
		printf("\n");
		fprintf(fichier, "XOR est : %s%s", xor, xor);
		printf("\n");
	}
	// conditions specific pour le menu
	if ((strcmp(choice, "decrypter") == 0)
			|| (strcmp(choice, "Decrypter") == 0)) {
		printf("Le text doit etre en mode encrypter ! ");
	}

	if ((strcmp(choice, "quit") == 0) || (strcmp(choice, "QUIT") == 0)) {
		printf("Program Terminer !");
		printf("\n");
	}

	printf("Choissisez  encrypter ou decrypter or quitter: ");
	scanf("%s", choice);

	if ((strcmp(choice, "encrypter") == 0)
			|| (strcmp(choice, "Encrypter") == 0)) {
		printf("Deja encrypter !");
		printf("\n");
	}

	if ((strcmp(choice, "decrypter") == 0)
			|| (strcmp(choice, "Decrypter") == 0)) {
		decrypt(text);
		printf("\n");
		fprintf(fichier, "\nDecrypted Cesar : %s \n", text);

		int k1;
		int atoi(const char * str);
		k1 = xor ^ atoi(text);

		printf("K est: %d", k1);
		printf("\n");

		hash = k ^ key;

		length = strlen(mdp);

		for (i = 0; i < length; i++)

		{

			hash = hash ^ mdp[i];

		}

		printf("Le hash : %c", hash);
		printf("\n");
		printf("Le decryptage : %s  \n", text);

	}

	if ((strcmp(choice, "quitter") == 0) || (strcmp(choice, "QUITTER") == 0)) {
		printf("Program Terminer !");
		printf("\nMercii Chaww!");

		printf("\n");
	}
	fclose(fichier);
	system("pause");
	return 0;

}
