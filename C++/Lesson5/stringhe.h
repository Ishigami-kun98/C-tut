#ifndef STRINGHE_H
#define STRINGHE_H

/**
* funzione che stampa la stringa

@param la stringa
**/
void stampa_stringa(const char *str);

/**
* funzione che ritorna la lunghezza

@return  lunghezzastringa
**/
unsigned int lunghezza_Stringa(const char *str);

/**
* funzione che inverte una stringa
* la nuova stringa è allocata dinamicamente
@param str puntantore alla stringa
**/
void inverti_stringa(char * str);

/**
* funzione che clona una stringa.
* la nuova stringa è allocata dinamicamente
@return puntatore alla string nuova
**/
char *clona_stringa(const char *str);

/**
*funzione che unisce le stringhe
*@param1 str1 prima stringa da concatenare
*@param2 str2 seconda stringa da concatenare
*@return : la stringa concatenata
**/
char *unisci_string(const char *str1, const char *str2);

/**
  *funzione che cerca stringhe

**/
const char *cerca_stringa(const char * s1, const char * s2);

/**
 *funzione che sostituisce una stringa
  **/
void sostituisci_stringa(char *s1, const char *s2);

#endif
