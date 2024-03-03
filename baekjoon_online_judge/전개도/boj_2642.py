# boj_2642 전개도

import sys

delta_pos = {'N':(-1, 0), 'S':(1, 0), 'W':(0, -1), 'E':(0, 1)} # (상, 하)
oposite_dir = {'N':'S', 'S':'N', 'W':'E', 'E':'W'} # 백트래킹을 위함
opposite_plane_idx = {0:1, 1:0, 2:3, 3:2, 4:5, 5:4} # 주사위의 반대편 면을 찾기 위함

# 0: top, 1: bottom, 2: front, 3: back, 4: left, 5: right
def move_dice(dice, direction):
    if direction == 'N':
        dice[0], dice[1], dice[2], dice[3] = dice[2], dice[3], dice[1], dice[0]
    elif direction == 'S':
        dice[0], dice[1], dice[2], dice[3] = dice[3], dice[2], dice[0], dice[1]
    elif direction == 'W':
        dice[0], dice[1], dice[4], dice[5] = dice[5], dice[4], dice[0], dice[1]
    else: # direction == 'E'
        dice[0], dice[1], dice[4], dice[5] = dice[4], dice[5], dice[1], dice[0]

def check(dice):
    return True if sum(dice) == 21 else False

def out_of_range(pos):
    if pos[0] < 0 or pos[0] >= 6 or pos[1] < 0 or pos[1] >= 6:
        return True
    else: 
        return False

def first_contact(pos, dice):
    if board[pos[0]][pos[1]] != 0 and dice[1] == 0:
        return True
    else: 
        return False

def dfs(pos, dice): # 현재 위치, 주사위

    for direction in ['N', 'S', 'W', 'E']:

        # 주사위가 이동할 위치 + 위치 범위 유효성 검사
        new_pos = (pos[0] + delta_pos[direction][0], pos[1] + delta_pos[direction][1])
        if out_of_range(new_pos): continue

        # 주사위 이동
        move_dice(dice, direction)

        # 주사위가 처음으로 새 전개도 면에 도착하는 경우
        if first_contact(new_pos, dice): 
            # 전개도의 숫자를 주사위에 적용
            dice[1] = board[new_pos[0]][new_pos[1]]

            # 재귀 호출
            dfs(new_pos, dice)

        # 주사위를 원래 위치로 되돌림
        move_dice(dice, oposite_dir[direction])



dice = [0] * 6
board = [list(map(int, sys.stdin.readline().split())) for _ in range(6)]

# 주사위의 초기 위치 찾기
for i in range(36):
    x, y = i // 6, i % 6
    if board[x][y] != 0: break

dice[1] = board[x][y]
dfs((x, y), dice)
if check(dice): print(dice[opposite_plane_idx[dice.index(1)]])
else: print(0)


"""
아이디어

가상의 주사위를 전개도 위에서 굴려가면서 전개도의 유효성을 검사한다.
가상의 주사위가 전개도 위를 굴러가면서, 주사위의 바닥이 전개도에 맞닿은 경우 전개도의 숫자를 주사위에 적용한다.
주사위를 이동 시 전개도가 0인 경우에는 전개도가 생성될 수 없는 경우이므로 해당 방향의 탐색을 종료한다.
"""

"""
디버깅 로그

주사위의 굴림 횟수를 6번으로 제한하면 안된다.
이미 탐색한 면을 다시 탐색하면서 탐색하는 경우가 있어서, 이동 횟수를 제한하면 안된다.
또한 이동 시에 탐색한 면이 모순되는 것이 아니라면, 계속 이동할 수 있다.
---> 위 아이디어를 사용하면 무한 탐색에 빠질 수 있다.


--------------------------------CANCLE--------------------------------
주사위의 탐색횟수를 제한하지 않으면 영원히 탐색을 종료할 수 없게 된다.
주사위가 이미 탐색한 면으로 돌아오는 경우는 탐색횟수를 차감하면지 않고, 새로운 면을 탐색하는 경우에만 횟수를 차감할 수 있도록 한다.
탐색을 종료하는 경우는 주사위의 모든 면이 채워진 경우이다.

재귀를 반복하면서 주사위를 복사해서 사용하지 않고, 주사위를 원래 위치로 되돌리는 방식을 사용한다.
---------------------------------END---------------------------------

--> 탐색을 제한하는 방식을 사용하지 말고 모든 dfs를 탐색하도록 할 것
굴릴곳이 없으면 원위치로 돌아온 후 다시 굴려야 할 것
재귀를 반복하면서 주사위를 복사해서 사용하지 않고, 주사위를 원래 위치로 되돌리는 방식을 사용한다.
이 방식을 통하면 모든 탐색을 마치고 자연스럽게 탐색을 종료할 수 있다.
"""


# test DICE class ========================================
class Dice:
    def __init__(self, top = 0, bottom = 0, front = 0, back = 0, left = 0, right = 0):
        self.top = top
        self.bottom = bottom
        self.front = front
        self.back = back
        self.left = left
        self.right = right

    def __str__(self):
        return f'top: {self.top}, bottom: {self.bottom}, front: {self.front}, back: {self.back}, left: {self.left}, right: {self.right}'
    
    def __repr__(self):
        return f'Dice({self.top}, {self.bottom}, {self.front}, {self.back}, {self.left}, {self.right})'
    
    def move(self, t):
        if t == 'N':
            self.top, self.front, self.bottom, self.back = self.front, self.bottom, self.back, self.top
        elif t == 'S':
            self.top, self.front, self.bottom, self.back = self.back, self.top, self.front, self.bottom
        elif t == 'W':
            self.top, self.right, self.bottom, self.left = self.right, self.bottom, self.left, self.top
        else:
            self.top, self.right, self.bottom, self.left = self.left, self.top, self.right, self.bottom

