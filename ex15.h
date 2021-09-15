/*****************************************************************************
 *   ex15.h                                    Version 20180714.101818        *
 *                                                                           *
 *   Brief description                                                       *
 *   Copyright (C) 2016-2018    by Ruben Carlo Benante                       *
 *****************************************************************************
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License.          *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************
 *   To contact the author, please write to:                                 *
 *   Ruben Carlo Benante                                                     *
 *   Email: rcb@beco.cc                                                      *
 *   Webpage: www.beco.cc                                                    *
 *   Phone: +55 (81) 3184-7555                                               *
 *****************************************************************************/

/* ------------------------------------------------------------------------- */
/**
 * \file ex15.h
 * \ingroup GroupUnique
 * \brief Brief description
 * \details This program really do a nice job as a template, and template only!
 * \version 20160908.182854
 * \date 2016-09-08
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _EXN_H
#define _EXN_H

/* ------------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <string.h> /* Strings functions definitions */
#include <ctype.h> /* Character functions */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <string.h> */ /* Strings functions definitions */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <stddef.h> */ /* Various types and MACROS */

/* ------------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20160908.182854" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SNUMP 5 /* codigo, ano e edicao: 4 digitos */
#define SISBN 14 /* numero ISBN: 13 digitos */
#define SPEQ  101 /* editora e local */
#define SMED  201 /* autor e titulo */
#define SGRA  626 /* linha do arquivo */

#define NWINS 6 /* janelas: help, add, search, change, del, about */
/* msgstatus */
#define TITULOST "Linha de status :"
#define STLINE (LINES -4)
#define STOK 0
#define YESNO 1

/* strings dos titulos */
#define TITULO "Sistemas de biblioteca Grupo Orwell"

const char *stela[NWINS]={"Tela 00: Ajuda",
                          "Tela 01: cadastro de livros" ,
                          "Tela 02: procura de livros",
                          "Tela 03: mudanca de livros",
                          "Tela 04: excluir um livro",
                          "Tela 05: about"};


typedef unsigned int uint; // variavel para a funcao STRISTR
/* ------------------------------------------------------------------------- */
/* struct com dados do livro */
typedef struct slivro
{
    /* livro
     * Código;Autor;Título;Editora;Local;Ano;Edição;ISBN\0
     * 4     ;200  ;200   ;100    ;100  ;4  ;4     ;13
     */
    int cod;
    char autor[SMED];
    char titulo[SMED];
    char editora[SPEQ];
    char local[SPEQ];
    int ano;
    int ed;
    int isbn;
} livro_t;
/* ------------------------------------------------------------------------- */
/* lista de variaveis para entrada de livro*/
    char codigo[4];
    char autor[200];
    char autorC[200];
    char titulo[200];
    char tituloC[200];
    char ano[7];
    char anoC[7];
    char local[100];
    char localC[100];
    char livro[1500];
    char dados[1500];
    char editora[100];
    char editoraC[100];
    char edicao[7];
    char edicaoC[7];
    char opcoes[8][10] = {"Autor:","Titulo:","Ano:","Editora:", "Local:", "Edicao","ISBN", "Fechar"};
    char opcoesC[8][15] = {"Autor:", "Titulo:","Editora:","Local:", "Ano:", "Edicao","ISBN", "Fechar"};
char dadosC[1500]="";
char autores[40]="";
char ISBN[20];
char ISBNC[20];
char PV[1]=";";
char h[2]="", j[2]="";
    int c,v,o;
char palavra2[626]; /* palavras escritas pelo usuario */

/* ------------------------------------------------------------------------- */
/* struct com informacoes sobre as janelas ncurses */
typedef struct swins
{
    int menu[NWINS]; /* menu das janelas */
    int lmax, cmax; /* linha e coluna maxima da janela */
    int wo; /* old window: confere se mudou a janela */
    int wi; /* indica a janela atual mostrada */
    WINDOW *w[NWINS]; /* vetor com todas janelas */
} wins_t;

/* ------------------------------------------------------------------------- */
/* prototypes */

/**< Prints help information and exit */
void help(void);
/**< Prints copyright information and exit */
void copyr(void); 
/**< Initializes some operations before start */
void ex15_init(wins_t *pwin);
/* funcao bomb para fechar o programa */
void bomb(wins_t win,char *msg, int status, FILE *f);
/* imprime base das telas */
void imprime_tela(wins_t *pwin); 
/* funcao responsavel pelo menu (estara presente me todas as janelas) */
void menu(int yMax, int xMax);
/* funcao responsavel pela janela help */
void funcao_help(wins_t *pwin); 
/* funcao responsavel por adicionar um livro ao banco de dados */
void funcaoAdd(wins_t *pwin); 
/* funcao de mensagem no status */
int mensagem_status(wins_t win, char*msg, int opt, char*op1, char*op2);
/* funcao responsavel por consultar um livro*/
void funcaoBuscar(wins_t *pwin);
/* funcao responsavel por alterar um livro*/
void funcaoalterar(wins_t *pwin, char livro[626]);
/* funcao responsavel por deletar um livro*/
void funcaodeletar(wins_t *pwin, char livro[626]);
/* funcao de centralisacao uma string */
int centralisar(int cl, char*msg);
/* funcao de comparacao de string insensivel a maiusculo ou minusculo*/
char *stristr(const char *String, const char *Pattern);
#endif /* NOT def _EXN_H */

/* ------------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */

