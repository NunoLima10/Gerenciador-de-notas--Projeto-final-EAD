/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/
#include"main.h"

int main (){
    setlocale(LC_ALL, "Portuguese");

    //variaveis globais
    inicio_turma=NULL;
    fim_turma=NULL;
    max_id=1000;
    elemento_grafico='*';

    int opecao;

    while(1){

        system("cls");

        menu();
        printf(" OPERACAO A REALIZAR:");
        scanf("%d",&opecao);
        fflush(stdin);
       if(opecao!=11){
            menu_opecao(opecao);
            opecao=0;
       }else{
          while(inicio_turma!=NULL){

               free(inicio_turma->anterior);
               inicio_turma=inicio_turma->seguinte;

          }


        break;
    }




}
    printf("\n MEMORIA LIBERADA COM SUCESSO...\n");
return 0;
}
