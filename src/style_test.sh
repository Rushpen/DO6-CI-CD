#!/bin/bash

cp ../materials/linters/.clang-format .

RES=$(clang-format -n ./cat/*.c ./grep/*.c 2>&1)

if [[ "$RES" ]]; then
    echo "$RES"
    rm -rf .clang-format
    exit 1
fi

rm -rf .clang-format
exit 0
