/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // usando sleep para pausar o tempo durante a execução
#include<locale.h>  //para colocar texto em portugues
#include<string.h> // tabalhar com strings

typedef struct alu{
   int numero;
   char nome[20];
   int nota;
   struct alu *anterior;
   struct alu *seguinte;
}*alu;      //tipo alu e um ponteiro da estrutura


//variaveis globais declaração
char elemento_grafico;  //elemento usado no grafico  "*"
int max_id;
alu inicio_turma;    //ponteiro para primeiro elemento da turma
alu fim_turma;       //ponteiro para ultimo elemento da turma


//procedimentos do menu
void menu_opecao(int opecao);
void linha();              //linha de iguais
void menu();
void enter();            //enter ao terminar as operacoes

//funções gerenciar turma

alu aluno_existe_nome(char info_nome[20]);  //funcao para procurar se aluno existe com base no nome
void exibir_aluno(alu aluno);               //procedimento para mostrar as informacoes dos alunos
alu aluno_existe(int id);                   //funcao para procurar se o aluno exite com base no id
void pedir_alunos();                        //procedimento para receber as informacoes dos alunos
alu criar_aluno();                          //funcao para criar um novo aluno
void inserir();                             //procedimento para inserir as informacoes dos alunos
int numero_alunos();

//funções clacificar notas

void mostrar_lista_aprovacao();             //procedimento para mostrar a lista de aprovados
void mostrar_melhor_aluno();                //procedimento para o melhor aluno
void mostrar_pior_aluno();                  //procedimento para o pior aluno
void mostrar_aprovados();                   //procedimento para a media da turma
void mostrar_media();
alu melhor_nota();
alu pior_nota();
int aprovados();
float media();
void grafico_notas();

//funções turma
void pesquisar_aluno();
void eliminar_aluno();
//void histograma();    outra opecao de histograma
void editar_eliminar();
void editar_aluno();
//funções quick_sort
void quick_sort( alu aluno_esd,alu aluno_dir);
alu _partition( alu aluno_esd,alu aluno_dir);
void mostrar_quick();


#endif // MAIN_H_INCLUDED
