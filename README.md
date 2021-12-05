# Term-Project-01

2. What is the topic?
 - ICP (Iterative Closest Point) algorithm
 - ICP is the Fitting a point cloud to a 3D model, a point cloud to a point cloud or a 3D model to a 3D model.

1. Justification of why you have chosen your topic.
 
 - ICP is the one of the algorithm in our developing software, and a good topic that applies 'Evolutionary computaton".
 
 - For fitting a point cloud to another(3D model or point cloud), I have to find two vector, translation vector (Tx, Ty, Tz) and rotation vector (Rx, Ry, Rz).
 
 - ICP is a exponential-time complexity problem. Some algorithm to solve ICP are also np-hard problem or exponential-time complexity problem.
 
 - Recently, There are some research to use a deep-learning for solving ICP.

 - I think ICP is good topic. Because a concept of ICP is simple, but solving the problem is difficult.

3. Design decision explaining why you select.

  3.1. Parameters such as the size of an initial population.

    - I will use 1,000 population. 
    - While solving this problem, I will change the size of population.
  
  3.3. Fitness function.
  
    - Fitness function is the function to compute average valoue of closest point distance.
    - Closest point distance is a shortest distance between two points, each points belong to different object(3D mesh or point cloud).
    - Closest point distance의 평균 값을 계산하는 함수를 fitness function으로 사용할 계획입니다.
    - Closest point distance는 한 object(mesh or point cloud)에 속한 point와 거리가 가장 가까운 상대 object의 point 사이의 거리를 의미합니다.
    
  3.2. Stopping criteria.
  
    - Fitness function의 값이 특정 값 이하일 경우, 알고리즘을 종료합니다.
    - 3D스캐너를 사용할 때 허용오차범위가 0.5mm 정도입니다. 이 값을 그대로 사용하거나 1.0mm 정도를 사용할 예정입니다.

  3.4. Selection operator.
  
    - 간단하게 ramdom selection을 사용할 예정입니다.
    - 강의에서 진행한 문제들과 숙제들을 봤을 때, 굳이 복잡한 방법 필요 없이 random selection을 사용해도 성능이 괜찮았던 것 같
    - Generation이 계속 진행되어도 수렴이 잘 되지 않으면, 다른 방법을 검토하겠습니다.

  3.5. Crossover operator.
  
    - 두 population의 Transaltion vector 교환 또는 rotation vector 교환으로 crossover operation을 수행할 예정입니다.
    - Tx, Ty, Tz, Rx, Ry, Rz 각각을 독립적으로 사용하여 crossover할 경우, 나름 피팅이 된 population의 결과를 안 좋은 방향으로 이끌 확률이 클 것으로 예상됩니다.
    - 각각을 독립적으로 사용하는 경우는 mutation을 통해서 적용할 예정입니다.

  3.6. Mutation operator.
  
    - Fitness function의 값에 비례하여 Tx, Ty, Tz, Rx, Ry, Rz의 변동 폭을 조정하여 Mutation을 수행할 예정입니다.
    - 적당한 비례식을 찾기 위해 초기에는 다양한 시도를 하면서 데이터를 모을 예정입니다.

  3.7. Generational selection strategy.
  
    - Ramdom selection을 사용할 예정입니다.

4. How to run your project.
 - 현재 개발중인 프로그램이 C++ 기반으로 구성되어 있어서, visual studio로 진행할 예정입니다. 상황에 따라 python으로의 포팅이 가능하다면 python 상에서 진행하겠습니다.
 - 과제제출시, C++기반이라면 exe파일과 몇몇 library파일, 그리고 evolutionary computation 관련 코드를 제출할 예정이며, python으로 진행한다면 python 파일을 제출하겠습니다. 

5. How to adjust parameters.
 - 과제를 진행하면서 문제를 이해하고 이 문제에서 각 parameter들의 변화가 어떤 반응을 유도하는지 파악하여 조정하겠습니다.
