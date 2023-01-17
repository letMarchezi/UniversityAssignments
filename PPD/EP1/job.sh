#!/bin/bash
#SBATCH -J mmul                     # Job name
#SBATCH -p fast                     # Job partition
#SBATCH -n 1                        # Number of processes
#SBATCH -t 01:30:00                 # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=40          # Number of CPUs per process
#SBATCH --output=%x.%j.out          # Name of stdout output file - %j expands to jobId and %x to jobName
#SBATCH --error=%x.%j.err           # Name of stderr output file

echo "*** SEQUENTIAL ***"
srun singularity run container.sif pi_seq 1000000000

echo ""
echo "*** PTHREAD ***"
for i in 1 2 5 10 20 40
do
	echo "execucao com $i threads:"
	srun singularity run container.sif pi_pth 1000000000 $i	
done
echo ""

echo "*** OPENMP ***"

for j in 1 2 5 10 20 40
do
	echo "execucao com $j threads:"
	export OMP_NUM_THREADS=$j
	srun singularity run container.sif pi_omp 1000000000
done
