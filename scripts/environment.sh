#!/bin/bash

ROOT=$(pwd)
ENVIRONMENTS=$ROOT/environments

checkfolder()
{
    FOLDER=$1
    FOLDERS=( $(ls $ENVIRONMENTS) )
    if [[ ! ${FOLDERS[*]} =~ ${FOLDER} ]]; then
        echo "Please, check your selected folder: $FOLDER"
        echo "Available folders are: ${FOLDERS[*]}"
        return 1
    fi
}

copycontent()
{
    TAG="\0"
    CONTENT="\0"

    while read -r LINE; do
        if [[ $LINE == "$"* ]]; then
            sed -i "s+$TAG+${CONTENT/%\\n/}+g" $2

            TAG=$LINE
            CONTENT=""
        else
            CONTENT="${CONTENT}${LINE}\n"
        fi
    done <$1
    sed -i "s+$TAG+${CONTENT/%\\n/}+g" $2
}

lunch()
{
    checkfolder $1
    [[ $? -eq 1 ]] && return 1
    
    cp $ENVIRONMENTS/common/CMakeLists.txt $ROOT

    GENERATED_CMAKE=$ROOT/CMakeLists.txt
    SELECTED_ENVIRONMENT=$ENVIRONMENTS/$1/CMakeLists.txt

    copycontent $SELECTED_ENVIRONMENT $GENERATED_CMAKE
}