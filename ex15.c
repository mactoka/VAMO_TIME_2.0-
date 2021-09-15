/*****************************************************************************
 *   ex15.c                                    Version 20180714.101818        *
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
 * @file ex15.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
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
 */

/*
 * Instrucoes para compilar:
 *   $make -B ex15.x DEBUG=0 
 *
 * Modelo de indentacao/estilo: --style=allman ou -A1
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex15.c
 */

/* ------------------------------------------------------------------------- */
/* includes at ex15.h */

#include "ex15.h" /* To be created for this template if needed */

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Programa gerenciador de biblioteca pessoal
 * @details Este programa gerencia uma biblioteca pessoal,
 * permite adicionar, consultar, alterar e remover livros.
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @warning Sem avisos no momento
 * @bug Sem bugs no momento
 * @todo tudo 
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */

    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "hV")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }

    /* inicio */

    int kpress;        /* teclas digitadas pelo usuario */
    wins_t win;        /* variavel da string do meuex15.h */
    ex15_init(&win);   /* funcao de inicialização */
    funcao_help(&win); /* imprime a tela help */


    do
    {
        kpress=getch();

        if(kpress==KEY_F(1)) /* F1 para imprimir a tela Help */
        {
            win.wi=0;
            funcao_help(&win);
        }
        if(kpress==KEY_F(2)) /* F2 para imprimir a tela Add Livros */
        {
            win.wi=1;
            funcaoAdd(&win);
        }
        if(kpress==KEY_F(3)) /* F3 para imprimir a tela procurar livro */
        {
            win.wi=2;
            funcaoBuscar(&win);
        }
        if(kpress==KEY_F(5)) /* F5 para mover para a tela da esquerda */
        {
            win.wi = ((win.wi-1) + 3) % 3; /* se move pra tela - 1 */
                switch(win.wi)
                {
                    case 0:
                        funcao_help(&win);
                        break;
                    case 1:
                        funcaoAdd(&win);
                        break;
                    /*case 2:
                        psearch(&win);
                        break;
                      case 3:
                        pchange(&win);
                        break;
                    case 4:
                        pdelet(&win);
                        break;*/
                }
        }
        if(kpress==KEY_F(6))  /* F6 para mover para a tela da direita */
        {
            win.wi = (win.wi+1) % 3; /* se move pra tela +1 */
                switch(win.wi)
                {
                    case 0:
                        funcao_help(&win);
                        break;
                    case 1:
                        funcaoAdd(&win);
                        break;
                    /*case 2:
                        psearch(&win);
                        break;
                      case 3:
                        pchange(&win);
                        break;
                    case 4:
                        pdelet(&win);
                        break; */
                }
        }
        if(kpress==KEY_F(8)) /* F8 para saida segura do programa */
        {
            if(mensagem_status(win, "Voce tem certeza que quer sair?", YESNO, "YES", "NO")) /* pede confirmacao para o usuario */
                bomb(win, "Voce apertou 'F8' para sair\n", 0, NULL);
        }
        napms(50);
    }while(kpress != 'q'); /* 'q' saida de emergencia */

    bomb(win, "Voce apertou 'q' : Saida de emergencia.\n", 0, NULL);

    return EXIT_SUCCESS;
}

/* ---------------------------------------------------------------------- */
/* funcao bomb para fechar o programa */
void bomb(wins_t win,char *msg, int status, FILE *f)
{
    IFDEBUG("bomb()");
    
    if(f) //se o usuario passar arquivo , fecha o arquivo
        fclose(f);

    for(int i=0; i<NWINS; i++) //deletar todas as janelas
        delwin(win.w[i]);

    endwin(); // termina o Ncurses
    fprintf(stderr, msg); // printa a mensagem no terminal do usuario

    exit(status); // da exit com o status que o usuario escolher

    return;
}

/* ------------------------------------------------------------------------- */
/* funcao de mensagem no status */ 
int mensagem_status(wins_t win, char*msg, int opt, char*op1, char*op2)
{
    IFDEBUG("imprime_tela()");

    int kpress;                   // armazenar tecla digitada pelo usuario
    int ls = strlen(TITULOST)+ 2; // calculo do tamanho do titulo status
    int ms = strlen(msg);         // calculo do tamanho da mensagem status
    int os = strlen(op1) + 2;     // calculo do tamanho da opcao 1 
    int item = 1;                 // variavel para imprimir mudanca das opcoes

    if(opt == YESNO)  // Em caso de opt ser YESNO
    {
        mvwprintw(win.w[win.wi], STLINE, ls,"%s", msg); // printar a mensagem na linha de status

        do // laco da esolha entre YES ou NO
        {                                 
            if(item == 1) // opcao YES
            {
                wattrset(win.w[win.wi], A_REVERSE);
                mvwprintw(win.w[win.wi], STLINE, ms + ls + 1,"%s",op1);
                wattrset(win.w[win.wi], A_NORMAL);
                mvwprintw(win.w[win.wi], STLINE, ms + ls + os,"%s",op2);
            }
            else // opcao NO
            {
                wattrset(win.w[win.wi], A_NORMAL);
                mvwprintw(win.w[win.wi], STLINE, ms + ls + 1,"%s",op1);
                wattrset(win.w[win.wi], A_REVERSE);
                mvwprintw(win.w[win.wi], STLINE, ms + ls + os,"%s",op2);
            }
              wrefresh(win.w[win.wi]);
            /* indentificar a tecla de o usuario digitar */
            kpress=getch();
            if(kpress == KEY_RIGHT || kpress == KEY_LEFT)
                item*=-1;                       // mudar o item faz com que imprima a opcao diferente
            wattrset(win.w[win.wi], A_NORMAL);  // conferir se a letra esta na fonte normal
            wrefresh(win.w[win.wi]);            // dar um wrefresh para imprimir novamente as opcoes coretamente
            napms(30);                          // 30 ms para descansar o processador
        }while(kpress != '\n'); // o loop continuira até o usuario digitar enter na sua opcao
        mvwhline(win.w[win.wi], STLINE, strlen(TITULOST)+1 ,' ',COLS- 2-strlen(TITULOST));
        wrefresh(win.w[win.wi]);
        if(item == 1) // ops 1
            return 1;   
        return 0; // ops 2
    }
    if(opt == STOK) // Em caso de opt ser STOK
    {
        mvwprintw(win.w[win.wi], STLINE, ls,"%s", msg); // printar a mesnagem de status
          // imprime o OK
        wattrset(win.w[win.wi], A_REVERSE);
        mvwprintw(win.w[win.wi], STLINE, ms + ls + 1,"OK");
        wattrset(win.w[win.wi], A_NORMAL);
        wrefresh(win.w[win.wi]);

        nodelay(win.w[win.wi], TRUE);
        do // laco para pagar tecla do usuario, espera confirmacao com enter
        { 
            kpress = getch();
        }while(kpress != '\n');
        nodelay(win.w[win.wi], TRUE);

        // limpa a linha de status
        mvwhline(win.w[win.wi], STLINE, strlen(TITULOST)+1 ,' ',COLS- 2-strlen(TITULOST));
        wrefresh(win.w[win.wi]);
        return 1;
    }
    return 0;
}
/*---------------------------------------------------------------------------*/
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex15", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "ex15");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");

    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex15", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void ex15_init(wins_t *pwin)
{
    IFDEBUG("ex15_init()");
   
    for(int i=0; i<NWINS; i++) /* define o menu 0 para todas as telas */
        pwin->menu[i] = 0; 

    pwin->lmax=LINES;  /* define as linhas maximas do struct */
    pwin->cmax=COLS;   /* define as colunas maximas do struct */
    pwin->wi=0;        /* define a tela tual do struct */
    pwin->wo=1;        /* define a tela antiga do struct */

    initscr();              /* inicia o Ncurses */
    napms(10);              /* 10 ms para iniciar o Ncurses sem problemas */
    halfdelay(2);
    refresh();              /* refresh inicial */
    noecho();               /* nao aparecer as teclas digitadas pelo usuario */
    start_color();
    curs_set(FALSE);        /* nao aparecer o cursor */
    keypad(stdscr, TRUE);   /* pode usar keypad */

    for(int i = 0; i<NWINS; i++) /* criacao das telas */
    {
        pwin->w[i] = newwin(LINES,COLS,0, 0);
        if(pwin->w[i]==NULL) /* no caso de nao conseguir criar as telas */
        {
            for(--i; i>=0 ; --i)
                delwin(pwin->w[i]); /* deleta todas que criou e termina o Ncurses juntamente com o programa */
            endwin();
            fprintf(stderr, "ERROR");
            exit(EXIT_FAILURE);
        }
    }
    
    return;
}

/* ------------------------------------------------------------------------- */
/* imprime base das telas */
void imprime_tela(wins_t *pwin)
{
    IFDEBUG("imprime_tela()");
    int c;
    c = centralisar(COLS, TITULO); /* centralisa o titulo */
     
    if(pwin->wi != pwin->wo) /* confere se a janela atual com a antiga para saber se precisa de wclear */
    {
        pwin->wo = pwin->wi;
        wclear(pwin->w[pwin->wi]);
    }

    box(pwin->w[pwin->wi], 0, 0);                             /* box da tela */
    
    mvwprintw(pwin->w[pwin->wi], 1, c,"%s", TITULO);          /* titulo da tela */
    mvwhline(pwin->w[pwin->wi], 2, 1,'*',COLS-2);             /* linha separadora abaixo do titulo */
    mvwprintw(pwin->w[pwin->wi], 3, 1,"%s", stela[pwin->wi]); /* o numero e o nome da tela atual */
    mvwhline(pwin->w[pwin->wi], 4, 1,'*',COLS-2);             /* linha separadora abaixo do nome da tela */
    mvwhline(pwin->w[pwin->wi], STLINE-1, 1,'*',COLS-2);      /* linha separadora acima da linha status */
    mvwprintw(pwin->w[pwin->wi], STLINE, 1,"%s", TITULOST);   /* titulo da linha status */
    mvwhline(pwin->w[pwin->wi], STLINE+1, 1,'*',COLS-2);      /* linha separadora abaixo da linha status */
    
    /* linha indicadora de funcoes das teclas, mostradas abaixo da mensagem de status */
    wattrset(pwin->w[pwin->wi], A_REVERSE);
    mvwprintw(pwin->w[pwin->wi], STLINE+2, 1,"   TECLAS:   |   F1(HELP)   |   F2(CADASTRO)   |   F3(PESQUISA)   |   F4(SALVAR)   |   F5(ANTERIOR)   |   F6(POSTERIOR)   |   F8(SAIR)   |");
    wattrset(pwin->w[pwin->wi], A_NORMAL);

	return;
}

/* ------------------------------------------------------------------------- */
/* funcao responsavel pela janela help */
void funcao_help(wins_t *pwin)
{

    IFDEBUG("phelp()");
    imprime_tela(pwin); /* imprime tela base */

    /* Imprime as informacoes para ajudar a utilizar o programa */
    wattron(pwin->w[pwin->wi], A_STANDOUT);
    mvwprintw(pwin->w[pwin->wi], 6, 1, "== Teclas de Funcao ==");
    wattroff(pwin->w[pwin->wi], A_STANDOUT);
    mvwprintw(pwin->w[pwin->wi], 8, 1, "<F1>         : Muda para a tela de ajuda.");
    mvwprintw(pwin->w[pwin->wi], 9, 1, "<F2>         : Muda para a tela de cadastro de livros.");
    mvwprintw(pwin->w[pwin->wi],10, 1, "<F3>         : Muda para a tela pesquisa de livros.");
    mvwprintw(pwin->w[pwin->wi],11, 1, "<F4>         : Salva / busca / altera um livro após completar seus campos.");
    mvwprintw(pwin->w[pwin->wi],12, 1, "<F5>         : Navega entre as telas disponiveis anteriores a atual.");
    mvwprintw(pwin->w[pwin->wi],13, 1, "<F6>         : Navega entre as telas disponiveis posteriores a atual.");
    mvwprintw(pwin->w[pwin->wi],14, 1, "<F8>         : Saida segura do programa.");
    mvwprintw(pwin->w[pwin->wi],15, 1, "<Q>          : Saida forcada do programa.");
    
    mvwhline(pwin->w[pwin->wi], 18, 1,'*',COLS-2); /* Linha de separacao da tela */
    
    wattron(pwin->w[pwin->wi], A_STANDOUT);
    mvwprintw(pwin->w[pwin->wi],20, 1, "== Instrucoes de Uso ==");
    wattroff(pwin->w[pwin->wi], A_STANDOUT); 
    wattron(pwin->w[pwin->wi], A_UNDERLINE);
    mvwprintw(pwin->w[pwin->wi],22, 1, "*Cadastro de Livros*");
    wattroff(pwin->w[pwin->wi], A_UNDERLINE); 
    mvwprintw(pwin->w[pwin->wi],23, 1, "==> Para cadastrar um ou mais livros, o usuario podera completar os campos necessarios e salvar utilizando a tecla <F4>. Para acessar o cadastro de livros novamente, o mesmo deve acessar a tela de cadastro de livros novamente (<F2>).");
    wattron(pwin->w[pwin->wi], A_UNDERLINE);
    mvwprintw(pwin->w[pwin->wi],26, 1, "*Pesquisa de Livros*");
    wattroff(pwin->w[pwin->wi], A_UNDERLINE); 
    mvwprintw(pwin->w[pwin->wi],27, 1, "==> Para pesquisar um livro ou mais livros, o usuario podera completar os campos necessarios e buscar utilizando a tecla <F10>. Letras maiusculas ou minusculas serao aceitas e encontradas. Apos isso, devera escolher entre as opcoes de pesquisa 'OR' ou 'AND'.");
    mvwprintw(pwin->w[pwin->wi],30, 1, "(OR / AND)");
    mvwprintw(pwin->w[pwin->wi],31, 1, "OR -> Ao selecionar essa opcao, o programa buscara por livro(s) que possua(m) QUAISQUER campos inseridos semelhantes aos dos livros presentes no banco de dados."); 
    mvwprintw(pwin->w[pwin->wi],32, 1, "AND -> Ao selecionar essa opcao, o programa buscara por livro(s) que possua(m) APENAS campos inseridos semelhantes aos dos livros presentes banco de dados."); 
    wattron(pwin->w[pwin->wi], A_UNDERLINE);
    mvwprintw(pwin->w[pwin->wi],34, 1, "*Retificacao de Livros*");
    wattroff(pwin->w[pwin->wi], A_UNDERLINE); 
    mvwprintw(pwin->w[pwin->wi],35, 1, "==> Para alterar um livro, o usuario devera primeiramente acessar a janela 'pesquisa de livros' (<F3>) e selecionar um livro. Ao teclar <enter> no escolhido, devera selecionar a opcao 'alterar' na barra de status. Apos isso, todos os campos desejaveis poderao ser retificados de forma similar ao cadastro de livros.");
    mvwprintw(pwin->w[pwin->wi],38, 1, "#Atencao: Caso qualquer erro tenha sido cometido ao completar um ou mais campos no momento de cadastrar ou retificar um livro, o usuario deve selecionar a opcao 'fechar' e selecionar a desejada janela novamente, se assim desejar.");
    wattron(pwin->w[pwin->wi], A_UNDERLINE);
    mvwprintw(pwin->w[pwin->wi],41, 1, "*Remocao de Livros*");
    wattroff(pwin->w[pwin->wi], A_UNDERLINE); 
    mvwprintw(pwin->w[pwin->wi],42, 1, "==> Para deletar um livro, o usuario devera primeiramente acessar a janela 'pesquisa de livros' (<F3>) e selecionar um livro. Ao teclar <enter> no escolhido, devera selecionar a opcao 'deletar' na barra de status. Apos isso, o livro sera deletado e nao estara mais disponivel para ser acessado."); 


    wrefresh(pwin->w[pwin->wi]);  /* Atualiza a janela atual */
    refresh(); /* Atualiza tela principal */

	return;
}

/* ------------------------------------------------------------------------- */
/* funcao responsavel por adicionar um livro ao banco de dados */
void funcaoAdd(wins_t *pwin)
{
	
	wrefresh(pwin->w[pwin->wi]); /* Atualiza janela atual */
    refresh(); /* Atualiza tela principal */
	
    halfdelay(255);

    imprime_tela(pwin); // imprime tela base
    keypad(pwin->w[pwin->wi], true);

    int a = 1, select = 0, r, choice;
    FILE *file; //chama o arquivo Livros

    file = fopen ("livros.txt", "r");
    while(fgets(livro, 210, file) != NULL) //pega o numero de linha do arquivo Livros.
        a++;//atribui o numero de linha a variavel "a".
    fclose(file);

      memset(autorC,0,strlen(autorC));
      memset(tituloC,0,strlen(tituloC));
      memset(anoC,0,strlen(anoC));
      memset(localC,0,strlen(localC));
      memset(editoraC,0,strlen(editoraC));
      memset(edicaoC,0,strlen(edicaoC));
      memset(ISBNC,0,strlen(ISBNC));


      mvwhline(pwin->w[pwin->wi], 15, 1,'*',COLS-2); /* Linha de separacao da tela  */


      /* Bibtex fixa */
	  mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
  	  mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
  	  mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      mvwprintw(pwin->w[pwin->wi], 31, 2, "}");

      wrefresh(pwin->w[pwin->wi]);
      refresh();

    if(mensagem_status(*pwin, "Deseja adicionar um livro?", YESNO, "Sim", "Nao"))
    {
    /* Loop principal */
    while(1) 
    {

        for(r=0;r<=8;r++)
        {
            if(r == select)//caso vc mova o cursor a opcao muda de cor
            wattron(pwin->w[pwin->wi], A_REVERSE);
            mvwprintw(pwin->w[pwin->wi], r+6, 2, "%s\n",opcoes[r]);
            wattroff(pwin->w[pwin->wi], A_REVERSE);//tira o destaque
            box(pwin->w[pwin->wi], 0, 0);
            wrefresh(pwin->w[pwin->wi]);
            refresh();
        }

                choice = wgetch(pwin->w[pwin->wi]);//pega input do usuario.
                switch(choice){
                case KEY_UP:
                    select--;
                    if(select == -1){
                        select = 7;
                    }
                        break;
                case KEY_DOWN:
                    select++;
                    if(select == 8){
                        select = 0;
                    }
                        break;
               default:
                    break;
            }

        if(choice == 10)
        {
            if(select == 0){
                for(r = 0; r < 40; r++)//incia um loop no qual se pode digitar na tela.
                {
                    autor[r] = wgetch(pwin->w[pwin->wi]); //pega o input do usuario e atribui ele a string determinada.
                    
                    mvwprintw(pwin->w[pwin->wi], 6, 10+r,"%c", autor[r]);//printa tal caracter da string.
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(autor[r] == ';')
						{
                        if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente.", STOK, "Ok", NULL))
                        {
                          memset(autor,0,strlen(autor)); 
                    	/*Bibtex fixa*/
				        mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
          				mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 31, 2, "}");

      				   	wrefresh(pwin->w[pwin->wi]);
      					refresh();
                        
                        break;
   	  					}
                        }
 
                    if(autor[r] == '\n') // mecanismo de parada do loop. caso se coloque "."no final.
                    {
                      strncpy(autorC, autor, strlen(autor)-1); //copia a string digitada a a copia da mesma menos o mecanismo de parada.
					            memset(autor,0,strlen(autor));
                      break;
                    }
                
                    mvwprintw(pwin->w[pwin->wi], 22, 15+r,"%c", autor[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
				}
            }
            if(select == 1){
                 for(r = 0; r < 40; r++){
                    titulo[r] = wgetch(pwin->w[pwin->wi]);
                    mvwprintw(pwin->w[pwin->wi], 7, 11+r,"%c", titulo[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(titulo[r] == ';')
						{
      				 if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente", STOK, "Ok", NULL))
                        {
                          memset(titulo,0,strlen(titulo));
						/*Bibtex fixa*/
          				mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
         	 			mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 31, 2, "}");

      					wrefresh(pwin->w[pwin->wi]);
      					refresh();
				
						break;
						}
                        }

                    if(titulo[r] == '\n' )
                    {
                        strncpy(tituloC, titulo, strlen(titulo)-1);
                        memset(titulo,0,strlen(titulo));
                        break;
                    }   
				    
                    mvwprintw(pwin->w[pwin->wi], 24, 15+r,"%c", titulo[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                   
                }
            }

            if(select == 2){
                 for(r = 0; r < 40; r++){
                    ano[r] = wgetch(pwin->w[pwin->wi]);
                    
                    mvwprintw(pwin->w[pwin->wi], 8, 8+r,"%c", ano[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(ano[r] == ';')
						{
                         if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente.", STOK, "Ok", NULL))
                        {
                          memset(ano,0,strlen(ano));
						/*Bibtex fixa*/
          				mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
         	 			mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 31, 2, "}");
      					
						wrefresh(pwin->w[pwin->wi]);
      					refresh();
                        
                        break;    
						}
                        }

                    if(ano[r] == '\n' )
                    {
                        strncpy(anoC, ano, strlen(ano)-1);
                        memset(ano,0,strlen(ano));
                        break;
                    }
                    mvwprintw(pwin->w[pwin->wi], 26, 15+r,"%c", ano[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                }
            }
            if(select == 3){
                 for(r = 0; r < 40; r++){
                    editora[r] = wgetch(pwin->w[pwin->wi]);
                    
                    mvwprintw(pwin->w[pwin->wi], 9, 12+r,"%c", editora[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(editora[r] == ';')
						{
                       if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente", STOK, "Ok", NULL))
                        {
                          memset(editora,0,strlen(editora));

						/*Bibtex fixa*/
          				mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
         	 			mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 31, 2, "}");
      					
						wrefresh(pwin->w[pwin->wi]);
      					refresh();

						 break;
						}
                        }

                    if(editora[r] == '\n' )
                    {
                        strncpy(editoraC, editora, strlen(editora)-1);
                        memset(editora,0,strlen(editora));
                        
                        break;
                    }
                    mvwprintw(pwin->w[pwin->wi], 28, 15+r,"%c", editora[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                }
            }

            if(select == 4){
                 for(r = 0; r < 40; r++){
                    local[r] = wgetch(pwin->w[pwin->wi]);
                    
                    mvwprintw(pwin->w[pwin->wi], 10, 9+r,"%c", local[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(local[r] == ';')
						{ 
                         if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente.", STOK, "OK", NULL))
                         {
                          memset(local,0,strlen(local));

						/*Bibtex fixa*/
          				mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
         	 			mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 31, 2, "}");
      					
						wrefresh(pwin->w[pwin->wi]);
      					refresh();

  					 	 break;
						 }
                        }

                    if(local[r] == '\n')
                    { 
                        strncpy(localC, local, strlen(local)-1);
                        memset(local,0,strlen(local));
                        
                        break;
                    }
                    mvwprintw(pwin->w[pwin->wi], 30, 15+r,"%c", local[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                }
            }

             if(select == 5){
                 for(r = 0; r < 40; r++){
                    edicao[r] = wgetch(pwin->w[pwin->wi]);
                    
                    mvwprintw(pwin->w[pwin->wi], 11, 9+r,"%c", edicao[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(edicao[r] == ';')
						{
                         if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente.", STOK, "OK", NULL))
                        {
                          memset(edicao,0,strlen(edicao));
						/*Bibtex fixa*/
          				mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
         	 			mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					mvwprintw(pwin->w[pwin->wi], 31, 2, "}");
      					
						wrefresh(pwin->w[pwin->wi]);
      					refresh();

						 break;
						}
                        }

                    if(edicao[r] == '\n' )
                    {
                        strncpy(edicaoC, edicao, strlen(edicao)-1);
                        memset(edicao,0,strlen(edicao));
                        
                        break;
                    }
                }
            }

            if(select == 6){
                 for(r = 0; r < 40; r++){
                    ISBN[r] = wgetch(pwin->w[pwin->wi]);
                    
                    mvwprintw(pwin->w[pwin->wi], 12, 9+r,"%c", ISBN[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    refresh();
                    
                    	if(ISBN[r] == ';')
						{
                            if(mensagem_status(*pwin, "Nao pode haver ';', favor digite novamente.", STOK, "Ok", NULL))
                            {
                                memset(ISBN,0,strlen(ISBN));   
						        /*Bibtex fixa*/
          				        mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
         	 			        mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
          				        mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
      					        mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
      					        mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
      					        mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
      					        mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
      					        mvwprintw(pwin->w[pwin->wi], 31, 2, "}");
      					
						        wrefresh(pwin->w[pwin->wi]);
      					        refresh();

						        break;
						    }	                    
                        } 
					  if(ISBN[r] == '\n' )
                      {
                        strncpy(ISBNC, ISBN, strlen(ISBN)-1);
                        memset(ISBN,0,strlen(ISBN));
                        
                        break;
                      }
                }
            }

           if(select == 7){
             if(mensagem_status(*pwin, "Certeza que quer perder as alteracoes? ", YESNO, "SIM" , "NAO"))
                break;
            }

          }//if pricipal (enter)

        if(choice == KEY_F(4))                             //f4 para aparecer o status
        {

        if(autorC[1] != 0)
        {
          o++;
        }
        if(tituloC[1] != 0)
        {
          o++;
        }
        if(editoraC[1] != 0)
        {
          o++;
        }
        if(localC[1] != 0)
        {
          o++;
        }
        if(anoC[1] != 0)
        {
          o++;
        }

        if(o>=5)
        {
            if(mensagem_status(*pwin, "Deseja salvar as alteracoes? ", YESNO, "SIM" , "NAO"))  //mensagem que a barra status ira imprimir e pegar o input
                        {
                      file=fopen("livros.txt", "a");      //verifica se existe o arquivo
                      if(file == NULL)
                      {                                   //caso nao ache o arquivo ele sai do loop
                        wrefresh(pwin->w[pwin->wi]);
                        break;
                      }
                      else{

                        memset(codigo,0,strlen(codigo));
                        memset(dados,0,strlen(dados));

                        if(a>9)                            // if que transforma um numero inteiro em um caracter da tabela ascii 
                        {
                        c = a/10;
                        v = a%10;

                        h[0]=(int)c+48;
                        j[0]= (int)v+48;

                        strcpy(codigo,h);
                        strcat(codigo,j);
                        }

                        else if(a <= 9){
                        h[0]= (int)a+48;
                        strcpy(codigo, h);
                        }

                        //adiciona os dados no arquivo livros.txt com divisão de ";"

                        fprintf(file, "%s;", codigo);
                        fprintf(file, "%s;", autorC);
                        fprintf(file, "%s;", tituloC);
                        fprintf(file, "%s;", editoraC);
                        fprintf(file, "%s;", localC);
                        fprintf(file, "%s;", anoC);
                        fprintf(file, "%s;", edicaoC);
                        fprintf(file, "%s\n", ISBNC);
                        wrefresh(pwin->w[pwin->wi]);
                        refresh();
                        a = a + 1; //para add mais de 1 livro de uma vez
                    }
                    fclose(file);
                    wrefresh(pwin->w[pwin->wi]);                   
                    refresh();
                   
                  //bibtex fixa
                  mvwprintw(pwin->w[pwin->wi], 17, 2, "BibTeX Entry:");
                  mvwprintw(pwin->w[pwin->wi], 20, 2, "@book{");
                  mvwprintw(pwin->w[pwin->wi], 22, 4, "title =                                               ");
                  mvwprintw(pwin->w[pwin->wi], 24, 4, "author =                                              ");
                  mvwprintw(pwin->w[pwin->wi], 26, 4, "year =                                                ");
                  mvwprintw(pwin->w[pwin->wi], 28, 4, "publisher =                                           ");
                  mvwprintw(pwin->w[pwin->wi], 30, 4, "adress =                                              ");
                  mvwprintw(pwin->w[pwin->wi], 31, 2, "}");

                  wrefresh(pwin->w[pwin->wi]);
                  refresh();
 
                    
                    
                    break;
                    } 
                    else break;
        }
        if(o<5)
        {
          o=0;
          if(mensagem_status(*pwin, "Ainda faltam informacoes obrigatorias, favor continue", STOK, "C" , NULL)){}
        }
     }
    }              //fim do while.
    }
    halfdelay(2);
    return;
}//fim da funcaoAdd.

/*------------------------------------------------------------------------------------------------------------*/
/* funcao responsavel por buscar um livro no banco de dados */
void funcaoBuscar(wins_t *pwin)
{
    halfdelay(255);
    imprime_tela(pwin); // imprime tela base
    
    FILE *file;         /* aequivo banco de dados */
    
    char livro[626];    /* livro do arquivo .txt*/
    char lista[30][626];
    char *s;            /* igualdade entre os fragmentos */
    char *token;        /* fagmento do livro a ser comparado */
    char *token2;       /* fagmento da palavra a ser comparada */
    char *base;         /* copia do livro a ser analisado*/
    char *base2;        /* copia das palavras a serem procuradas */
    char *lixo;         /* armazena o codigo */
    
    int kpress;
    int contador = 0;   /* contador pra procura com AND */
    int r;    
    int aba = 0;
    int manipular_aba;
    int escolha;        /* escolha entre OR e AND*/
    int quantidade = 0;
    int i = 0;
    
    memset(dadosC,0,strlen(dadosC));
    memset(autorC,0,strlen(autorC));
    memset(tituloC,0,strlen(tituloC));
    memset(anoC,0,strlen(anoC));
    memset(localC,0,strlen(localC));
    memset(editoraC,0,strlen(editoraC));
    memset(edicaoC,0,strlen(edicaoC));
    memset(ISBNC,0,strlen(ISBNC));
    memset(autor,0,strlen(autor));
    memset(titulo,0,strlen(titulo));
    //memset(ano,0,strlen(ano));
    memset(local,0,strlen(local));
    memset(editora,0,strlen(editora));
    //memset(edicao,0,strlen(edicao));
    memset(ISBN,0,strlen(ISBN));

    file = fopen("livros.txt","r");
    if(file == NULL)
    {
        mvwprintw(pwin->w[pwin->wi], 11, 1,"ERRO arquivo não encontrado");
        exit(0);
    }
    keypad(pwin->w[pwin->wi], true);
    mvwhline(pwin->w[pwin->wi], LINES/2, 1,'*',COLS-2);

    while(1)
    {
        for(int j = 0; j<8 ; j++ )
            if(j == contador)
            {
                wattron(pwin->w[pwin->wi], A_REVERSE);
                mvwprintw(pwin->w[pwin->wi], 6 + j, 2,"%s", opcoesC[j]);
                wattroff(pwin->w[pwin->wi], A_REVERSE);
            }
            else
                mvwprintw(pwin->w[pwin->wi], 6 + j, 2,"%s", opcoesC[j]);
        wrefresh(pwin->w[pwin->wi]);
        kpress = wgetch(pwin->w[pwin->wi]);
        switch(kpress)
        {
            case KEY_DOWN:
            {
                contador ++;
                if(contador == 8)
                    contador = 7;
                break;
            }
            case KEY_UP:
            {
                contador --;
                if(contador == -1)
                    contador = 0;
                break;
            }
            default:
                break;
        }
        if(kpress == '\n')
        {
            if(contador == 0)
            {
                for(r = 0; r < 40; r++)
                {
                    autores[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],6, 2 + 11 + r,"%c", autores[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(autores[r] == '\n')
                    {
                        strncpy(autorC, autores, strlen(autores)-1);
                        break;
                    }
                }
            }
            if(contador == 1)
            {
                for(r = 0; r < 40; r++)
                {
                    titulo[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],7, 2+ 11 + r,"%c", titulo[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(titulo[r] == '\n') 
                    {
                        strncpy(tituloC, titulo, strlen(titulo)-1);
                        break;
                    }
                }
            }
            if(contador == 2)
            {
                for(r = 0; r < 40; r++)
                {
                    editora[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],8, 2 + 11 + r,"%c", editora[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(editora[r] == '\n') 
                    {
                        strncpy(editoraC, editora, strlen(editora)-1);
                        break;
                    }
                }
            }
            if(contador == 3)
            {
                for(r = 0; r < 40; r++)
                {
                    local[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],9, 2 + 11 + r,"%c", local[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(local[r] == '\n') 
                    {
                        strncpy(localC, local, strlen(local)-1);
                        break;
                    }
                }
            }
            if(contador == 4)
            {
                for(r = 0; r < 40; r++)
                {
                    ano[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],10, 2 + 11 + r,"%c", ano[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(ano[r] == '\n') 
                    {
                        strncpy(anoC, ano, strlen(ano)-1);
                        break;
                    }
                }
            }
            if(contador == 5)
            {
                for(r = 0; r < 40; r++)
                {
                    edicao[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],11, 2 + 11 + r,"%c", edicao[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(edicao[r] == '\n') 
                    {
                        strncpy(edicaoC, edicao, strlen(edicao)-1);
                        break;
                    }
                }
            }
            if(contador == 6)
            {
                for(r = 0; r < 40; r++)
                {
                    ISBN[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],12, 2 + 11 + r,"%c", ISBN[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(ISBN[r] == '\n') 
                    {
                        strncpy(ISBNC, ISBN, strlen(ISBN)-1);
                        break;
                    }
                }
            }
            if(contador == 7)
                break;
        }
        if(kpress == KEY_F(4))
        {
            strcat(dadosC, autorC);
            strcat(dadosC,";");
            strcat(dadosC,tituloC);
            strcat(dadosC,";");
            strcat(dadosC,editoraC);
            strcat(dadosC,";");
            strcat(dadosC,localC);
            strcat(dadosC,";");
            strcat(dadosC,anoC);
            strcat(dadosC,";");
            strcat(dadosC,edicaoC);
            strcat(dadosC,";");
            strcat(dadosC,ISBNC);
            strcat(dadosC,";");
            
            memset(palavra2,0,strlen(palavra2));
            strcpy(palavra2, dadosC);
            

    wrefresh(pwin->w[pwin->wi]);
    
    escolha = mensagem_status(*pwin, "Escolha o tipo de pesquisa:", YESNO, "OR", "AND");
    wrefresh(pwin->w[pwin->wi]);
    while(fgets(livro,626,file) != NULL)
    {
        base = strdup(livro);
        base2 = strdup(palavra2);
        lixo = strsep(&base ,";");
        
        while((token = strsep(&base,";")) && (token2 = strsep(&base2,";")) != NULL)
        {
            if(strcmp(lixo,"D") == 0)
                break;
            if(escolha == 0) /* opcao AND */
            {
                if((token && (strcmp(token,"\0") > 0)) && (token2 && (strcmp(token2,"\0") > 1)))
                {
                    s = stristr(token, token2);
                    if(s == NULL)
                        break;
                }
                quantidade++;
                if(quantidade == 7)
                {
                    strcpy(lista[i], livro);
                    i++;
                }
            }
            if(escolha == 1) /* opcao OR */
            {
                if((token && (strcmp(token,"\0") > 0)) && (token2 && (strcmp(token2,"\0") > 0)))
                {
                    s = stristr(token, token2);
                    if(s)
                    {
                        strcpy(lista[i], livro);
                        i ++;
                        break;
                    }
                }
            }
        }
        quantidade = 0;
        if(i == 29)
            break;
    }
    fclose(file);

    if(escolha)
        mvwprintw(pwin->w[pwin->wi], (LINES/2)+ 1 , 1, "Busca por conectivo OR | <- -> move as abas");
    else
        mvwprintw(pwin->w[pwin->wi], (LINES/2)+ 1 , 1, "Busca por conectivo  AND | <- -> move as abas");
    mvwprintw(pwin->w[pwin->wi], (LINES/2)+ 2 , 1, "Livros encontrados: %i", i);
    wrefresh(pwin->w[pwin->wi]);
    refresh();
    if(i)
    {
        do{
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 4, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 5, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 6, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 7, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 8, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 9, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 10, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 11, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 12, 1,' ',COLS-2);
            mvwhline(pwin->w[pwin->wi], (LINES/2) + 13, 1,' ',COLS-2); 
            if((i - aba) > 10)
                manipular_aba = 10;
            else
            {
                manipular_aba = (i - aba);
                if(quantidade > (manipular_aba - 1))
                    quantidade = manipular_aba - 1;
            }
            for(int j = 0; j<manipular_aba ; j++ )
                if(j == quantidade)
                {
                    wattron(pwin->w[pwin->wi], A_REVERSE);
                    mvwprintw(pwin->w[pwin->wi], (LINES/2) + 4 + j, 1,"%s", lista[j+aba], A_REVERSE);
                    wattroff(pwin->w[pwin->wi], A_REVERSE);
                }
                else
                    mvwprintw(pwin->w[pwin->wi], (LINES/2) + 4 + j, 1,"%s", lista[j+aba]);
            wrefresh(pwin->w[pwin->wi]);
            kpress = getch();
            switch(kpress)
            {
                case KEY_RIGHT:
                {
                    if((aba + 10) < i)
                        aba +=10;
                    break;
                }
                case KEY_LEFT:
                {
                    aba -= 10;
                    if(aba < 0)
                        aba=0;
                    break;
                }
                case KEY_DOWN:
                {
                    quantidade ++;
                    if(manipular_aba == 10)
                    {
                        if(quantidade == 10)
                            quantidade = 9;
                    }
                    else
                    {
                        if(quantidade >= manipular_aba)
                            quantidade = manipular_aba - 1;
                    }
                    break;
                }
                case KEY_UP:
                {
                    quantidade --;
                    if(quantidade == -1)
                        quantidade = 0;
                    break;
                }
                default:
                    break;
            }
            napms(30);
        }while(kpress != '\n');
        
        mvwprintw(pwin->w[pwin->wi], STLINE - 2, 1,"escolhido : %s", lista[quantidade+aba]);
        wrefresh(pwin->w[pwin->wi]);
        escolha = mensagem_status(*pwin, "Opcoes :", YESNO, "ALTERAR", "DELETAR");
        if(escolha == 1) /* alterar */
        {
            pwin->wi = 3;
            funcaoalterar(pwin, lista[quantidade]);
        }
        if(escolha == 0) /* deletar */
        {
            pwin->wi = 4;
            funcaodeletar(pwin, lista[quantidade]);
        }
    } 
            break;
        
        } 
        wrefresh(pwin->w[pwin->wi]);
        napms(30);
    }
    wclear(pwin->w[pwin->wi]);
    imprime_tela(pwin);
    
    return;
}

/* --------------------------------------------------------------------------- */
/* Funcao responsavel por alterar um livro no banco de dados */
void funcaoalterar(wins_t *pwin, char livro[626])
{
    IFDEBUG("funcaoalterar()");
    imprime_tela(pwin); //imprime tela base
    FILE *file;
    FILE *copia;
    char livrofile[626];
    char palavra2[626];
    char alterado[626]; // armazena o a linha alterada
    char *basefile;
    char *base;
    char *token;
    char *lixo;
    char *s;
    char *PV = ";";     // variavel pra colocar junto ao codigo quando colocar-lo de volta
    int escolha;
    int kpress;
    int contador = 0;   /* contador pra procura com AND */
    int r;    
    
    memset(dadosC,0,strlen(dadosC));
    memset(autorC,0,strlen(autorC));
    memset(tituloC,0,strlen(tituloC));
    memset(anoC,0,strlen(anoC));
    memset(localC,0,strlen(localC));
    memset(editoraC,0,strlen(editoraC));
    memset(edicaoC,0,strlen(edicaoC));
    memset(ISBNC,0,strlen(ISBNC));
    memset(autores,0,strlen(autores));
    memset(titulo,0,strlen(titulo));
    //memset(ano,0,strlen(ano));
    memset(local,0,strlen(local));
    memset(editora,0,strlen(editora));
    //memset(edicao,0,strlen(edicao));
    memset(ISBN,0,strlen(ISBN));
    memset(palavra2,0,strlen(palavra2));
    
    keypad(pwin->w[pwin->wi], true);
    base = strdup(livro);
    lixo = strsep(&base ,";");

    // imprime base da tela de alteracao de livro
    mvwprintw(pwin->w[pwin->wi],  5, 1, "Dados originais:");
    token = strsep(&base ,";");
    mvwprintw(pwin->w[pwin->wi],  6, 1, " Título: %s",token);
    token = strsep(&base ,";");
    mvwprintw(pwin->w[pwin->wi],  7, 1, "  Autor: %s",token);
    token = strsep(&base ,";");
    mvwprintw(pwin->w[pwin->wi],  8, 1, "    Ano: %s",token);
    token = strsep(&base ,";");
    mvwprintw(pwin->w[pwin->wi],  9, 1, "Editora: %s",token);
    token = strsep(&base ,";");
    mvwprintw(pwin->w[pwin->wi], 10, 1, "  Local: %s",token);
    token = strsep(&base ,";");
    mvwprintw(pwin->w[pwin->wi], 11, 1, " Edição: %s",token);
    mvwprintw(pwin->w[pwin->wi], 12, 1, "   ISBN: %s",base);
    
    mvwhline(pwin->w[pwin->wi], LINES/2, 1,'*',COLS-2);
    
    /* ---------------------------------------------- */ 
    /*    entrada da funcao da linha para palavra2    */ 
    /* isto é apenas uma simulação para testar a funcao*/ 
    while(1)
    {
        for(int j = 0; j<8 ; j++ )
            if(j == contador)
            {
                wattron(pwin->w[pwin->wi], A_REVERSE);
                mvwprintw(pwin->w[pwin->wi], (LINES/2)+1+ j, 2,"%s", opcoesC[j]);
                wattroff(pwin->w[pwin->wi], A_REVERSE);
            }
            else
                mvwprintw(pwin->w[pwin->wi], (LINES/2)+1 + j, 2,"%s", opcoesC[j]);
        wrefresh(pwin->w[pwin->wi]);
        kpress = wgetch(pwin->w[pwin->wi]);
        switch(kpress)
        {
            case KEY_DOWN:
            {
                contador ++;
                if(contador == 8)
                    contador = 7;
                break;
            }
            case KEY_UP:
            {
                contador --;
                if(contador == -1)
                    contador = 0;
                break;
            }
            default:
                break;
        }
        if(kpress == '\n')
        {
            if(contador == 0)
            {
                for(r = 0; r < 40; r++)
                {
                    autores[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+1, 10+r,"%c", autores[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(autores[r] == '\n')
                    {
                        strncpy(autorC, autores, strlen(autores)-1);
                        break;
                    }
                }
            }
            if(contador == 1)
            {
                for(r = 0; r < 40; r++)
                {
                    titulo[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+2, 10+r,"%c", titulo[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(titulo[r] == '\n') 
                    {
                        strncpy(tituloC, titulo, strlen(titulo)-1);
                        break;
                    }
                }
            }
            if(contador == 2)
            {
                for(r = 0; r < 40; r++)
                {
                    editora[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+3 , 10+r,"%c", editora[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(editora[r] == '\n') 
                    {
                        strncpy(editoraC, editora, strlen(editora)-1);
                        break;
                    }
                }
            }
            if(contador == 3)
            {
                for(r = 0; r < 40; r++)
                {
                    local[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+4, 10+r,"%c", local[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(local[r] == '\n') 
                    {
                        strncpy(localC, local, strlen(local)-1);
                        break;
                    }
                }
            }
            if(contador == 4)
            {
                for(r = 0; r < 40; r++)
                {
                    ano[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+5, 10+r,"%c", ano[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(ano[r] == '\n') 
                    {
                        strncpy(anoC, ano, strlen(ano)-1);
                        break;
                    }
                }
            }
            if(contador == 5)
            {
                for(r = 0; r < 40; r++)
                {
                    edicao[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+6, 10+r,"%c", edicao[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(edicao[r] == '\n') 
                    {
                        strncpy(edicaoC, edicao, strlen(edicao)-1);
                        break;
                    }
                }
            }
            if(contador == 6)
            {
                for(r = 0; r < 40; r++)
                {
                    ISBN[r] = getch();
                    mvwprintw(pwin->w[pwin->wi],(LINES/2)+7, 10+r,"%c", ISBN[r]);
                    wrefresh(pwin->w[pwin->wi]);
                    if(ISBN[r] == '\n') 
                    {
                        strncpy(ISBNC, ISBN, strlen(ISBN)-1);
                        break;
                    }
                }
            }
            if(contador == 7)
                break;
        }
        if(kpress == KEY_F(4))
        {
            strcat(dadosC, autorC);
            strcat(dadosC,";");
            strcat(dadosC,tituloC);
            strcat(dadosC,";");
            strcat(dadosC,editoraC);
            strcat(dadosC,";");
            strcat(dadosC,localC);
            strcat(dadosC,";");
            strcat(dadosC,anoC);
            strcat(dadosC,";");
            strcat(dadosC,edicaoC);
            strcat(dadosC,";");
            strcat(dadosC,ISBNC);
            strcpy(palavra2,dadosC);
            break;
        
        } 
        wrefresh(pwin->w[pwin->wi]);
        napms(30);
    }
    
    /* ---------------------------------------------- */        
    /* ---------------------------------------------- */ 
    /* ---------------------------------------------- */ 
    
    escolha = mensagem_status(*pwin, "Confirma alteração?", YESNO, "YES", "NO");
    if(escolha)
    {
        file = fopen("livros.txt","a+");
        copia = fopen("copia.txt","w");
        if(file == NULL)
        {
            printf("ERRO arquivo não encontrado\n");
            exit(0);
        }
        base = strdup(livro);
        lixo = strsep(&base ,";");
        while(fgets(livrofile,626,file) != NULL)
        {
            basefile = strdup(livrofile);
            lixo = strsep(&basefile ,";");
            s = stristr(basefile , base); 
            if(s)
            {
                strcat(strcpy(alterado, lixo), PV);
                strcat(alterado, palavra2);
                fprintf(copia, "%s\n", alterado);
            }
            else 
                fprintf(copia, "%s", livrofile);
        }
        fclose(file);
        fclose(copia);
        rename("copia.txt","livros.txt");
    }
    wrefresh(pwin->w[pwin->wi]);
    
    return;
}

/* --------------------------------------------------------------------------- */
/* Funcao responsavel por deletar um livro do banco de dados*/
void funcaodeletar(wins_t *pwin, char livro[626])
{
    imprime_tela(pwin); //imprime tela base
    FILE *file;
    FILE *copia;
    char livrofile[626];
    char *s;
    char *lixo;
    char *base;
    int tamanho;
    int tamanho2;
    int escolha;
    
    escolha = mensagem_status(*pwin, "Deseja mesmo deletar este livro?", YESNO, "YES", "NO");
    if(escolha)
    {
        file = fopen("livros.txt","a+");
        copia = fopen("copia.txt","w");
        if(file == NULL)
        {
            printf("ERRO arquivo não encontrado\n");
            exit(0);
        }
        while(fgets(livrofile,626,file) != NULL)
        {
            s = stristr(livrofile , livro); 
            if(s)
            {
                tamanho = strlen(s);
                tamanho2 = strlen(livrofile);
                if(tamanho == tamanho2)
                {
                    base = strdup(livrofile);
                    lixo = strsep(&base,";");
                    lixo = strdup("D");
                    fprintf(copia, "%s;%s",lixo , base);
                }
                else
                    fprintf(copia, "%s", livrofile);
            }
            else
                fprintf(copia, "%s", livrofile);
        }
        fclose(file);
        fclose(copia);
        rename("copia.txt","livros.txt");
    }
    pwin->wi = 0;
    funcao_help(pwin); // imprime a tela help

    return;
}

/* --------------------------------------------------------------------------- */
/* Funcao reponsavel por aceitar caracteres maiusculos e minusculos */
char *stristr(const char *String, const char *Pattern)
{
      char *pptr, *sptr, *start;
      uint  slen, plen;

      for (start = (char *)String,
           pptr  = (char *)Pattern,
           slen  = strlen(String),
           plen  = strlen(Pattern);

           
           /* Enquanto o tamanho da string for menor que o tamanho normal */

           slen >= plen;

           start++, slen--)
      {
            /* Encontra o comeco do padrao na string */
            
            while (toupper(*start) != toupper(*Pattern))
            {
                  start++;
                  slen--;

                  /* if pattern longer than string */

                  if (slen < plen)
                        return(NULL);
            }

            sptr = start;
            pptr = (char *)Pattern;

            while (toupper(*sptr) == toupper(*pptr))
            {
                  sptr++;
                  pptr++;

                  /* Se o fim do padrao for encontrado, entao o padrao foi encontrado */
                  
                  if ('\0' == *pptr)
                        return (start);
            }
      }
      return(NULL);
}

/* ------------------------------------------------------------------------- */
/* Funcao responsavel por centralizar mensagem na tela */
int centralisar(int cl, char*msg)
{
    int sl = strlen(msg); // calcula o tamanho da mensagem
    return (cl -sl)/2;    // retorna um valor int da coluna centralisada com a palavra centralisada
}

/* ------------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */

