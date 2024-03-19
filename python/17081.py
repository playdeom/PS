main_info={
    "level":1,
    "max_hp":20,
    "hp":20,
    "atk":2,
    "def":2,
    "max_exp":5,
    "exp":0,
    "weapon": 0,
    "armor": 0,
    "ac": 0,
    "HR": False,
    "RE": False,
    "CO": False,
    "EX": False,
    "DX": False,
    "HU": False,
    "CU": False
}
row, col = map(int, input().split())
arr = []
for i in range(row):
    arr.append(list(input()))
command = list(input())

last_pos_main = '.'
killed_by = ""
mc = 0
ibc = 0
tc = 0
for i in range(row):
    for j in range(col):
        if arr[i][j] == '&' or arr[i][j] == 'M':
            mc += 1
        elif arr[i][j] == '@':
            st_pos1, st_pos2 = i, j
        elif arr[i][j] == 'B':
            ibc += 1
mi = [[dict() for _ in range(col)] for _ in range(row)] 
for i in range(mc):
    r, c, s, w, a, h, e = input().split(" ")

    mi[int(r)-1][int(c)-1] = {
        "name": s,
        "atk": int(w),
        "def": int(a),
        "hp": int(h),
        "exp": int(e)
    }
item_info = [[dict() for _ in range(col)] for _ in range(row)]
for i in range(ibc):
    r, c, t, s = input().split(" ")
    if t == 'W' or t == 'A':
        item_info[int(r) - 1][int(c) - 1] = {
            "type": t,
            "val": int(s)
        }
    else:
        item_info[int(r) - 1][int(c) - 1] = {
            "type": t,
            "val": s
        }
def item(now1,now2):
    global main_info,last_pos_main
    last_pos_main='.'
    item=item_info[now1][now2]
    if item['type']=='W':
        main_info["weapon"]=item['val']
    if item['type']=='A':
        main_info["armor"]=item['val']
    elif item['type']=='O':
        if main_info["ac"]<4: 
            if not main_info[item['val']]:
                main_info["ac"]+=1
                main_info[item['val']]=True
def spike():
    global main_info,killed_by
    if not main_info["DX"]:
        main_info["hp"]-=5
    else:
        main_info["hp"]-=1
    if main_info["hp"]<=0:
        main_info["hp"]=0
        killed_by="SPIKE TRAP"
        return -1
def exp(now1,now2):
    global main_info, last_pos_main
    monster=mi[now1][now2]
    if main_info["EX"]:
        main_info["exp"]+=int(monster['exp']*1.2)
    else:
        main_info["exp"]+=monster['exp']
    if main_info["exp"]>=main_info["max_exp"]:
        main_info["level"]+=1
        main_info["exp"]=0
        main_info["max_exp"]+=5
        main_info["max_hp"]+=5
        main_info["hp"]=main_info["max_hp"]
        main_info["atk"]+=2
        main_info['def']+=2
def monsters(now1,now2,b=False):
    global last_pos_main, killed_by,main_info
    first = True
    no_damage = False
    player_attack_damage = main_info["atk"] + main_info["weapon"]
    player_defend = main_info["def"] + main_info["armor"]
    monster = mi[now1][now2]
    mhp = monster["hp"]
    if b and main_info["HU"]:
        main_info["hp"] = main_info["max_hp"]
        no_damage = True
    while True:
        if first and main_info["CO"]:
            if main_info["DX"]:
                damage_check = max(1, 3*player_attack_damage - monster["def"])
            else:
                damage_check = max(1, 2*player_attack_damage - monster["def"])
            first = False
        else:
            damage_check = max(1, player_attack_damage - monster["def"])
        monster_damage = max(1, monster["atk"] - player_defend)
        monster["hp"] -= damage_check
        if monster["hp"] <= 0:
            last_pos_main = '.'
            if main_info["HR"]:
                main_info["hp"] = min(main_info["hp"] + 3, main_info["max_hp"])
            exp(now1,now2)
            if b:
                return 2
            return 1
        if no_damage:
            no_damage = False
        else:
            main_info["hp"] -= monster_damage
        if main_info["hp"] <= 0:
            main_info["hp"] = 0
            mi[now1][now2]["hp"] = mhp
            killed_by = monster["name"]
            return -1
def run_module(now1,now2):
    global main_info,last_pos_main
    check=arr[now1][now2]
    if(check=='@'):
        check=last_pos_main
    else:
        last_pos_main=check
        arr[now1][now2]='@'
    if(check=='.'):
        return 0
    elif(check=='B'):
        item(now1,now2)
    elif(check=='&'):
        return monsters(now1,now2)
    elif(check=='M'):
        return monsters(now1,now2,True)
    elif(check=='^'):
        return spike()
    elif(check=='#'):
        assert True
now1,now2=st_pos1,st_pos2
message=''

for move in command:
    tc+=1
    past1,past2=now1,now2
    arr[past1][past2]=last_pos_main
    if(move=='L'):
        now2=max(0,now2-1)
    elif(move=='R'):
        now2 = min(col-1, now2+1)
    elif(move=='U'):
        now1=max(0,now1-1)
    elif(move=='D'):
        now1 = min(row-1, now1+1)
    if(arr[now1][now2]=='#'):
        now1,now2=past1,past2
    
    check=run_module(now1,now2)
    if check==2:
        message="YOU WIN!"
        break
    elif check==-1:
        if main_info["RE"]:
            main_info["RE"]=False
            main_info["ac"]-=1
            main_info["hp"]=main_info["max_hp"]
            arr[now1][now2]=last_pos_main
            now1,now2=st_pos1,st_pos2
            last_pos_main='.'
            arr[now1][now2]='@'
        else:
            arr[now1][now2]=last_pos_main
            message=f"YOU HAVE BEEN KILLED BY {killed_by}.."
            break

if message=='':
    message="Press any key to continue."
for i in range(row):
    print("".join(arr[i]))
print(f"Passed Turns : {tc}")
print("LV", ":", main_info["level"])
print("HP", ":", str(main_info["hp"])+'/'+str(main_info["max_hp"]))
print("ATT", ":", str(main_info["atk"]) + '+' + str(main_info["weapon"]))
print("DEF", ":", str(main_info["def"]) + '+' + str(main_info["armor"]))
print("EXP", ":", str(main_info["exp"])+'/'+str(main_info["max_exp"]))
print(message)