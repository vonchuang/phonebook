reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using 3:xtic(1) with histogram title 'One-at-a-Time hash table'  , \
'' using 4:xtic(1) with histogram title 'DJBHash table' , \
'' using 5:xtic(1) with histogram title 'BKDRHash table' , \
'' using ($0-0.01):($2+0.003):2 with labels title ' ', \
'' using ($0+0.05):($3+0.003):3 with labels title ' ', \
'' using ($0+0.41):($4+0.003):4 with labels title ' ', \
'' using ($0+0.77):($5+0.003):5 with labels title ' '
