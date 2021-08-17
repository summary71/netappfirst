set term pdf color 

#Different line color style..
set style line 1  lc rgb '#0000FF' lt 1 lw 2.5 pt 1 ps 1.5			#that is Blue color
set style line 2  lc rgb '#8A2BE2' lt 1 lw 1.5 pt 2 ps 1.5 			#that is Blue violet
set style line 3  lc rgb '#006400' lt 1 lw 1.5 pt 3 ps 1.5 			#that is Dark green color
set style line 4  lc rgb '#808000' lt 1 lw 1.5 pt 4 ps 1.5 			#that is Olive color
set style line 5  lc rgb '#8B0000' lt 1 lw 1.5 pt 5 ps 1.5 			#that is dark red color
set style line 6  lc rgb '#FF00FF' lt 1 lw 1.5 pt 6 ps 1.5			#that is magenta color
set style line 7  lc rgb '#FFD700' lt 1 lw 1.5 pt 7 ps 1.5 			#that is Gold color
set style line 8  lc rgb '#DAA520' lt 1 lw 1.5 pt 8 ps 1.5 			#that is goldenrod  color
set style line 9  lc rgb '#CD853F' lt 1 lw 1.5 pt 9 ps 1.5 			#that is peru Color
set style line 10  lc rgb '#8B4513' lt 1 lw 1.5 pt 10 ps 1.5 			#that is saddlebrown Color


set key left

set grid #GNU FILE

set xlabel "Number of Nodes"
set ylabel "Distance"
set output "tspaverage.pdf" #GNU FILE
plot "nearestall.dat" using 1:3 with linespoint ls 1 title "Nearest",\
"saall.dat" using 1:3 with linespoint ls 2 title "SA"
set output "tsp.pdf" #GNU FILE
plot "nearestall.dat" using 1:3:2:4 with errorbars ls 1 title "Nearest",\
"saall.dat" using 1:3:2:4 with errorbars ls 2 title "SA",\
"nearestall.dat" using 1:3 with linespoint ls 1 notitle,\
"saall.dat" using 1:3 with linespoint ls 2 notitle 

