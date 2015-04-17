Depend on SFML 2.2 for dynlib1 (compile time)
Depend on Love 9.2 for dynlib2 (run time)

```
[DYN-LIB] -- SFML style
{
    [INIT] -> window initialization
    [POLL] -> poll event from queue
    [DRAW] -> data draw
}
```

TODO UPDATE :

	 Deplacemets du SNAKE avec une liste chainee.
	 Le SNAKE avance automatiquement, et les input claviers modifient
	 sa trajectoire

	 fonction faire_avancer_le_snake() qui prend en parametres la liste
	 chainee, et qui met a jour la position du maillon dans la map
	 (lst->next->pos = lst->pos && lst = lst->next)

	 fonction bouger_le_snake() qui va modifier la trajectoire, et
	 influencer les deplacements du snake
