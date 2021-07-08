
/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/


#include"main.h"

 alu _partition( alu aluno_esd,alu aluno_dir){
    alu pivot,aluno_troca,aluno_procurado;
    pivot=aluno_dir;
    aluno_troca=aluno_esd->anterior;

    char info_nome[20];
    int info_numero,info_nota;


    for(aluno_procurado=aluno_esd;aluno_procurado!=aluno_dir;aluno_procurado=aluno_procurado->seguinte){
        if(aluno_procurado->nota >=pivot->nota){

            if(aluno_troca==NULL)aluno_troca=aluno_esd;else aluno_troca=aluno_troca->seguinte;

            info_nota=aluno_troca->nota;
            strcpy(info_nome,aluno_troca->nome);
            info_numero=aluno_troca->numero;

            aluno_troca->nota=aluno_procurado->nota;
            strcpy(aluno_troca->nome,aluno_procurado->nome);
            aluno_troca->numero=aluno_procurado->numero;

            aluno_procurado->nota=info_nota;
            strcpy(aluno_procurado->nome,info_nome);
            aluno_procurado->numero=info_numero;
        }
     }

            if(aluno_troca==NULL) aluno_troca=aluno_esd ;else aluno_troca=aluno_troca->seguinte;
            info_nota=aluno_troca->nota;
            strcpy(info_nome,aluno_troca->nome);
            info_numero=aluno_troca->numero;


            aluno_troca->nota=pivot->nota;
            strcpy(aluno_troca->nome,pivot->nome);
            aluno_troca->numero=pivot->numero;

            pivot->nota=info_nota;
            strcpy(pivot->nome,info_nome);
            pivot->numero=info_numero;

 return aluno_troca;
 }


void quick_sort(alu aluno_esd ,alu aluno_dir){

if((aluno_dir != NULL) && (aluno_esd != aluno_dir) && (aluno_esd != aluno_dir->seguinte)){
    alu p=_partition(aluno_esd,aluno_dir);
    quick_sort(aluno_esd,p->anterior);
    quick_sort(p->seguinte,aluno_dir);


}


}

void mostrar_quick(){
    linha();
    printf("\tORDENACAO EM ORDEM DECRESCENTE USANDO QUICK SORT\n");
    linha();
alu aluno_procurado;

quick_sort(inicio_turma ,fim_turma);

aluno_procurado=inicio_turma;


while(aluno_procurado!=NULL){
    exibir_aluno(aluno_procurado);
    printf("\n");
    aluno_procurado=aluno_procurado->seguinte;

}


}
