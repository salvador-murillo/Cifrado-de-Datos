#! /bin/bash
salir=1

SECCIONES=(
    '1.Metodos-Cifra-Historia' 

)

array1=(
    '0.HolaMundo' 

)

while true
do
    #--Bloque Para mostrar SECCIONES
    clear
    echo $'\t\t\t'"CIFRADO DE DATOS"
    echo $'\n'"Secciones a mostrar:"$'\n'

    for i in ${SECCIONES[@]}
    do
        echo "$i" #Muestra SECCIONES
    done

    numeroSec=0
    read -p $'\n''Elige numero de seccion: ' numeroSec
    cd "${SECCIONES[$numeroSec-1]}"   
    #--Termina seleccion de bloque y entra a carpeta de la seccion 

    #--Bloque Para mostrar Programa a ejecutar
    clear
    echo $'\t\t\t'"CIFRADO DE DATOS"
    echo $'\n'"Programas:"$'\n'
    
    pro=array$numeroSec[@] #Creacion de variable para array indirecto de acuerdo a la categoria
    for j in ${!pro}
    do
        echo $j #Muestra Programas de acuerdo a la categoria
    done
    
    numeroPro=0
    # echo $'\n'"Estas en: " && pwd
    read -p $'\n''Escriba NUMERO (14) o LETRA y NUMERO (E1) de programa: ' numeroPro

    if [[ $numeroPro -ge 11 && $numeroPro -le  13 ]]
        then
            numeroPro=$((numeroPro-11))
    fi
    ruta=array$numeroSec[$numeroPro]
    echo $'\n'"Cargando: Seccion ${SECCIONES[$numeroSec-1]} | Programa #${!ruta}"
    cd "${!ruta}"
    # echo $'\n'"Estas en: " && pwd

    clang++ -pthread -std=c++17 -o main main.cpp || make main && ./main
    read -p $'\nVolver a seleccion de programas? 1-SI 2-NO : ' salir
    if (($salir > 1))
        then
            cd ../..
            exit
    fi
    cd ../..
done