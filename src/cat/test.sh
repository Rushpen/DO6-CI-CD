#!/bin/bash

SUCCESS=0
FAIL=0
VERDICT=""

for flag in -b -e -E -n -s -t -T
do
  ./s21_cat $flag test.txt > s21_cat.txt
  cat $flag test.txt > cat.txt
  if diff -s s21_cat.txt cat.txt >/dev/null; then
    ((SUCCESS++))
  else
    echo "[-] flags $flag not passed"
    ((FAIL++))
  fi
  rm s21_cat.txt cat.txt
done

echo "passed $SUCCESS tests"
echo "failed $FAIL tests"

if [ $FAIL -ne 0 ]; then
  exit 1
fi