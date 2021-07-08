/*PROJETO FINAL DE AED
DIEGO DONOVAN SILVA SOUSA 1 ANO 2 SEMESTRE
NUNO JORGE GOMES LIMA 1 ANO 2 SEMESTRE
05/07/2021*/


#include"main.h"

void pesquisar_aluno(){              //funcao para pesquisar um determinado aluno id/nome
    int opcao,info_id;
    alu aluno_procurado;
    char info_nome[20];

    linha();
    printf("\t\t\tPESQUISAR ALUNO\n");
    linha();

    printf(" 1-PESQUISAR POR ID\n");
    printf(" 2-PESQUISAR POR NOME\n");
    linha();

    while(1){
        printf(" ESCOLHA A OPCAO: ");
        scanf("%d",&opcao);
        fflush(stdin);
        printf("\n");
        linha();
        if (opcao==1){
                while(1){                                          //pesquisar usando id
                    printf("\n INSIRA O NUMERO(ID): ");
                    scanf("%d",&info_id);
                    fflush(stdin);
                    aluno_procurado=aluno_existe(info_id);
                    if((info_id>0)&&(info_id<max_id)){
                        if(aluno_procurado!=NULL){
                            exibir_aluno(aluno_procurado);
                            break;
                        }
                        else{
                            printf("\n");
                            linha();
                            printf("\n O ALUNO NAO EXISTE \n");
                        }
                    }

                }
            break;    //terminar ao terminar a opecao 1
        }
                                                                //segunda parte para pesquisar usando o nome
        else if(opcao==2){
            while(1){

                    printf("\n INSIRA O NOME: ");
                    fgets(info_nome,20,stdin);
                    fflush(stdin);
                    aluno_procurado=aluno_existe_nome(info_nome);
                        if(aluno_procurado!=NULL){
                            exibir_aluno(aluno_procurado);
                            break;
                        }
                        else{
                            printf("\n");
                            linha();
                            printf("\n O ALUNO NAO EXISTE\n");
                        }
                    }

                }

            break;   //terminar ao terminar a opecao 2
        }

    }




void eliminar_aluno(){ // para eliminar editar

    linha();
    printf("\t\t\tELIMINAR ALUNO\n");
    linha();
    alu aluno_procurado,aluno_seguinte,aluno_anterior;
    int info_id,confirma;

    while(1){
        printf("\n INSIRA O NUMERO(ID): ");
        scanf("%d",&info_id);
        fflush(stdin);

        if((info_id>0)&&(info_id<max_id)){
            aluno_procurado=aluno_existe(info_id);


            if(aluno_procurado!=NULL){

            exibir_aluno(aluno_procurado);

            printf("\n CONFIRMAR ELIMINAÇÃo DIGITE 1: ");
            scanf("%d",&confirma);
            fflush(stdin);

            if (confirma==1){

                                                                     //fazer as trocas dos ponteiros dependo da posibilidade
                        if((aluno_procurado->anterior ==NULL)&&(aluno_procurado->seguinte!=NULL)){
                            aluno_seguinte=aluno_procurado->seguinte;
                            inicio_turma=aluno_seguinte;
                            aluno_seguinte->anterior=NULL;


                        }
                        else if((aluno_procurado->seguinte==NULL) &&(aluno_procurado->anterior!=NULL)){
                            aluno_anterior=aluno_procurado->anterior;
                            fim_turma=aluno_anterior;
                            aluno_anterior->seguinte=NULL;

                        }

                        else if((aluno_procurado->seguinte!=NULL)&&(aluno_procurado->anterior!=NULL)){
                            aluno_anterior=aluno_procurado->anterior;
                            aluno_seguinte=aluno_procurado->seguinte;


                            aluno_anterior->seguinte=aluno_procurado->seguinte;
                            aluno_seguinte->anterior=aluno_procurado->anterior;
                        }
                        else {

                            inicio_turma=NULL;
                            fim_turma=NULL;
                            printf("\n O ULTIMO ALUNO FOI REMOVIDO, TURMA ELIMINADA\n");
                            break;
                        }


                    printf(" \n ALUNO REMOVIDO COM SUCESSO");

                    break;



            }else continue;



        }else printf("\n O ALUNO NAO EXISTE\n");

        }


    }
    free(aluno_procurado);

}
void editar_aluno(){
    //char info_nome[20];
    int info_id,info_nota;
    alu aluno_procurado;

    linha();
    printf("\t\t\tEDITAR ALUNO\n");
    linha();

    printf("\n INSIRA O NUMERO(ID): ");
        scanf("%d",&info_id);
        fflush(stdin);

        if((info_id>0)&&(info_id<max_id)){
            aluno_procurado=aluno_existe(info_id);
            if(aluno_procurado!=NULL){
                exibir_aluno(aluno_procurado);
                while(1){
                    printf("\n INSIRA A NOVA NOTA: ");
                    scanf("%d",&info_nota);
                    fflush(stdin);

                    if((info_nota>=0)&&(info_nota<=20)){
                        break;
                    }
                    else{
                        printf("\n A NOTA INSERIDA E INVALIDA\n");
                    }
            }
            aluno_procurado->nota=info_nota;
        }
    }
}
void editar_eliminar(){
    int opcao;
    linha();
    printf("\t\t\tELIMINAR/EDITAR ALUNO\n");
    linha();
    printf(" 1-EDITAR ALUNO\n");
    printf(" 2-ELIMINAR ALUNO\n");
    linha();
    while(1){
        printf(" OPERACAO A REALIZAR: ");
        scanf("%d",&opcao);
        fflush(stdin);

        if(opcao==1){
            editar_aluno();
            break;
        }
        else if(opcao==2){
            eliminar_aluno();
            break;
        }
        else{
            printf(" INVALIDO\n ");
        }

        }


}


/*void histograma(){
    alu aluno_histograma,aluno_histograma2;
    aluno_histograma=inicio_turma;

    int aux,i;
    while (aluno_histograma!=NULL){
            aluno_histograma2=inicio_turma;
            aux=0;
        while(aluno_histograma2!=NULL){
            if(aluno_histograma2->nota==aluno_histograma->nota){
                aux++;
            }

            aluno_histograma2=aluno_histograma2->seguinte;
        }
        printf("%d|",aluno_histograma->nota);
        for (i=0;i<aux;i++){
            printf("*");
        }
        printf("\n");


       aluno_histograma=aluno_histograma->seguinte;
    }

}*/




