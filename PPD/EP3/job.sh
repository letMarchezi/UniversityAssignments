#!/bin/bash
#SBATCH -J laplace                     # Job name
#SBATCH -p fast                     # Job partition
#SBATCH -n 1                        # Number of processes
#SBATCH -t 01:30:00                 # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=40          # Number of CPUs per process
#SBATCH --output=%x.%j.out          # Name of stdout output file
#SBATCH --error=%x.%j.err           # Name of stderr output file
lscpu

echo "*** SEQUENTIAL LAPLACE EQUATION GRID 1000X1000 ***"
srun singularity run container.sif laplace_seq_it 1000
echo " "
echo "*** OPENMP LAPLACE EQUATION grid 1000x1000 ***"

for j in 1 2 5 10 20 40
do
	export OMP_NUM_THREADS=$j

	echo "OPENMP PARALLEL LAPLACE EQUATION WITH $j THREADS"
	srun singularity run container.sif laplace_omp_it 1000
	echo "----------------------------------------------"
	echo " "
	
done
