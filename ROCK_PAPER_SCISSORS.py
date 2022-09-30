import random

print("ROCK\nPAPER\nSCISSORS")
print("-----------------------------\n")
print("r for rock\np for paper\ns for scissors\n--------\n")

lst=['r','p','s']

chance_taken=0
comp_point=0
player_point=0
remain_chance=10

while(remain_chance>chance_taken):
    ip=input("enter your selection: ")
    c=random.choice(lst)

    if c==ip:
        print("Both tie so 0 point to both")


    elif c=='r' and ip=='p':
        print(f"You entered {ip} and computer entered {c}")
        print("You wins 1 point")
        player_point=player_point+1
        print(f"Your score:{player_point}\t computer score:{comp_point}")

    elif c=='r' and ip=='s':
        print(f"You entered {ip} and computer entered {c}")
        print("Computer wins 1 point")
        comp_point=comp_point+1
        print(f"Your score:{player_point}\t computer score:{comp_point}")

    elif c=='p' and ip=='r':
        print(f"You entered {ip} and computer entered {c}")
        print("Computer wins 1 point")
        comp_point=comp_point+1
        print(f"Your score:{player_point}\t computer score:{comp_point}")

    elif c=='p' and ip=='s':
        print(f"You entered {ip} and computer entered {c}")
        print("You wins 1 point")
        player_point=player_point+1
        print(f"Your score:{player_point}\t computer score:{comp_point}")

    elif c == 's' and ip == 'r':
        print(f"You entered {ip} and computer entered {c}")
        print("You wins 1 point")
        player_point = player_point + 1
        print(f"Your score:{player_point}\t computer score:{comp_point}")

    elif c=='s' and ip=='p':
        print(f"You entered {ip} and computer entered {c}")
        print("Computer wins 1 point")
        comp_point=comp_point+1
        print(f"Your score:{player_point}\t computer score:{comp_point}")

    else:
        print("enter valid choice ")
        continue

    chance_taken=chance_taken+1
    print(f"you have consumed:{chance_taken} chance \t remaing chances :{remain_chance-chance_taken}")
    print("-----------------------------\n")


if(comp_point==player_point):
    print("Gameover\nThis is a tie")

elif comp_point>player_point:
    print("Game over\nSorry..you lose..play again")

elif comp_point<player_point:
    print("Game over\nHurray...You win")

print(f"Your score :{player_point}\t Computer score :{comp_point}")


