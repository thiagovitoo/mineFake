#include "../headers/item.h"

void loadItens(Item item[NUM_ITENS], Texturas textura) {
    /*
    Tipos:
    1- Infinito
    2- Uso instantâneo
    3- Consumível
    */

    item[0] = criaItem("Espada de Diamante", "Aplica um poderoso golpe que elimina inimigos no bloco a frente do jogador", 1, 0, textura.interface[10]);
    item[1] = criaItem("Armadura de Diamante", "Tem 30% de chance de neutralizar um ataque", 1, 1, textura.interface[0]);
    item[2] = criaItem("Balde de Água", "Conhecido por sua incrível utilidade para se fazer MLGs, permite ativar o portal do Aether e passar de fase", 2, 2, textura.interface[12]);
    item[3] = criaItem("Maça Dourada Encantada", "Concede 3 vidas", 3, 3, textura.interface[13]);
    item[4] = criaItem("Poção de vida", "Recupera uma vida perdida", 3, 4, textura.interface[14]);
    item[5] = criaItem("Cobre", "Metal, concede 50 pontos para o jogador", 2, 5, textura.interface[4]);
    item[6] = criaItem("Ferro", "Metal, concede 100 pontos para o jogador", 2, 6, textura.interface[5]);
    item[7] = criaItem("Ouro", "Metal precioso, concede 250 pontos para o jogador", 2, 7, textura.interface[6]);
    item[8] = criaItem("Diamante", "Joia, concede 500 pontos para o jogador", 2, 8, textura.interface[7]);
    item[9] = criaItem("Esmeralda", "Joia Rara, concede 1000 pontos para o jogador", 2, 9, textura.interface[8]);
    item[10] = criaItem("TNT", "Explode, tira uma vida do jogador", 2, 10, textura.interface[9]);
}

Item criaItem(char nome[TAM_NOME_ITEM], char descricao[TAM_DESC], int tipo, int ID, Texture2D textura) {
    Item item;
    strcpy(item.nome, nome);
    strcpy(item.descricao, descricao);
    item.tipo = tipo;
    item.ID = ID;
    item.textura = textura;
    return item;
}

Item getLevelItem(Mapa *mapa, int fase, Item itens[NUM_ITENS]) {
    Item item;
    if (fase == 1) {
        item = itens[0];
        mapa->jogador.temEspada = true;
    } else if (fase == 2) {
        item = itens[1];
        mapa->jogador.temArmadura = true;
    } else if (fase == 3) {
        item = itens[3];
        mapa->jogador.macas += 1;
    }
    return item;
}

Item getKey(Item itens[NUM_ITENS]) {
    return itens[4];
}

Item getRandomItem(Mapa *mapa, int fase, Item item[NUM_ITENS]) {
    int n = GetRandomValue(1, 20);
    if (fase == 1) {
        switch (n) {
            case 1 ... 4:
                mapa->jogador.pocoes += 1;
                return item[4];
                break;
            case 5 ... 12:
                mapa->jogador.pontos += 50;
                return item[5];
                break;
            case 13 ... 17:
                mapa->jogador.pontos += 100;
                return item[6];
                break;
            case 18 ... 20:
                mapa->jogador.pontos += 250;
                return item[7];
                break;

        }
    }
    if (fase == 2) {
        switch (n) {
            case 1 ... 4:
                mapa->jogador.pocoes += 1;
                return item[4];
                break;
            case 5 ... 11:
                mapa->jogador.pontos += 50;
                return item[5];
                break;
            case 12 ... 15:
                mapa->jogador.pontos += 100;
                return item[6];
                break;
            case 16 ... 18:
                mapa->jogador.pontos += 250;
                return item[7];
                break;
            case 19 ... 20:
                mapa->jogador.pontos += 500;
                return item[8];
                break;
        }
    }
    if (fase == 3) {
        switch (n) {
            case 1 ... 4:
                mapa->jogador.pocoes += 1;
                return item[4];
                break;
            case 5:
                mapa->jogador.macas += 1;
                return item[3];
                break;
            case 6 ... 10:
                mapa->jogador.pontos += 50;
                return item[5];
                break;
            case 11 ... 14:
                mapa->jogador.pontos += 100;
                return item[6];
                break;
            case 15 ... 17:
                mapa->jogador.pontos += 250;
                return item[7];
                break;
            case 18 ... 19:
                mapa->jogador.pontos += 500;
                return item[8];
                break;
            case 20:
                mapa->jogador.pontos += 1000;
                return item[9];
                break;
        }
    }
}

void useItem(Mapa *mapa, Item item, Sound som[NUM_SONS]) {
    if (item.tipo == 3) {
        switch (item.ID) {
            case 3: //maça
                if (mapa->jogador.macas > 0) {
                    PlaySound(som[8]);
                    mapa->jogador.vidas += 3;
                    mapa->jogador.macas --;
                }
                break;
            case 4:
                if (mapa->jogador.pocoes > 0) {
                    PlaySound(som[9]);
                    mapa->jogador.vidas += 1;
                    mapa->jogador.pocoes --;
                }
                break;
        }
    }
}

//imprimeItem() {}
