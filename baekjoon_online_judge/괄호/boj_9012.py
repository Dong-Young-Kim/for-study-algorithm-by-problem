# boj_9012.py : 괄호

# replace() 함수를 이용하여 "()"을 ""로 치환하면서 괄호를 제거
# ()을 제거하는 과정을 반복하면 vps인지 아닌지 판별할 수 있음

import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    
    # readline()은 개행문자까지 포함하므로 rstrip()으로 제거
    str = input().rstrip() 

    while("()" in str):
        str = str.replace("()", "")

    print("NO") if str else print("YES")

    
# while (str.find("()") != string::npos) {
#     str.replace(str.find("()"), 2, "");
# }

    