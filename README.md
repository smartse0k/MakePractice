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

```
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

Makefile의 양식

```
target:   dependencies ...
          commands
          ...
```

Makefile 작성 (들여쓰기는 Space가 아닌 Tab 문자여야 함.)

```
build:
	g++ -c -o ./obj/calculator.o ./src/calculator.cc
	g++ -c -o ./obj/adder-module.o ./src/adder-module.cc
	g++ -c -o ./obj/subtractor-module.o ./src/subtractor-module.cc
	g++ -c -o ./obj/multiplier-module.o ./src/multiplier-module.cc
	g++ -c -o ./obj/divider-module.o ./src/divider-module.cc
	g++ -c -o ./obj/main.o ./src/main.cc
	g++ -o ./bin/calc.out ./obj/calculator.o ./obj/adder-module.o ./obj/subtractor-module.o ./obj/multiplier-module.o ./obj/divider-module.o ./obj/main.o
```

## Step 4 : make로 빌드(컴파일 및 링크) 해보기

make 명령어 입력

> 터미널에 `make` 또는 `make build` 입력.
> * `make` : Makefile에서 첫 번째 target(=build)이 수행된다.
> * `make build` : 위 Makefile에서 target이 build이므로 build에 해당하는 명령이 수행된다.

출력

```
g++ -c -o ./obj/calculator.o ./src/calculator.cc
g++ -c -o ./obj/adder-module.o ./src/adder-module.cc
g++ -c -o ./obj/subtractor-module.o ./src/subtractor-module.cc
g++ -c -o ./obj/multiplier-module.o ./src/multiplier-module.cc
g++ -c -o ./obj/divider-module.o ./src/divider-module.cc
g++ -c -o ./obj/main.o ./src/main.cc
g++ -o ./bin/calc.out ./obj/calculator.o ./obj/adder-module.o ./obj/subtractor-module.o ./obj/multiplier-module.o ./obj/divider-module.o ./obj/main.o
```

## Step 5 : 깔끔하게 정리해보기

### Compile과 Build 나누기

Makefile 변경

```make
build: compile_main
	g++ -o ./bin/calc.out ./obj/calculator.o ./obj/adder-module.o ./obj/subtractor-module.o ./obj/multiplier-module.o ./obj/divider-module.o ./obj/main.o

compile_main: compile_calculator compile_module
	g++ -c -o ./obj/main.o ./src/main.cc

compile_calculator:
	g++ -c -o ./obj/calculator.o ./src/calculator.cc

compile_module:
	g++ -c -o ./obj/adder-module.o ./src/adder-module.cc
	g++ -c -o ./obj/subtractor-module.o ./src/subtractor-module.cc
	g++ -c -o ./obj/multiplier-module.o ./src/multiplier-module.cc
	g++ -c -o ./obj/divider-module.o ./src/divider-module.cc

```

`make` 또는 `make build` 실행하였을때 출력은 위와 동일.

> 1. `build`는 `compile_main`에 의존하고 있으므로 `compile_main`가 먼저 수행
> 2. `compile_main`는 `compile_calculator`와 `compile_module`에 의존하므로 각 항목을 먼저 수행
> 3. 따라서 `build`를 하기 위해서는 `compile_calculator`, `compile_module`, `compile_main`, `build` 순서대로 수행된다.

-----

이외에 Make의 Rule이나 Macro 등이 있지만 이것들은 나중에 해보기로...

끝.
