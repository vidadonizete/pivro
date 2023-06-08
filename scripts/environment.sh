#!/bin/bash

ROOT=$(pwd)
ENVIRONMENTS=$ROOT/environments/

lunch()
{
    ENVIRONMENT=$ENVIRONMENTS/$1
    cp $ENVIRONMENTS/common/CMakeLists.txt $ROOT
}