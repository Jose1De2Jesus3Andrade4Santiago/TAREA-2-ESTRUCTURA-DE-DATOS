//librerias
#include<iostream>
using namespace std;

//definiciones
struct Libro{
    char *titulo;
    int anioDePublicacion;
    struct Libro* next;
    struct Libro* previous;
};

//prototipos
Libro* crear_libro();
void insertar_libro(Libro** ,Libro**);
void imprimir_ascendente(Libro* );
void imprimir_descendente(Libro* ,Libro* );
Libro* buscar_libro(Libro* );
void modificar_libro(Libro* );
void borrar_libro(Libro**,Libro**);

int main(){
    Libro* lista=NULL;
    Libro* cola=NULL;
	return 0;
}

Libro* crear_libro(){
    int anio=0;
    char *titulo=new char[64];
    cout<<"INGRESA EL TITULO DEL LIBRO QUE DESEAS INGRESAR: "<<endl;
     cin>>titulo;
    cout<<"INGRESA EL ANIO DE PUBLICACION DEL LIBRO QUE DESEAS INGRESAR: "<<endl;
    cin>>anio;
    Libro* nuevo_libro=new Libro();
    nuevo_libro->titulo=titulo;
    nuevo_libro->anioDePublicacion=anio;
    return nuevo_libro;
}

void insertar_libro(Libro** lista,Libro** cola){
    Libro* nuevo_libro=crear_libro();
    if(*lista==NULL){
        *lista=nuevo_libro;
        nuevo_libro->next=NULL;
        nuevo_libro->previous=NULL;
        *cola=nuevo_libro;
    } 
    else{
        Libro* aux=*cola;
        aux->next=nuevo_libro;
        nuevo_libro->previous=aux;
        nuevo_libro->next=NULL;
        *cola=nuevo_libro;
    }
}

void imprimir_ascendente(Libro* lista){
    Libro* aux=lista;
    if(lista==NULL){
        cout<<"Lista vacia"<<endl;
    }
    while(aux!=NULL){
        cout<<aux->titulo<<endl;
        cout<<aux->anioDePublicacion<<endl;
        aux=aux->next;
    }
}

void imprimir_descendente(Libro* lista,Libro* cola){
    Libro* aux=cola;
    if(lista==NULL){
        cout<<"Lista vacia"<<endl;
    }
    while(aux!=NULL){
        cout<<aux->titulo<<endl;
        cout<<aux->anioDePublicacion<<endl;
        aux=aux->previous;
    }
}

Libro* buscar_libro(Libro* lista){
    if(lista==NULL){
        cout<<"TU LISTA ESTA VACIA, INGRESA ELEMENTOS EN ELLA PARA PODER BUSCAR"<<endl;
        break;
    }
    else{
        char *titulo=new char[64];
        int anio=0;
        cout<<"QUE LIBRO ESTAS BUSCANDO? "<<endl;
        cin>>titulo;
        cout<<"EN QUE ANIO SE PUBLICO? "<<endl;
        cin>>anio;
        Libro* aux=lista;
        while(aux!=NULL && aux->titulo!=titulo && aux->anioDePublicacion!=anio){
            aux=aux->next;
        }
        return aux;
    }
}

void modificar_libro(Libro* lista){
    Libro* modificado=buscar_libro(lista);
    cout<<"DIGITA EL NUEVO TITULO: "<<endl;
    cin>>modificado->titulo;
    cout<<"DIGITA EL NUEVO ANIO DE PUBLICACION: "<<endl;
    cin>>modificado->anioDePublicacion;
}

void borrar_libro(Libro** lista,Libro** cola){
	Libro* borrado=buscar_libro(*lista);
    if(*lista==*cola){//primer caso cuando la lista tiene un unico elemento
        *lista=NULL;
        *cola=NULL;
    }
    else{
        if(borrado==*lista){//segundo caso cuando queremos eliminar la raiz
            Libro*posterior=*cola;
            while(posterior->previous!=*lista){
                posterior=posterior->previous;
            }
            *lista=posterior;
            posterior->previous=NULL;
        }
        if(borrado==*cola){//tercer caso cuando queremos borrar un elemento al final de la lista
        	Libro* anterior=*cola;
            anterior=borrado->previous;
            anterior->next=NULL;
        }
        else{//cuarto caso cuando queremos eliminar un elemento de en medio
        	Libro* anterior=*lista;
        	Libro* posterior=*cola;
        	while(anterior->next!=borrado){
        		anterior=anterior->next;
			}
			while(posterior->previous!=borrado){
				posterior=posterior->previous;
			}
            anterior->next=borrado->next;
            posterior->previous=borrado->previous;
		}
    }
    delete borrado;
}