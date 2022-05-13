# philosophers
main point - 최대한 context switch에 소요되는 시간을 줄이고 임계구역을 구분하여 deadlock이 발생하지 않도록 설계하는 것 

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
$ 20
```

```
$ ./philo 5 410 200 200 7 > f1    //save to f1 file
$ cat f1 | grep eating | wc -l    //check the number of eating 
$ 36 
```

홀수의 경우-이 subject는 모든 철학자들이 n번 “이상" 먹었을 때 시뮬레이션을 종료하라는 언급만 있음. 그래서 “최소한"의 조건으로 문제를 푼 것! 홀수명의 철학자로 테스트하게되면 무조건 N+1번 먹는 철학자가 존재할 수 밖에 없다

## philosopher visualizer
https://nafuka11.github.io/philosophers-visualizer/ 
