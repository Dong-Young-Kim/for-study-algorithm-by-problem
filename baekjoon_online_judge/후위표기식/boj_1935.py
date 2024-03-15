# boj_1918 : 후위 표기식2

# 후위 표기식을 계산하는 문제
# 1. 피연산자는 스택에 push
# 2. 연산자를 만나면 스택에서 피연산자를 2개 pop하여 연산을 수행 (뺄셈, 나눗셈의 경우는 순서를 바꿔야 함에 주의)
# 3. 결과 값을 다시 스택에 push. 이 과정을 
# 4. 1-3d을 수식이 끝날 때 까지 반복
# 5. 수식이 끝났다면 스택에 마지막 남은 값이 결과 값이 된다.

# 참고 https://jamanbbo.tistory.com/54

operand_stack = []
num_operand = int(input())
postfix = input()
value = []
for i in range(num_operand):
    value.append(int(input()))

for o in postfix:
    if o not in {'+', '-', '*', '/'}: 
        operand_stack.append(value[ord(o)-65])
    else:
        b = operand_stack.pop()
        a = operand_stack.pop()
        if o == '+':
            operand_stack.append(a+b)
        elif o == '-':
            operand_stack.append(a-b)
        elif o == '*':
            operand_stack.append(a*b)
        elif o == '/':
            operand_stack.append(a/b)
        else: pass

print(f'{operand_stack[0]:.2f}')
