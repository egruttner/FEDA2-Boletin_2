#Comparaciones

python3 plot_tres.py \
csv/secuencial-dif_tam-pos0_results.csv \
csv/binaria-dif_tam-pos0_results.csv \
csv/galopante-dif_tam-pos0_results.csv \
Secuencial Binaria Galopante "Búsqueda - Elemento ubicado en el 10% del archivo" "Tamaño muestra" "Tiempo[ms]"

python3 plot_tres.py \
csv/secuencial-dif_tam-pos25_results.csv \
csv/binaria-dif_tam-pos25_results.csv \
csv/galopante-dif_tam-pos25_results.csv \
Secuencial Binaria Galopante "Búsqueda - Elemento ubicado en el 25% del archivo" "Tamaño muestra" "Tiempo[ms]"

python3 plot_tres.py \
csv/secuencial-dif_tam-pos50_results.csv \
csv/binaria-dif_tam-pos50_results.csv \
csv/galopante-dif_tam-pos50_results.csv \
Secuencial Binaria Galopante "Búsqueda - Elemento ubicado en el 50% del archivo" "Tamaño muestra" "Tiempo[ms]"

python3 plot_tres.py \
csv/secuencial-dif_tam-pos75_results.csv \
csv/binaria-dif_tam-pos75_results.csv \
csv/galopante-dif_tam-pos75_results.csv \
Secuencial Binaria Galopante "Búsqueda - Elemento ubicado en el 75% del archivo" "Tamaño muestra" "Tiempo[ms]"

python3 plot_tres.py \
csv/secuencial-dif_tam-pos100_results.csv \
csv/binaria-dif_tam-pos100_results.csv \
csv/galopante-dif_tam-pos100_results.csv \
Secuencial Binaria Galopante "Búsqueda - Elemento ubicado al final del archivo" "Tamaño muestra" "Tiempo[ms]"

python3 plot_tres.py \
csv/secuencial-dif_pos-tam100000_results.csv \
csv/binaria-dif_pos-tam100000_results.csv \
csv/galopante-dif_pos-tam100000_results.csv \
Secuencial Binaria Galopante "Búsqueda - Mismo Tamaño Vs Posición" "% Ubicación Elemento" "Tiempo[ms]"

python3 plot_dos.py \
csv/binaria-dif_pos-tam100000_results.csv \
csv/galopante-dif_pos-tam100000_results.csv \
Binaria Galopante "Binaria Vs Galopante - Mismo Tamaño Vs Posición" "% Ubicación Elemento" "Tiempo[ms]"