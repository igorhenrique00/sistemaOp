#include <iostream>
#include "Disco.hpp"
#include <stdio.h>
#include <string>
#include <cstring>
#include <fstream>//ofstream, ifstream, fstream

using namespace std;

int main()
{
    Disco d;
    int op, contlinha;

    ifstream arq;
    arq.open("arquivo.txt");
    string linha;
    if(arq.is_open()){
        while(getline(arq,linha)){
        cout<<linha<<endl;
        contlinha++;
        char *pt;
        const char sep[] = "AP<> , ' '";
        char* cpylinha = (char*)malloc(strlen(linha.c_str())+1);
        strcpy(cpylinha,linha.c_str());
        pt = strtok(cpylinha,sep);
            while(pt){
                cout<<"token:  "<<pt<<endl;
                pt = strtok(NULL, sep);
            }
        }
    cout<< "Numero de linhas : "<<contlinha<<endl;
    arq.close();
    }
    else{
        cout<<"O ARQUIVO NAO FOI ENCONTRADO"<<endl;
    }

    do{
        cout << "MENU:" << endl;
        cout<<"1-Carregar Disco\n2-Executar Processos\n0-Sair"<<endl;
        cin>>op;
        switch(op){
            case 0:
            exit(1);
            case 1:
            d.CarregarDisco();
            break;
            case 2:
            //p.ExecutarProcessos();
            break;
            default:
            cout<<"Nenhuma opcao válida.\nTente novamente."<<endl;
        }
    }while(op!=0);



    return 0;
}
