#!/bin/bash

set -e
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd ${DIR}

PROB_HDR="$1.h"

g++ -std=c++11 -Wall -I./include src/main.cpp -DPROB_HDR=${PROB_HDR}
./a.out
