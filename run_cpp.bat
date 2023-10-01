@echo off
g++ -std=c++17 -Werror -Wall -Wformat=2 -Wextra -O2 -Wshadow -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC %1 -o %~n1.exe
%~n1.exe < "C:\Users\ASUS\OneDrive\Desktop\competitive_programming\input.txt" > "C:\Users\ASUS\OneDrive\Desktop\competitive_programming\output.txt"
