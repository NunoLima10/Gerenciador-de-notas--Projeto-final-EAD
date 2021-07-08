/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/

#include"main.h"

alu criar_aluno(){// funcao usada para criar o aluno
  alu aluno1,aluno_novo;

  aluno1=fim_turma; //recebe o ultimo aluno

  if(inicio_turma==NULL){  //caso a turma esteja vazia

    aluno1=(alu)malloc(sizeof(struct alu)); //alu e ponteiro de struct alu
    if(aluno1==NULL){
       printf("\n...ERRO DE ALOCACAO...");
       exit(0);
    }
    aluno1->anterior=NULL;
    aluno1->seguinte=NULL;
    inicio_turma=aluno1;  //variavel global para o inicio da turma
    fim_turma=aluno1;    //variavel global para o fim da turma
    return aluno1;
  }
  else{ //caso a turma nao esteja vazia

    aluno_novo=(alu)malloc(sizeof(struct alu));
    if(aluno_novo==NULL){
       printf(" \n...ERRO DE ALOCACAO...");
       exit(0);
    }
    aluno_novo->anterior=aluno1;    //ligacao entre o aluno novo com o ultimo aluno
    aluno1->seguinte=aluno_novo;    //ligacao entre o ultimo aluno com o aluno novo
    aluno_novo->seguinte=NULL;
    fim_turma=aluno_novo;           //o fim da turma passa a ser o aluno novo

  return aluno_novo;
  }

}

alu aluno_existe(int id){//funcao usada para procurar se o aluno existe com base no id
    alu aluno_procurado;

    aluno_procurado=inicio_turma;

    while(aluno_procurado!=NULL){
        if(aluno_procurado->numero==id) break;
        aluno_procurado=aluno_procurado->seguinte;
    }

    return aluno_procurado; //caso nao encontre retorna null (while parado em Null)

    }

alu aluno_existe_nome(char info_nome[20]){//funcao usada para procurar se o aluno existe com base no nome
    alu aluno_procurado;
    aluno_procurado=inicio_turma;

    char nome[20];
    while(aluno_procurado!=NULL){
        strcpy(nome,aluno_procurado->nome);
        if(!(strcmp(nome,info_nome)))break;
        aluno_procurado=aluno_procurado->seguinte;
    }
    return aluno_procurado;         //caso nao encontre retorna null (while parado em Null)
}


void inserir(){//funcao usada para receber as informacoes dos alunos
    int info_id,info_nota;
    char info_nome[20];
    alu aluno,aluno_procurado;
    aluno=criar_aluno();

    while(1){
     printf("\n INSIRA O NUMERO(ID) : ");
     scanf("%d",&info_id);
     fflush(stdin);
     aluno_procurado=aluno_existe(info_id);  //procura se o aluno existe com o id incerido

     if((info_id>0)&&(info_id<max_id)){
        if(aluno_procurado==NULL){
            break;
        }
         else printf("\n O ALUNO JA EXISTE\n");


        }else printf("\n Id Maximo entre 1 a %d",max_id);}


    aluno->numero=info_id;
        while(1){
        printf("\n INSIRA O NOME: ");
        fgets(info_nome,20,stdin);
        fflush(stdin);
        aluno_procurado=aluno_existe_nome(info_nome); //procura se o aluno existe com o nome incerido

        if(aluno_procurado==NULL){
            break;
        }
        else{
            printf("\n O ALUNO JA EXISTE\n");
        }
   }

    strcpy(aluno->nome,info_nome);

    while(1){
        printf("\n INSIRA A NOTA: ");
        scanf("%d",&info_nota);
        fflush(stdin);

        if((info_nota>=0)&&(info_nota<=20)){
            break;
        }
        else{
            printf("\n A NOTA INSERIDA E INVALIDA\n");
        }
     }
    aluno->nota=info_nota;


}


void pedir_alunos(){//funcao para pedir a quantidade de alunos a ser incerida, aceita ate 10 alunos por vez
    int numero_pedidos,i;
    numero_pedidos=0;
    linha();
    printf("\t\t\tADICIONAR ALUNOS\n");
    linha();
    printf("\n INSIRA A QUANTIDADE DE ALUNOS A INSERIR (01) a (10): "); //para incerir  ate 10 alunos por vez

    while(1){
        scanf("%d",&numero_pedidos);
    if((numero_pedidos>0)&&(numero_pedidos<=10)){
        break;
    }
    else{
        printf("\n INVALIDO\n");
        printf("\n INSIRA NOVAMENTE: ");

    }
        fflush(stdin);
    }

    system("cls");

    for(i=0;i<numero_pedidos;i++){
        linha();
        printf("\t\t\tINSIRA AS INFORMACOES(%d)\n",i+1);
        linha();
        inserir();
    }

}

void exibir_aluno(alu aluno){//funcao usada para mostrar na tela as informacoes do aluno
    printf("\n ID: %d",aluno->numero);
    printf("\n NOME: %s",aluno->nome);
    printf(" NOTA: %d",aluno->nota);
}
int numero_alunos(){        //funcao para verificar o numero total de alunos existentes na turma
    alu aluno_procurado;
    int numero_total;

    aluno_procurado=inicio_turma;
    numero_total=0;

    while(aluno_procurado!=NULL){
        numero_total++;
        aluno_procurado=aluno_procurado->seguinte;
    }

    return numero_total;

}

