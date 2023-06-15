#!/bin/bash
#SBATCH -J wave_simulation          # Job name
#SBATCH -p fast                     # Job partition
#SBATCH -n 1                        # Number of processes
#SBATCH -t 01:30:00                 # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=40          # Number of CPUs per process
#SBATCH --output=%x.%j.out          # Name of stdout output file
#SBATCH --error=%x.%j.err           # Name of stderr output file

lscpu

echo "*** SEQUENTIAL WAVE PROPAGATION GRID 700X700 ***"
srun singularity run container.sif wave_seq 700 700 400
echo " "
echo "*** OPENMP PARALLEL WAVE PROPAGATION GRID 1000x1000 ***"
mv wavefield/wavefield.txt wavefield/wavefield_seq.txt
for j in 1 2 5 10 20 40
do
	export OMP_NUM_THREADS=$j

	echo "OPENMP PARALLEL WAVE PROPAGATION WITH $j THREADS"
	srun singularity run container.sif wave_omp 700 700 400
	echo "----------------------------------------------"
	echo " "
	
done
mv wavefield/wavefield.txt wavefield/wavefield_omp.txt