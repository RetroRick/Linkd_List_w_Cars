#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char brand[20];
    char model[20];
    int year;
    float consumption;
    struct car *next;
} car;

car *head = NULL;

void write();
void read();
void list_car();
void ord_cons();
void ord_year();
void reg_car();
void greater_cons();
void smallest_cons();
void del_st_item();

int main() {
    int opcao = -1;
    read();
    while (opcao != 0) {
        printf("\n\nMenu\n\nEscolha uma das opcoes abaixo:\n");
        printf("1-Inserir Carro:\n");
        printf("2-Lista Carros:\n");
        printf("3-Carro com maior consumo:\n");
        printf("4-Carro com menor consumo:\n");
        printf("5-Imprimir lista por ordem decresc. de consumo:\n");
        printf("0-Sair do programa:\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                reg_car();
                write();
                break;
            case 2:
                list_car();
                break;
            case 3:
                greater_cons();
                break;
            case 4:
                smallest_cons();
                break;
            case 5:
                ord_cons();
                break;
            case 0:
                write();
                exit(0);
                break;
            default:
                printf("Introduza uma opcao valida\n");
                break;
        }
    }
    return 0;
}

void write(){
    car *pt = head;
    FILE *fptr;
    fptr = fopen ("cars.b","wb");

    if(fptr == NULL){
        printf("Erro ao abrir ficheiro");
        return;
    }
    while(pt != NULL){
        fwrite(pt, sizeof(car), 1, fptr);
        pt = pt->next;
    }

    fclose(fptr);

}



void read(){
    FILE *fptr;
    fptr = fopen ("cars.b","rb");

    if(fptr == NULL){
        printf("Erro ao abrir ficheiro");
        return;
    }

    while (1){
        car *newcar = malloc(sizeof(car));
        if (fread(newcar, sizeof(car),1,fptr)==0 ){
            fclose(fptr);
            return;
        }
        newcar->next = head;
        head = newcar;
    }

    fclose(fptr);

}

void list_car(){
    car *ptr =  head;

    printf("Brand\tModel\tYear\tComsumption:\n");
    while (ptr != NULL) {

        printf("%s \t%s \t%d \t%.2f\n",
               ptr->brand,
               ptr->model,
               ptr->year,
               ptr->consumption);

        ptr = ptr->next;
    }
}

void ord_cons(){

    int nao_houve_mais_trocas = 1;


    while (nao_houve_mais_trocas == 1) {

        nao_houve_mais_trocas = 0;

        car *ptr = head;
        car *prev = NULL;

        while (ptr != NULL) {
            car *nextCar = ptr->next;
            if (nextCar == NULL) break;
            if (ptr->consumption > nextCar->consumption) {
                nao_houve_mais_trocas = 1;
                ptr->next = nextCar->next;
                if (prev != NULL)
                    prev->next = nextCar;
                else
                    head = nextCar;
                nextCar->next = ptr;
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }
}

void ord_year(){

    int nao_houve_mais_trocas = 1;


    while (nao_houve_mais_trocas == 1) {

        nao_houve_mais_trocas = 0;

        car *ptr = head;
        car *prev = NULL;

        while (ptr != NULL) {
            car *nextCar = ptr->next;
            if (nextCar == NULL) break;
            if (ptr->year > nextCar->year) {
                nao_houve_mais_trocas = 1;
                ptr->next = nextCar->next;
                if (prev != NULL)
                    prev->next = nextCar;
                else
                    head = nextCar;
                nextCar->next = ptr;
            }
            prev = ptr;


            ptr = ptr->next;
        }
    }
}



void reg_car(){
    car *new_car =(car*)malloc(sizeof(car));
    printf("Registe a marca do carro\n");
    scanf("%s", new_car->brand);
    printf("Registe o modelo do carro\n");
    scanf("%s", new_car->model);
    printf("Introduza o ano do carro\n");
    scanf("%d", &new_car->year);
    printf("Introduza o consumo do carro\n");
    scanf("%f", &new_car->consumption);

    new_car->next= head;
    head = new_car;
}

void greater_cons() {
    car *ptr =  head;
    car *ptr_2 = head;
    printf("Comsumption:\n");
    while (ptr != NULL) {
        if (ptr->consumption > ptr_2->consumption) {
            ptr_2 = ptr;

        }
        ptr = ptr->next;
    }
    printf("O carro com maior consumo e %s %s que consome %.2f\n", ptr_2->brand,ptr_2->model, ptr_2->consumption);
}

void smallest_cons() {
    car *ptr =  head;
    car *ptr_2 = head;
    printf("Comsumption:\n");
    while (ptr != NULL) {
        if (ptr->consumption < ptr_2->consumption) {
            ptr_2 = ptr;


        }
        ptr = ptr->next;
    }
    printf("O carro com menor consumo e %s %s que consome %.2f\n", ptr_2->brand,ptr_2->model, ptr_2->consumption);
}

void del_st_item()
{
    car *ptr = head
}