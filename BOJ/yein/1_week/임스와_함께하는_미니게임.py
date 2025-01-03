# 임스와 함께하는 미니게임
n, game = input().split(" ")
arr = []
for _ in range(int(n)):
  arr.append(input())
arr = set(arr)
if (game == "Y"):
  need = 1
elif (game == "F"):
  need = 2
elif (game == "O"):
  need = 3
print(len(arr)//need)


'''
게임에 참가하고자 하는 사람 수 n, 게임 종류를 game 변수에 받고,
게임에 참가하고자 하는 사람의 아이디를 arr 배열에 저장하였습니다.
중복된 이름을 삭제하기 위해 배열을 set()로 변환하였습니다.
이후, 게임 종류에 따라 임스 외 필요한 인원 수를 need에 할당하였고,
중복되지 않는 사람 수를 필요 인원 수로 나눠 그 몫을 출력하였습니다.

이 문제의 주요개념은 set와 그 내장함수일 것입니다.
제가 굳이 타입변환을 선택한 이유는 문제 풀 당시
set 요소 추가 함수 (.add) 가 생각나지 않았기 때문입니다...
'''
