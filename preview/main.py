arr=[
    '...www......'
    '...www......'
    '...www......'
    'gggrrrbbbooo'
    'gggrrrbbbooo'
    'gggrrrbbbooo'
    '...yyy......'
    '...yyy......'
    '...yyy......'
]
for _ in range(int(input())):
    n=int(input())
    move=list(input().split())
    up=[
        'www',
        'www',
        'www'
    ]
    down=[
        'yyy',
        'yyy',
        'yyy'
    ]
    front=[
        'rrr',
        'rrr',
        'rrr'
    ]
    left=[
        'ggg',
        'ggg',
        'ggg'
    ]
    right=[
        'bbb',
        'bbb',
        'bbb'
    ]
    back=[
        'ooo',
        'ooo',
        'ooo'
    ]
    #how...?
    #trash..
    #윗면
    #리스트화
    #--------------
    for i in range(0,3):
        up[i]=list(up[i])
        down[i]=list(down[i])
        front[i]=list(front[i])
        left[i]=list(left[i])
        right[i]=list(right[i])
        back[i]=list(back[i])
    #--------------
    for i in move:
        if i[0]=='U':
            if i[1]=='+':
                #윗면 시계방향
                #F->L->B->R
                left[0]+=front[0]
                del front[0][0:3]
                back[0]+=left[0][0:3]
                del left[0][0:3]
                right[0]+=back[0][0:3]
                del back[0][0:3]
                front[0]+=right[0][0:3]
                del right[0][0:3]
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=up[j][k]
                up=save
            else:
                #F->R->B->L
                right[0]+=front[0]
                del front[0][0:3]
                back[0]+=right[0][0:3]
                del right[0][0:3]
                left[0]+=back[0][0:3]
                del back[0][0:3]
                front[0]+=left[0][0:3]
                del left[0][0:3]
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=up[j][k]
                up=save
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=up[j][k]
                up=save
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=up[j][k]
                up=save
        elif i[0]=='D':
            if i[1]=='+':
                #아랫면 시계방향
                right[2]+=front[2]
                del front[2][0:3]
                back[2]+=right[2][0:3]
                del right[2][0:3]
                left[2]+=back[2][0:3]
                del back[2][0:3]
                front[2]+=left[2][0:3]
                del left[2][0:3]
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=down[j][k]
                down=save
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=down[j][k]
                down=save
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=down[j][k]
            else:
                left[2]+=front[2]
                del front[2][0:3]
                back[2]+=left[2][0:3]
                del left[2][0:3]
                right[2]+=back[2][0:3]
                del back[2][0:3]
                front[2]+=right[2][0:3]
                del right[2][0:3]
                save=[['' for j in range(3)] for i in range(3)]
                for j in range(3):
                    for k in range(3):
                        save[k][3-j-1]=down[j][k]
                down=save
        elif i[0]=='F':
            if i[1]=='+':
                pass
            else:
                pass
        elif i[0]=='B':
            if i[1]=='+':
                pass
            else:
                pass
        elif i[0]=='L':
            if i[1]=='+':
                pass
            else:
                pass
        elif i[0]=='R':
            if i[1]=='+':
                pass
            else:
                pass
    print(''.join(up[0]))
    print(''.join(up[1]))
    print(''.join(up[2]))
