#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>

void combat();
void MainMenu();
void Registracija();
void Logovanje();
void LevelovanjeWarrior();
void PostLogin();

//STRUKTURE********************************
struct Warrior {
	char ime[50];
	int level;
	int zdravlje;
	int snaga;
};

struct Archer {
	char ime[50];
	int level;
	int zdravlje;
	int snaga;
};
struct ProtivnikTower {
	int zdravlje;
	int snaga;
};
void combat(struct Warrior* player, struct ProtivnikTower* protivnik) {
	while (1) {
		int akcija;
		printf("\nAkcije:\n");
		printf("1. Napad\n");
		printf("2. Bekstvo\n");
		scanf("%d", &akcija);

		if (akcija == 1) {
			// Napad korisnika
			printf("\nNapadili ste protivnika!\n");
			protivnik->zdravlje -= player->snaga;
			printf("Protivnik zdravlje: %d\n", protivnik->zdravlje);

			if (protivnik->zdravlje <= 0) {
				printf("Pobedili ste protivnika!\n");
				break; 
			}

			// Napad protivnika
			printf("\nProtivnik napada!\n");
			int protivnikovNapad = rand() % (protivnik->snaga) + 1;
			player->zdravlje -= protivnikovNapad;
			printf("Vase zdravlje: %d\n", player->zdravlje);

			if (player->zdravlje <= 0) {
				printf("Izgubili ste borbu...\n");
				printf("Probajte ponovo :)\n");
				LevelovanjeWarrior();
				break;
				
			}
		}
		else if (akcija == 2) {
			printf("\nBekstvo!\n");
			LevelovanjeWarrior();
			break;
		}
		else {
			printf("\nNiste izabrali validnu akciju.\n");
		}
	}
}

//POKAZIVACI********************************************
void ispisiWarrior(struct Warrior* warrior) {
	printf("Warrior:\n");
	printf("Ime: %s\n", warrior->ime);
	printf("Level: %d\n", warrior->level);
	printf("Zdravlje: %d\n", warrior->zdravlje);
	printf("Snaga: %d\n", warrior->snaga);
}
void ispisiArcher(struct Archer* archer) {
	printf("Archer:\n");
	printf("Ime: %s\n", archer->ime);
	printf("Level: %d\n", archer->level);
	printf("Zdravlje: %d\n", archer->zdravlje);
	printf("Snaga: %d\n", archer->snaga);
}
void LevelovanjeWarrior() {
	
	int opcija;
	printf("1.START CAMPAIGN\n");
	printf("2.START INFINITY TOWER\n");
	printf("3. EXIT\n");
	scanf("%d", &opcija);
	if (opcija == 1) {
		printf("Dolazi uskoro...");
		LevelovanjeWarrior();
	}
	else if (opcija == 2) {
		int level = 1;
		
		int povecanjeZdravlja, povecanjeSnage;
		struct Warrior warrior1;
		strcpy(warrior1.ime, "Vanguard");
		warrior1.level = 1;
		warrior1.zdravlje = 120;
		warrior1.snaga = 15;
		printf("Unesite povecanje zdravlja nakon svakog nivoa: ");
		scanf("%d", &povecanjeZdravlja);
		printf("Unesite povecanje snage nakon svakog nivoa: ");
		scanf("%d", &povecanjeSnage);
		
		while (1) {
			printf("Početak Infinity Tower nivoa %d\n", level);

			struct ProtivnikTower protivnik;
			protivnik.zdravlje = 30 + level * povecanjeZdravlja;
			protivnik.snaga = 5 + level * povecanjeSnage;
			

			printf("Protivnik zdravlje: %d\n", protivnik.zdravlje);
			printf("Protivnik snaga: %d\n\n\n", protivnik.snaga);
			printf("Tvoje zdravlje: %d\n", warrior1.zdravlje);
			printf("Tvoja snaga: %d\n", warrior1.snaga);
		
			
			char izgledProtivnika[10][21][100] = {
				// Izgled za level 1
				{
					"             .'* *.'               ",
					"               __/_*_*(_)          ",
					"              / _______ \\         ",
					"             _\\_)/___\\(_/_        ",
					"            / _((\\- -/))_ \\       ",
					"            \\ \\())(-)(()/ /       ",
					"             ' \\(((()))/ '         ",
					"            / ' \\)).))/ ' \\       ",
					"           / _ \\ - | - /_  \\      ",
					"          (   ( .;''';. .'  )     ",
					"          _\\\"__ /    )\\ __\"/_    ",
					"            \\/  \\   ' /  \\        ",
					"             .'  '...' ' )         ",
					"              / /  |  \\ \\         ",
					"             / .   .   . \\        ",
					"            /   .     .   \\       ",
					"           /   /   |   \\   \\      ",
					"         .'   /    b    '.  '.     ",
					"     _.-'    /     Bb     '-. '-._ ",
					" _.-'       |      BBb       '-.  '-. ",
					"(________mrf\\____.dBBBb.________)____)"
				},
				// Izgled za level 2
				{
					"                  __,,,,_",
					"          _ __..-;''`--/'/ /.',-`-.",
					"      (`/' ` |  \\ \\ \\\\ / / / / .-'/`,_",
					"     /'`\\ \\   |  \\ | \\| // // / -.,/_,'-,",
					"    /<7' ;  \\ \\  | ; ||/ /| | \\/    |`-/,/-.,_,/')",
					"   /  _.-, `,-\\,__|  _-| / \\ \\/|_/  |    '-/.;.\'",
					"   `-`  f/ ;      / __/ \\__ `/ |__/ |",
					"        `-'      |  -| =|\\_  \\  |-' |",
					"              __/   /_..-' `  ),'  //",
					"          fL ((__.-'((___..-'' \\__.'"
				},
				//Izgled za level 3
				{
					"        .-\"\"\"\"\"-.",
					"       /       \\",
					"   __ /   .-.  .\\",
					"  /  `\\  /   \\/  \\",
					"  |  _ \\/   .==.==.",
					"  | (   \\  /____\\__\\",
					"   \\ \\      (_()(_()",
					"    \\ \\            '---._",
					"     \\                   \\_",
					"  /\\ |`       (__)________/",
					" /  \\|     /\\___/",
					"|    \\     \\||VV",
					"|     \\     \\|\"\"\"\",",
					"|      \\     ______)",
					"\\       \\  /`",
					" \\      \\(",
				},
			};

			printf("Izgled protivnika:\n");
			for (int i = 0; i < 20; i++) {
				printf("%s\n", izgledProtivnika[level - 1][i]);
			}
			combat(&warrior1, &protivnik); // Poziv funkcije za borbu

			if (protivnik.zdravlje <= 0) {
				printf("Pobedili ste protivnika!\n");
				level++; // Prelazak na sledeći nivo
				printf("Prelazite na nivo %d!\n", level);
			}
			
		}
			
	
	}
	else if (opcija == 3) {
		PostLogin();
	}
	else {
		LevelovanjeWarrior();
	}
}
//Login Sistem
//POSTLOGIN***************************************
void PostLogin() {
	int opcija;
	int opcija2;
	printf("1. Izaberi karaktera\n");
	printf("2. Vidi o karakterima\n");
	printf("3. Logout\n");
	scanf("%d", &opcija);
	if (opcija == 1) {
		printf("Dobrodosao u izbor karaktera, za sada mozemo ponuditi 2 vrste:\n");
		printf("1. Warrior\n");
		printf("2. Mage\n");
		scanf("%d", &opcija2);
		if (opcija2 == 1) {
			int opcija;
			struct Warrior warrior1;
			strcpy(warrior1.ime, "Vanguard");
			warrior1.level = 1;
			warrior1.zdravlje = 120;
			warrior1.snaga = 15;
			ispisiWarrior(&warrior1);
			printf(" /\\\n");
			printf(" ||\n");
			printf(" ||\n");
			printf(" ||\n");
			printf(" ||           {}\n");
			printf(" ||          .--.\n");
			printf(" ||         /.--.\\\n");
			printf(" ||         |====|\n");
			printf(" ||         |`::`|\n");
			printf("_||_    .-;`\\..../`;-.\n");
			printf(" /\\\\   /  |...::...|  \\\n");
			printf(" |:'\\ |   /'''::'''\   |\n");
			printf("  \\ /\\;-,/\\   ::   /\\--; \n");
			printf("   \\ <` >  >._::_.<,<__>\n");
			printf("    `\"\"`  /   ^^   \\|  |\n");
			printf("          |        |\\::/\n");
			printf("          |        |/|||\n");
			printf("          |___/\\___| '''\n");
			printf("           \\_ || _/\n");
			printf("           <_ >< _>\n");
			printf("           |  ||  |\n");
			printf("           |  ||  |\n");
			printf("          _\\.:||:./_\n");
			printf("         /____/\\____\\\n");
			printf("Da li zelite da izaberete Warrior klasu?\n");
			printf("1. DA\n");
			printf("2. NE\n");
			scanf("%d", &opcija);
			if (opcija == 1) {
				printf("Uspesno ste izabrali Warrior klasu!\n");
				LevelovanjeWarrior();
			}
			else if (opcija == 2) {
				PostLogin();
			}
			else {
				PostLogin();
			}

		}


		else if (opcija2 == 2) {
			struct Archer archer1;
			strcpy(archer1.ime, "Arch Mage");
			archer1.level = 1;
			archer1.zdravlje = 80;
			archer1.snaga = 30;
			ispisiArcher(&archer1);
			printf("              _,-'|\n");
			printf("           ,-'._  |\n");
			printf(" .||,      |####\\ |\n");
			printf("\\.`',/     \\####| |\n");
			printf("= ,. =      |###| |\n");
			printf("/ || \\    ,-'\\#/,'`.\n");
			printf("  ||     ,'   `,,. `.\n");
			printf("  ,|____,' , ,;' \\| |\n");
			printf(" (3|\\    _/|/'   _| |\n");
			printf("  ||/,-''  | >-'' _,\\\\\n");
			printf("  ||'      ==\\ ,-'  ,'\n");
			printf("  ||       |  V \\ ,|\n");
			printf("  ||       |    |` |\n");
			printf("  ||       |    |   \\\n");
			printf("  ||       |    \\    \\\n");
			printf("  ||       |     |    \\\n");
			printf("  ||       |      \\_,-'\n");
			printf("  ||       |___,,--\")_\\\n");
			printf("  ||         |_|   ccc/\n");
			printf("  ||        ccc/\n");
			
			
				
			printf("Da li zelite da izaberete Mage klasu?\n");
			printf("1. DA\n");
			printf("2. NE\n");
			scanf("%d", &opcija);
			if (opcija == 1) {
				printf("Uspesno ste izabrali Mage klasu!\n");
			}
			else if (opcija == 2) {
				PostLogin();
			}
			else {
				PostLogin();
			}
		}
		else {
			printf("Pogresan unos!");
			PostLogin();
		}
	}
	else if (opcija == 2) {
		int opcija4;
		printf("Warriro je lorem ipsum........\n");
		printf("Mage je lorem ipsum.........\n");
		printf("Zelis li da se vratis nazad?");
		printf("\n1. DA\n");
		printf("2. NE\n");
		scanf("%d", &opcija4);
		if (opcija4 == 1) {
			PostLogin();

		}
		else if (opcija4 == 2) {
			printf("E pa moras da se vratis nazad :D\n");
			PostLogin();
		}
		else {
			PostLogin();
		}

	}
	else if (opcija == 3) {
		Logovanje();
	}
	else {
		printf("Niste uneli 1, 2 ili 3....");
		PostLogin();
	}
}
//LOGOVANJE***************************************
void Logovanje() {
	char KorisnickoIme[50];
	char Lozinka[50];
	printf("*****Uloguj se!******\n");
	printf("1.Korisnicko ime: ");
	scanf("%s", &KorisnickoIme);
	printf("2.Lozinka: ");
	scanf("%s", &Lozinka);
	FILE* file = fopen("data.txt", "r");
	if (file != NULL) {
		char user[50], password[50];
		while (fscanf(file, "User: %s\n", user) != EOF) {
			fscanf(file, "Password: %s\n", password);
			if (strcmp(user, KorisnickoIme) == 0 && strcmp(password, Lozinka) == 0) {
				printf("Uspesno ste se ulogovali!\n");

				fclose(file);
				PostLogin();

				return;
			}
		}
		printf("Pogresno korisnicko ime ili lozinka.\n");
		Logovanje();
		fclose(file);
	}
	else {
		printf("Greska pri otvaranju datoteke.\n");
	}
}
//Registracija Korisnika
void Registracija() {
	int opcija2;
	printf("Dobrodosli u registraciju!\n");
	printf("1.Napravi nalog\n");
	printf("2.Vrati se nazad");
	scanf("%d", &opcija2);
	if (opcija2 == 1) {
		int opcija3;
		char KorisnickoIme[20];
		char Lozinka[20];
		printf("Unesite korisnicko ime: ");
		scanf("%s", &KorisnickoIme);
		printf("Unesite lozinku: ");
		scanf("%s", &Lozinka);
		FILE* file = fopen("data.txt", "a");
		if (file != NULL) {
			fprintf(file, "User: %s\n", KorisnickoIme);
			fprintf(file, "Password: %s\n", Lozinka);
			fclose(file);
			printf("Nalog uspesno napravljen i sacuvan u datoteci.\n");
			printf("Da li zelis da nastavis na logovanje?\n");
			printf("1.Uloguj se\n");
			printf("2.Exit\n");
			scanf("%d", &opcija3);
			if (opcija3 == 1) {
				Logovanje();

			}
			else if (opcija3 == 2) {
				printf("Hvala ti sto si napravio nalog!");
			}
			

		}
		else {
			printf("Greška pri otvaranju datoteke.\n");
		}
	}
	else if (opcija2 == 2) {
		MainMenu();
		
	}
	else {
		printf("Molim te unesi 1 ili 2");
		Registracija();
	}
}
//MainMenu, registracija i login
void MainMenu() {
	int opcija;
	printf("Dobrodosao u MMO RPG igru, kako bi nastavio dalje pritisni 1 ili 2(1 za registraciju, 2 za login)\n");

	printf("1.Registruj se\n");
	printf("2.Uloguj se\n");
	printf("Izaberite opciju 1 ili 2: ");
	scanf("%d", &opcija);
	if (opcija == 1) {
		Registracija();

	}
	else if (opcija == 2) {
		Logovanje();
	}
	else {
		printf("Pogresan unos...");
		MainMenu();
	}
}

int main() {
	
	MainMenu();
	
	
	
	return 0;
}
