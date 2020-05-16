//
//
//  main.cpp
//  |JANA|
//
//  Copyright © 2020 aslbank.com. All rights reserved.
//
//
#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#define SIZE 6


using namespace std;

int size= 10;

string os="clear";//EN caso windows es clear.

//Matriz de Usuarios
string UserMatrix[6][6]; //Cada Columna es un usuario

struct USER{
    string email;
    string password;
    bool auth;
};

//DeclaraciÛn de Funciones
bool welcome();
bool Create_Acount(bool NotUser,string UserMatrlix[6][6]);
bool validarEmail(string correo);
USER login();
bool authenticate(string correo, string password);
void menu(USER user);
void func_agregar_dispositivos(USER user);
void func_eliminar_dispositivos(USER user);
void func_listar_dispositivos(USER user);
void func_modificar_caracteristicas_dispositivos(USER user);
void func_modificar_funcionalidades_dispositivos(USER user);

//FunciÛn Principal
int main()
{

    //Bienbenida al programa y pregunta si es o no usuario
    //La funcion devuelve un valor yes o no
    //Evaluamos la respuesta del usuario las funcion retorna un true o false.
    //True para usarios y false para no usuarios.

    //Variables de Retorno
    bool Func_Welcome;
    bool Func_Create_Acount;
    
    //Limpiamos la terminal
    //system("clear");
    USER usuario;
    do{
        Func_Welcome= welcome();
        do{
            Func_Create_Acount=Create_Acount(Func_Welcome,UserMatrix);
        }while(!Func_Create_Acount);
        usuario=login();
    }while(!usuario.auth);
    menu(usuario);

    return 0;
}

/*

Funcion que pegunta al usuario
es nuevo o existente retornando
su respuesta (yes/no).

*/
bool welcome()
{
    //Se inicializa una variables string para almacenar la respesta
    //Se inicializa variable booleana
    string acount;
    bool estado;

    //Se imprime un mensaje de bienvenida
    system("clear");
    cout<< "\t\t\t--------------------"<<endl;
    cout<< "\t\t\t-| Welcome to JANA |-"<<endl;
    cout<< "\t\t\t---------------------"<<endl;
    cout<< "\t\t\t                    "<<endl;
    cout<< "\t\t\t                    "<<endl;

    //Se pregunnta si tiene cuenta o no
    cout<< " -| Hi, you have acount? (yes/no): ";
    //Se alamacena la respuesta en acount
    cin>>acount;
    cout<<"  "<<endl;


    //Se evalua la respuesta del usuario para saber si es nuevo o existente.
    if(acount=="yes"||acount=="YES"||acount=="y"||acount=="Y")
    {
        //En caso de que sea usuario activo.
        estado=true;
        cout<<" -| Oh you are a Active User!!!"<<endl;
        cout<<"  "<<endl;
    }
    else
    {
        //En caso de que sea un nuevo usuario.
        estado=false;

    }

    //Se retorna el resultado de la evaluacion.
    return estado;
}

//Funcion que crea Usuarios
bool Create_Acount(bool NotUser,string UserMatrix[6][6])
{

    int CountUsers=0,fila=0;
    bool pass=true;
    string change="j";

    if (NotUser==false)//CREAR Cuenta en VectUsers.
    {
        bool state=false;
        cout<<" -| Oh you need create a Acount!!!"<<endl;
        cout<<"  "<<endl;
        cout<<" -| Very well now i will help to create your user."<<endl;
        cout<<"  "<<endl;
        //Gurdando Usuarios en La Matrix De Usuarios
        for(CountUsers=CountUsers;state==false;CountUsers++)
        {
            cout<<" -| Now you are a User: "<<CountUsers+1<<endl;
            cout<<"  "<<endl;

            for (fila=0;fila<=6;fila++)
            {

                if(fila==0)
                {
                    cout<<" -| First: Give Me Your First Name and Last Name: ";
                    cin>>UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==1)
                {
                    bool valido=true;
                    do{
                        cout<<" -| Second: Give Me Your Javeriana Email: ";
                        cin>>UserMatrix[fila][CountUsers];
                        valido=validarEmail(UserMatrix[fila][CountUsers]);
                        if(!valido)
                            cout<<"Error: There is already a user registered with that email"<<endl;
                        cout<<"  "<<endl;
                    }while(!valido);
                }
                if(fila==2)
                {
                    cout<<" -| Third: Give Me Your Profession: ";
                    cin>>UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==3)
                {
                    cout<<" -| Quarter: Give Me Your Sex (M/F): ";
                    cin>>UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==4)
                {
                    cout<<" -| Fifth: Give Me Your Born Date(DD/MM/AA): ";
                    cin>>UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==5)
                {
                    cout<<" -| Sixth: Create a Password: ";
                    cin>>UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }


            }//For Fila End
            state= true;

        }//For Columns End
       //Limpiamos la terminal
        system("clear");
        //Hora imprimimos la informaciÛn dada por el ususrio para verificarla.
        cout<<"  "<<endl;
        cout<<" -| "<<UserMatrix[0][CountUsers-1]<<" Check that it is the correct information. "<<endl;
        cout<<"  "<<endl;
        CountUsers=CountUsers;
        state= false;
        for(CountUsers=CountUsers-1;state==false;CountUsers++)
        {
            cout<<" -| Now you are a User: "<<CountUsers+1<<endl;
            cout<<"  "<<endl;

            for (fila=0;fila<=6;fila++)
            {
                if(fila==0)
                {
                    cout<<" -| First: Your First Name and Last Name: "
                    <<UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==1)
                {
                    cout<<" -| Second: Your Javeriana Email: "
                    <<UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==2)
                {
                    cout<<" -| Third: Your Profession: "
                    <<UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==3)
                {
                    cout<<" -| Quarter: Your Sex (M/F): "
                    <<UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==4)
                {
                    cout<<" -| Fifth: Your Born Date(DD/MM/AA): "
                    <<UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }
                if(fila==5)
                {
                    cout<<" -| Sixth: Your Password: "
                    <<UserMatrix[fila][CountUsers];
                    cout<<"  "<<endl;
                }


            }//For Fila End
            state= true;
        }//For Columns End
        cout<<" "<<endl;
        cout<<" -| Do you want to change something? (yes/no): ";
        cin>>change;
        if(change=="y" || change=="yes" || change=="Y" || change=="YES")
        {
            system("clear");
            pass=false;

        }else{
            pass=true;
            cout<<" "<<endl;
            cout<<" -| Successful account process!!! "<<endl;
            CountUsers++;
            cout<<" "<<endl;
        }
    //Uso solo para saber el orden de las columnas

    }//IF END
    return pass;

}

bool validarEmail(string correo){
    for(int i=0;i<6;i++){
        if(correo==UserMatrix[1][i])
            return true;
    }
    return true;
}

USER login()
{
    string correo;
    string password;
    bool auth;
    string again;
    USER user;
    do{
        cout<<" -| Give me your Javeriana email:"<<endl;
        cin>>correo;
        cout<<" -| Give me your password:"<<endl;
        cin>>password;
        user.email=correo;
        user.password=password;
        user.auth=true;
        auth=authenticate(correo,password);
        if(auth==true){
            cout<<"Authentication Success!"<<endl;
            return user;
        }
        else{
            cout<<"Authentication Failed. Please, try again!"<<endl;
            cout<<"Do you want to try again? (yes/no):"<<endl;
            cin>>again;
            if(again=="no"||again=="NO"||again=="n"||again=="N"){
                user.auth=false;
                return user;
            }
            system("clear");
        }
    }while(!auth);
    return user;

}

bool authenticate(string correo,string password)
{
    bool r=true;
    
    for(int i=0;i<6;i++){
        if(correo!=UserMatrix[1][i])
        {
            r= false;
            
        }
        if(password!=UserMatrix[5][i])
        {
            r= false;
        }
            
        r= true;
    }
    
    return r;
}

void menu(USER user){
    int opcion;
    cout<<" -| Welcome to JANA Menu"<<endl;
    cout<<" -| 1. Agregar Dispositivos"<<endl;
    cout<<" -| 2. Eliminar Dispositivos"<<endl;
    cout<<" -| 3. Listar Dispositivos"<<endl;
    cout<<" -| 4. Modificar Caracteristicas Dispositivos"<<endl;
    cout<<" -| 5. Modificar Funcionalidades Dispositivos"<<endl<<endl;
    cout<<" -| Type the option do you want to access (1-8)"<<endl;
    cin>>opcion;

    switch(opcion){
        case 1:
            cout<<" -| Opcion: Agregar Dispositivos"<<endl;
            func_agregar_dispositivos(user);
            break;
        case 2:
            cout<<" -| Opcion: Eliminar Dispositivos"<<endl;
            func_eliminar_dispositivos(user);
            break;
        case 3:
            cout<<" -| Opcion: Listar Dispositivos"<<endl;
            func_listar_dispositivos(user);
            break;
        case 4:
            cout<<" -| Opcion: Modificar Caracteristicas Dispositivos"<<endl;
            func_modificar_caracteristicas_dispositivos(user);
            break;
        case 5:
            cout<<" -| Opcion: Modificar Funcionalidades Dispositivos"<<endl;
            func_modificar_funcionalidades_dispositivos(user);
            break;
        default:
            cout<<" -| Ingrese un numero de opcion valido"<<endl;
            break;
    }
}


void func_agregar_dispositivos(USER user){

}

void func_eliminar_dispositivos(USER user){

}

void func_listar_dispositivos(USER user){

}

void func_modificar_caracteristicas_dispositivos(USER user){

}

void func_modificar_funcionalidades_dispositivos(USER user){

}
