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
