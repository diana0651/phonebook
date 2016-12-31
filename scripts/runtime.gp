reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
 set output 'runtime.png'
  
plot [:][:0.16]'output.txt' using 2:xtic(1) with histogram title 'original', \
 '' using 3:xtic(1) with histogram title 'optimized'  , \
 '' using 4:xtic(1) with histogram title 'hashfunction'  , \
 '' using 5:xtic(1) with histogram title 'smazalgo'  , \
 '' using ($0-0.1):($2+0.001):2 with labels title ' ', \
 '' using ($0+0.1):($3+0.002):3 with labels title ' ', \
 '' using ($0+0.2):($4+0.002):4 with labels title ' ', \
 '' using ($0+0.4):($5+0.003):5 with labels title ' '