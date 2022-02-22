# MakePractice

make 연습

# Step

## Step 1 : 매우 귀찮게 계산기 코딩하기

가능한 여러 파일로 쪼개서 계산기를 코딩해본다. (src 디렉토리)

## Step 2 : gcc/g++로 빌드(컴파일 및 링크) 해보기

디렉토리 생성

```
mkdir ./obj # 목적 프로그램
mkdir ./bin # 실행 프로그램
```

컴파일

```bash
g++ -c -o ./obj/calculator.o ./src/calculator.cc
g++ -c -o ./obj/adder-module.o ./src/adder-module.cc
g++ -c -o ./obj/subtractor-module.o ./src/subtractor-module.cc
g++ -c -o ./obj/multiplier-module.o ./src/multiplier-module.cc
g++ -c -o ./obj/divider-module.o ./src/divider-module.cc
g++ -c -o ./obj/main.o ./src/main.cc
```

링크

```bash
g++ -o ./bin/calc.out ./obj/calculator.o \
                      ./obj/adder-module.o \
                      ./obj/subtractor-module.o \
                      ./obj/multiplier-module.o \
                      ./obj/divider-module.o \
                      ./obj/main.o
```

테스트

```bash
./bin/calc.out
```

실행결과

```bash
The program is starting.
Calculator and modules are loaded.
Modules are attached to calculator.
Testing some expression.
1 + 2 = 3
10 - 7 = 3
3 x 4 = 12
48 / 8 = 6
Testing complete.
The program is started.
== USAGE ==
COMMAND number number
COMMAND: add|sub|mul|div|exit
===========
>add 1 2
3
>add 999 999
1998
```

## Step 3 : Makefile 작성해보기

## Step 4 : make로 빌드(컴파일 및 링크) 해보기

## Step 5 : 깔끔하게 정리해보기