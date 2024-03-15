# boj_1918 : 후위 표기식

# 중위 표기식을 후위 표기식으로 변환하는 문제

# [규칙]
# 1. 피연산자는 그대로 출력한다.
# 2. 연산자는 스택의 top에 있는 연산자보다 높거나 같은 것이 없을 때 까지 pop하여 출력한 후 스택에 넣는다.
# 2-1. 현재 > 스택의 top : 스택에 넣는다.
# 2-2. 현재 <= 스택의 top : 스택의 top을 pop하여 출력한 후 2번을 반복한다.
# 3. 여는 괄호는 스택에 넣는다.
# 4. 닫는 괄호가 나오면 여는 괄호가 나올 때까지 스택에서 pop하여 출력한다.
# 5. 중위 표기식이 끝나면 스택에 있는 연산자를 모두 pop하여 출력한다.


opsk = []
infix = input()
postfix = ''
for o in infix:
    if o not in {'+', '-', '*', '/', '(', ')', ' '}: postfix += o
    elif o in {'+', '-'}:
        while opsk and opsk[-1] != ('('):
            postfix += opsk.pop()
        opsk.append(o)
    elif o in {'*', '/'}:
        while opsk and opsk[-1] in {'*', '/'}:
            postfix += opsk.pop()
        opsk.append(o)
    elif o == '(':
        opsk.append(o)
    elif o == ')':
        while opsk:
            if opsk[-1] == '(':
                opsk.pop()
                break
            else:
                postfix += opsk.pop()
    else: pass
while opsk: postfix += opsk.pop()
print(postfix)

"""
TC
A*(B+C)/D
=> ABC+*D/

A+(B-C)/D
=> ABC-D/+

A+B*C+D
=> ABC*+D+

A*B*C
=> AB*C*
"""

"""
각 연산자의 우선 순위를 정의하고, 우선순위를 비교하여 스택에 push할 지 정하는 방법도 있다.
이때 우선 순위는 {()} < {+,-} < {*,/} < 이다.
(의 경우 push 할 때는 높은 우선 순위를 갖는 것 처럼 작동하지만
pop 할 때는 가장 낮은 우선 순위를 갖는 것 처럼 작동해야 하기 떄문

"""