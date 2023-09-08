import sys

rango = int(sys.argv[1])

# Abrir un archivo en modo escritura
with open("input.txt", "w") as archivo:
    # Escribir los números del 1 al 1000 en el archivo
    archivo.write(str(rango) + "\n")
    for numero in range(1, rango+1):
        archivo.write(str(numero) + "\n")


