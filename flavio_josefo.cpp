//librerias a incluir
#include <iostream>
using namespace std;

//definiciones
struct Persona{
    string nombre;
    Persona* next;
};

//prototipos
Persona* crear_persona();
Persona* ultima_persona(Persona*);
Persona* buscar_persona(Persona*);
void imprimir_lista(Persona*,int);
void llenar_lista(Persona**,int*);
void ruleta(Persona*,int* tamanio);
void insertar_persona(Persona**,int*);
void eliminar_persona(Persona**,Persona*);

int main(){
    int tamanio=0;
    Persona *raiz=NULL;
    llenar_lista(&raiz,&tamanio);
    ruleta(raiz,&tamanio);
    return 0;
}

Persona* crear_persona(){
    string nombre;
    cout<<"DIGITA EL NOMBRE DE LA PERSONA QUE DESEAS INGRESAR: ";
    cin>>nombre;
    Persona *nueva_persona=new Persona();
    nueva_persona->nombre=nombre;
    return nueva_persona;
}

void insertar_persona(Persona** raiz,int* tamanio){
    Persona *nueva_persona=crear_persona();
    if(*raiz==NULL){
        *raiz=nueva_persona;
        nueva_persona->next=*raiz;
        *(tamanio)+=1;
    }
    else{
        Persona* temporal=ultima_persona(*raiz);
        temporal->next=nueva_persona;
        nueva_persona->next=*raiz;
        *(tamanio)+=1;
    }
}

void llenar_lista(Persona** raiz,int*tamanio){
    char opcion;
    do{
        insertar_persona(raiz,tamanio);
        cout<<"DESEAS INGRESAR A OTRA PERSONA? (NO=N,SI=CUALQUIER OTRA TECLA) "<<endl;
        cin>>opcion;
    }while(opcion!='N');

}

Persona* ultima_persona(Persona *raiz){
    Persona *aux;
    aux=raiz;
    while(aux->next!=raiz){
        aux=aux->next;
    }
    return aux;
}

void imprimir_lista(Persona* raiz,int tamanio){
    Persona* aux=raiz;
    cout<<endl;
    for(int i=0;i<tamanio;i++)
    {
        cout<<aux->nombre<<endl;
        aux=aux->next;
    }
}

Persona* buscar_persona(Persona*raiz){
    string nombre;
    Persona* aux=raiz;
    cout<<"DESDE QUE PERSONA QUIERES COMENZAR?"<<endl;
    cout<<"NOTA: SI HAY DOS PERSONAS CON EL MISMO NOMBRE SE COMENZARA DESDE EL QUE APAREZCA PRIMERO EN LA LISTA"<<endl;
    cin>>nombre;
    while(aux->nombre!=nombre){
        aux=aux->next;
    }
    return aux;
}

void eliminar_persona(Persona**raiz,Persona* persona){
    Persona* aux=*raiz;
    while(aux->next!=persona){
        aux=aux->next;
    }
    if(persona==*raiz){
        aux->next=persona->next;
        *raiz=persona->next;
    }
    else{
        aux->next=persona->next;
    }
    delete persona;
}

void ruleta(Persona* raiz,int* tamanio){
    int saltos=0;
    cout<<"INGRESA EL NUMERO DE PERSONAS QUE QUIERES SALTAR"<<endl;
    cin>>saltos;
    Persona* aux=buscar_persona(raiz);
    Persona* aux2;
    while(*tamanio!=1){
        for(int i=0;i<=saltos;i++){
            aux=aux->next;
        }
        *(tamanio)-=1;
        aux2=aux->next;
        eliminar_persona(&raiz,aux);
        aux=aux2;
    }
    cout<<"FELICIDADES AL SOBREVIVIENTE";
    imprimir_lista(raiz,*tamanio);
}