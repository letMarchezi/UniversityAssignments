#!/bin/bash
#SBATCH -J mmul                     # Job name
#SBATCH -p fast                     # Job partition
#SBATCH -n 1                        # Number of processes
#SBATCH -t 01:30:00                 # Run time (hh:mm:ss)
#SBATCH --cpus-per-task=40          # Number of CPUs per process
#SBATCH --output=%x.%j.out          # Name of stdout output file
#SBATCH --error=%x.%j.err           # Name of stderr output file


echo "*** SEQUENTIAL LAPLACE EQUATION ***"

echo "*** PTHREAD LAPLACE EQUATION ***"

export OMP_NUM_THREADS=${SLURM_CPUS_PER_TASK}
for i in 1 2 5 10 20 40 do
	srun singularity run container.sif laplace_pth_it $i
done	
