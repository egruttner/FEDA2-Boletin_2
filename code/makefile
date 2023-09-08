CC = g++
CFLAGS = -std=c++14 -O2

SRCS = main.cpp 
OBJS = $(SRCS:.cpp=.o)

TEST_CASES_NUMBER := $(shell seq 1 5) #rango de archivos de input y output

# Experimentos con posición fija, cambio de tamaño
RANGE_1 = 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

# Experimentos con cambio de posición y tamaño fijo
RANGE_2 = 16 17 18 

# -> DIFERENTES TAMAÑOS - UBICACIÓN 10%
# 1 SECUENCIAL
# 2 BINARIA
# 3 GALOPANTE

# -> DIFERENTES TAMAÑOS - UBICACIÓN 25%
# 4 SECUENCIAL
# 5 BINARIA
# 6 GALOPANTE

# -> DIFERENTES TAMAÑOS - UBICACIÓN 50%
# 7 SECUENCIAL
# 8 BINARIA
# 9 GALOPANTE

# -> DIFERENTES TAMAÑOS - UBICACIÓN 75%
# 10 SECUENCIAL
# 11 BINARIA
# 12 GALOPANTE

# -> DIFERENTES TAMAÑOS - UBICACIÓN 100%
# 13 SECUENCIAL
# 14 BINARIA
# 15 GALOPANTE

# -> DIFERENTES UBICACIONES - TAMAÑO 100.000
# 16 SECUENCIAL
# 17 BINARIA
# 18 GALOPANTE


INPUT_PREFIX := datasets/input$(num_dataset)/input

OUTPUT_PREFIX := output/output$(num_dataset)/output

all: program
	for j in $(RANGE_1); do \
		echo "Crea cabecera en CSV"; \
		./program $$j --head $$num_dataset; \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --pruebas $$j $$num_dataset < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --pruebas $$num_dataset < $(INPUT_PREFIX)$$i.txt > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
	done

	for j in $(RANGE_2); do \
		echo "Crea cabecera en CSV"; \
		./program $$j --head $$num_dataset; \
		for i in $(TEST_CASES_NUMBER); do \
			echo "./program --pruebas $$j $$i < $(INPUT_PREFIX)4.txt > $(OUTPUT_PREFIX)$$j$$i.txt"; \
			./program $$j --pruebas $$i < $(INPUT_PREFIX)4.txt > $(OUTPUT_PREFIX)$$j$$i.txt; \
		done; \
	done

program: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o program

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) program output*