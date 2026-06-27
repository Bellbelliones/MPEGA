#include <stdio.h>
#include <string.h>

#include "ficheiros.h"

//existeMotorista()//

int existeMotorista(int idMotorista)
{
    FILE *f;

    Motorista motorista;

    f=fopen("motoristas.dat","rb");

    if(f==NULL)
    {
        return 0;
    }

    while(fread(&motorista,sizeof(Motorista),1,f))
    {
        if(motorista.idMotorista==idMotorista)
        {
            fclose(f);
            return 1;
        }
    }

    fclose(f);

    return 0;
}

// GuardarMotorista//

int guardarMotorista(Motorista motorista)
{

    FILE *f;

    if(motorista.idMotorista<=0)
    {
        printf("Erro: ID inválido.\n");
        return 0;
    }

    if(strlen(motorista.nome)==0)
    {
        printf("Erro: Nome obrigatório.\n");
        return 0;
    }

    if(strlen(motorista.BI)==0)
    {
        printf("Erro: BI obrigatório.\n");
        return 0;
    }

    if(strlen(motorista.telefone)==0)
    {
        printf("Erro: Telefone obrigatório.\n");
        return 0;
    }

    if(existeMotorista(motorista.idMotorista))
    {
        printf("Erro: Motorista já cadastrado.\n");
        return 0;
    }

    f=fopen("motoristas.dat","ab");

    if(f==NULL)
    {
        printf("Erro ao abrir ficheiro.\n");
        return 0;
    }

    fwrite(&motorista,sizeof(Motorista),1,f);

    fclose(f);

    printf("Motorista guardado com sucesso.\n");

    return 1;

}

// ExisteMatricula//


int existeMatricula(char matricula[])
{

    FILE *f;

    Veiculo veiculo;

    f=fopen("veiculos.dat","rb");

    if(f==NULL)
    {
        return 0;
    }

    while(fread(&veiculo,sizeof(Veiculo),1,f))
    {
        if(strcmp(veiculo.matricula,matricula)==0)
        {
            fclose(f);
            return 1;
        }
    }

    fclose(f);

    return 0;

}

// Guardar veículo//




int guardarVeiculo(Veiculo v)
{
    FILE *f;

    if(v.capacidade <= 0)
        return 0;

    if(v.lugaresDisponiveis >
       v.capacidade)
        return 0;

    if(existeMatricula(v.matricula))
        return 0;

    atualizarEstadoVeiculo(&v);

    f = fopen("veiculos.dat","ab");

    if(f == NULL)
        return 0;

    fwrite(&v,
           sizeof(Veiculo),
           1,
           f);

    fclose(f);

    return 1;
}

void atualizarEstadoVeiculo(Veiculo *veiculo)
{

    if(veiculo->lugaresDisponiveis==0)
    {
        strcpy(veiculo->estado,"Cheio");
    }

    else if(veiculo->lugaresDisponiveis<=2)
    {
        strcpy(veiculo->estado,"Quase Lotado");
    }

    else if(veiculo->lugaresDisponiveis==veiculo->capacidade)
    {
        strcpy(veiculo->estado,"Vazio");
    }

    else
    {
        strcpy(veiculo->estado,"Disponível");
    }


    

}




