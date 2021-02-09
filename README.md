# This repo contains my effort to learn MPI.

To run a sample mpi program "hello_world_mpi.c" from this repo on a personal machine (laptop/desktop) <br/>

$ mpicc hello_world_mpi.c <br/>

$ mpirun -n 6 ./a.out

To run a sample mpi program on CSPAR cluster Bladerunner (or any cluster) <br/>

$ mpicc hello_world_mpi.c <br/>

Use the following slurn script to submit the job <br/>

------------------------------------------------------
#!/bin/bash                                                                     
#SBATCH --nodes=1                                                               
#SBATCH --ntasks 12                                                             
#SBATCH --job-name parallel_hello                                               
#SBATCH --partition=norlal12cores                                               
#SBATCH --time=0:01:00                                                          
#SBATCH --output parallel_hello_world.out                                       

module load mpi/openmpi-x86_64

mpirun --mca btl '^openib' -n 12 ./a.out > output.txt

echo done
---------
-----------------------------------------------------
Copy and paste the above script to the file named "slurm_run" and then type the following in the terminal:

$ sbatch slurm_run

You can change the partition to normal8cores/normal16cores depending on your need.