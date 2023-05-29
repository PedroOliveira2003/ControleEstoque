#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;



struct TipoProdutos{
    int codTipoProd;
    char descTipoProd[20];
};

struct Produtos{
  int codProduto;
  char descProduto[20];
  char tipoProduto[20];
  int codFornecedor2;
  int qtdEst;
  int qtdEstMin;
  int qtdEstMax;
  float valorUnitario;

};


struct Estado{

 int codUf;
 char nomeEstado[20];

};

struct Fornecedores{
  int codFornecedor;
  char nomeFornecedor[20];
  char endereco[20];
  string telefone;
  char cidadeFornecedor[20];
  int ufFornecedor;
  string cnpj;

};

void LeituraTipoProd(struct TipoProdutos p[],int &contadorTipoProd,int tam){ //leitura do tipo do produto
    int i=0;
    for(int saida = 1; i<tam && saida !=0;i++){
        cout<<"\nCodigo do Tipo Do Produto " << (i+1) << ": ";
        cin>>p[i].codTipoProd;
        if(p[i].codTipoProd > 0){
            cout<<"Descricao Produto: ";
            cin>>p[i].descTipoProd;
        }
        else saida = 0;
    }
    contadorTipoProd = i-1;
}

void LeituraFornecedor(struct Fornecedores f[],int &contadorFornecedor,int tam){ //leitura do fornecedor
       int i=0;
       for(int saida =1; i<tam && saida !=0;i++){
        cout<<"\nCodigo do Fornecedor " << (i+1) <<": ";
        cin>>f[i].codFornecedor;
        if(f[i].codFornecedor > 0){
            cout<<"Nome: ";
            cin>>f[i].nomeFornecedor;
            cout<<"Endereco: ";
            cin>>f[i].endereco;
            cout<<"Telefone: ";
            cin>>f[i].telefone;
            cout<<"Cidade: ";
            cin>>f[i].cidadeFornecedor;
            cout<<"UF:";
            cin>>f[i].ufFornecedor;
            cout<<"CNPJ:";
            cin>>f[i].cnpj;
        }
          else saida = 0;
    }
    contadorFornecedor = i-1;
}

void LeituraProduto(struct Produtos t[],int &contadorProduto,int tam){ //leitura do produto

     int i=0;
     for(int saida =1;i<tam && saida !=0;i++){
        cout<<"\nCodigo do Produto " << (i+1)<<": ";
        cin>>t[i].codProduto;
        if(t[i].codProduto>0){
            cout<<"Descricao:";
            cin>>t[i].descProduto;
            cout<<"Tipo Produto:";
            cin>>t[i].tipoProduto;
            cout<<"Codigo Fonecedor";
            cin>>t[i].codFornecedor2;
            cout<<"Quantidade Estoque:";
            cin>>t[i].qtdEst;
            cout<<"Quantidade Maxima Estoque:";
            cin>>t[i].qtdEstMax;
            cout<<"Quantidade Minima Estoque:";
            cin>>t[i].qtdEstMin;
            cout<<"Valor Unitario: ";
            cin>>t[i].valorUnitario;
        }
        else saida= 0;
     }

      contadorProduto = i-1;
}

void LeituraEstado(struct Estado e[],int &contadorEstado, int tam){ //leitura do estado
   int i =0;
   for(int saida = 1; i<tam && saida!=0;i++){
     cout<<"\nCodigo da UF: ";
     cin>>e[i].codUf;
    if(e[i].codUf >0){
        cout<<"Estado: ";
        cin>>e[i].nomeEstado;
    }
    else saida = 0;
   }
 contadorEstado = i-1;
}
void buscaestadoaleat(struct Estado e[],int cod);
void LeituraFornecedorinc(struct Estado e[],struct Fornecedores f[],int &contadorFornecedor){ //leitura do fornecedor
       int i=0;
       for(int saida =1; i<20 && saida !=0;i++){
        cout<<"\nCodigo do Fornecedor " << (i+1) <<": ";
        cin>>f[i].codFornecedor;
        if(f[i].codFornecedor > 0){
            cout<<"Nome: ";
            cin>>f[i].nomeFornecedor;
            cout<<"Endereco: ";
            cin>>f[i].endereco;
            cout<<"Telefone: ";
            cin>>f[i].telefone;
            cout<<"Cidade: ";
            cin>>f[i].cidadeFornecedor;
            cout<<"Digite o codigo  Uf:";
            int cod;
            cin>>f[i].ufFornecedor;
            cod = f[i].ufFornecedor;
            buscaestadoaleat(e,cod);
            cout<<"CNPJ:";
            cin>>f[i].cnpj;
        }
          else saida = 0;
    }
    contadorFornecedor = i-1;
}

void incluirFornecedor(struct Fornecedores S[], int contS, struct Fornecedores T[], int contT, struct Fornecedores A[],int &contA){//Incluir Fornecedor
   int i=0,j=0,k=0;
   for(;i<contS && j < contT;k++){
    if(S[i].codFornecedor <T[j].codFornecedor){
        A[k].codFornecedor = S[i].codFornecedor;
        strcpy(A[k].nomeFornecedor,S[i].nomeFornecedor);
        strcpy(A[k].endereco,S[i].endereco);
        A[k].telefone = S[i].telefone;
        strcpy(A[k].cidadeFornecedor,S[i].cidadeFornecedor);
        A[k].ufFornecedor = S[i].ufFornecedor;
        A[k].cnpj = S[i].cnpj;
        i++;
    }
    else{
        A[k].codFornecedor = T[j].codFornecedor;
        strcpy(A[k].nomeFornecedor,T[j].nomeFornecedor);
        strcpy(A[k].endereco,T[j].endereco);
        A[k].telefone = T[j].telefone;
        strcpy(A[k].cidadeFornecedor,T[j].cidadeFornecedor);
        A[k].ufFornecedor = T[j].ufFornecedor;
        A[k].cnpj = T[j].cnpj;
        j++;
    }
   }
   while(i< contS){

        A[k].codFornecedor = S[i].codFornecedor;
        strcpy(A[k].nomeFornecedor,S[i].nomeFornecedor);
        strcpy(A[k].endereco,S[i].endereco);
        A[k].telefone = S[i].telefone;
        strcpy(A[k].cidadeFornecedor,S[i].cidadeFornecedor);
        A[k].ufFornecedor = S[i].ufFornecedor;
        A[k].cnpj = S[i].cnpj;
        i++;
        k++;
   }
   while(j<contT){
         A[k].codFornecedor = T[j].codFornecedor;
        strcpy(A[k].nomeFornecedor,T[j].nomeFornecedor);
        strcpy(A[k].endereco,T[j].endereco);
        A[k].telefone = T[j].telefone;
        strcpy(A[k].cidadeFornecedor,T[j].cidadeFornecedor);
        A[k].ufFornecedor = T[j].ufFornecedor;
        A[k].cnpj = T[j].cnpj;
        j++;
        k++;

   }
 contA = k;
}


void mostrarInclusao(struct Fornecedores A[], int contA){
  cout<<"\n\nFornecedores Atualizados\n"<<endl;
  for(int i=0;i<contA; i++){
    cout << "\tCod Forn: "<<A[i].codFornecedor;
    cout << "\tNome Fornr: "<<A[i].nomeFornecedor;
    cout << "\tEndereco: "<< A[i].endereco;
    cout << "\tTelefone: "<< A[i].telefone;
    cout << "\tCidade Forn: "<< A[i].cidadeFornecedor;
    cout << "\tUf: "<< A[i].ufFornecedor;
    cout << "\tCNPJ: " << A[i].cnpj;
    cout<<"\n\t-------------------------------------------------------------"<<endl;
  }
}


void buscaestadoaleat(struct Estado e[],int cod){
    int inicio = 0, fim = 10;
    int meio = (inicio+fim)/2;
    for (; fim>= inicio && cod!= e[meio].codUf ;meio = (inicio+fim)/2){
        if(cod > e[meio].codUf)
            inicio = meio+1;
        else
            fim = meio -1;
    }
    if (cod == e[meio].codUf){
        cout<<e[meio].nomeEstado <<endl;
    }
    else
        cout<<"\n Estado não encontrado"<<endl;
    getch();
}
void buscaProduto(struct Produtos p[],int &cod);
void buscaFornecedor(struct Fornecedores f[],int cod);
void leituraProdutoinc(struct Fornecedores f[],struct Produtos prodt[],struct Produtos p[], int &contadorProdutos){ //a termina
   int i = 0;
    for (int saida = 1; i < 20 && saida != 0; i++) {
        cout << "\nCodigo do Produto " << (i + 1) << ": ";
        cin >> p[i].codProduto;
        int cod2;
            cod2 = p[i].codProduto;
            buscaProduto(prodt, cod2);
            if(cod2 == 0)
            saida = 0;
        if (cod2!=0) {
            cout << "Descricao: ";
            cin >> p[i].descProduto;
            cout << "Tipo Produto: ";
            cin >> p[i].tipoProduto;
            cout<< "Codigo Fornecedor: ";
            cin >> p[i].codFornecedor2;
            int cod = p[i].codFornecedor2;
            buscaFornecedor(f, cod);
            cout << "Quantidade Estoque: ";
            cin >> p[i].qtdEst;
            cout << "Quantidade Maxima Estoque: ";
            cin >> p[i].qtdEstMax;
            cout << "Quantidade Minima Estoque: ";
            cin >> p[i].qtdEstMin;
            cout << "Valor Unitario: ";
            cin >> p[i].valorUnitario;
        } else {
            saida = 0;
        }
    }

    contadorProdutos = i - 1;

}

void incluirProduto(struct Produtos S[], int contS, struct Produtos T[], int contT, struct Produtos A[], int &contA){
 int i=0,j=0,k=0;
 for(;i<contS && j< contT;k++){
    if(S[i].codProduto < T[j].codProduto){
        A[i].codProduto = S[i].codProduto;
        strcpy(A[k].descProduto,S[i].descProduto);
        strcpy(A[k].tipoProduto,S[i].tipoProduto);
        A[k].codFornecedor2 = S[i].codFornecedor2;
        A[k].qtdEst = S[i].qtdEst;
        A[k].qtdEstMin = S[i].qtdEstMin;
        A[k].qtdEstMax = S[i].qtdEstMax;
        A[k].valorUnitario = S[i].valorUnitario;
        i++;
    }
    else {
        A[k].codProduto = T[j].codProduto;
        strcpy(A[k].descProduto,T[j].descProduto);
        strcpy(A[k].tipoProduto,T[j].tipoProduto);
        A[k].codFornecedor2 = T[j].codFornecedor2;
        A[k].qtdEst = T[j].qtdEst;
        A[k].qtdEstMin = T[j].qtdEstMin;
        A[k].qtdEstMax = T[j].qtdEstMax;
        A[k].valorUnitario = T[j].valorUnitario;
        j++;
    }
 }
     while(i <contS){
        A[k].codProduto = S[i].codProduto;
        strcpy(A[k].descProduto,S[i].descProduto);
        strcpy(A[k].tipoProduto,S[i].tipoProduto);
        A[k].codFornecedor2 = S[i].codFornecedor2;
        A[k].qtdEst = S[i].qtdEst;
        A[k].qtdEstMin = S[i].qtdEstMin;
        A[k].qtdEstMax = S[i].qtdEstMax;
        A[k].valorUnitario = S[i].valorUnitario;
        i++;
        k++;
     }
     while(j<contT){
         A[k].codProduto = T[j].codProduto;
        strcpy(A[k].descProduto,T[j].descProduto);
        strcpy(A[k].tipoProduto,T[j].tipoProduto);
        A[k].codFornecedor2 = T[j].codFornecedor2;
        A[k].qtdEst = T[j].qtdEst;
        A[k].qtdEstMin = T[j].qtdEstMin;
        A[k].qtdEstMax = T[j].qtdEstMax;
        A[k].valorUnitario = T[j].valorUnitario;
        j++;
        k++;
     }
   contA = k;
}

void mostrarInclusaoProduto(struct Produtos A[], int contA){

    cout<<"\n\nProdutos Atualizados"<<endl;
    for(int i=0;i<contA;i++){
            cout<<"\tCod Produto: " <<A[i].codProduto;
            cout<<"\tDescricao:"<< A[i].descProduto;
            cout<<"\tTipo Produto:"<<A[i].tipoProduto;;
            cout<<"\tCodigo Fonecedor"<<A[i].codFornecedor2;
            cout<<"\tQuantidade Estoque:"<<A[i].qtdEst;
            cout<<"\tQuantidade Maxima Estoque:"<<A[i].qtdEstMax;
            cout<<"\tQuantidade Minima Estoque:"<<A[i].qtdEstMin;
            cout<<"\tValor Unitario: " <<A[i].valorUnitario;
            cout<<"\n\t-------------------------------------------------------------"<<endl;
    }
}

void buscaFornecedor(struct Fornecedores f[],int cod){
  int inicio = 0, fim = 10;
  int meio = (inicio+fim)/2;
  for(; fim>=inicio && cod!= f[meio].codFornecedor; meio = (inicio+fim)/2){
    if(cod > f[meio].codFornecedor)
        inicio = meio +1;
    else
        fim = meio -1;
  }

   if(cod == f[meio].codFornecedor){
    cout<<"\Nome Fornecedor:" <<f[meio].nomeFornecedor<<endl;

   }
  else
    cout<<"\nFornecedor Invalido"<<endl;
}

void buscaProduto(struct Produtos pro[],int &cod){
int inicio =0, fim =20;
int meio = (inicio +fim)/2;
for(; fim>=inicio && cod!= pro[meio].codProduto;meio = (inicio+fim)/2){
    if(cod > pro[meio].codProduto)
        inicio = meio +1;
    else
        fim = meio -1;
}

     if(cod ==pro[meio].codProduto){
        cout<<"\nPRODUTO: "<<cod<<" JA CADASTRADO!"<<endl;
         cod = 0;
         system("Pause");

     }

}
void buscaProdutovender(struct Produtos pro[],int &cod){
int inicio =0, fim =20;
int meio = (inicio +fim)/2;
for(; fim>=inicio && cod!= pro[meio].codProduto;meio = (inicio+fim)/2){
    if(cod > pro[meio].codProduto)
        inicio = meio +1;
    else
        fim = meio -1;
}

     if(cod ==pro[meio].codProduto){
        cout<<"Descricao: "<<pro[meio].descProduto<<endl;
        cout<<"Quantidade em estoque:"<<pro[meio].qtdEst<<endl;
        cout<<"Valor unitario: "<<pro[meio].valorUnitario<<endl;


     }

}

void buscaTipoProdutoVender(struct TipoProdutos tipo[],int &cod){
  int inicio=0, fim =20;
  int meio = (inicio+fim)/2;
  for(; fim>=inicio && cod!=tipo[meio].codTipoProd;meio = (inicio+fim)/2){
    if(cod> tipo[meio].codTipoProd)
        inicio = meio + 1;
    else
        fim = meio -1;
  }

  if(cod==tipo[meio].codTipoProd){
    cout<<"Descricao do tipo do produto: " <<tipo[meio].descTipoProd;

  }

}

void buscaVender(struct Produtos produto[],int cod,int &qtdvender);
void venderProduto(struct Fornecedores fornecedor[],struct TipoProdutos tipo[] ,struct Produtos produto[],struct Produtos prod[],int &contadorVenda){

    cout<<"\nDigite o codigo do Produto: ";
    cin>>prod[0].codProduto;
    if(prod[0].codProduto> 0){
        int cod2;
        cod2 = prod[0].codProduto;
        buscaProdutovender(produto,cod2);
        buscaTipoProdutoVender(tipo,cod2);
        buscaFornecedor(fornecedor,cod2);
        cout<<"\nQuantidade a ser vendida: ";
        int qtdvender;
        cin>> qtdvender;
        buscaVender(produto,cod2,qtdvender);


    }

}

void buscaVender(struct Produtos produto[],int cod,int &qtdvender){
int inicio = 0, fim =20;
int meio = (inicio+fim)/2;
for(; fim>=inicio && cod!=produto[meio].codProduto;meio = (inicio+fim)/2){
    if(cod > produto[meio].codProduto)
        inicio = meio+1;
    else
        fim = meio -1;
}
  if(cod == produto[meio].codProduto){
    if(qtdvender > produto[meio].qtdEst){
        cout<<"\n VALOR MAIOR QUE O ESTOQUE";
        system("pause");
        fim = 21;

    }
    cout<<"\n VALOR DA VENDA R$:" << qtdvender * produto[meio].valorUnitario;
    char conf;
    cout<<"\nConfirme a Venda [S/N]:";
    cin>> conf;
    if(conf == 'S'){
        produto[meio].qtdEst = produto[meio].qtdEst - qtdvender;
        cout<<"\nVenda Realizada"<<endl;
        cout<<"\nESTOQUE ATUALIZADO: "<<produto[meio].qtdEst;

    }
    else
        cout<<"\nVenda Cancelada";
  }



}

int main(){
struct TipoProdutos tipoprod[5]; //Struct dos Tipos Produtos
struct Fornecedores fornecedores1[5];//Struct dos Fornecdores
struct Produtos produtos1[5]; // Struct dos Produtos
struct Estado estado1[5];

int varleitura=1;
while(varleitura>0){

cout<<"\t\tMENU";//menu principal
cout<<"\n----------------\n";
cout<<"\t1- Cadastrar"<<endl;
cout<<"\t2- Inserir"<<endl;
cout<<"\t3- Vender"<<endl;
cout<<"\t4- Buscar"<<endl;
cout<<"\t0- Sair"<<endl;
cout<<"---------------\n";
cout<<"\t Escolha opcao: ";
cin>>varleitura;

system("cls");


switch(varleitura){

   case 1: //menu de leitura
   cout<<"Deseja cadastrar qual item abaixo:"<<endl;
   cout<<"\t1- Tipo do Produto"<<endl;
   cout<<"\t2- Fornecedor"<<endl;
   cout<<"\t3- Produto"<<endl;
   cout<<"\t4- Estado"<<endl;
   cout<<"\t0- Voltar"<<endl;
   cout<<"---------------\n";
   cout<<"\t Escolha opcao: ";
   int escolhaleitura;
   cin>>escolhaleitura;
   system("cls");

   switch(escolhaleitura){

   case 1:
       int contadorStipoprod;
       int qtdtipoler;
       cout<<"Deseja Ler quantos Tipos: "; //leitura do tipo Produto, Perguntando quantos deseja ler
       cin>>qtdtipoler;
       if(qtdtipoler > 0){
        LeituraTipoProd(tipoprod,contadorStipoprod,qtdtipoler);
       }
       else cout<<"\n Numero invalido";
       getch();
       system("cls");
     break;
   default:
    break;

   case 2:
    int contadorSFornecedor;
    int qtdFornecedorLer;
    cout<<"Deseja Ler quantos Fornecedores: "; //leitura do Fornecedor Perguntando quantos deseja ler
    cin>>qtdFornecedorLer;
    if(qtdFornecedorLer>0){
            LeituraFornecedor(fornecedores1,contadorSFornecedor,qtdFornecedorLer);
    }

    else cout<<"\n Numero invalido";
    getch();
    system("cls");

    break;

   case 3:
       int contadorProduto;
       int qtdProdutoLer;
       cout<<"Deseja Ler Quantos Produtos: "; //leitura do Produto Perguntando quantos deseja ler
       cin>>qtdProdutoLer;
       if(qtdProdutoLer>0){
        LeituraProduto(produtos1,contadorProduto,qtdProdutoLer);
       }
       else cout<<"\nNumero Invalido";
       getch();
       system("cls");
       break;

   case 4:
        int contadorEstado;
        int qtdEstado;
        cout<<"\nDeseja Ler Quantos Estado: ";
        cin>>qtdEstado;
        if(qtdEstado> 0){
            LeituraEstado(estado1,contadorEstado,qtdEstado);
        }
        else cout<<"\nNumero invalido";
        system("cls");

   }
   escolhaleitura = 0;
   break;


   case 2: //Menu Inserir
    cout<<"Deseja Inserir qual item abaixo:"<<endl;
    cout<<"\t1- Tipo do Produto"<<endl;
    cout<<"\t2- Fornecedor"<<endl;
    cout<<"\t3- Produto"<<endl;
    cout<<"\t4- Estado"<<endl;
    cout<<"\t0- Voltar"<<endl;
    cout<<"---------------\n";
    cout<<"\t Escolha opcao: ";
    int inserirdado;
    cin>>inserirdado;

    system("cls");

    switch(inserirdado){

    case 3:
        struct Produtos produtosS[20],produtosT[20],produtosA[40];
        int contpS, contpT,contpA;

        cout<<"\nLeitura do Arquivo S";
        leituraProdutoinc(fornecedores1,produtos1,produtosS,contpS);
        system("cls");



        cout<<"\nLeitura Arquivo T";
        leituraProdutoinc(fornecedores1,produtos1,produtosT,contpT);
        system("cls");

        incluirProduto(produtosS,contpS,produtosT,contpT,produtosA,contpA);
        mostrarInclusaoProduto(produtosA,contpA);
        getch();
        system("cls");
           break;

    case 2:
        struct Fornecedores fornecedoresS[20], fornecedoresT[20], fornecedoresA[40];
        int contS, contT, contA;

        cout<<"\n\nLeitura do Arquivo S";
        LeituraFornecedorinc(estado1,fornecedoresS,contS);
        system("cls");

        cout<<"\nLeitura do Arquivo T";
        LeituraFornecedorinc(estado1,fornecedoresT,contT);
        system("cls");

        incluirFornecedor(fornecedoresS,contS,fornecedoresT,contT,fornecedoresA,contA);
        mostrarInclusao(fornecedoresA,contA);
        getch();
        system("cls");
        break;

    }
    inserirdado = 0;
   break;

    case 3:
        struct Produtos produtosVenda[5];
        int contadorVenda;

        venderProduto(fornecedores1,tipoprod,produtos1,produtosVenda, contadorVenda);


        getch();
        system("cls");
        break;
 varleitura = 0;
       }

  }
 }
