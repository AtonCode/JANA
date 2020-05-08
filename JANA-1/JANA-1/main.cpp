//
//  main.cpp
//  |JANA|
//
//  Created by Alejandro Sacristán Leal on 4/04/20.
//  Copyright © 2020 aslbank.com. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <cstdlib>
#define SIZE 6


using namespace std;

int size= 10;

    string os="clear";//EN caso windows es cls.

   //Funciones
   bool welcome();
   bool Create_Acount(bool NotUser,string UserMatrix[6][6]);

   //Variables que almacenan returns de Funciones
   bool Func_Welcome;
   bool Func_Create_Acount;
   bool Func_Create_Acount2;
    

   //Vectores de Usuarios
    string UserMatrix[6][6];
   


//Función Principal
int main()
{
    
    //Bienbenida al programa y pregunta si es o no usuario
    //La funcion devuelve un valor yes o no
    //Evaluamos la respuesta del usuario las funcion retorna un true o false.
    //True para usarios y false para no usuarios.
    Func_Welcome= welcome();
    //Limpiamos la terminal
    //system("clear");
    Func_Create_Acount=Create_Acount(Func_Welcome,UserMatrix);
    Func_Create_Acount2=Create_Acount(Func_Create_Acount,UserMatrix);
    Create_Acount(Func_Create_Acount2,UserMatrix);
    
    
    
    //Login con el dato true de Func_Create_Acount2
    
    
    
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
    string acount="HEH";
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
    getline(cin,acount);
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
                    getline(cin, UserMatrix[fila][CountUsers]);
                    cout<<"  "<<endl;
                }
                if(fila==1)
                {
                    cout<<" -| Second: Give Me Your Javeriana Email: ";
                    getline(cin, UserMatrix[fila][CountUsers]);
                    cout<<"  "<<endl;
                }
                if(fila==2)
                {
                    cout<<" -| Third: Give Me Your Profession: ";
                    getline(cin, UserMatrix[fila][CountUsers]);
                    cout<<"  "<<endl;
                }
                if(fila==3)
                {
                    cout<<" -| Quarter: Give Me Your Sex (M/F): ";
                    getline(cin, UserMatrix[fila][CountUsers]);
                    cout<<"  "<<endl;
                }
                if(fila==4)
                {
                    cout<<" -| Fifth: Give Me Your Born Date(DD/MM/AA): ";
                    getline(cin, UserMatrix[fila][CountUsers]);
                    cout<<"  "<<endl;
                }
                if(fila==5)
                {
                    cout<<" -| Sixth: Create a Password: ";
                    getline(cin, UserMatrix[fila][CountUsers]);
                    cout<<"  "<<endl;
                }
               
                
            }//For Fila End
            state= true;
            
        }//For Columns End
       //Limpiamos la terminal
       system("clear");
        //Hora imprimimos la información dada por el ususrio para verificarla.
        cout<<"\t\t\t-|*|--------------------|*|-"<<endl;
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
        getline(cin,change);
        if(change=="y"|change=="yes"|change=="Y"|change=="YES")
        {
            pass=false;
            
        }else{
            pass=true;
            cout<<" "<<endl;
            cout<<" -| Successful account process!!! "<<endl;
            cout<<" "<<endl;
        }
        
        
    //Uso solo para saber el orden de las columnas
          
    }//IF END
    

    
    return pass;

}

