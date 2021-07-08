/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/

#include"main.h"
alu melhor_nota(){//funcao usada para encontrar a maior nota da a turma
    alu aluno_procurado,melhor_aluno;
    int maior_nota;

    aluno_procurado=inicio_turma;
    maior_nota=0;


    while(aluno_procurado!=NULL){
    if(aluno_procurado->nota>=maior_nota){
        maior_nota=aluno_procurado->nota;
        melhor_aluno=aluno_procurado;
    }
    aluno_procurado=aluno_procurado->seguinte;

    }
    return melhor_aluno;
}


alu pior_nota(){//funcao usada para encontrar a pior nota da a turma
    alu aluno_procurado,pior_aluno;
    int pior_nota;

    aluno_procurado=inicio_turma;
    pior_nota=inicio_turma->nota;


    while(aluno_procurado!=NULL){
        if(aluno_procurado->nota<=pior_nota){
            pior_nota=aluno_procurado->nota;
            pior_aluno=aluno_procurado;
        }
        aluno_procurado=aluno_procurado->seguinte;

    }
    return pior_aluno;
}

int aprovados(){
    alu aluno_procurado;
    int numero_aprovados;
    aluno_procurado=inicio_turma;
    numero_aprovados=0;

    while(aluno_procurado!=NULL){
        if(aluno_procurado->nota>9)numero_aprovados++;
        aluno_procurado=aluno_procurado->seguinte;
    }
    return numero_aprovados;
}

float media(){    //funcao usada para calcular a media dos elementos da turma
    alu aluno_procurado;
    aluno_procurado=inicio_turma;
    int soma_notas=0,numero_alunos=0;
    float media_turma;
    while(aluno_procurado!=NULL){
        soma_notas=soma_notas+aluno_procurado->nota;
        aluno_procurado=aluno_procurado->seguinte;
        numero_alunos++;
    }

    media_turma=(float)soma_notas/numero_alunos;

    return media_turma;

}


//procedimentos para mostrar
void mostrar_melhor_aluno(){  //procedimento para mostrar as informacoes do melhor aluno
    linha();
    printf("\t\t\t\tMELHOR ALUNO\n");
    linha();
    alu melhor_aluno;
    melhor_aluno=melhor_nota();
    exibir_aluno(melhor_aluno);

}
void mostrar_pior_aluno(){      //procedimento para mostrar as informacoes do pior aluno
    linha();
    printf("\t\t\t\tPIOR ALUNO\n");
    linha();
    alu pior_aluno;
    pior_aluno=pior_nota();
    exibir_aluno(pior_aluno);

}

void mostrar_aprovados(){       //procedimento para mostrar as informacoes dos alunos aprovados
    linha();
    printf("\t\t\tNUMERO DE APROVADOS\n");
    linha();
    int numero_aprovados;
    numero_aprovados=aprovados();
    printf("\n O numero de aprovados foi: %d",numero_aprovados);
}

void mostrar_media(){       //procedimento para mostrar a media da turma
    printf("\t\t\tMEDIA DA TURMA\n");
    linha();
    float media_turma;
    media_turma=media();
    printf("\n A media da turma e: %2.1f",media_turma);
}

void mostrar_lista_aprovacao(){   //procedimento para mostrar os reprovados/aprovados
    alu aluno_procurado;
    aluno_procurado=inicio_turma;
    int numero_aprovados,numero_reprovados,numero_total,percentagem;
    percentagem=0;
    numero_total=numero_alunos();
    numero_aprovados=aprovados();
    numero_reprovados=numero_total-numero_aprovados;

    if(numero_aprovados) percentagem=(numero_aprovados*100)/numero_total; //calcular a percentagem de aprovados caso aprovados !=0

    linha();
    printf("\t\t\t\tAPROVADOS(%d%c)\n",percentagem,'%');
    linha();
    while(aluno_procurado!=NULL){
        if(aluno_procurado->nota>9){
            exibir_aluno(aluno_procurado);
            printf("\n");
            linha();
        }
        aluno_procurado=aluno_procurado->seguinte;
    }
    if(numero_aprovados==0){
       printf("\n");
       printf("\t\t\t  NENHUM ALUNO APROVADO\n");
       printf("\n");
       linha();
    }

    percentagem=0;
    aluno_procurado=inicio_turma;
     if(numero_reprovados) percentagem=(numero_reprovados*100)/numero_total;


    printf("\t\t\t\tREPROVADOS(%d%c)\n",percentagem,'%');
    linha();
    while(aluno_procurado!=NULL){
        if(aluno_procurado->nota<=9){
            exibir_aluno(aluno_procurado);
            printf("\n");
            linha();
        }
        aluno_procurado=aluno_procurado->seguinte;
    }
        if(numero_reprovados==0){
            printf("\n");
            printf("\t\t\t  NENHUM ALUNO REPROVADO\n");
            printf("\n");
    }

}
void grafico_notas(){  //procedimento para mostrar o grafico da turma
    linha();
    printf("\t\t\t  GRAFICO DAS NOTAS\n");
    linha();
    alu aluno_procurado;
    int elementos_grafico,i;
    aluno_procurado=inicio_turma;
     printf("\n");
    while(aluno_procurado!=NULL){
      elementos_grafico=aluno_procurado->nota;
       printf("%2.d|",aluno_procurado->nota);
      for(i=0;i<elementos_grafico;i++){

          printf("%c",elemento_grafico);
      }

       printf("\n");
       aluno_procurado=aluno_procurado->seguinte;
    }
}


