//
// Created by Thomaz on 12/03/2020.
//

#include "Dados.h"
#include <stdlib.h>


ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    int i2 = 0;
    int cont = 0;
    while (i2 < 8) {
        int i3 = 0;
        while (i3 < 8) {
            e->tab[i2][i3] = VAZIO;
            i3++;
        }
        i2++;
    }
    e -> ultima_jogada.coluna = 4;
    e -> ultima_jogada.linha = 4;
    e -> tab[0][0] = UM;
    e -> tab[7][7] = DOIS;
    e -> tab[4][4] = BRANCA;
    e -> jogador_atual = 1;
    e -> num_jogadas = 1;
    while(cont < 32){
        e->jogadas[cont].jogador1.linha = 4;
        e->jogadas[cont].jogador1.coluna = 4;
        e->jogadas[cont].jogador2.linha = 4;
        e->jogadas[cont].jogador2.coluna = 4;
        cont++;
    }
    return e;
}

char conv_c(int col){
    char c;
    c = 'a' + col;
    return c;
}

char conv_l(int lin){
    char c;
    c = '1' + lin;
    return c;
}

int obter_jogador_atual(ESTADO *estado){
    int x;
    x = estado->jogador_atual;
    return x;
}

int obter_numero_de_jogadas(ESTADO *estado){
    int y;
    y = estado->num_jogadas;
    return y;
}

CASA obter_estado_casa(ESTADO *e, COORDENADA c){
    int a;
    int b;
    b = e->ultima_jogada.linha;
    a = e->ultima_jogada.coluna;
    CASA casa;
    casa = e->tab[a][b];
    return casa;
}

CASA obter_casa(ESTADO *e, int y, int x){
    return e->tab[y][x];
}

int obter_coluna(ESTADO *e, int player, int jogada){
    if (player == 2)
        return e->jogadas[jogada].jogador2.coluna;
    else
        return e->jogadas[jogada].jogador1.coluna;
}

int obter_linha(ESTADO *e, int player, int jogada){
    if (player == 2)
        return e->jogadas[jogada].jogador2.linha;
    else
        return e->jogadas[jogada].jogador1.linha;
}

int obter_coluna_ult(ESTADO *e){
    return e->ultima_jogada.coluna;
}
int obter_linha_ult(ESTADO *e){
    return e->ultima_jogada.linha;
}

COORDENADA obter_coord_ult(ESTADO *e){
    return e->ultima_jogada;
}

COORDENADA obter_coord(ESTADO *e, int player, int jogada){
    if (player == 2)
        return  e->jogadas[jogada].jogador2;
    else
        return  e->jogadas[jogada].jogador1;
}

JOGADA obter_jogadas(ESTADO *e,int n){
    return e->jogadas[n];
}

int guardar_jogada1(ESTADO* e,int j, char cha, int l){
    int c;
    c = conv_c(cha);
    e->jogadas[j].jogador1.coluna = c;
    e->jogadas[j].jogador1.linha = l;
    return 0;
}

int guardar_jogada2(ESTADO* e,int j, char cha, int l){
    int c;
    c = conv_c(cha);
    e->jogadas[j].jogador2.coluna = c;
    e->jogadas[j].jogador2.linha = l;
    return 0;
}
