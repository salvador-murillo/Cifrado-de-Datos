#! /bin/bash
salir=1
numeroSecU=0

SECCIONES=(
    '1.Metodos-Cifrado-Historia'
)

proTema1=(
    '1.Algortimo-Cesar'
    '2.Algoritmo-Polybios'
    '3.Algoritmo-Vigenere'
)


mostrarTitulo(){
    clear
    echo $'\033[36m'$'CIFRADO DE DATOS '$'\033[0m'' | '$'\033[33m''Universidad de Guadalajara'
    echo $'\033[0m'
}

mostrarSalida(){
    clear     
    echo $'\033[0m'$'\n\t¿Estas en '$'\033[31m''REPLIT'$'\033[0m''? Presiona '$'\033[32m''RUN'$'\033[0m'$' para volver a ejecutar\n'
}

mostrarSeccion(){
   salirSec1=1
   while [[ $salirSec1 > 0  ]]; 
   do
        mostrarTitulo
        echo $"Practicas a mostrar:"$'\n'
        # j=0 # TEST para ocultar proyecto
        for i in ${SECCIONES[@]};
        do

            # if [[ j -eq 10 ]]; then
            #     echo $'\033[8;32m'"$i"
            # else
            echo $'\033[32m'"$i" # FIXME dejar solo esta linea dentro del for
            # fi
            # j=$(($j+1))
        done

        numeroSecU=0
        numeroSec=${#SECCIONES[@]}

        read -p $'\033[0m'$'\n''Ingresa el numero de practica (sección): ' numeroSecU
        if [[ $numeroSecU -ge 0 && $numeroSecU -le $numeroSec ]]
            then
                cd "${SECCIONES[$numeroSecU-1]}"
                salirSec1=0
            else
                echo $'\n\033[31m''Numero N0 Valido'$'\n\033[0m''Regresando a menu...'
                sleep 1.5
                clear
        fi
    done 
}

mostrarProgramas(){
    salirSec2=1
    while [[ $salirSec2 > 0 ]]; 
    do
        mostrarTitulo
        
        echo $'TEMA '${SECCIONES[$numeroSecU-1]}$'\n\nProgramas:'

        pro=proTema$numeroSecU[@] #Creacion de variable para array indirecto de acuerdo a la categoria
        for j in ${!pro}
        do
            echo $'\033[32m'"$j" #Muestra Programas de acuerdo a la categoria
        done

        numeroPro=0
        read -p $'\n\033[0m''Escriba NUMERO (1) de programa: ' numeroPro

        #--Determinar calcular programa
        if [[ numeroSecU -eq 1 ]] && [[ numeroPro -ge 1 && numeroPro -le 3 ]]; then
            numeroPro=$((numeroPro-1))
            #echo $'\n\nel numero de programa ahora es: ' $numeroPro
            salirSec2=0
        else
            echo $'\n\033[31m''Numero NO Valido'$'\n\033[0m''Seleccione de nuevo...'
            sleep 1.5
            clear
        fi
        #--Termina calcular programa

        if [[ salirSec2 -eq 0 ]]; then
            ruta=proTema$numeroSecU[$numeroPro]
            echo $'\n''Cargando...'$'\033[33m'"#${!ruta}"$'\033[0m'
            cd "${!ruta}"
            sleep 2
        fi
    done
}

while true
do
    #--Funcion para mostrar SECCIONES
    mostrarSeccion

    #--Funcion para mostrar PROGRAMAS
    mostrarProgramas
    
    clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main
        
    echo $'\033[32m'$'\n''Volver a seleccion de programas?' $'\033[31m'
    read -p '1-SI 2-NO : ' salir
    echo $'\033[0m' #Reset Color Blanco
    if (($salir > 1))
        then
            mostrarSalida
            cd ../..
            exit
    fi
    cd ../..
done