[TermProject.zip](https://github.com/UDSEO/Term-Project-01/files/7668881/TermProject.zip)
[TermProject.zip](https://github.com/UDSEO/Term-Project-01/files/7668874/TermProject.zip)
# Term-Project-01

2. What is the topic?
 - ICP (Iterative Closest Point) algorithm
 - ICP is the Fitting a point cloud to a 3D model, a point cloud to a point cloud or a 3D model to a 3D model.

1. Justification of why you have chosen your topic.
 
 - ICP is the one of the algorithm in our developing software, and a good topic that applies 'Evolutionary computaton".
 
 - For fitting a point cloud to another(3D model or point cloud), I have to find two vector, translation vector (Tx, Ty, Tz) and rotation vector (Rx, Ry, Rz).
 
 - ICP is an exponential-time complexity problem. Some algorithm to solve ICP are also np-hard problem or exponential-time complexity problem.
 
 - Recently, There are some research to use a deep-learning for solving ICP.

 - I think ICP is a good topic. Because the concept of ICP is simple, but solving the problem is difficult.

3. Design decision explaining why you select.

  3.1. Parameters such as the size of an initial population.

    - I will use 1,000 population. 
    - While solving this problem, I will change the size of population.
  
  3.3. Fitness function.
  
    - Fitness function is the function to compute average value of closest point distance.
    - Closest point distance is a shortest distance between two points, each points belong to different object(3D mesh or point cloud).
    - While solving this problem, I'm able to change the size of population.
    
  3.2. Stopping criteria.
    
    - The value of fitness function is lower then the specific constant, algorithm stop.
    - The specific constant is 0.5mm or 1.0mm. When using a 3D scanner, an error tolerance is 0.5mm.
    

  3.4. Selection operator.
  
    - I will use 'random selection'.
    
  3.5. Crossover operator.
  
    - Crossover operator is a exchange the rotation vector or translation vector between two populations.
    - I'm considering a exchange the each value(Tx, Ty, Tz, Rx, Ry, Rz) between two populations. 

  3.6. Mutation operator.

    - I will control the range of random value as per the fitness function.
    - I will collect some data for finding a characteristic of problem and some good equation to solve problem.

  3.7. Generational selection strategy.
  
   - I will use 'elitism'. (random selection -> elitism)
    
    
4. How to run your project.
 - I will run my project with visual studio, C++. 
 - If I can port my project to use python, I'll do that.
 - I will submit the EXE file, some library file, and the code of evolutionary computation parts when I run my project with visual studio and c++.
 - I will submit the python file when I run my project with python.

5. How to adjust parameters.

