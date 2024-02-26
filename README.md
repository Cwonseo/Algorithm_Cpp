# Algorithm_Cpp

<details>
  <summary>누적합 및 구현로직</summary>
  
  ### 누적합\_prefixSum(=psum)

- 요소들의 누적된 합의 의미. 어떠한 배열을 기반으로 앞에서부터 요소들의 누적된 합을 저장해 새로이 배열을 만들어 활용한다.
  [1, 10, 11, 100]이라는 배열이 있다고 하자.
  새로이 prefixSum을 만들 때는 1번째 index부터 요소를 넣어준다.
  
  psum[0] = 첫번째까지 합한 값 1
  psum[1] = 두번째까지 합한 값 11
  psum[2] = 다섯번째까지 합한 값 22
  psum[3] = 네번째까지 합한 값 121

prefixSum은 [1, 11, 21, 121]이 되는 것이다.

 prefixSum[3] - prefixSum[1]는 
arr[0] + arr[1] + arr[2] + arr[3] -
arr[0] + arr[1] 이므로

원본 배열의 2,3 번째 값을 합한 값이 나온다. 
위 로직으로 문제풀이 진행.

**구간 쿼리** -> psum or 펜윅트리

배열의 요소들이 변하지 않는 정적 배열 -> 누적합 사용
이 문제에서 배열의 요소가 순간순간마다 변하는 동적배열 -> psum을 사용할 수 없음.

**구간에 대한 합을 구하라는 요청**
중첩 반복 사용 시 시간초과 난다면 누적합 사용

최대값을 구하라고 하면 최솟값부터 최대값을 구하는거임.

  <summary>그래프</summary>

### BFS

### DFS

### 연결리스트

### 분할정복

  <summary>완전탐색</summary>


  <summary>백트래킹</summary>

  ## 모든 경우의 수중 가지 않아도 될 경우의 수는 가지 않는 것.

  나타내야 하는 결과값이 최대값 혹은 최소값에 도달했다면 더이상 탐색하지 않는 것.

</details>




<details>
  <summary>누적합 및 구현로직</summary>
  </details>