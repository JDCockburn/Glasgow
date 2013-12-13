unset key
unset xtics
unset ytics
set size square
set pointsize 0.1
plot "./in_circle.dat" pt 4 lt 3,\
"out_circle.dat" pt 4 lt 1
pause -1