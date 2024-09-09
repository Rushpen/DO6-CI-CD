#!/bin/bash

echo "Test with 1 file and pattern1:"
SUCCESS=0
FAIL=0
VERDICT=""

pattern1="Linux"
for flag in -e -i -v -c -l -n -h -s -o
do
  ./s21_grep $flag $pattern test.txt test.txt > s21_grep.txt
  grep $flag $pattern test.txt test.txt > grep.txt
  if diff -s s21_grep.txt grep.txt >/dev/null; then
    ((SUCCESS++))
  else
    echo "[-] flags $flag not passed"
    ((FAIL++))
  fi
  rm s21_grep.txt grep.txt
done

echo "passed $SUCCESS tests with pattern '$pattern1'"
echo "failed $FAIL tests with pattern '$pattern1'"

echo ""
echo "Test with 2 files and pattern2:"
SUCCESS=0
FAIL=0

pattern2="cate"
for flag in -e -i -v -c -l -n -h -s -o
do
  ./s21_grep $flag $pattern test.txt test2.txt > s21_grep.txt
  grep $flag $pattern test.txt test2.txt > grep.txt
  if diff -s s21_grep.txt grep.txt >/dev/null; then
    ((SUCCESS++))
  else
    echo "[-] flags $flag not passed"
    ((FAIL++))
  fi
  rm s21_grep.txt grep.txt
done

echo "passed $SUCCESS tests with pattern '$pattern2'"
echo "failed $FAIL tests with pattern '$pattern2'"

if [ $FAIL -ne 0 ]; then
  exit 1
fi