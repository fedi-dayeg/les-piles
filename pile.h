#pragma once
#define Nmax 200
typedef struct cellule {
	int info;
	struct cellule* suivant;
};

typedef struct cellule* pile;

void affiche(pile);
int et_vide(pile);
pile init(pile);
int et_plaine(pile);
int taille(pile);
pile empiler(pile, int);
int sommet(pile);
pile depuler(pile);


void affiche(pile p)
{
	pile q;
	if (et_vide(p)) {
		printf("La Pile Et Vide !!");
	}
	else
	{
		q = p;
		while (q != NULL)
		{
			printf("_________________\n");
			printf("\n|\t%d\t|\n",q->info);
			 
			q = q->suivant;
		}
	}
}

int et_vide(pile p)
{
	return (p == NULL);
}

pile init(pile p)
{
	return (NULL);
	printf("\nLa liste A ete initialiser\n");
}


int et_plaine(pile p)
{
	return (taille(p) == Nmax);
}

int taille(pile p)
{
	pile q;
	int n;
	n = 0;
	q = p;
	while (q != NULL)
	{
		n++;
		q = q->suivant;
	}
	return (n);
}


pile empiler(pile p, int e)
{
	pile q;
	if (et_plaine(p))
	{
		printf("Votr Pile Et Saturer IMPOSSIBLE de Emppiler!!\n");
	}
	else
	{
		q = (pile)malloc(sizeof(struct cellule));
		q->info = e;
		q->suivant = p;
		p = q;
	}
	return (p);
}

int sommet(pile p)
{
	if (!et_vide(p))

		return (p->info);


}

pile depuler(pile p)
{
	pile q;
	if (et_vide(p))
	{
		printf("Pile Et VIDE!! IMPOSSIBLE de depuler\n");
	}
	else
	{
		q = p;
		p = p->suivant;
		free(p);
	}
	return (p);
}