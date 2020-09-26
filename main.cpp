#include <allegro.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <string>
#include <sstream>

#include <fstream>
#include <nlohmann/json.hpp>

#include "Clases/Imagenes.cpp"

BITMAP *buffer;
BITMAP *fondo;

using namespace std;
using namespace nlohmann;

string str;

int menu();
int opciones();
void jugar(int basepal);

vector<Imagen> cargarJson(string categoria);

int main()
{
    int opcionppal, salir, basepal;

    allegro_init();
    install_keyboard();
    install_mouse();

    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
    show_mouse(screen);

    set_window_title("A PENSAR");

    buffer = create_bitmap(640, 480);

    fondo = load_bitmap("img/Fondo.bmp", NULL);


    while(salir != 3){

        opcionppal = menu();

        switch(opcionppal){

            case 1:
                jugar(opciones());

            break;

            case 2:



            break;

        }



    }

    draw_sprite(buffer,fondo,0,0);
    masked_blit(fondo,buffer, 0,0,0,0,716,506);
    blit(buffer,screen, 0,0,0,0,640,480);
    clear(buffer);

    readkey();

    return 0;
}
END_OF_MAIN();

int menu(){

    int i, click = 1, accion;

    BITMAP *buffer = create_bitmap(640,480);

    BITMAP *menu;
    BITMAP *menu1;
    BITMAP *menu2;
    BITMAP *menu3;

    menu = load_bitmap("img/Menu.bmp",NULL);
    menu1 = load_bitmap("img/Menu1.bmp",NULL);
    menu2 = load_bitmap("img/Menu2.bmp",NULL);
    menu3 = load_bitmap("img/Menu3.bmp",NULL);

    while(click == 1){

        i = 0;

        if(i == 0){

            draw_sprite(buffer,menu,0,0);

        }

        if(mouse_x > 30 && mouse_x < 320 && mouse_y > 142 && mouse_y < 240){

            draw_sprite(buffer,menu1,0,0);

            if(mouse_b & 1){

                accion = 1;
                click = 0;

            }

            i = 1;

        }

        if(mouse_x > 30 && mouse_x < 490 && mouse_y > 250 && mouse_y < 320){

            draw_sprite(buffer, menu2, 0, 0);

            if(mouse_b & 1){

                accion = 2;
                click = 0;

            }

            i = 2;

        }

        if(mouse_x > 30 && mouse_x < 255 && mouse_y > 330 && mouse_y < 410){

            draw_sprite(buffer,menu3,0,0);

            if(mouse_b & 1){

                accion = 3;
                click = 0;

            }

            i = 3;

        }

        blit(buffer, screen, 0, 0, 0, 0, 640, 480);

    }

    clear(buffer);
    return accion;

}

int opciones(){

    int i, click = 1, basepal;

    buffer = create_bitmap(640, 480);

    BITMAP *fondo_opciones;
    BITMAP *fondo_opciones1;
    BITMAP *fondo_opciones2;
    BITMAP *fondo_opciones3;

    fondo_opciones = load_bitmap("img/Menu_Opciones.bmp", NULL);
    fondo_opciones1 = load_bitmap("img/Menu_Opciones1.bmp", NULL);
    fondo_opciones2 = load_bitmap("img/Menu_Opciones2.bmp", NULL);
    fondo_opciones3 = load_bitmap("img/Menu_Opciones3.bmp", NULL);

    while(click == 1){

        i = 0;

        if(i == 0){

            draw_sprite(buffer, fondo_opciones, 0, 0);

        }

        if(mouse_x > 30 && mouse_x < 250 && mouse_y > 225 && mouse_y < 265){

            draw_sprite(buffer, fondo_opciones1, 0, 0);

            if(mouse_b & 1){

                click = 0;
                basepal = 1;

            }

            i = 1;

        }

        if(mouse_x > 30 && mouse_x < 200 && mouse_y > 295 && mouse_y < 340){

            draw_sprite(buffer, fondo_opciones2, 0, 0);

            if(mouse_b & 1){

                click = 0;
                basepal = 2;

            }

            i = 2;

        }

        if(mouse_x > 30 && mouse_x < 580 && mouse_y > 370 && mouse_y < 415){

            draw_sprite(buffer, fondo_opciones3, 0, 0);

            if(mouse_b & 1){

                click = 0;
                basepal = 3;

            }

            i = 3;

        }

        blit(buffer, screen, 0, 0, 0, 0, 640, 480);

    }

    return basepal;


}

void jugar(int basepal){

    char respuesta;

    BITMAP *abecedario[26] = {};

    for(int i = 0 ; i < 26 ; i++){

        str = "img/ ";
        str[4] = i+65;
        str += ".bmp";

        abecedario[i] = load_bitmap(str.c_str(), NULL);
    }

    BITMAP *numeros[11] = {};

    for(int i = 0 ; i < 11 ; i++){

        str = "img/ ";
        int code = i+48;

        str[4] = (code != 58) ? code : 49;

        str += (code == 58) ? "0.bmp" : ".bmp";

        numeros[i] = load_bitmap(str.c_str(), NULL);
    }

    vector<Imagen> imagenesDeporte = cargarJson("Deportes");
    vector<Imagen> imagenesLenguaje = cargarJson("Lenguajes");
    vector<Imagen> imagenesPais = cargarJson("Paises");

    string deportes[2] = {"futbol", "baloncesto"};
    BITMAP *imagenes_deportes[2] = {load_bitmap("img/Futbol.bmp", NULL), load_bitmap("img/Baloncesto.bmp", NULL)};


    string paises[2] = {"francia", "brasil"};
    string lenguajes[2] = {"racket", "C++"};

    BITMAP *buffer = create_bitmap(640, 480);
    BITMAP *fondo_deportes;
    BITMAP *fondo_paises;
    BITMAP *fondo_lenguajes;
    BITMAP *x;
    BITMAP *digitar_letra;
    BITMAP *intentos;

    fondo_deportes = load_bitmap("img/Fondo_deportes.bmp", NULL);
    fondo_paises = load_bitmap("img/Fondo_ciudades.bmp", NULL);
    fondo_lenguajes = load_bitmap("img/Fondo_lenguajes.bmp", NULL);
    x = load_bitmap("img/X1.bmp", NULL);
    digitar_letra = load_bitmap("img/Digitar_Letra.bmp", NULL);
    intentos = load_bitmap("img/Intentos.bmp", NULL);

    while(respuesta != 'n'){

        int j = 0, longitud = 0, vidas = 10, y = 1;
        //char temporal[longitud], palgen[longitud];
        string temporal, palgen;


        srand(time(0));
        j = 0 + rand() % 3;

        switch(basepal){

            case 1:

                longitud = imagenesDeporte[j].getTexto().size();
                temporal = imagenesDeporte[j].getTexto();
//                strcpy(temporal, imagenesDeporte[j].getTexto().c_str());

                draw_sprite(buffer, fondo_deportes, 0, 0);
                masked_blit(load_bitmap(imagenesDeporte[j].getUrl().c_str() , NULL), buffer, 0, 0, 205, 100, 260, 194);

//                longitud = deportes[j].size();
//                strcpy(temporal, deportes[j].c_str());
//                masked_blit(imagenes_deportes[j], buffer, 0, 0, 205, 100, 260, 194);

            break;

            case 2:

//                longitud = imagenesPais[j].getTexto().size();
//                strcpy(temporal, imagenesPais[j].getTexto().c_str());
//                draw_sprite(buffer, fondo_paises, 0, 0);

//                longitud = paises[j].size();
//                strcpy(temporal, paises[j].c_str());
//                draw_sprite(buffer, fondo_paises, 0, 0);

            break;

            case 3:

//                longitud = lenguajes[j].size();
//                strcpy(temporal, lenguajes[j].c_str());
//                draw_sprite(buffer, fondo_lenguajes, 0, 0);

            break;

        }

//        palgen[longitud] = '\0';
//        cout << palgen;
//        cout << temporal;

        for(int i = 0; i < temporal.size(); i++){
            palgen += " ";
            masked_blit(x, buffer, 0, 0, 25+i*60, 400, 60, 60);

        }

        while(vidas > 0){

            masked_blit(digitar_letra, buffer, 0, 0, 190, 325, 293, 60);
            masked_blit(intentos, buffer, 0, 0, 15, 25, 472, 58);
            masked_blit(numeros[vidas], buffer, 0, 0, 500, 25, 60, 60);
            blit(buffer, screen, 0, 0, 0, 0, 640, 480);

            char letra = readkey();
            bool perder = true;

            for(int i = 0; i < temporal.size(); i++){

                if(tolower(letra) == tolower(temporal[i])){

                    perder = false;
                    masked_blit(abecedario[tolower(letra) - 97], buffer, 0, 0, 25+i*60, 400, 60, 60);

                    palgen[i] = letra;

                }

            }


            if(perder){
               vidas--;
            }

            //y = strcmp(palgen, temporal);

//            if(y == 0){
//
//                BITMAP *ganaste = load_bitmap("img/Ganaste.bmp", NULL);
//                draw_sprite(buffer, fondo_lenguajes, 0, 0);
//                t=1;
//
//            }

            cout << palgen << " - " << temporal << endl;
            if(palgen == temporal){
                cout << "Ganamos wey!" << endl;
                BITMAP *ganaste = load_bitmap("img/Ganaste.bmp", NULL);
                draw_sprite(buffer, fondo_lenguajes, 0, 0);
                //t=1;

            }


        }

        cout << "Perdimos wey!" << endl;


        blit(buffer,screen, 0,0,0,0,640,480);

    }


}

//Se carga la informacion de las imagenes
//almacenadas en un archivo Json
//dependiendo de la categoria indicada

vector<Imagen> cargarJson(string categoria){


    vector<Imagen> images;

    json imagenes;
    ifstream people_file("imagenes.json", ifstream::binary);
    people_file >> imagenes;

    for (json element : imagenes["imagenes"][categoria]){
        images.push_back( Imagen(element["url"],element["texto"]) );
    }

    return images;

}
