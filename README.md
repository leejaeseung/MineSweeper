# Minesweeper
C++ 객체지향 프로그래밍으로 구현한 지뢰찾기 콘솔 게임입니다.
## UI 및 조작
모든 동작은 마우스 입력으로 진행된다.
- **메인 UI**

![image](https://user-images.githubusercontent.com/23518329/102706809-71876580-42d8-11eb-8d47-b7ab77e3ea1e.png)

![image](https://user-images.githubusercontent.com/23518329/102707175-0770bf80-42dc-11eb-9fe9-35798bffaab2.png)

난이도 버튼으로 지뢰 개수를 변경할 수 있고, width, height -, + 버튼으로 맵의 크기를 조정할 수 있다.  
NEW 버튼을 누르면 새로운 게임이 시작되고, Continue 버튼을 누르면 아래와 같이 저장된 게임을 불러올 수 있다.

![image](https://user-images.githubusercontent.com/23518329/102707209-66363900-42dc-11eb-88c2-4fd18ece202d.png)

- **인게임 UI**

![image](https://user-images.githubusercontent.com/23518329/102707161-ce384f80-42db-11eb-9af8-5b8f6f0ee742.png)

중앙 맵에서 게임을 진행할 수 있고, 좌측 상단의 버튼을 통해 메뉴로 가거나 게임을 저장할 수 있다.

![image](https://user-images.githubusercontent.com/23518329/102707240-95e54100-42dc-11eb-9a21-2931cd8094a5.png)

게임이 진행되면 좌측 상단에 진행률이 표시된다.  
지뢰를 밟거나 모두 찾으면, 게임이 종료되고 현재까지의 진행을 리플레이 해준다.
