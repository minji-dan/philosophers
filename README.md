# philosophers

## Install
```
$ make
```

## Running  
```
$ ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
1. number_of_philosophers: n명의 철학자. n개의 포크
2. time_to_die: 아래의 경우 죽음 (ms) 
  - 마지막 식사 시작 후, simulation 시작 후 time_to_die ms 안에 먹기 시작하지 않은 경우 
3. time_to_eat: 철학자가 먹는데 걸리는 ms
  -fork 2개 유지 
4. time_to_sleep: 철학자가 자는 데에 걸리는 ms
5. number_of_times_each_philosopher_must_eat: (optional argument). 만약 모든 철학자들이 최소한 이 횟수만큼 식사를 했다면, 시뮬레이션이 끝남. 만약 이 인자가 설정되지 않았다면, 철학자가 죽었을 때만 시뮬레이션이 끝남 

## checking  
```
$ ./philo 4 410 200 200 5 > f1    //save to f1 file
$ cat f1 | grep eating | wc -l    //check the number of eating 
```
