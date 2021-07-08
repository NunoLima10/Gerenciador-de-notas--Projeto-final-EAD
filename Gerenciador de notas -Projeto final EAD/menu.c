/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/

#include"main.h"
void menu(){

    printf("\t\t\tGESTOR DE NOTAS ISECMAR\n");
    linha();
    printf("\t\t\t\tMENU\t\t\t\n");
    linha();
    printf(" 1-INTRODUZIR NOTAS DOS ALUNOS\n");
    printf(" 2-ALUNO COM NOTA MAIS ALTA\n");
    printf(" 3-ALUNO COM A NOTA MAIS BAIXA\n");
    printf(" 4-QUANTIDADE APROVADOS\n");
    printf(" 5-MEDIA DA TURMA\n");
    printf(" 6-LISTA APROVADOS/REPROVADOS\n");
    printf(" 7-PESQUISAR ALUNO\n");
    printf(" 8-IMPRIMIR LISTA DE NOTAS(ORDEM DECRESCENTE)\n");
    printf(" 9-VISUALIZAR GRAFICO TURMA\n");
    printf(" 10-ELIMINAR/EDITAR\n");
    printf(" 11-TERMINAR\n");
    linha();
}

void linha(){
     printf("========================================================================\n");
}

void menu_opecao(int opecao){

    if(opecao==1){
       system("cls");
       pedir_alunos();  //inserir novos alunos independentemente se a turma esta vazia ou nao
       enter();
    }
    else if((opecao==2)&&(inicio_turma!=NULL)){
       system("cls");
       mostrar_melhor_aluno();
       enter();

    }
    else if((opecao==3)&&(inicio_turma!=NULL)){
       system("cls");
       mostrar_pior_aluno();
       enter();
    }
    else if((opecao==4)&&(inicio_turma!=NULL)){
       system("cls");
       mostrar_aprovados();
       enter();
    }
    else if((opecao==5)&&(inicio_turma!=NULL)){
        system("cls");
        mostrar_media();
        enter();
    }
    else if((opecao==6)&&(inicio_turma!=NULL)){
        system("cls");
        mostrar_lista_aprovacao();
        enter();
    }
    else if((opecao==7)&&(inicio_turma!=NULL)){
        system("cls");
        pesquisar_aluno();
        enter();
    }
    else if((opecao==8)&&(inicio_turma!=NULL)){
        system("cls");
        mostrar_quick();
        enter();
    }
    else if((opecao==9)&&(inicio_turma!=NULL)){
        system("cls");
         grafico_notas();
        //histograma(); OUTRA OPCAO
        enter();
    }
    else if((opecao==10)&&(inicio_turma!=NULL)){
        system("cls");
        editar_eliminar();
        enter();
    }

    else{
        if (inicio_turma==NULL)printf("\n NENHUM ALUNO REGISTRADO");
        else printf("\n INVALIDO");

        Sleep(1500); //esperar 1.5 segundos
        }

}
void enter(){
    char finalizar[2];
    //linha();
    printf("\n ENTER PARA CONTINUAR...");
    fgets(finalizar,2,stdin);
}




