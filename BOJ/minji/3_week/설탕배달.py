def solution (n):
    cnt = n//5
    x = (n//5)*5
    if (x == n):
        print(cnt)
        return 0
    else:
        while((n-x) % 3 != 0):
            x -= 5
            cnt -= 1
            if (x < 0):
                print(-1)
                return 0
        
        cnt += (n-x)//3
        print(cnt)
        return 0

n = int(input())
solution(n)
    
