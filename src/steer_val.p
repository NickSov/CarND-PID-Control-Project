# Gnuplot for RMSE Error

set title "Steering Values,15"
#set autoscale
#unset log
#unset label
#set key at 190.0,4.75
#set key font "Helvetica,12"
#set xr [0:10]
#set yr [0:10]
set autoscale
#set xlabel "Iteration (count)" font "Helvetica,12"
#set ylabel "RMSE" font "Helvetica,12"

plot "steer_vals.txt" using 1:2 title 'S Position 1' with linespoints, \
