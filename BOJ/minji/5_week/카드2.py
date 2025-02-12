'''
#런타임 오류 발생 코드
card_list = []
n = int(input())

for i in range(n):
    card_list.append(i+1)

while(len(card_list) != 1):
    del card_list[0]
    card_list.append(card_list[0])
    del card_list[0]

print(*card_list)         
'''

from collections import deque

n = int(input())  
card_list = deque(range(1, n+1)) 

while len(card_list) > 1:
    card_list.popleft()  
    card_list.append(card_list.popleft())  

print(*card_list) 

                            
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                