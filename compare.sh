#!/bin/bash

echo "What flag and wath path do you want test?"
read ans
mkdir -p ../Desktop/compare
touch ../Desktop/compare/command.txt
echo "$ans" >> ../Desktop/compare/command.txt
time ls $ans &>../Desktop/compare/ls.txt
time ./ft_ls $ans &>../Desktop/compare/ft_ls.txt
diff ../Desktop/compare/ls.txt ../Desktop/compare/ft_ls.txt &>../Desktop/compare/diff.txt
mkdir -p ../Desktop/compare/compare_error
ls $ans 2>../Desktop/compare/compare_error/ls.txt
./ft_ls $ans 2>../Desktop/compare/compare_error/ft_ls.txt
diff ../Desktop/compare/compare_error/ls.txt ../Desktop/compare/compare_error/ft_ls.txt &>../Desktop/compare/compare_error/diff.txt
