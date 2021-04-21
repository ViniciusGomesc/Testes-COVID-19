    arq = fopen("testes.txt", "r");


    if(arq != NULL){

        clscr();
        printf("\n\n\n\n\n\n\n\n                                  Carrengando os dados");
        saving(3, 2);
        
        verificaArquivo(dataPeople, &numeroDeTestes);
    }

    fclose(arq);