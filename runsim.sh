make   # for compiling tspsol.cpp if needed

width=1000
height=1000
seedlist=(2021 2022 2023)
nodelist=(10 20 30 40 50)

# Step 1: data Generation
for seed in ${seedlist[@]}
do
	for n in ${nodelist[@]}
	do

		echo "Data Generation" $n $seed
		python3 tspgen.py $n $width $height $seed > inputdat.$n.$width.$height.$seed
	done
done

# Step 2: Simulation
for seed in ${seedlist[@]}
do
	for n in ${nodelist[@]}
	do
		echo "Simulation " $n $seed
		./tspsol.exe $width $height $seed < inputdat.$n.$width.$height.$seed > outputdat.$n.$width.$height.$seed

	done
done

#Step 3: Data Analysis
echo "Start Analysis"
cat out* | grep nearestfinal | awk '{print $2, $5, $6}' > nearest.dat
cat out* | grep safinal | awk '{print $2, $5, $6}' > sa.dat
python3 tspanalysis.py < sa.dat > saall.dat
python3 tspanalysis.py < nearest.dat > nearestall.dat

cat tsp.gnu | gnuplot
ls -l *.pdf

