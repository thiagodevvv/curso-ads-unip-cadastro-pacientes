#include <stdio.h> //printf scanf
#include <stdlib.h> // armazenar memoria
#include <windows.h> //comandos do sistema operacional
#include <string.h> //manipulação de strings
#include <conio.h> // getche e getch
#include <ctype.h> // para trabalhar com caracteres, transformar em maiusculas ou minusculas, verificar se é númerico ou char

//cabeçalho cadastro
int cabecalhoCadastro () {
    printf("///////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\n");
    printf("      AREA DE CADASTRO DE PACIENTES DIAGNOSTICADOS COM COVID-19        \n");
    printf("\n");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////\n");
    printf("///////////////////////////////////////////////////////////////////////////\n");
    return 0;
}
int login(){
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,11);
    printf("/////////////////////////////////\n");
    printf("\n");
    printf("        EFETUAR LOGIN             \n");
    printf("\n");
    printf("/////////////////////////////////\n");
    printf("\n");
    typedef struct{
        char login[20];
        char senha[20];
    }pessoa;pessoa p[1];

    char login[20];
    char senha[20];
    int validade;

    strcpy(p[0].login, "agente");
    strcpy(p[0].senha, "0000");

    //Inicialisa variável com o valor 0
    validade=0;

    //Enquanto a variável de validação for igual a 0 nao irá sair do laço/while
    while( validade==0 ){

        printf("\nlogin:");
        scanf("%s", login);

        printf("\nsenha:");
        scanf("%s", senha);

    //Se a condição do login for verdadeira, o login é efetuado e a variavel "validade" recebe o valor 1 saindo do laço/while
        if ((strcmp(login,p[0].login)==0) && (strcmp(senha,p[0].senha)==0)){
            printf("Login efetuado\n");
            validade=1;
        }//se a condição login for falsa, o login não sera efetuado, e a variavel "validade" manterá o valor iniciando o laço novamente
        else{
            printf("Login e/ou senha incorretas\n");
            validade=0;
        }
    }
    printf("Entrando...\n");
    Sleep(1000);
    system("cls");
    return validade;
}

int cadastro () {
    system("cls");
    cabecalhoCadastro();

    char nome[100];
    char cpf[11];
    char telefone[10];
    char email[50];
    int dia;
    int mes;
    int ano;
    char rua[100];
    int numero_rua;
    char bairro[50];
    char cidade[30];
    char estado[2];
    char cep[10];
    int dia_diagnostico;
    int mes_diagnostico;
    int ano_diagnostico;
    char comorbidade[100];
    int result;
    int resp = 1;
    int retorno_salvarDados;

    typedef struct dados{
        char nome[100];
        char cpf[11];
        int telefone;
        char email[50];
        int dia;
        int mes;
        int ano;
        char rua[100];
        int numero_rua;
        char bairro[50];
        char cidade[30];
        char estado[3];
        char cep[10];
        int dia_diagnostico;
        int mes_diagnostico;
        int ano_diagnostico;
        char comorbidade[100];
        struct dados *proximo;
    }Dados;



void verificarRisco (int ano, char *comorbidade, char *cep) {
    printf("\nVerificando se pertence ao grupo de risco... \n");
    int anoAtual = 2020;
    int calculo;
    int result;
    int i;
    int tamString;
    calculo = anoAtual - ano;
    tamString = strlen(comorbidade);
    for(i=0; i < tamString; i++) {
        comorbidade[i] = toupper(comorbidade[i]);
    }
    result = strcmp(comorbidade,"N");
    if(calculo > 65 || result != 0 ) { // se paciente for maior que 65 anos ou a comparação não for igual a N quer dizer que tem preenchido riscos
      FILE *ponteiro_arquivo;
      ponteiro_arquivo = fopen("PacientesRiscoCovid19.txt", "a");
      if(ponteiro_arquivo == NULL) {
        printf("Erro ao criar o arquivo.");
      }
      fprintf(ponteiro_arquivo, "%s %s %s %s %d \n", "CEP:",cep," | ","IDADE:", calculo);
        printf("Paciente pertence ao grupo de risco!\n");
        printf("Salvando dados...\n");
        Sleep(1000);
      fclose(ponteiro_arquivo);

    }else {
        printf("Paciente nao esta no grupo de risco!\n");
    }
}



    Dados *inicia() {
        return NULL;
    }

    int salvarDadosTxt (Dados *lista_paciente) {

    int result_salvarDadosTxt;
    int retorno;
    FILE *ponteiro_arquivo;
    ponteiro_arquivo = fopen("dadosCovid19.txt", "a");
    if(ponteiro_arquivo == NULL) {
        printf("Erro ao abrir o arquivo");
    }
    retorno = fprintf(ponteiro_arquivo, "%s %s %s %s %d %s %d %s %d %s %s %s %s %s %s %s %s %d %s %s %s %s %s %d %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %d %s %d %s %d \n","NOME:", lista_paciente->nome," | ",
            "NASCIMENTO:",lista_paciente->dia,"/",lista_paciente->mes,"/",lista_paciente->ano, " | ", "EMAIL:",lista_paciente->email," | ", "CPF:", lista_paciente->cpf," | ", "TELEFONE:", lista_paciente->telefone," | ",
            "ENDEREÇO:",lista_paciente->rua," | ", "NUMERO CASA:",lista_paciente->numero_rua," | ", "BAIRRO:",lista_paciente->bairro," | ", "CIDADE:",lista_paciente->cidade," | ",
            "ESTADO:",lista_paciente->estado," | ", "CEP:",lista_paciente->cep," | ", "COMORBIDADE:", lista_paciente->comorbidade," | ", "DATA DIAGNOSTICO:",lista_paciente->dia_diagnostico, "/",lista_paciente->mes_diagnostico,
            "/",lista_paciente->ano_diagnostico);
    if(retorno < 0) {
         result_salvarDadosTxt = 0;
    }else {
        result_salvarDadosTxt = 1;
    }
    fclose(ponteiro_arquivo);
    return result_salvarDadosTxt;
}

    Dados *inserir(Dados *lista_paciente,char *nome,int dia, int mes, int ano, char *email,char *cpf, int telefone, char *rua, int numero_rua, char *bairro,
                   char *cidade, char *estado, char *cep, char *comorbidade, int dia_diagnostico, int mes_diagnostico, int ano_diagnostico) {
            Dados *nova_lista = (Dados*)malloc(sizeof(Dados));
            strcpy(nova_lista->nome, nome);
            nova_lista->dia = dia;
            nova_lista->mes = mes;
            nova_lista->ano = ano;
            strcpy(nova_lista->email,email);
            strcpy(nova_lista->cpf, cpf);
            nova_lista->telefone = telefone;
            strcpy(nova_lista->rua, rua);
            nova_lista->numero_rua = numero_rua;
            strcpy(nova_lista->bairro, bairro);
            strcpy(nova_lista->cidade, cidade);
            strcpy(nova_lista->estado, estado);
            strcpy(nova_lista->cep, cep);
            strcpy(nova_lista->comorbidade, comorbidade);
            nova_lista->dia_diagnostico = dia_diagnostico;
            nova_lista->mes_diagnostico = mes_diagnostico;
            nova_lista->ano_diagnostico = ano_diagnostico;
            nova_lista->proximo = lista_paciente;
            return nova_lista;
    }
    Dados *lista_paciente;
    lista_paciente = inicia(); //lista inicia vazia.
    while(resp == 1 || resp == 49) {
        printf("NOME:");
        scanf(" %[^\n]s", &nome);
        printf("NASCIMENTO\n");
        printf("DIA:");
        scanf("%d", &dia);
        printf("MES:");
        scanf("%d",&mes);
        printf("ANO:");
        scanf("%d", &ano);
        printf("EMAIL:");
        scanf(" %[^\n]s", &email);
        printf("CPF:");
        scanf(" %[^\n]s", &cpf);
        printf("TELEFONE:");
        scanf(" %[^\n]s", &telefone);
        printf("ENDERECO RUA:");
        scanf(" %[^\n]s", &rua);
        printf("NUMERO:");
        scanf("%d",&numero_rua);
        printf("BAIRRO:");
        scanf(" %[^\n]s", &bairro);
        printf("CIDADE:");
        scanf(" %[^\n]s", &cidade);
        printf("ESTADO:");
        scanf(" %[^\n]s", &estado);
        printf("CEP:");
        scanf("%s", &cep);
        printf("PACIENTE TEM ALGUMA COMORBIDADE? CASO NAO DIGITE 'N' :");
        scanf(" %[^\n]s", &comorbidade);
        printf("DATA DO DIAGNOSTICO \n");
        printf("DIA:");
        scanf("%d",&dia_diagnostico);
        printf("MES:");
        scanf("%d", &mes_diagnostico);
        printf("ANO:");
        scanf("%d", &ano_diagnostico);
        lista_paciente = inserir(lista_paciente,nome,dia,mes,ano,email,cpf,telefone,rua,numero_rua,bairro,cidade,estado,cep,comorbidade,dia_diagnostico, mes_diagnostico, ano_diagnostico);
        retorno_salvarDados = salvarDadosTxt(lista_paciente);
        if(retorno_salvarDados == 1) {
            printf("Dados gravados com sucesso!\n");
            verificarRisco(ano,comorbidade,cep);
            Sleep(1000);
        }else {
            printf("Erro ao gravar os dados! \n");
        }
        printf("Deseja continuar? APERTE[1] PARA SIM OU APERTE[2] PARA NAO \n");
        resp = getche();
        if(resp == 49) {
            printf("Abrindo nova aba...");
            Sleep(1000);
            printf("\n ...");
            Sleep(1000);
            system("cls");
            cabecalhoCadastro();
        }
        if(resp == 50) {
            printf("Fechando programa...\n");
            Sleep(1000);
            exit(1);
        }
    }

    return result;
}

int consultarDados () {
    int comando;
    system("cls");
    printf("\n");
    printf("\n");
    printf("                                  APERTE [1] PARA IR PARA CADASTRO DE PACIENTE                                  \n");
    printf("                                  APERTE [2] PARA FECHAR                                                        \n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////// \n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n");
    printf("                                    AREA DE CONSULTA DE PACIENTES COM COVID 19                                   \n");
    printf("\n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////// \n");
    printf("//////////////////////////////////////////////////////////////////////////////////////////////////////////////// \n");
    printf("\n");

    char Linha[999];
    FILE *ponteiro_arquivo;
    char *result;
    ponteiro_arquivo = fopen("dadosCovid19.txt", "r");
    if(ponteiro_arquivo == NULL) {
        printf("Nenhum dado salvo!\n");
    }else {
        while(!feof(ponteiro_arquivo)) {//falar de FEOF na parte escrita do projeto. FEOF indica se existem um identificador de fim de arquivo.
        result = fgets(Linha,999,ponteiro_arquivo);
        if(result) {
            printf("%s",Linha);
            printf("-------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        }
    }

    comando = getche();
    while(comando != 49 && comando != 50) {
        printf("COMANDO INCORRETO!!! \n");
        comando = getche();
    }
    if(comando == 49) {
        cadastro();
    }
    else if(comando == 50) {
        printf("Fechando programa...");
        Sleep(1000);
        exit(1);
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int home() {
    int comando;
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color,11);

        printf("\n");
        printf("\n");
        printf("////////////////////////////////////////////\n");
        printf("\n");
        printf("\n");
        printf("CADASTRAR PACIENTES APERTE [1]\n");
        printf("\n");
        printf("CONSULTAR PACIENTES APERTE [2]\n");
        printf("\n");
        printf("\n");
        printf("////////////////////////////////////////////\n");
        printf("\n");
        printf("COMANDO: ");
        comando = getch();
    while(comando != 49 && comando != 50) {
        printf("\n");
        printf("COMANDO INCORRETO! ");
        comando = getche();
    }
    if(comando == 49) {
        cadastro();
    }else if(comando == 50) {
        consultarDados();
    }else {
        printf("\n COMANDO INCORRETO!");
    }
    return 0;
}
