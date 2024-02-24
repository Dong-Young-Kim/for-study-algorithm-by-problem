# boj_12100 : 2048 (Easy)

# 2048 게임은 nxn 크기의 보드에서 숫자 블록을 이동시켜 합쳐서 2048 블록을 만드는 게임이다.


# (핵심) 상하좌우 움직임을 모두 구현하지 말고 board 전체를 회전시키는 함수를 구현하자
# 시계방향으로 회전할 때
# 1. 회전한 배열의 i 행은 원래의 i 열이었다.
# 2. 회전한 배열의 j 열은 원래의 N-1-j 행이었다.

# 시계방향 90도 회전 함수
def rotate_cw90(board):
    n = len(board)
    ret_board = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            ret_board[i][j] = board[n-1-j][i]
    return ret_board

# 하나의 line에서 왼쪽으로 블럭들을 이동시키는 함수
def align_left_line(line):
    n = len(line)
    ret_l = [0] * n
    idx = 0
    for j in range(n):
        if line[j] == 0: continue
        ret_l[idx] = line[j]
        idx += 1
    return ret_l
# 하나의 line에서 블럭을 왼쪽으로 합치는 함수
def merge_left_line(line):
    n = len(line)
    ret_l = line[:]
    j = 0
    for j in range(n-1):
        if ret_l[j] == ret_l[j+1]:
            ret_l[j] *= 2
            ret_l[j+1] = 0
    return ret_l

# 문서 수정 시에 위 두 line 함수를 return 값을 반환하도록 변경하여 구현하였는데
# 실행시간에 있어서 기존에 구현한 방법(원본을 수정하는 방법)이 더 빠르게 동작한다.
# return 값을 통해서 구현의 통일성은 향상됐지만 가급적이면 새로운 배열을 생성하지 않고 원본을 수정하는 방법을 사용하는 것이 경제적으로 판단된다.

# 왼쪽으로 블럭들을 이동시키는 함수
# 1. 왼쪽으로 블럭들을 이동시킨다. (블럭을 합치기 윈한 사전작업)
# 2. 같은 블럭들을 합친다.
# 3. 다시 왼쪽으로 블럭들을 이동시킨다.
def move_left(board):
    n = len(board)
    ret_board = []
    for line in board:
        tmp_l = align_left_line(line)
        tmp_l = merge_left_line(tmp_l)
        tmp_l = align_left_line(tmp_l)
        ret_board.append(tmp_l)
    return ret_board

# 4방향 이동을 출력하는 테스트 코드
def print_move_4direc(board):
    dir = ['left', 'down', 'right', 'up']
    for i in range(4):
        print(dir[i])
        if(i != 0): board = rotate_cw90(board)
        new_board = move_left(board)
        for _ in range(4-i): new_board = rotate_cw90(new_board)
        pass
        for row in new_board: print(' '.join(map(str, row)))



def solve(board, count):
    ret = max([max(row) for row in board]) # board의 최대값을 구하는 방법
    if count == 0:
        return ret
    for _ in range(4):
        new_board = move_left(board)
        if new_board != board: # 시간 절약
            ret = max(ret, solve(new_board, count-1))
        board = rotate_cw90(board)
    return ret

# 시간 절약을 위해서 board의 변화가 없을 때는 재귀호출을 하지 않는다.
# solve(board, count)는 solve(board, count-1)보다 항상 크거나 같음을 보장할 수 있기 떄문이다. (두 board가 같을 때)

############################################
############################################
############################################

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)] # (2차원 배열을 선언과 동시에 입력받는 방법이다)

print(solve(board, 5))  # 5번의 움직임을 통해 만들 수 있는 최대값을 출력한다.


# 4방향 이동 출력
# print_move_4direc(board)


"""
반례모음
3
2 2 2
4 4 4
8 8 8
=> 16

3
0 0 0
0 2 0
0 0 0
=> 2

10
8 8 4 16 32 0 0 8 8 8
8 8 4 0 0 8 0 0 0 0
16 0 0 16 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 16
0 0 0 0 0 0 0 0 0 2
=> 128
=> 오답 64

4
8 16 0 0
0 0 16 8
0 0 0 0
0 0 0 0
=>32
=> 오답 16
"""